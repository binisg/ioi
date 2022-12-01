#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int N, M; 
vector<vector<int>> vec;
vector<pair<int, int>> pos;
vector<vector<bool>> visited;

bool flood_fill(int &x) {
    for (int i = 0; i < N; i++) {
        fill(visited[i].begin(), visited[i].end(), false);
    }

    if (pos.size() == 0) return true;

    stack<pair<int, int>> s;
    s.push(pos[0]);

    while (!s.empty()) {
        int a = s.top().first, b = s.top().second;
        visited[a][b] = true;
        s.pop();
        
        if (a > 0) {
            if (!visited[a-1][b] && abs(vec[a][b] - vec[a-1][b]) <= x) s.push({a-1, b});
        }

        if (a < N-1) {
            if (!visited[a+1][b] && abs(vec[a][b] - vec[a+1][b]) * 1 <= x) s.push({a+1, b});
        }

        if (b > 0) {
            if (!visited[a][b-1] && abs(vec[a][b] - vec[a][b-1]) * 1 <= x) s.push({a, b-1});
        }

        if (b < M-1) {
            if (!visited[a][b+1] && abs(vec[a][b] - vec[a][b+1]) * 1 <= x) s.push({a, b+1});
        }
    }

    for (auto p: pos) {
        if (!visited[p.first][p.second]) return false;
    }

    return true;
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    vec.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x; cin >> x;
            if (x == 1) pos.push_back({i, j}); 
        }
    }

    int a = 0, b = 1e9, mid;
    while (a < b) {
        mid = (a+b)/2;
        if (flood_fill(mid)) {
            b = mid;
        } else {
            a = mid+1;
        }
    }

    cout << b << '\n';

    return 0;
}