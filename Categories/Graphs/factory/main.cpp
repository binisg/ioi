#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int &i) {
    if (visited[i]) return;
    visited[i] = true;
    for (int k = 0; k < adj[i].size(); k++) {
        dfs(adj[i][k]);
    }
    return;
}

int main() {
    FILE *in = fopen("factory.in", "r");
    FILE *out = fopen("factory.out", "w");

    int N;
    fscanf(in, "%d", &N);

    adj.resize(N);
    visited.resize(N);

    for (int i = 0; i < N-1; i++) {
        int x, y;
        fscanf(in, "%d%d", &x, &y);
        adj[y-1].push_back(x-1);
    }

    int result = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) visited[j] = false;
        dfs(i);
        for (int j = 0; j < N; j++) {
            if (!visited[j]) {
                goto end;
            }
        }
        result = i+1;
        break;
        end: continue;
    }

    fprintf(out, "%d\n", result);
    
    return 0;
}