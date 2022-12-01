#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int N; cin >> N;

    vector<int> start(N);
    for (int i = 0; i < N; i++) {
        cin >> start[i];
    } 

    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        pos[start[i]-1] = i;
    }

    vector<ll> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<ll> res(N);
    for (int i = 0; i < N; i++) {
        int loc = i;
        for (int j = 0; j < 3; j++) {
            loc = pos[loc];
        }
        res[loc] = nums[i];
    }

    for (int i = 0; i < N; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}