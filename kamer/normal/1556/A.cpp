#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 2 == 1) {
            cout << "-1\n";
        } else if (a == b) {
            if (a == 0) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        } else {
            cout << "2\n";
        }
    }
}