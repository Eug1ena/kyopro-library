namespace F2Linear{
    int GaussJordan(vector<vector<int>> &a, bool is_extended = false){
        int h = int(a.size());
        int w = int(a[0].size());

        int rank = 0;
        rep(col, w){
            if(is_extended && col == w - 1) break;
            
            int pivot = -1;
            rep2(row, rank, h){
                if(a[row][col]){
                    pivot = row;
                    break;
                }
            }
            if(pivot == -1){
                continue;
            }

            swap(a[pivot], a[rank]);
            rep(row, h){
                if(row != rank && a[row][col]){
                    rep(i, w) a[row][i] ^= a[rank][i];
                }
            }
            rank++;
        }
        return rank;
    }

    int LinearEquation(vector<vector<int>> a, vector<int> b, vector<int> &res){
        int h = int(a.size());
        int w = int(a[0].size());
        
        vector<vector<int>> mat(h, vector<int>(w + 1));
        rep(i, h){
            rep(j, w){
                mat[i][j] = a[i][j];
            }
            mat[i][w] = b[i];
        }
        
        int rank = GaussJordan(mat, true);
        
        rep2(row, rank, h){
            if(mat[row][w]){
                return -1;
            }
        }
        
        res.assign(w, 0);
        rep(i, rank) res[i] = mat[i][w];
        return rank;
    }
}
