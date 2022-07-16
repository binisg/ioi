#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <deque>
#include <queue>

using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<unordered_set<int>> cant;

int counter = 0;

int main() {
    FILE *in = fopen("planting.in", "r");
    FILE *out = fopen("planting.out", "w");

    int N;
    fscanf(in, "%d", &N);
    visited.resize(N); adj.resize(N); cant.resize(N);

    for (int i = 0; i < N-1; i++) {
        int x, y;
        fscanf(in, "%d%d", &x, &y);
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cant[i].insert(adj[i][j]);
            for (int k = 0; k < adj[j].size(); k++) cant[i].insert(adj[j][k]);
        }
    }

    deque<int> d; queue<int> q; 
    q.push(0);

    while (!q.empty()) {
        int i = q.front(); q.pop();
        if (visited[i]) continue;
        visited[i] = true;
        int top;
        if (d.size() > 0) {
            top = d.front();
            auto k = cant[i].find(top);
            if (k != cant[i].end()) {
                d.push_back(i);
                counter++;
            } else {
                d.pop_front();
                d.push_back(i);
            }
        } else {
            d.push_back(i);
            counter++;
        }
        for (int j = 0; j < adj[i].size(); j++) {
            q.push(adj[i][j]);
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout << "[ ";
    //     for (auto j: cant[i]) {
    //         cout << j << " ";
    //     }
    //     cout << "]\n";
    // }

    cout << counter << endl;

    return 0;
}