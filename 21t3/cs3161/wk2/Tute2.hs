module Tute2 where

-- Prelude is in some sense the standard library of Haskell,
-- and "hiding (++)" means that we don't want to import the (++)
-- which already exists as a function. We're going to (re-)define
-- our own function which shares that name.
import Prelude hiding ((++))

-- Remember that the List type we talked about in tute 1 is essentially
-- the same as Haskell's built-in lists:
--   [] (what we wrote as Nil) are empty lists
--   x : xs (what we wrote as Cons x xs) is a non-empty list

-- | What is this function doing?
--   It concatenates two lists, returning the result.
(++) :: [a] -> [a] -> [a]
[]       ++ ys = ys              -- eq. 1
(x : xs) ++ ys = x : (xs ++ ys)  -- eq. 2

{-

Left identity: ∀xs. [] ++ xs == xs
"Proof". This is just eq. 1, so nothing to prove.

Right identity: ∀xs. xs ++ [] == xs
Proof. We do an induction on xs.
  - BC: We have xs == [], so we need to prove that [] ++ [] == [].
          LHS == [] ++ []
              == [] by eq. 1
              == RHS
  - IC: We have xs == x : xs'. Assume for an I.H. that xs' ++ [] == xs'.
        Then we need to prove (x : xs') ++ [] == x : xs'.
          LHS == (x : xs') ++ []
              == x : (xs' ++ []) by eq. 2
              == x : xs'         by I.H.
              == RHS

Associativity: ∀xs ys zs. (xs ++ ys) ++ zs == xs ++ (ys ++ zs)
Proof. We do an induction on xs, letting ys and zs be arbitrary lists.
  - BC: We have xs == []. Exercise!
  - IC: We have xs == x : xs'. Exercise!

-}
