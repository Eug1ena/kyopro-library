vector<Point> ConvexHull(vector<Point> ps){
    int n = int(ps.size());
    
    sort(all(ps), [](Point p, Point q){
        if(p.real() != q.real()) return p.real() < q.real();
        return p.imag() < q.imag();
    });
    
    vector<Point> qs;
    rep(i, n){
        while(qs.size() >= 2 && ccw(qs[qs.size() - 2], qs.back(), ps[i]) != 1) {
            qs.pop_back();
        }
        qs.push_back(ps[i]);
    }
    
    int t = int(qs.size());
    repr(i, n - 1){
        while(qs.size() > t && ccw(qs[qs.size() - 2], qs.back(), ps[i]) != 1) {
            qs.pop_back();
        }
        qs.push_back(ps[i]);
    }
    
    qs.pop_back();
    return qs;
}
