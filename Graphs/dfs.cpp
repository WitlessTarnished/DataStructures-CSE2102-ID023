#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;                    
    vector<vector<int>> adjList;      

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);       
        adjList[v].push_back(u);       
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(vertices, false);  
        cout << "DFS starting from node " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);  

  
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.DFS(0); 

    return 0;
}
