#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int main() {
    FILE *in = fopen("stacking.in", "r");
    FILE *out = fopen("stacking.out", "w");

    int N, K;
    fscanf(in, "%d%d", &N, &K);

    vector<int> *arr = new vector<int>[N];

    while (K--) {
        int x, y;
        fscanf(in, "%d%d", &x, &y);
        arr[x-1].push_back(y-1);
    }

    int* val = new int[N];
    
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < arr[i].size(); j++) pq.push(-arr[i][j]);
        val[i] = pq.size();
        while (!pq.empty() && pq.top() * (-1) == i) pq.pop();
    }

    sort(val, val+N);
    int result = val[N/2];
    fprintf(out, "%d\n", result);

    return 0;
}