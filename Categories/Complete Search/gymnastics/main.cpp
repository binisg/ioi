#include <iostream>
#include <cstdio>
#include <vector>

#define REPS(i, a, x) for (int i = a; i <= x; i++)
#define REP(i, a, x) for (int i = a; i < x; i++)

using namespace std;

int main() {
    FILE *in = fopen("gymnastics.in", "r");
    FILE *out = fopen("gymnastics.out", "w");

    int K, N;
    fscanf(in, "%d%d", &K, &N);

    vector<vector<int>> ranks(K, vector<int>(N, 0));

    REP (i, 0, K) {
        vector<int> to_add (N);
        REP (j, 0, N) {
            fscanf(in, "%d", &to_add[j]);
        }
        ranks[i] = to_add;
    }

    int pairs = 0;

    REPS(i, 1, N) {
        REPS(j, i+1, N) {
            bool is_pair_1 = true;
            bool is_pair_2 = true;
            for (vector<int> vec: ranks) {
                for (int k: vec) {
                    if (!is_pair_1 && !is_pair_2) goto end;
                    if (k == i) {
                        is_pair_2 = false;
                        goto ranks_end;
                    }
                    if (k == j) {
                        is_pair_1 = false;
                        goto ranks_end;
                    }
                }
                ranks_end:
                continue;
            }
            if (is_pair_1 || is_pair_2) pairs++;
            end:
            continue;
        }
    }

    fprintf(out, "%d", pairs);

    fclose(in);
    fclose(out);

    return 0;
}