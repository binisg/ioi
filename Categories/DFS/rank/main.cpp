#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> res;

bool dfs(int i, vector<bool> &visited, int &target) {
    visited[i] = true;

    for (auto x: adj[i]) {
        if (x == target) return true;
        else if (!visited[x]) {
            if (dfs(x, visited, target)) return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, K; cin >> N >> K;
    adj.resize(N); res.resize(N, 0); 

    for (int i = 0; i < K; i++) {
        int a, b, s1, s2; 
        cin >> a >> b >> s1 >> s2;
        if (s1 > s2) adj[a-1].push_back(b-1);
        else if (s1 < s2) adj[b-1].push_back(a-1);
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false);
        if (dfs(i, visited, i)) result++;
    }

    cout << result << '\n';

    return 0;
}