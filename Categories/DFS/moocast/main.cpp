#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second

vector<vector<int>> adj;

int dfs(int num, vector<bool> &visited) {
    int result = 1;
    visited[num] = true;

    for (int p: adj[num]) {
        if (!visited[p]) {
            result += dfs(p, visited);
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int N; cin >> N;
    adj.resize(N); vector<pair<pi, int>> vec(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i].x.x >> vec[i].x.y >> vec[i].y;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int dist_x = max(vec[i].x.x - vec[j].x.x, vec[j].x.x - vec[i].x.x), dist_y = max(vec[i].x.y - vec[j].x.y, vec[j].x.y - vec[i].x.y);
            if ((dist_x) + (dist_y) <= vec[i].y) {
                adj[i].push_back(j);
            }
        }
    }

    int max_num = 0;
    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false); 
        int num = dfs(i, visited);
        max_num = max(max_num, num);
    }

    cout << max_num << '\n';

    return 0;
}