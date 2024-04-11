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

int delta (int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);

    int res = 0;
    for (int i = 0; i < sa.size(); i++)
        if (sa[i] != sb[i])
            res++;

    return res;
}

int main () {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &n);

        int best = 0;
        int wykl = to_string(n).size();
        for (int i = pow(10, wykl-1); i < pow(10, wykl); i++) {
            if (i % 7 == 0 and delta(n, i) < delta(n, best)) {
                best = i;
            }
        }

        printf("%d\n", best);


    
    }
    return 0;
}