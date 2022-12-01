#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool good(vector<vector<char>> &vec, int &gs, vector<vector<bool>> &visited) {
    stack<pair<int, int>> s;
    s.push({vec.size()-1, vec[0].size()-1});
    int g = 0;

    while (!s.empty()) {
        int i = s.top().first, j = s.top().second;
        s.pop();

        if ((i < 0 || j < 0 || i == vec.size() || j == vec[0].size()) || visited[i][j] || vec[i][j] == '#') continue;
        if (vec[i][j] == 'B') return false;
        if (vec[i][j] == 'G') g++;

        visited[i][j] = true;

        s.push({i-1, j});
        s.push({i, j-1});
        s.push({i+1, j});
        s.push({i, j+1});
    }  

    if (g == gs) return true;
    else return false;
}

void flood_fill (int i, int j, vector<vector<char>> &vec, vector<vector<bool>> &visited) {
    visited[i][j] = true;

    if (
        (i != 0 && vec[i-1][j] == 'B') ||
        (j != 0 && vec[i][j-1] == 'B') ||
        (i != vec.size()-1 && vec[i+1][j] == 'B') ||
        (j != vec[0].size() && vec[i][j+1] == 'B')
    ) {
        if (vec[i][j] == '.') vec[i][j] = '#';
        return;
    }

    if (i != 0) {
        if (!visited[i-1][j]) {
            if (vec[i-1][j] != '#') {
                flood_fill(i-1, j, vec, visited);
            }
        }
    }

    if (j != 0) {
        if (!visited[i][j-1]) {
            if (vec[i][j-1] != '#') {
                flood_fill(i, j-1, vec, visited);
            }
        }
    }

    if (i != vec.size()-1) {
        if (!visited[i+1][j]) {
            if (vec[i+1][j] != '#') {
                flood_fill(i+1, j, vec, visited);
            }
        }
    }

    if (j != vec[0].size()-1) {
        if (!visited[i][j+1]) {
            if (vec[i][j+1] != '#') {
                flood_fill(i, j+1, vec, visited);
            } 
        }
    }

}

void solve() {
    int N, M; cin >> N >> M;
    int gs = 0;

    vector<vector<char>> vec(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 'G') gs++;
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    flood_fill(N-1, M-1, vec, visited);

    vector<vector<bool>> visited2(N, vector<bool> (M, false));
    if (good(vec, gs, visited2)) cout << "Yes\n";
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