#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second 

void dfs(int i, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[i] = true;

    for (auto j: adj[i]) {
        if (!visited[j]) {
            dfs(j, visited, adj);
        }
    }
}

int dist(pi &a, pi &b) {
    return pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
}

bool solve(int num, vector<pi> &vec) {
    vector<vector<int>> adj(vec.size());
    for (int i = 0; i < adj.size()-1; i++) {
        for (int j = i+1; j < adj.size(); j++) {
            if (dist(vec[i], vec[j]) <= num) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited(adj.size(), false);
    dfs(0, visited, adj);

    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) return false;
    }

    return true;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int N; cin >> N;

    vector<pi> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].x >> vec[i].y;
    }

    int a = 0, b = 1e9, mid; 
    while (a < b) {
        mid = (a+b)/2;
        if (solve(mid, vec)) {
            b = mid;
        } else a = mid+1;
    }

    cout << b << '\n';

    return 0;
}