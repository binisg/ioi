#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N = 10;
    int arr[10] = {9, 5, 4, 3, 2, 10, 1, 6, 7, 8};
    vector<int> vec = {8, 3, 5, 1, 10, 2, 9, 4, 6, 7};
    cout << "[ ";
    for (int i{}; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "] => ";
    sort(arr, arr+N);
    cout << "[ ";
    for (int i{}; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
    cout << "[ ";
    for (int i: vec) {
        cout << i << " ";
    }
    cout << "] => ";
    sort(vec.begin(), vec.end());
    cout << "[ ";
    for (int i: vec) {
        cout << i << " ";
    }
    cout << "]\n";
    return 0;
}