namespace lowlink{
    vector<vector<pair<int, int>>> roads_l;

    vector<int> label, lowlink;
    vector<bool> is_bridge;

    int dfs(int now, int back){
        lowlink[now] = label[now];
        
        int label_num = label[now];
        for(auto to: roads_l[now]){
            if(to.second == back){
                continue;
            }
            if(label[to.first] == -1){
                label[to.first] = label_num + 1;
                label_num = dfs(to.first, to.second);
                if(label[now] < lowlink[to.first]){
                    is_bridge[to.second] = true;
                }
            }
            lowlink[now] = min(lowlink[now], lowlink[to.first]);
        }
        return label_num;
    }

    vector<bool> get_bridge(int N, vector<pair<int, int>> edges){
        roads_l.resize(N);
        int cnt = 0;
        for(auto i: edges){
            roads_l[i.first].push_back({i.second, cnt});
            roads_l[i.second].push_back({i.first, cnt});
            cnt++;
        }
        label = vector<int>(N, -1);
        lowlink = vector<int>(N, -1);
        is_bridge = vector<bool>(edges.size(), false);
        rep(i, N){
            if(label[i] == -1){
                label[i] = 0;
                dfs(i, -1);
            }
        }
        return is_bridge;
    }
}

// verify: https://judge.yosupo.jp/submission/21094
