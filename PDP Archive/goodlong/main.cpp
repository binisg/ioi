#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("goodlong.in");
    ofstream out("goodlong.out");

    int N, K;
    in >> N >> K;

    int arr[N];
    for (int i = 0; i < N; i++) in >> arr[i];

    int max_sum = 0, curr_sum = 0, start = 0, result = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > curr_sum + arr[i]) {
            start = i;
            curr_sum = arr[i];
        } else {
            curr_sum += arr[i];
        }
        if (curr_sum >= K * (i-start+1)) {
            result = max(result, i-start+1);
        }
        max_sum = max(max_sum, curr_sum);
    }

    out << result << "\n";

    return 0;
}