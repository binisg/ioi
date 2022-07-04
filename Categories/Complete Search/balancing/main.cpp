#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 10000005
typedef pair<int, int> pi;

int my_sort(pi &p1, pi &p2) {
    if (p1.second > p2.second) return 0;
    else if (p1.second == p2.second) {
        if (p1.first > p2.first) return 0;
        return 1;
    }
    return 1;
}

int main() {
    FILE *in = fopen("balancing.in", "r");
    FILE *out = fopen("balancing.out", "w");

    int N, B;
    fscanf(in, "%d%d", &N, &B);

    vector<pi> vp;

    for (int i = 0; i < N; i++) {
        pi p;
        fscanf(in, "%d%d", &p.first, &p.second);
        vp.push_back(p);
    }

    sort(vp.begin(), vp.end());

    int min_num = MAX_N;

    for (int i = 0; i < vp.size(); i++) {
        if (vp[i].first > B) break;
        if (i < vp.size()-1 && vp[i+1].first == vp[i].first) continue;
        int div_y = vp[i].first+1;
        vector<pi> copy = vp;
        sort(copy.begin(), copy.end(), my_sort);
        for (int j = 0; j < copy.size(); j++) {
            if (copy[j].second > B) goto end;
            if (j < copy.size()-1 && copy[j+1].second == copy[j].second) continue;
            int div_x = copy[j].second+1;
            int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
            for (int k = 0; k < vp.size(); k++) {
                if (vp[k].first > div_y) {
                    if (vp[k].second > div_x) r2++;
                    else r1++;
                } else {
                    if (vp[k].second > div_x) r4++;
                    else r3++;
                }
            }
            int result = max(max(r1, r2), max(r3, r4));
            if (result < min_num) min_num = result;
            else if (result > min_num && j < 0) goto end;
        }
        end:
        continue;
    }

    fprintf(out, "%d\n", min_num);

    return 0;
}