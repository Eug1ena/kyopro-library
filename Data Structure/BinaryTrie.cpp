template<class T, int BIT_COUNT = -1>
struct BinaryTrie{
    struct Node {
        Node *child[2];
        int under_cnt;
        
        Node() : child{nullptr, nullptr}, under_cnt(0) {}
    };
    
    int B;
    Node *root;
    
    BinaryTrie() : root(new Node()) {
        if(BIT_COUNT == -1){
            B = numeric_limits<T>::digits + int(numeric_limits<T>::is_signed);
        }else{
            B = BIT_COUNT;
        }
    }
    
    void insert(T x){
        Node *at = root;
        repr(i, B){
            (at -> under_cnt)++;
            
            bool d = ((x >> i) & 1);
            if(!(at -> child[d])) (at -> child[d]) = new Node();
            at = at -> child[d];
        }
        (at -> under_cnt)++;
    }
    
    int count(T x){
        Node *at = root;
        repr(i, B){
            bool d = ((x >> i) & 1);
            at = at -> child[d];
            if(!at) return 0;
        }
        return at -> under_cnt;
    }
    
    bool erase(T x){
        Node *at = root;
        repr(i, B){
            bool d = ((x >> i) & 1);
            at = at -> child[d];
            if(!at) return false;
        }
        
        at = root;
        repr(i, B){
            (at -> under_cnt)--;
            
            bool d = ((x >> i) & 1);
            at = at -> child[d];
        }
        (at -> under_cnt)--;
        return true;
    }
    
    int size(){
        return root -> under_cnt;
    }
    
    T kth_element(int k){ // 0-indexed
        assert(0 <= k && k < size());
        k++;
        
        Node *at = root;
        T ans = 0, one = 1;
        repr(i, B){
            int l_cnt = (at -> child[0] ? at -> child[0] -> under_cnt : 0);
            if(k <= l_cnt){
                at = at -> child[0];
            }else{
                at = at -> child[1];
                k -= l_cnt;
                ans += (one << i);
            }
        }
        return ans;
    }
};
