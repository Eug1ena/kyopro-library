# 内容物 / Contents

## データ構造

### SegmentTree.cpp

一般化されたセグメント木。単位元を持つモノイドなら何でも入る。

RSQの場合の例:

```c++
auto f = [](int a, int b){ return a + b; };
SegmentTree<int> seg(n, f, 0);
```

RMQの場合の例:

```c++
auto f = [](int a, int b){ return min(a, b); };
SegmentTree<int> seg(n, f, INT_MAX);
```

verify (RSQ): https://judge.yosupo.jp/submission/54165<br>verify (RMQ): https://judge.yosupo.jp/submission/54166

### LazySegmentTree.cpp
抽象化された遅延セグメント木。詳細な使い方は [別紙](HowToUseLazySeg.md) 参照。<br>

### SegmentTreeBeats.cpp

区間chmin/chmax/addと区間sumの取得ができるセグメント木。<br>verify: https://judge.yosupo.jp/submission/55830

### BinaryIndexedTree.cpp

一点加算とprefix和の取得ができるBinary Indexed Tree。<br>verify: https://old.yosupo.jp/submission/54164

### UnionFind.cpp
Union-Find木。サイズの取得も可能。<br>

### UnionFindEdge.cpp
辺情報の増えたUnion-Find木。辺の本数の取得が可能。<br>
verify: [https://atcoder.jp/contests/arc111/submissions/19296389](https://atcoder.jp/contests/arc111/submissions/19296389)

### HLD.cpp, HLDCommutative.cpp, LazyHLDCommutative.cpp

それぞれ 一点更新区間取得、一点更新区間取得(可換性要求)、区間更新区間取得(可換性要求) のHL分解。<br>可換性を要求する方はしない方より更新が2倍速い。<br>詳細は [別紙](HowToUseHLDs.md) 参照のこと。

## グラフ

### GraphTemplate.cpp

グラフライブラリのテンプレート。<br>以下のグラフライブラリは一部C++14以前では動作しない。( [テンプレート推論 ](https://cpprefjp.github.io/lang/cpp17/type_deduction_for_class_templates.html)をしているため)<br>

### LCA.cpp

最小共通祖先と木上の距離。セグ木も使っているので注意。<br>verify: https://atcoder.jp/contests/abc014/submissions/25003425

### GraphCollection.cpp

最短経路。BFS, 01BFS, Dijkstraが利用できる。<br>移動できない頂点はdist[v]=-1になる。<br>erify (BFS): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/ALDS1_11_C/judge/5782056/C++17<br>verify (01BFS): https://atcoder.jp/contests/arc005/submissions/25002875<br>verify (Dijkstra):https://judge.yosupo.jp/submission/56419

### Lowlink.cpp

O(V+E)でグラフの橋・関節点を検出する。is_bridge[i]="辺iが橋か"。<br>非連結だったり多重辺があってもok。<br>verify: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/GRL_3_A/judge/5782944/C++17

### Diameter.cpp
木の直径。<br>
verify: https://atcoder.jp/contests/typical90/submissions/25008504

## 数学

### FFT.cpp

FFTによって高速化された多項式の畳み込み。<br>
verify: [https://atcoder.jp/contests/atc001/submissions/14417236](https://atcoder.jp/contests/atc001/submissions/14417236)

### XorConvolution.cpp

高速アダマール変換(FWHT)によって高速化されたxorの畳み込み。<br>高速アダマール変換については [ここ](https://cympfh.cc/aiura/hadamard-xor-convolution) が詳しい。<br>verify: https://judge.yosupo.jp/submission/54616

### F2Linear.cpp

F2線形代数。掃き出し法&rank計算のGaussJordan()と連立方程式を解くLinearEquation()がある。<br>verify (GaussJordan()): https://atcoder.jp/contests/yahoo-procon2019-qual/submissions/24720728<br>verify (LinearEquation()): まだ

### PowerSeries.cpp

形式的冪級数。積はO(N^2)時間。<br>verify: https://atcoder.jp/contests/abl/submissions/25137726

## 便利系

### Modint.cpp
いわゆるModint。加減乗除、逆数、累乗、入出力の機能がある。<br>
(小さな注意: "10-Modint(5)"はエラーを吐くので"-Modint(5)+10"と表記する)<br>
verify: [https://atcoder.jp/contests/agc053/submissions/21690367](https://atcoder.jp/contests/agc053/submissions/21690367)

## その他

### LargestRectangleInHistogram.cpp
ヒストグラム中の最大長方形。stackを利用したO(N)解法。<br>
verify: [https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/5428996/Euglena/C++14](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/5428996/Euglena/C++14)

### InversionNumber.cpp

転倒数。引数には重複の無い数列のみ受け付ける。<br>verify: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5726662

### SuffixArray.cpp

Suffix ArrayとLCP Arrayを計算する。それぞれO(|S|log|S|), O(|S|)時間で動く。<br>verify (SA): https://judge.yosupo.jp/submission/55557<br>verify (LCP): https://judge.yosupo.jp/submission/55834