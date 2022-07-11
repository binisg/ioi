#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    int val;
    vector<int> schools;
    int index;
};

int val_sort(student &a, student &b) {
    if (a.val > b.val) return 1;
    return 0;
}

int main() {
    FILE *in = fopen("erasmus.in", "r");
    FILE *out = fopen("erasmus.out", "w");

    int N, M;
    fscanf(in, "%d%d", &N, &M);

    int pos[N];
    for (int i = 0; i < N; i++) {
        fscanf(in, "%d", &pos[i]);
    }

    vector<student> vec(M);
    for (int i = 0; i < M; i++) {
        int el, x;
        fscanf(in, "%d%d", &vec[i].val, &el);
        while (el--) {
            fscanf(in, "%d", &x);
            vec[i].schools.push_back(x);
        }
        vec[i].index = i;
    }

    sort(vec.begin(), vec.end(), val_sort);
    vector<int> result(M, 0);

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].schools.size(); j++) {
            if (pos[vec[i].schools[j]-1] != 0) {
                pos[vec[i].schools[j]-1]--;
                result[vec[i].index] = vec[i].schools[j];
                break;
            }
        }
    }

    char alt[4] = {'N', 'O', 'N', 'E'};

    for (int i = 0; i < M; i++) {
        if (result[i] > 0) fprintf(out, "%d\n", result[i]);
        else {
            for (int j = 0; j < 4; j++) fprintf(out, "%c", alt[j]);
            fprintf(out, "\n");
        }
    }

    return 0;
}