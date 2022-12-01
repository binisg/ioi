#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second 

int N, D, M; vector<pi> vec;

bool f(int &x) {
    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < x; j++) {
            if (vec[index].x > (i+1)) break;
            if ((i+1) - vec[index].x > D) return false;
            index++;
            if (index >= M) goto endofloop;
        }
    }

    endofloop:
    return index >= M;
}

void res(int &x) {
    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < x; j++) {
            if (index < M) {
                cout << vec[index].y << ' ';
                index++; 
            }
        }
        cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> D >> M;
    vec.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> vec[i].x;
        vec[i].y = i+1;
    }

    sort(vec.begin(), vec.end());

    int l = 1, r = M, mid; 
    while (l < r) {
        mid = (l+r)/2;
        if (!f(mid)) l = mid+1;
        else {
            r = mid;
        }
    }

    cout << l << '\n';
    res(l);
    // for (int i = 0; i < result.size(); i++) {
    //     for (int j = 0; j < result[i].size(); j++) {
    //         if (result[i][0] == 0) break;
    //         cout << result[i][j] << ' ';
    //     }
    //     cout << 0 << '\n';
    // }

    return 0;
}