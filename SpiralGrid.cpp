vector<pair<int, int>> SpiralGrid(int H, int W){
    vector<pair<int, int>> ret;
    rep(i, W){
        ret.push_back({0, i});
    }
    int y = 0, x = W - 1;
    for(int i = 1; i < min(H, W); i++){
        rep(j, H - i){
            if(i % 2) y++; else y--;
            ret.push_back({y, x});
        }
        rep(j, W - i){
            if(i % 2) x--; else x++;
            ret.push_back({y, x});
        }
    }
    return ret;
}

verify : https://yukicoder.me/submissions/445147
