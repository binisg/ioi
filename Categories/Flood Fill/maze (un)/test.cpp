#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool good(vector<vector<char>> &vec, vector<vector<bool>> &visited) {
    stack<pair<int, int>> s;
    s.push({vec.size()-1, vec[0].size()-1});

    while (!s.empty()) {
        int i = s.top().first, j = s.top().second;
        s.pop();

        if ((i < 0 || j < 0 || i == vec.size() || j == vec[0].size()) || visited[i][j] || vec[i][j] == '#') continue;
        if (vec[i][j] == 'B') return false;

        visited[i][j] = true;

        s.push({i-1, j});
        s.push({i, j-1});
        s.push({i+1, j});
        s.push({i, j+1});
    }  

    return true;
}

void solve() {
    int N, M; cin >> N >> M;

    vector<vector<char>> vec(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> vec[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    if (good(vec, visited)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}