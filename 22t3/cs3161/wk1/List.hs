-- Some additional practice exercises with Haskell basics

-- You can run/test your solutions using a REPL, either locally through
-- stack once you've installed it, or on the CSE machines using cabal:
--   $ cabal repl
--   <some output...>
--   Prelude> :l List.hs
--   <some more output...>
--   *Main> mapList abs (Cons (-1) (Cons (-2) (Cons (-3) Nil)))
--   Cons 1 (Cons 2 (Cons 3 Nil))
--   ...
-- (replace cabal with stack if you're working locally)

-- Remember that you can reload a file that you have open in the repl using :r
-- so that any changes you've made since loading it take effect

module List where

-- The types I introduced in the tutorial

data List a = Nil
            | Cons a (List a)
            deriving Show

type IntList = List Int

-- Ex. 1: Join two integer lists together
-- For example,
--   ghci> concatIntLists (Cons 1 Nil) (Cons 2 Nil)
--   Cons 1 (Cons 2 Nil)

concatIntLists :: IntList -> IntList -> IntList
concatIntLists = undefined

-- Ex. 2: Convert a List of our type to a Haskell built-in list
-- For example,
--   ghci> convertToHaskellList (Cons 1 (Cons 2 Nil))
--   [1, 2]

convertToHaskellList :: List a -> [a]
convertToHaskellList = undefined

-- Ex. 3: Apply a function to each element of a list
-- For example,
--   mapList (\x -> x + 1) (Cons 1 (Cons 2 Nil))
--   Cons 2 (Cons 3 Nil)

mapList :: (a -> b) -> List a -> List b
mapList = undefined

-- Ex. 4: Extract the elements of a list at "even" positions/indices
-- For example,
--   ghci> onlyEvens (Cons 1 (Cons 2 (Cons 3 Nil)))
--   Cons 1 (Cons 3 Nil)

-- Hint: you probably need a helper function

onlyEvens :: List a -> List a
onlyEvens = undefined
