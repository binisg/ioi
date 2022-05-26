#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp_even_nums (int x, int y) {
    if (x % 2 == 0 && y % 2 != 0) return true;
    else if (x % 2 != 0 && y % 2 == 0) return false;
    else return x < y;
}

int main() {
    vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "[ ";
    for (int i: nums) cout << i << " ";
    cout << "] => ";

    sort(nums.begin(), nums.end(), comp_even_nums);

    cout << "[ ";
    for (int i: nums) cout << i << " ";
    cout << "]\n";
    return 0;
}