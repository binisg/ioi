#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    int result = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i-1] != arr[i]) result++;
    }
    printf("%d", result);
    return 0;
}