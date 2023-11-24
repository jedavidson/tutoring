module MinHS where

data Type
  = IntTy
  | BoolTy
  | FunTy Type Type
  deriving (Eq, Show)

data Expr
  = Num Int
  | Lit Bool
  | Plus Expr Expr
  | Eq Expr Expr
  | If Expr Expr Expr
  | Apply Expr Expr
  | Recfun Type Type (Expr -> Expr -> Expr)

{-                    ^^^^^^^^^^^^^^^^^^^^
          This Recfun object is a bit weird.
          The (Expr -> Expr -> Expr) thing is the "f. x. e" abstraction
          described in the MinHS slides. Within that, we say that
          f is the function expression itself (i.e. a Recfun!), x is the
          argument expression to the function, and e is the expression
          returned by the function. The reason why the f exists is so that
          we can do recursion: it allows us to pass the function around as
          an object so that the evaluator can apply it to an argument again.
-}

data Value
  = IntV Int
  | BoolV Bool
  | FunV (Expr -> Expr -> Expr)

-- Ignore this bit of code. It lets us be able to print out to the terminal
-- a string representation of our custom Value type, which is useful for
-- testing the evaluator above with examples and seeing its output.
instance Show Value where
  show (IntV n) = "IntV " ++ show n
  show (BoolV b) = "BoolV " ++ show b
  show (FunV _) = error "'show' called on a function value"

-- | Evaluates a given MinHS expression.
eval :: Expr -> Value
eval (Num n) = IntV n
eval (Lit b) = BoolV b
eval (Plus e1 e2) =
  let IntV n1 = eval e1
      IntV n2 = eval e2
   in IntV (n1 + n2)
eval (Eq e1 e2) =
  case (eval e1, eval e2) of
    (IntV n1, IntV n2) -> BoolV (n1 == n2)
    (BoolV b1, BoolV b2) -> BoolV (b1 == b2)
    _ -> error "Incompatible types for =="
eval (If ec et ee) =
  let BoolV c = eval ec
   in if c then eval et else eval ee
eval (Recfun _ _ e) = FunV e
eval (Apply ef ex) =
  let FunV f = eval ef
   in eval $ f ef ex

{-           ^^^^^^^
      Again, this might be slightly strange.
      We evaluated the function expression to extract the actual "function" (f)
      that does the magic at the Haskell level (i.e. our metalanguage), but we
      also saw earlier that the arguments to that function are expressions.
      The first of those was the function expression itself (ef), and the second
      was the argument expression (ex).
      Remember that we pass around the function expression to allow recursion.
-}

{- Some examples to check that our evaluator is working as intended. -}

onePlusOne :: Expr
onePlusOne = Plus (Num 1) (Num 1)

onePlusOneRecfun :: Expr
onePlusOneRecfun =
  let -- This function is equivalent to the C code
      -- int add(int x, int y) {
      --   return x + y;
      -- }
      add =
        Recfun
          IntTy
          (FunTy IntTy IntTy)
          ( \_ x ->
              Recfun IntTy IntTy (\_ y -> Plus x y)
          )
   in Eq (Apply (Apply add (Num 1)) (Num 1)) (Plus (Num 1) (Num 1))

sumOfFirst3Naturals :: Expr
sumOfFirst3Naturals =
  let -- This function is recursive. Notice how we refer to the first argument f,
      -- which represents the Recfun itself so that we can apply it again.
      -- Note that if the argument is a negative number, this loops forever!
      --
      -- This function is equivalent to the C code
      -- int sumTo(int x) {
      --   if (n == 0) return 1;
      --   else        return x + sumTo(x - 1);
      -- }
      sumTo =
        Recfun
          IntTy
          IntTy
          ( \f x ->
              If
                (Eq x (Num 1))
                (Num 1)
                (Plus x (Apply f (Plus x (Num (-1)))))
          )
   in Apply sumTo (Num 3)
