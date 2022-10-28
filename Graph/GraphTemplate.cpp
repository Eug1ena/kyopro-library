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
    
    int size() const {
        return int(g.size());
    }
    
    void add_directed_edge(int from, int to, T cost = 1){
        g[from].push_back(Edge<T>(from, to, cost, edge_cnt++));
    }
    
    void add_edge(int from, int to, T cost = 1){
        g[from].push_back(Edge<T>(from, to, cost, edge_cnt));
        g[to].push_back(Edge<T>(to, from, cost, edge_cnt++));
    }
    
    const vector<Edge<T>>& operator [](int k) const {
        return g[k];
    }
    
    void resize(int n){
        g.resize(n);
    }
};
template<class T = int>
using Edges = vector<Edge<T>>;
