#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second  

int N, M; 
vector<vector<int>> adj; 
vector<bool> closed;

void dfs(int &i, vector<bool> &visited, vector<bool> &closed) {
    visited[i] = true;
    for (auto j: adj[i]) {
        if (!visited[j] && !closed[j]) dfs(j, visited, closed);
    }
}

bool cantravel() {
    int counter = 0;
    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++) {
        if (!visited[i] && !closed[i]) {
            dfs(i, visited, closed);
            counter++;
        }
    }

    return counter <= 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    
    cin >> N >> M;
    adj.resize(N); closed.resize(N, false);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1); adj[b-1].push_back(a-1);
    }

    if (cantravel()) cout << "YES\n";
    else cout << "NO\n";

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        if (i == N-1) return 0;
        closed[num-1] = true;
        if (cantravel()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
