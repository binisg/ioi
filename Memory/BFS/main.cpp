#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ifstream in("bfs.in");

    int N, K;
    in >> N >> K;
    vector<vector<int>> adj(N);
    vector<bool> visited(N);
    for (int i = 0; i < N; i++) visited[i] = false;
    for (int i = 0; i < K; i++) {
        int a, b;
        in >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int a = q.front(); q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        cout << a << "\n";
        for (int i: adj[a]) q.push(i);
    }

    return 0;
}