#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 100000005

int main() {
    int N;
    scanf("%d", &N);
    N *= 2;
    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+N);

    int min_result = MAX_N;

    for (int a = 0; a < N; a++) {
        for (int b = a+1; b < N; b++) {
            int result = 0;
            vector<int> del;
            for (int i = 0; i < N; i++) {
                if (i != a && i != b) del.push_back(arr[i]);
            }
            for (int i = 1; i < N-2; i += 2) {
                result += del[i] - del[i-1];
            }
            min_result = min(min_result, result);
        }
    }

    printf("%d", min_result);

    return 0;
}