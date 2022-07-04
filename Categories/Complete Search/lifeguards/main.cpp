#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
#define REP(i, x, y) for (int i = x; i < y; i++)

int main() {
    FILE *in = fopen("lifeguards.in", "r");
    FILE *out = fopen("lifeguards.out", "w");

    int N;
    fscanf(in, "%d", &N);

    vector<pi> vec (N);

    for (int i = 0; i < N; i++) {
        fscanf(in, "%d%d", &vec[i].first, &vec[i].second);
    }

    sort(vec.begin(), vec.end());
    int max_num = 0;

    for (int j = 0; j < vec.size(); j++) {
        int result = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (i == j) continue;
            int x = vec[i].first, y = vec[i].second;
            int add = 1;
            if (i + 1 == j) add = 2;
            while (i < vec.size()-add && vec[i+add].first < y) {
                y = max(y, vec[i+1].second);
                i++;
                if (i == j) {
                    i++;
                    add = 1;
                }
                if (i + 1 == j) add = 2;
            }
            result += (y - x);
        }
        max_num = max(max_num, result);
    }

    fprintf(out, "%d\n", max_num);

    return 0;
}