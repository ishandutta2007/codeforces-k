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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int get_ans(string s, int c)
{
    int del = 0;
    int i = 0;
    int j = s.size() - 1;
    while(i < j)
    {
        if (s[i] == s[j])
        {
            ++i;
            --j;
            continue;
        }
        if (s[i] != c && s[j] != c)
            {
                //cout << i << " " << j << " " << (char)c << endl;
                return -1;
            }
        if (s[i] == c)
        {
            del++;
            i++;
            continue;
        }
        if (s[j] == c)
        {
            del++;
            j--;
            continue;
        }
    }
    return del;
}


int solve()
{
    cin >> n;

    string s;

    cin >> s;


    int vl = -1;
    for (int i = 'a'; i <= 'z'; ++i)
    {
        int curvl = get_ans(s, i);
        if ((curvl <= vl && curvl != -1) || vl == -1)
            vl = curvl;
    }

    cout << vl << endl;

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