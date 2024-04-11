#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 0;

int n;

int main () {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &n);

        vector<int> t;
        t.resize(n);
        // for (auto &it : t) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
        }
        sort(t.begin(), t.end());

        printf("%d\n", t[n-1] + t[n-2]);
    }
    return 0;
}