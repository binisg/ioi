#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void set_dfs(int i, set<int> &s, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[i] = true;
    s.insert(i);

    for (auto x: adj[i]) {
        if (!visited[x]) {
            set_dfs(x, s, adj, visited);
        }
    }
}

int set_find(int &x, set<int> &s) {
    int ret = 1e9;
    auto i = lower_bound(s.begin(), s.end(), x);

    if (i != s.end()) {
        ret = max(*i, x) - min(*i, x);
    }
    if (i != s.begin()) {
        i--;
        ret = min(ret, max(*i, x) - min(*i, x));
    }

    return pow(ret, 2);
}

int counter = 0;

void dfs(int &i, vector<vector<int>> &adj, vector<bool> &visited, int &min_start, int &min_end, set<int> &start, set<int> &end) {
    counter++;
    visited[i] = true;
    min_start = min(min_start, set_find(i, start));
    min_end = min(min_end, set_find(i, end));

    for (auto x: adj[i]) {
        if (!visited[x]) {
            dfs(x, adj, visited, min_start, min_end, start, end);
        }
    }
}

int func(int &i, vector<vector<int>> &adj, vector<bool> &visited, set<int> &start, set<int> &end) {
    int min_start = 1e9, min_end = 1e9;
    dfs(i, adj, visited, min_start, min_end, start, end);
    return min_start + min_end;
}


int solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    set<int> start, end;

    vector<bool> visited(N, false);
    set_dfs(0, start, adj, visited);

    if (start.find(N-1) != start.end()) {
        return 0;
    }

    set_dfs(N-1, end, adj, visited);

    int result = 1e9;
    for (int x: start) {
        result = min(result, set_find(x, end));
    }


    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            result = min(result, func(i, adj, visited, start, end));
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }

    return 0;
}