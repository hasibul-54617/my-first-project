#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<bool>& visited, vector<bool>& recStack, vector<vector<int>>& graph) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack, graph))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;//second commit
    return false;
}

bool isCycle(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(V);

    for (auto edge : edges) {
        graph[edge.first].push_back(edge.second);
    }

    vector<bool> visited(V, false), recStack(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, graph))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5; //first commit
    vector<pair<int, int>> edges = {{0,1},{1,2},{2,0},{3,4}};

    if (isCycle(V, edges)) {
        cout << "Cycle found" << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}
