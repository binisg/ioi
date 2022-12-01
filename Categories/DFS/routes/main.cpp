#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj1, adj2;
vector<bool> visited;

int chosen = 0;

void dfs_from(int &i) {
    visited[i] = true;

    for (auto &x: adj1[i]) {
        if (!visited[x]) dfs_from(x);
    }
}

void dfs_to(int &i) {
    visited[i] = true;

    for (auto &x: adj2[i]) {
        if (!visited[x]) dfs_to(x);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    adj1.resize(N); adj2.resize(N); 
    visited.resize(N, false); 

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj1[a-1].push_back(b-1);
        adj2[b-1].push_back(a-1);
    }

    dfs_from(chosen);
    for (int i = 1; i < N; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << chosen+1 << " " << i+1 << '\n';
            return 0;
        } 
    }

    fill(visited.begin(), visited.end(), false);

    dfs_to(chosen);
    for (int i = 1; i < N; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i+1 << " " << chosen+1 << '\n';
            return 0;
        } 
    }

    cout << "YES\n";

    return 0;
}