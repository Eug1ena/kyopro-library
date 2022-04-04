lint LargestRectangleInHistogram(vector<lint> h){
    int n = int(h.size());
    vector<lint> R(n, n), L(n, -1);
    
    vector<lint> stack;
    rep(i, n){
        while(!stack.empty() && h[i] < h[stack.back()]){
            R[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    stack.clear();
    repr(i, n){
        while(!stack.empty() && h[i] < h[stack.back()]){
            L[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    
    lint ans = 0;
    rep(i, n){
        ans = max(ans, (R[i] - L[i] - 1) * h[i]);
    }
    return ans;
}
