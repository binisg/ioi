#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <queue>

using namespace std;
#define ll long long

int zero = 0;

vector<ll> fix_vec(set<int> &s, int &N) {
    vector<ll> result(N, N);

    auto it = s.begin();
    for (int i = 0; i < N; i++) {
        
    }

    return result;
}

void set_bfs(int i, set<int> &s, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[i] = true;
    queue<int> q;
    q.push(i);
    int p;

    while (!q.empty()) {
        p = q.front();
        s.insert(p);
        q.pop();
        for (int i: adj[p]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

ll set_find(int &x, set<int> &s) {
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

    set_bfs(zero, start, adj, visited);

    if (start.find(N-1) != start.end()) {
        return 0;
    }

    set_bfs(N-1, end, adj, visited);

    ll result = 1e9*1e9;
    for (int x: start) {
        result = min(result, set_find(x, end));
    }

    vector<ll> dist_start = fix_vec(start, N), dist_end = fix_vec(end, N);

    ll min_start = 1e9*1e9, min_end = 1e9*1e9;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            queue<int> q;
            q.push(i);
            int p;
            while (!q.empty()) {
                p = q.front();
                min_start = min(min_start, dist_start[p]);
                min_end = min(min_end, dist_end[p]);
                q.pop();
                for (int i: adj[p]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }

    result = min(result, (ll)pow(min_start, 2) + (ll)pow(min_end, 2));

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