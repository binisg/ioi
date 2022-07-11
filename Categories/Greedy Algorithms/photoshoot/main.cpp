#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pi;

unordered_map<string, int> memo;

int counter = 0;

int profit (string &s, int &c_1, int &c_2) {
    counter++;
    if (s[s.size()-1] == 'G') c_1++;
    reverse(s.begin(), s.end());
    if (s[s.size()-2] == 'G') c_2++;
    reverse(s.begin(), s.end());
    return c_2 - c_1;
}

pi changes(string &s) {
    int max_profit = 0;
    pi max_limits = {-1, -1};

    for (int i = 0; i < s.size()-1; i += 2) {
        string str = "";
        int c_1 = 0, c_2 = 0;
        for (int j = i; j < s.size()-1; j += 2) {
            str.push_back(s[j]);
            str.push_back(s[j+1]);
            cout << str << endl;
            int curr_profit;
            if (memo.count(str)) {
                curr_profit = memo[str];
            } else {
                curr_profit = profit(str, c_1, c_2);
                memo[str] = curr_profit;
            }
            if (curr_profit <= 0 && i != 0) break;
            if (max_profit < curr_profit) {
                max_profit = curr_profit;
                max_limits = {i, j+2};
            }
        }
    }

    return max_limits;
}

int main() {
    int N;
    scanf("%d", &N);

    cin.ignore();

    string s;
    getline(cin, s);

    int result = 0;

    pair<int, int> p = changes(s);
    while (p.first != -1 && p.second != -1) {
        cout << counter << endl;
        if (p.first == 0) {
            result++;
            reverse(s.begin(), s.begin()+p.second);
        }
        else {
            result += 2;
            reverse(s.begin(), s.begin()+p.first);
            reverse(s.begin(), s.begin()+p.second);
        }
        p = changes(s);
        cout << s << endl;
    }

    printf("%d", result);

    return 0;
}