// solution seen not applied
// ((() )) and (() ())

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N -1e9

int solve(vector<int> &vec, int index, int sum) {
    if (index == 4) {
        if (sum <= 24) return sum;
        else return MAX_N;
    }

    int result = MAX_N;

    int a, b, c, d1;
    double d2;

    a = sum + vec[index];
    int val = solve(vec, index+1, a);
    if (val == 24) cout << "+ " << vec[index] << " " << index << '\n';
    result = max(result, val);

    b = sum - vec[index];
    val = solve(vec, index+1, b);
    if (val == 24) cout << "- " << vec[index] << " " << index << '\n';
    result = max(result, val);

    if (index != 0) {
        c = sum * vec[index];
        val = solve(vec, index+1, c);
        if (val == 24) cout << "* " << vec[index] << " " << index << '\n';
        result = max(result, val);
    }

    if (index != 0 && vec[index] != 0) {
        d1 = sum / vec[index];
        d2 = (double)sum / (double)vec[index];
        if ((double)d1 == d2) {
            val = solve(vec, index+1, d1);
            if (val == 24) cout << "/ " << vec[index] << " " << index << '\n';
            result = max(result, val);
        }
    }

    return result;
}

void testcase() {
    vector<int> vec(4);
    cin >> vec[0] >> vec[1] >> vec[2] >> vec[3];

    int res = MAX_N;

    do {
        int r = solve(vec, 0, 0);
        if (r <= 24) res = max(res, r);
    } while (next_permutation(vec.begin(), vec.end()));

    if (res != MAX_N) cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    while (N--) {
        testcase();
    }

    return 0;
}