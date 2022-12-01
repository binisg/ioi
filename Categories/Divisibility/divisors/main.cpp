#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define s 1e6

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    vector<int> multiples(s+1, 0);

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        int rt = sqrt(num);
        for (int j = 1; j <= rt; j++) {
            if (num % j == 0) {
                multiples[j]++;
                if (num / j != j) {
                    multiples[num/j]++;
                }
            }
        }
    }

    for (int i = s; i >= 1; i--) {
        if (multiples[i] > 1) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}