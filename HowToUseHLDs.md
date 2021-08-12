## How to use HLDs

### HLD.cpp

パス上の **一点更新** と **区間取得** に対応したHL分解。可換性を **要求しない** 。<br>引数はSegmentTree.cppと同じ。<br>辺にコストがある場合はis_edge = trueにする。<br>verify (辺コスト): https://yukicoder.me/submissions/688261

### HLDCommutative.cpp

パス上の **一点更新** と **区間取得** に対応したHL分解。可換性を **要求する** 。<br>引数はSegmentTree.cppと同じ。<br>辺にコストがある場合はis_edge = trueにする。<br>verify (辺コスト): https://codeforces.com/contest/593/submission/125571364

### LazyHLDCommutative.cpp

パス上の **区間更新** と **区間取得** に対応したHL分解。可換性を **要求する** 。<br>引数はLazySegmentTree.cppと同じ。<br>辺にコストがある場合はis_edge = trueにする。<br>verify: https://yukicoder.me/submissions/688077