-- If you want to play around with this code on CSE, save the file and then
-- run the following commands in the directory the file is located in:
-- sequence of commands:
--   $ cabal repl
--   ...
--   Prelude> :l Tute1.hs
---  ...
--   *Main> mapList abs (Cons (-1) (Cons (-2) (Cons (-3) Nil)))
--   Cons 1 (Cons 2 (Cons 3 Nil))
--   ...

module Tute1 where

-- | An example of the data keyword
--   We use this when we're making our own data type
--   In this case, we're defining our own list type:
--     * List is a unary (1-arg) type constructor
--     * Nil is a nullary (0-arg) data constructor producing empty lists
--     * Cons is a binary (2-arg) type constructor producing non-empty lists
--   With regards to the rest of the Haskell happening here, some notes:
--     * Haskell allows type args - that's the "a" thing on the LHS, which can
--       be roughly compared to generics in Java, C++ or otherwise
--     * We have deriving - in this particular use case, we're instructing
--       Haskell to figure out a way to be able to print Lists for testing,
--       which it can automatically do in a lot of cases (!!!)
data List a = Nil
            | Cons a (List a)
            deriving Show

-- | An example of the type keyword
--   We use this when we want to give a name to an existing type
--   In this case, an IntList is just a List of Ints
type IntList = List Int

-- | Join two integer lists together
--   Note the use of pattern matching on the List data constructors,
--   which is why Haskell code is often very succinct; you can essentially
--   define a function by cases like we would in maths
concatIntLists :: IntList -> IntList -> IntList
concatIntLists Nil         ys = ys
concatIntLists (Cons x xs) ys = Cons x (concatIntLists xs ys)

-- | Convert a List of our type to a Haskell built-in list
--   Note the use of the : operator, which is a prepend operation on lists
--   You usually hear this operator called "cons" (which is actually the
--   motivation for my choice of constructor name in our List type!)
convertToHaskellList :: List a -> [a]
convertToHaskellList Nil         = []
convertToHaskellList (Cons x xs) = x : convertToHaskellList xs

-- | Apply a function to each element of a list
--   A more complicated example demonstrating higher-order functions,
--   i.e. functions as arguments to other functions
--   Note also the use of _, which you can use in place of unused args
--   (e.g. in the Nil case, we don't actually apply the function given)
mapList :: (a -> b) -> List a -> List b
mapList _ Nil         = Nil
mapList f (Cons x xs) = Cons (f x) (mapList f xs)
