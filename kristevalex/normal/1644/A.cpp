#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    string s;
    cin >> s;
        bool r = false;
        bool g = false;
        bool b = false;
    for (int i = 0; i < s.size(); ++i)
    {

        if (s[i] == 'r')
            r  = true;
        if (s[i] == 'g')
            g  = true;
        if (s[i] == 'b')
            b  = true;

        if (s[i] == 'R' && !r)
        {
            cno;
            return 0;
        }
        if (s[i] == 'G' && !g)
        {
            cno;
            return 0;
        }
        if (s[i] == 'B' && !b)
        {
            cno;
            return 0;
        }
    }




    cyes;

    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}