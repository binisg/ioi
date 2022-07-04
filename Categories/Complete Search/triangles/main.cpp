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
    int result = 0;

    vector<vector<int>> n_x(N, vector<int>{});
    vector<vector<int>> n_y(N, vector<int>{});

    for (int i = 0; i < N; i++) {
        int x = vec[i].first;
        int y = vec[i].second;
        vector<int> xs;
        vector<int> ys;
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            if (vec[j].second == vec[i].second) xs.push_back(vec[j].first);
            if (vec[j].first == vec[i].first) ys.push_back(vec[j].second);
        }
        n_x[i] = xs;
        n_y[i] = ys;
    }

    for(vector<int> v: n_x) {
        cout << "[ ";
        for (int i: v) cout << i << " ";
        cout << "]\n";
    }

    cout << endl;

    for(vector<int> v: n_y) {
        cout << "[ ";
        for (int i: v) cout << i << " ";
        cout << "]\n";
    }


        // for (int j = i+1; j < N-1; j++) {
    //         if (vec[j].first != vec[i].first) break;
    //         int one = vec[j].second - vec[i].second;
    //         int two = 0;
    //         for (int k = j+1; k < N; k++) {
    //             if (vec[k].second == vec[j].second) {
    //                 two = max(two, vec[k].first - vec[k].first);
    //             }
    //         }
    //         result = max(result, one*two);
    //     }
    // }

    // cout << result << endl;

    return 0;
}