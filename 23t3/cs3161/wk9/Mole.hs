module Mole where

-- | Ex. 1
moveMole :: Int -> [Int]
moveMole 1 = [2]
moveMole 2 = [1, 3]
moveMole 3 = [2, 4]
moveMole 4 = [3, 5]
moveMole 5 = [4]
moveMole _ = error "???"

-- | Ex. 2
killMole :: Int -> Int -> [Int]
killMole d m = if d == m then [] else [m]

-- | Ex. 3.1
myReturn :: a -> [a]
myReturn x = [x]

-- | Ex. 3.2
myBind :: [a] -> (a -> [b]) -> [b]
myBind xs f = concat $ map f xs

move :: [Int] -> Int -> [Int]
move [] m = [m]
move (x : xs) m =
  let ys = killMole x m
      zs = concat (map moveMole ys)
   in concat (map (move xs) zs)

-- | Ex. 4.1: Write the above using the functions from Task 3
move' :: [Int] -> Int -> [Int]
move' [] m = myReturn m
move' (x : xs) m =
  myBind (myBind (killMole x m) moveMole) (move' xs)

-- | Ex. 4.2: Write the above using the inbuilt List monad
move'' :: [Int] -> Int -> [Int]
move'' [] m = return m
move'' (x : xs) m = do
  m' <- killMole x m
  m'' <- moveMole m
  move'' xs m''

-- | Ex. 5
play :: [Int] -> [Int]
play xs = do
  m <- [1 .. 5]
  move xs m
