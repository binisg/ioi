#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_unordered_set>

using namespace std;

int main() {
    FILE *in = fopen("planting.in", "r");
    FILE *out = fopen("planting.out", "w");

    int N;
    fscanf(in, "%d", &N);

    vector<int> adj[N];
    for (int i = 0; i < N-1; i++) {
        int x, y;
        fscanf(in, "%d%d", &x, &y);
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    int count[N];
    for (int i = 0; i < N; i++) {
        count[i] = adj[i].size();
    }

    unordered_unordered_set<int> vec[N];
    for (int i = 0; i < N; i++) {  
        for (int j = 0; j < adj[i].size(); j++) {
            vec[i].insert(adj[i][j]);
            for (int k = 0; k < adj[j].size(); k++) {
                vec[i].insert(adj[j][k]);
            }
        }
    }

    vector<int> color(N, -1); int limit = 1;
    color[0] = limit;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (color[j] == -1) continue;
            auto is = vec[i].find(j);
            if (is == vec[i].end()) {
                bool found = false;
                for (auto k: vec[i]) {
                    if (k != j && color[k] == color[j]) {
                        found = true;
                        break;
                    }
                }
                if (found) continue;
                color[i] = color[j]; break;
            }
        }
        if (color[i] == -1) {
            color[i] = ++limit;
        }
    }

    fprintf(out, "%d\n", limit);

    return 0;
}