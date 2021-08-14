template<class T = int>
struct Edge{
    int from, to;
    T cost;

    Edge() = default;
    Edge(int from, int to, T cost = 1) : from(from), to(to), cost(cost) {}

    operator int() const { return to; }
};

template<class T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    T INF = numeric_limits<T>::max() / 4;

    Graph() = default;

    explicit Graph(int n) : g(n) {}
    
    size_t size(){
        return g.size();
    }
    
    void add_edge(int from, int to, T cost = 1){
        g[from].push_back({from, to, cost});
    }
    
    vector<Edge<T>>& operator [](int k){
        return g[k];
    }
};
template<class T = int>
using Edges = vector<Edge<T>>;
