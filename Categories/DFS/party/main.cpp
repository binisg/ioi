#include <iostream>
#include <vector>

using namespace std;

bool whatif(int x, vector<vector<int>> &adj, int &a, int &b, vector<bool> &visited) {
    visited[x] = true;

    for (auto i: adj[x]) {
        if (!visited[i] && !(x == a && i == b) && !(x == b && i == a)) whatif(i, adj, a, b, visited);
    }

    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    bool stop = false;
    while (!stop) {
        bool ans = true;

        int p, c; cin >> p >> c;
        if (p == 0 && c == 0) {
            stop = true;
            continue;
        }

        vector<vector<int>> adj(p);
        for (int i = 0; i < c; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b); adj[b].push_back(a);
        }

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                vector<bool> visited(p, false);
                if (!whatif(0, adj, i, adj[i][j], visited)) {
                    ans = false;
                    goto end;
                }
            }
        }

        end: 
        if (ans) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}