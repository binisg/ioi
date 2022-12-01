// // correct_idea_not_so_good_implementation_try_again

// #include <iostream>
// #include <map>
// #include <vector>

// using namespace std;

// typedef pair<int, int> pi;;
// #define x first 
// #define y second

// vector<pi> calc(map<int, int> m, int first, int s) {
//     cout << 0;
//     vector<pi> r; 
//     while (r.size() != s) {
//         for (auto i = m.rbegin(); i != m.rend(); i++) {
//             if (i->x < first/2) {
//                 return {{-1, -1}};
//             }
//             if (m[i->x] == 0) continue;
//             if ((first - i->x == i->x && i->y > 1) || (first - i->x != i->x && m.count(first-i->x) && m[first-i->x] > 0)) {
//                 r.push_back({first - i->x, i->x});
//                 m[i->x]--; m[first-i->x]--;
//                 first = max(r[r.size()-1].x, r[r.size()-1].y);
//                 break;
//             }
//             if (next(i) == m.rend()) {
//                 return {{-1, -1}};
//             }
//         }
//     }
//     return r;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     vector<vector<pi>> result(t);

//     for (int o = 0; o < t; o++) {
//         int n; cin >> n;
//         map<int, int> m;
//         for (int i = 0; i < n*2; i++) {
//             int x; cin >> x;
//             m[x]++;
//         }
//         vector<pi> vec(n);
//         vec[0] = {m.rbegin()->x, -1};
//         m[vec[0].x]--;
//         for (auto i = m.rbegin(); i != m.rend(); i++) {
//             if (m[i->x] == 0) continue;
//             vec[0].y = i->first;
//             m[vec[0].y]--;
//             vector<pi> can = calc(m, vec[0].x, n-1);
//             if (can[0].x != -1) {
//                 for (int i = 0; i < can.size(); i++) {
//                     vec[i+1] = can[i];
//                 }
//                 goto yes;
//             }
//             m[vec[0].y]++;
//         }

//         no:
//         cout << "NO\n";
//         continue;
//         yes:
//         cout << "YES\n";
//         cout << vec[0].x + vec[0].y << '\n';
//         for (int i = 0; i < vec.size(); i++) {
//             cout << min(vec[i].x, vec[i].y) << ' ' << max(vec[i].x, vec[i].y) << '\n';
//         }
//     }

//     return 0;
// }