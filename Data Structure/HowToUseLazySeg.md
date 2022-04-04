## How to use lazy segment tree

### コンストラクタの引数

* f(要素, 要素) = マージされた要素
* g(要素, 作用素) = 作用された要素
* h(元の作用素, 新たな作用素) = マージされた作用素
* p(作用素, 作用する区間の長さ) = その区間の作用素

### 記述例

区間add + 区間min:

```c++
auto f = [](int a, int b) { return min(a, b); };
auto g = [](int a, int b) { return a + b; };
auto h = [](int a, int b) { return a + b; };
auto p = [](int a, int len) { return a; };
LazySegmentTree<int> seg(n, f, g, h, p, INT_MAX);
```

区間add + 区間sum:

```c++
auto f = [](int a, int b) { return a + b; };
auto p = [](int a, int len) { return a * len; };
LazySegmentTree<int> seg(n, f, f, f, p, 0);
```

区間update + 区間min: 

```c++
auto f = [](int a, int b) { return min(a, b); };
auto g = [](int a, int b) { return b; };
auto h = [](int a, int b) { return b; };
auto p = [](int a, int len) { return a; };
LazySegmentTree<int> seg(n, f, g, h, p, INT_MAX);
```

区間update + 区間sum:

```c++
auto f = [](int a, int b) { return a + b; };
auto g = [](int a, int b) { return b; };
auto h = [](int a, int b) { return b; };
auto p = [](int a, int len) { return a * len; };
LazySegmentTree<int> seg(n, f, g, h, p, 0);
```

### verify

区間add + 区間min: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/DSL_2_H/judge/5763734/C++14<br>区間add + 区間sum: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/DSL_2_G/judge/5763735/C++14<br>区間update + 区間min: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/DSL_2_F/judge/5763746/C++14<br>区間update + 区間sum: https://onlinejudge.u-aizu.ac.jp/status/users/Euglena/submissions/1/DSL_2_I/judge/5763759/C++14

区間affine + 区間sum: https://judge.yosupo.jp/submission/55687<br>(要素と作用素の型が違う場合)

