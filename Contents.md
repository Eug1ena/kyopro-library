## 内容物 / Contents
### SpiralGrid.cpp
2次元グリッド上の渦巻き。左上のマスから右向きに進む。返り値のpairは(y, x)の形。<br>
verify : [https://yukicoder.me/submissions/445147](https://yukicoder.me/submissions/445147)

### UnionFind.cpp
Union-Find木。サイズの取得も可能。<br>

### UnionFindEdge.cpp
辺情報の増えたUnion-Find木。辺の本数の取得が可能。<br>
verify: [https://atcoder.jp/contests/arc111/submissions/19296389](https://atcoder.jp/contests/arc111/submissions/19296389)

### SegtreeRUQRMQ.cpp
RUQとRMQに対応した遅延セグメント木。<br>

### FFT.cpp
FFTによって高速化された多項式の畳み込み。<br>
verify : [https://atcoder.jp/contests/atc001/submissions/14417236](https://atcoder.jp/contests/atc001/submissions/14417236)

### Lowlink.cpp
O(E)でグラフの橋を検出する。返り値の配列は"arr[i]=辺iが橋か"。<br>
verify: [https://judge.yosupo.jp/submission/21094](https://judge.yosupo.jp/submission/21094)

### Modint.cpp
いわゆるModint。加減乗除、逆数、累乗、入出力の機能がある。<br>
(小さな注意: "10-Modint(5)"はエラーを吐くので"-Modint(5)+10"と表記する)<br>
verify: [https://atcoder.jp/contests/agc053/submissions/21690367](https://atcoder.jp/contests/agc053/submissions/21690367)

### LargestRectangleInHistogram.cpp
ヒストグラム中の最大長方形。stackを利用したO(N)解法。<br>
verify: [https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/5428996/Euglena/C++14](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/5428996/Euglena/C++14)

### Diameter.cpp
木の直径。<br>
verify: [https://atcoder.jp/contests/typical90/submissions/23441141](https://atcoder.jp/contests/typical90/submissions/23441141)