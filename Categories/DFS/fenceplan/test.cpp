#include <iostream>
#include <vector>

using namespace std;

struct cow {
    int x, y;
    vector<int> adj;
};

vector<bool> visited;
vector<cow> cows;

void dfs(int x, vector<bool> &visited, pair<int, int> &min_p, pair<int, int> &max_p) {
    visited[x] = true;
    if (cows[x].x > max_p.first) max_p.first = cows[x].x;
    if (cows[x].x < min_p.first) min_p.first = cows[x].x;
    if (cows[x].y > max_p.second) max_p.second = cows[x].y;
    if (cows[x].y < min_p.second) min_p.second = cows[x].y;

    for (int i = 0; i < cows[x].adj.size(); i++) {
        if (!visited[cows[x].adj[i]]) dfs(cows[x].adj[i], visited, min_p, max_p);
    }
}

int find_dist(int x1, int y1, int x2, int y2) {
    int one = max(x1-x2, x2-x1), two = max(y1-y2, y2-y1);
    int val = one + two;
    if (one > 0) val += two; if (two > 0) val += one;
    return val;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int N, M; cin >> N >> M;
    visited.resize(N); cows.resize(N);
    fill(visited.begin(), visited.end(), false);

    for (int i = 0; i < N; i++) cin >> cows[i].x >> cows[i].y;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        cows[a-1].adj.push_back(b-1);
        cows[b-1].adj.push_back(a-1);
    }
    
    int min_dist = 1e9;
    for (int i = 0; i < N; i++) {
        vector<pair<int, int>> vec;
        if (!visited[i]) {
            pair<int, int> min_p = {1e9, 1e9}, max_p = {0, 0};
            dfs(i, visited, min_p, max_p);
            min_dist = min(min_dist, find_dist(min_p.first, min_p.second, max_p.first, max_p.second));
        }
    }

    cout << min_dist << '\n';

    return 0;
}