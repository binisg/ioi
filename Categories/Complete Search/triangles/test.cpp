#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

int main() {
    FILE *in = fopen("triangles.in", "r");
    FILE *out = fopen("triangles.out", "w");

    int N;
    fscanf(in, "%d", &N);

    vector<pi> vec(N);

    for (int i = 0; i < N; i++) {
        fscanf(in, "%d%d", &vec[i].first, &vec[i].second);
    }

    sort(vec.begin(), vec.end());

    vector<int> max_x(N);
    vector<int> max_y(N);
    
    for (int i = 0; i < N; i++) {
        int xest = 0, yest = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (vec[i].first == vec[j].first) xest = max(xest, max(vec[i].second, vec[j].second) - min(vec[i].second, vec[j].second));
            if (vec[i].second == vec[j].second) yest = max(yest, max(vec[i].first, vec[j].first) - min(vec[i].first, vec[j].first));
        }
        max_x[i] = xest;
        max_y[i] = yest;
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        // x triangle
        int max_num = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (vec[j].second == vec[i].second) max_num = max(max_num, (max(vec[i].first, vec[j].first) - min(vec[i].first, vec[j].first)) * max_x[j]);
        }
        // y triangle
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (vec[j].first == vec[i].first) max_num = max(max_num, (max(vec[i].second, vec[j].second) - min(vec[i].second, vec[j].second)) * max_y[j]);
        }
        // result
        result = max(result, max_num);
    }

    fprintf(out, "%d\n", result);

    fclose(in);
    fclose(out);

    return 0;
}