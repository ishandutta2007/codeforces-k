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
#define log(x) //cout << "logging: value of '" << #x << "' = " << x << "." << endl


string s;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    int q;
    cin >> n >> m >> q;

    cin >> s;

    vector<pll> cp(m);
    vector<ll> ends(m+1, 0);

    ends[0] = s.size();

    for (int i = 0; i < m; ++i)
    {
        cin >> cp[i].ft >> cp[i].sd;
        cp[i].ft--;
        cp[i].sd;

        ends[i+1] = ends[i] + cp[i].sd - cp[i].ft;
    }

    for (int i = 0; i < q; ++i)
    {
        ll val;
        cin >> val;
        --val;
        log(val);

        for (int i = m; i >= 0; --i)
        {
            log(i);
            log(val);
            if (val < s.size())
            {
                cout << s[val] << endl;
                break;
            }

            if (val < ends[i] && val >= ends[i-1])
            {log(val);
                val -= ends[i-1];
                val += cp[i-1].ft;
                log(ends[i]);
                log(ends[i-1]);
                log(cp[i-1].ft);
                log(val);
            }
        }
    }






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