module Tute10 where

-- Ex: Show how the type checker translates this bit of code
--     to remove the typeclasses.

-- class Compare a where
--   cmp :: a -> a -> Bool
type CompareDict a = (a -> a -> Bool)

-- instance Compare Int where
--   cmp x y = x <= y
intCompareDict :: CompareDict Int
intCompareDict x y = x <= y

-- instance (Compare a) => Compare [a] where
--   cmp xs ys = and (zipWith cmp xs ys)
listCompareDict :: CompareDict a -> CompareDict [a]
listCompareDict cmp xs ys = and (zipWith cmp xs ys)

-- group :: (Compare a) => [a] -> [[a]]
-- group []       = []
-- group (x : xs) = let (ys, zs) = span (cmp x) xs
--                   in (x : ys) : group zs
group :: CompareDict a -> [a] -> [[a]]
group cmp []       = []
group cmp (x : xs) = let (ys, zs) = span (cmp x) xs
                      in (x : ys) : group cmp zs

-- Ex: Define datatypes for a square and rectangle, and suitable
--     coercion functions proving the subtype relations claimed.

data Square    = Square Int
data Rectangle = Rectangle Int Int

coerce :: Square -> Rectangle
coerce (Square w) = Rectangle w w

rs2rr :: (Rectangle -> Square) -> Rectangle -> Rectangle
rs2rr rs = coerce . rs

rs2ss :: (Rectangle -> Square) -> Square -> Square
rs2ss rs = rs . coerce

ss2sr :: (Square -> Square) -> (Square -> Rectangle)
ss2sr ss = coerce . ss

rr2sr :: (Rectangle -> Rectangle) -> (Square -> Rectangle)
rr2sr rr = rr . coerce
