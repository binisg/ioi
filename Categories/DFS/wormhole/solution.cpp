#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second 

int N, M;
vector<int> pos;

void dfs(int &a, vector<vector<pi>> &adj, vector<int> &visited, int &counter, int &limit) {
    visited[a] = counter;

    for (auto i: adj[a]) {
        if (visited[i.x] == 0 && i.y < limit) dfs(i.x, adj, visited, counter, limit);
    }
}

bool can(int &limit, vector<vector<pi>> &adj) {
    vector<int> visited(N, 0);

    int counter = 1;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            dfs(i, adj, visited, counter, limit);
            counter++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (visited[pos[i]] != visited[i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("wormsort.in", "r", stdin);
    // freopen("wormsort.out", "w", stdout);

    cin >> N >> M;

    pos.resize(N); bool sorted = true; 
    for (int i = 0; i < N; i++) {
        cin >> pos[i];
        if (i != 0 && pos[i] < pos[i-1]) sorted = false;
    }

    if (sorted) {
        cout << -1 << '\n';
        return 0;
    }

    int max_weight = 0;

    vector<vector<pi>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        max_weight = max(max_weight, c);
        adj[a-1].push_back({b-1, c});
        adj[b-1].push_back({a-1, c});
    }

    int a = 0, b = max_weight, mid;
    while (a < b) {
        mid = (a+b)/2;
        if (can(mid, adj)) {
            b = mid;
        } else {
            a = mid+1;
        }
    }

    cout << a << '\n';

    return 0;
}