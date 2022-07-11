#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int i) {
    if (visited[i]) return;
    visited[i] = true;
    cout << i << "\n";
    for (int j: adj[i]) dfs(j);
    return;
}

int main() {
    ifstream in("dfs.in");

    in >> N >> K;
    adj.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++) visited[i] = false;
    for (int i = 0; i < K; i++) {
        int a, b;
        in >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);

    return 0;
}