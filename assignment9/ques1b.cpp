#include<iostream>
#include<vector>
using namespace std;

#define WHITE 0
#define GRAY  1
#define BLACK 2

class Graph {
    int V;
    vector<int> adj[100];
    int time;

public:
    Graph(int V) {
        this->V = V;
        time = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS_VISIT(int u, int color[], int d[], int f[], int pi[]) {
        color[u] = GRAY;
        time = time + 1;
        d[u] = time;

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(color[v] == WHITE) {
                pi[v] = u;
                DFS_VISIT(v, color, d, f, pi);
            }
        }

        color[u] = BLACK;
        time = time + 1;
        f[u] = time;
    }

    void DFS() {
        int color[100], d[100], f[100], pi[100];

        for(int i = 0; i < V; i++) {
            color[i] = WHITE;
            pi[i] = -1;
        }

        for(int i = 0; i < V; i++) {
            if(color[i] == WHITE)
                DFS_VISIT(i, color, d, f, pi);
        }

        cout << "Vertex  d  f  Parent\n";
        for(int i = 0; i < V; i++) {
            cout << i << "      " << d[i] << "  " << f[i] << "  " << pi[i] << endl;
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);

    g.DFS();
    return 0;
}
