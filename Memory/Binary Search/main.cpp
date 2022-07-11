#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("binary_search.in");

    int N, x;
    in >> N >> x;

    int arr[N];
    for (int i = 0; i < N; i++) {
        in >> arr[i];
    }

    sort(arr, arr+N);

    int start = 0, end = N-1, k;
    while (start <= end) {
        k = (start+end)/2;
        if (arr[k] == x) break;
        else if (arr[k] > x) end = k-1;
        else start = k+1;
    }

    if (k < N && arr[k] == x) cout << "Found\n";
    else cout << "Not found\n";

    return 0;
}