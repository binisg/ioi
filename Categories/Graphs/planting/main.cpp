#include <iostream>
#include <cstdio>
#include <vector>

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

    int max_sum = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        sum += count[i];
        for (int j = 0; j < adj[i].size(); j++) {
            sum += (count[adj[i][j]] - 1);
        }
        max_sum = max(max_sum, sum);
    }

    max_sum++;

    fprintf(out, "%d\n", max_sum);

    return 0;
}