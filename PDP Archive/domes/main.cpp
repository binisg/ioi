#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("domes.in", "r", stdin);
    freopen("domes.out", "w", stdout);

    int N, M; cin >> N >> M;

    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int counter = 0;
    for (auto v: adj) {
        if (v.size() < 2) counter++;
    }

    cout << counter << '\n';

    return 0;
}