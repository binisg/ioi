#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pi;

unordered_map<string, int> memo;

int main() {
    int N;
    scanf("%d", &N);

    cin.ignore();

    string s;
    getline(cin, s);

    int result = 0, start = 0, end = 1;

    for (int i = 1; i < s.size(); i += 2) {
        string str = "";
        int j;
        for (j = i; j < s.size(); j += 2) {
            if ((i == 1 && (s[j] != 'G' && s[j-1] != 'H')) || ((s[j-1] == 'H' && s[j] == 'H' && (str.size() != 0 || i == 1)) || (s[j-1] == 'G' && s[j] == 'G' && (str.size() != 0 || i == 1)) || (s[j] == 'H' && s[j-1] == 'G'))) {
                str.push_back(s[j-1]);
                str.push_back(s[j]);
            } else {
                break;
            }
        }
        if (str != "") {
            bool add = false;
            for (int o = 1; o < str.size(); o += 2) {
                if ((str[o] == 'H' && str[o-1] == 'G') || (str[o] == 'G' && str[o-1] == 'H')) {
                    add = true;
                    break;
                }
            }
            if (add) {
                if (i == 1) result++;
                else result += 2;
            }
        }
        i = j;
    }    

    printf("%d", result);

    return 0;
}