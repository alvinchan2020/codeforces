import Control.Monad
import Data.Char
import Data.Int

solve :: Int64 -> Int
solve n
  | n `mod` 2050 /= 0 = -1
  | otherwise = bitsSum $ quot n 2050
  where
    bitsSum i = sum $ (\c -> ord c - ord '0') <$> show i

solveIO :: IO ()
solveIO = do
  l <- getLine
  let n = read l :: Int64
  putStr $ show (solve n) ++ "\n"

main :: IO ()
main = do
  l <- getLine
  let t = read l :: Int
  replicateM_ t solveIO
