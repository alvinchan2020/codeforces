import Control.Monad

-- Hmmmmm, alright, I know how to solve it in an imperative way,
-- but it seems hard to solve it in functional way, 'cause I wanna use states and mutations
solve :: Int -> Int -> [[Int]] -> [[Int]]
solve n m paths = [[0]]

solveIO :: IO ()
solveIO = do
  [n, m] <- readLineIntegers
  paths <- replicateM n readLineIntegers

  let resultPaths = solve n m paths
  sequence_ (writeLineIntegers <$> resultPaths)
  where
    readLineIntegers = (read <$>) . words <$> getLine :: IO [Int]
    writeLineIntegers = putStrLn . unwords . (show <$>) :: [Int] -> IO ()

main :: IO ()
main = do
  t <- read <$> getLine :: IO Int
  replicateM_ t solveIO
