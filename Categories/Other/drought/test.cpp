#include <iostream>
#include <vector>

using namespace std;

int can (vector<int> &vec, int num) {
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

int main() {
    vector<int> vec = {8, 10, 5};

    // int start = -1, end = 5, mid, result = 1e9;
    // while (start < end) {
    //     mid = (start + end)/2;
    //     int res = can(vec, mid);
    //     if (res != -1) {
    //         result = min(result, res);
    //         start = mid;
    //     } else {
    //         end = mid-1;
    //     }
    // }

    cout << can(vec, 2) << '\n';

    return 0;
}