# 内容物 / Contents

## データ構造 (Data Structure)

### SegmentTree.cpp

セグメント木。モノイドなら何でも入る。

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
遅延セグメント木。詳細な使い方は [別紙](HowToUseLazySeg.md) 参照。<br>

### DualSegmentTree.cpp

双対セグ木。半群なら何でも入る。

RUQの場合の例:

```c++
DualSegmentTree<int> seg(n, [](int a, int b){ return b; });
```

verify (RUQ): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/DSL_2_D/judge/5843123/C++17

### SegmentTreeBeats.cpp

区間chmin/chmax/addと区間sumの取得ができるセグメント木。

verify: https://judge.yosupo.jp/submission/55830

### BinaryIndexedTree.cpp

Binary Indexed Tree。一点加算とprefix和の取得ができる。

verify: https://old.yosupo.jp/submission/54164

### SparseTable.cpp

Sparse Table。

verify: https://judge.yosupo.jp/submission/59897

### UnionFind.cpp
Union-Find木。サイズの取得も可能。<br>

### UnionFindEdge.cpp
辺情報の増えたUnion-Find木。辺の本数の取得が可能。

verify: [https://atcoder.jp/contests/arc111/submissions/19296389](https://atcoder.jp/contests/arc111/submissions/19296389)

### HLD.cpp, HLDCommutative.cpp, LazyHLDCommutative.cpp

それぞれ 一点更新区間取得、一点更新区間取得(可換性要求)、区間更新区間取得(可換性要求) のHL分解。<br>可換性を要求する方はしない方より更新が2倍速い。<br>詳細は [別紙](HowToUseHLDs.md) 参照のこと。

### BinaryTrie.cpp

2進数を扱うTrie木。初期化時にbit長も与えることができる。<br>要素の追加、削除、検索、k番目の取得が、bit数をBとしてO(B)でできる。

vefify: https://atcoder.jp/contests/arc033/submissions/27195036<br>verify: https://yukicoder.me/submissions/715960

## グラフ (Graph)

### GraphTemplate.cpp

グラフライブラリのテンプレート。<br>~~以下のグラフライブラリは一部C++14以前では動作しない。( [テンプレート推論 ](https://cpprefjp.github.io/lang/cpp17/type_deduction_for_class_templates.html)をしているため)~~ 改修してC++14でも動作するようにしました。<br>

### LCA.cpp

最小共通祖先と木上の距離。

verify: https://atcoder.jp/contests/abc014/submissions/25003425

### ShortestPath.cpp

最短経路。BFS, 01BFS, Dijkstraが利用できる。<br>移動できない頂点はdist[v]=INFになる。

verify (BFS): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/ALDS1_11_C/judge/5782056/C++17<br>verify (01BFS): https://atcoder.jp/contests/arc005/submissions/25002875<br>verify (Dijkstra):https://judge.yosupo.jp/submission/56419

### BellmanFord.cpp

ベルマンフォード法による最短経路。O(VE)時間。<br>負閉路の検出や、負閉路を鑑みて最短経路を求めたりできる。<br>移動できない頂点はdist[v]=INF、いくらでも距離を短くできる頂点はdist[v]=-g.INFになる。

verify (負閉路検出): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/GRL_1_B/judge/7061196/C++14<br>verify (負閉路を鑑みた最短経路): https://atcoder.jp/contests/abc137/submissions/36010964 

### Lowlink.cpp

O(V+E)でグラフの橋・関節点を検出する。is_bridge[i]="辺iが橋か"。<br>非連結だったり多重辺があってもok。

verify: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/GRL_3_A/judge/5782944/C++17

### Diameter.cpp
木の直径。

verify: https://atcoder.jp/contests/typical90/submissions/25008504

### SCC.cpp

強連結成分分解。groupsが強連結成分のグループ、compが各頂点の属するグループの番号、dagが強連結成分を縮約したDAG。<br>グループの番号はdagにおけるトポロジカルソートの順番になっている。

verify: https://judge.yosupo.jp/submission/62065

### MST.cpp

クラスカル法で最小全域木を求める。

verify: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/ALDS1_12_A/judge/6660885/C++17

### FordFulkerson.cpp

Ford-Fulkerson法による最大流。最悪計算量はO(FE)。<br>もちろん最小カットも解ける。

verify: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/GRL_6_A/judge/7057609/C++14

### MinCostFlow.cpp

Primal-Dual法による最小費用流。辺のコストは非負整数に限る。<br>内部ではポテンシャルを使ってダイクストラ法を動かしており、最悪計算量はO(FElogE)。

verify: https://atcoder.jp/contests/practice2/submissions/36013215

## 数学 (Math)

### FFT.cpp

FFTによる多項式の畳み込み。

verify: [https://atcoder.jp/contests/atc001/submissions/14417236](https://atcoder.jp/contests/atc001/submissions/14417236)

### NTT.cpp

NTTによるmod 998244353の多項式の畳み込み。

verify: https://atcoder.jp/contests/practice2/submissions/30714508

### XorConvolution.cpp

高速アダマール変換(FWHT)による添字xorの畳み込み。<br>高速アダマール変換については [ここ](https://cympfh.cc/aiura/hadamard-xor-convolution) が詳しい。

verify: https://judge.yosupo.jp/submission/54616

### F2Linear.cpp

F2線形代数。掃き出し法&rank計算のGaussJordan()と連立方程式を解くLinearEquation()がある。

verify (GaussJordan()): https://atcoder.jp/contests/yahoo-procon2019-qual/submissions/24720728<br>verify (LinearEquation()): まだ

### PowerSeries.cpp

形式的冪級数。積はO(N^2)時間。

verify: https://atcoder.jp/contests/abl/submissions/25137726

### Combination.cpp

組合せ。

### Matrix.cpp

行列。

## その他 (Misc)

### Modint.cpp

いわゆるModint。加減乗除、逆数、累乗、入出力の機能がある。<br>

verify: [https://atcoder.jp/contests/agc053/submissions/21690367](https://atcoder.jp/contests/agc053/submissions/21690367)

### Geometry.cpp

2次元幾何の諸々。[ここ](https://sen-comp.hatenablog.com/entry/2020/03/10/015751) を参考にした。

verify (dot, cross): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/CGL_2_A/judge/5899158/C++17<br>verify (ccw): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/CGL_1_C/judge/5899164/C++17<br>verify (intersection系): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/CGL_2_B/judge/5899167/C++17<br>verify (intersection系): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/CGL_2_C/judge/5899173/C++17<br>verify (distance_between系): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/CGL_2_D/judge/5899177/C++17<br>verify (projection): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/CGL_1_A/judge/5899185/C++17<br> verify (reflection): https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/CGL_1_B/judge/5899187/C++17

### ConvexHull.cpp

蟻本に載っているグラハムスキャンという手法で凸包を求める。O(NlogN)時間。<br>凸包の頂点は反時計回りに並べて返される。

verify: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/0068/judge/7054203/C++14

### LargestRectangleInHistogram.cpp

ヒストグラム中の最大長方形。stackを利用したO(N)解法。

verify: [https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/5428996/Euglena/C++14](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/5428996/Euglena/C++14)

### InversionNumber.cpp

転倒数。引数には重複の無い数列のみ受け付ける。

verify: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5726662

### SuffixArray.cpp

Suffix ArrayとLCP Arrayを計算する。それぞれO(|S|log|S|), O(|S|)時間で動く。

verify (SA): https://judge.yosupo.jp/submission/55557<br>verify (LCP): https://judge.yosupo.jp/submission/55834

### RollingHash.cpp

mod 2^61-1のローリングハッシュ。

verify: https://atcoder.jp/contests/tenka1-2014-qualb/submissions/28286218
