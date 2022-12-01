#include <iostream>
#include <vector>

using namespace std;

int can (vector<int> &vec, int &num) {
    int a, b = vec[0];
    for (int i = 0; i < vec.size()-1; i++) {
        a = b, b = vec[i+1];
        while (a != num && b != num) {
            a--;
            b--;
        }
        if (a != num) return -1;
    }

    if (b != num) return -1;

    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += (vec[i] - num);
    }

    return sum;
}

int solve() {
    int N; cin >> N;
    int min_i = 1e9;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        min_i = min(min_i, vec[i]);
    }

    int start = -1, end = min_i, mid, result;
    while (start < end) {
        mid = (start+end)/2;
        int curr_result = can(vec, mid);
        if (curr_result != -1) {
            result = min(result, curr_result);
            start = mid;
        } else {
            end = mid-1;
        }
    }

    if (start == -1) return -1;
    return result;
}

int main() {
    freopen("test.txt", "r", stdin);

    int T; cin >> T;

    while (T--) {
        int a = solve();
        cout << solve() << '\n';
    }

    return 0;
}