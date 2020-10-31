# 競プロメモ

## 考察
 > [**ABC174 / C - Repsept**](https://atcoder.jp/contests/abc174/tasks/abc174_c)
 - 余りが同じであれば同じ数とみなせる。
 - mod (合同式) を上手く使う。
##  
 > [**ABC174 / E - Logs**](https://atcoder.jp/contests/abc174/tasks/abc174_e)
 - 最大値の最小化問題
   - 二分探索

## 計算量
 - 制約: `n <= 10^9`
   - nまでの二重ループ以上はほぼ無理。
 
## 浮動小数点数
 - 誤差が出やすいので、上手く式変形して整数だけで判定を行う。
   - 2乗 (両辺)
   - 整数になるまで 10^n をかける etc

## 深さ優先探索(DFS)
 > **再帰関数**
 
 > **stack**
 - 迷路到達判定
 - 総和
 - 最大値 etc
  
## 幅優先探索(BFS)
 > **queue**
 - 迷路最短経路
 - 最小値 etc
