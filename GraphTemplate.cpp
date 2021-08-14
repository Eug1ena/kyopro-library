template<class T = int>
struct Edge{
    int from, to;
    T cost;
    int id;
 
    Edge() = default;
    Edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}
 
    operator int() const { return to; }
};

template<class T = int>
struct Graph{
private:
    vector<vector<Edge<T>>> g;
public:
    int edge_cnt = 0;
    T INF = numeric_limits<T>::max() / 4;
 
    Graph() = default;
 
    explicit Graph(int n) : g(n) {}
    
    size_t size(){
        return g.size();
    }
    
    void add_directed_edge(int from, int to, T cost = 1){
        g[from].push_back({from, to, cost, edge_cnt++});
    }
    
    void add_edge(int from, int to, T cost = 1){
        g[from].push_back({from, to, cost, edge_cnt});
        g[to].push_back({to, from, cost, edge_cnt++});
    }
    
    vector<Edge<T>>& operator [](int k){
        return g[k];
    }
};
template<class T = int>
using Edges = vector<Edge<T>>;
