// ?.?fg?jdK>hd<8?tgs|]7^ri+a

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

#define all(X) (X).begin(), (X).end()
#define reset(X) memset(X, 0, sizeof(X))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define fi first
#define se second

using namespace __gnu_pbds;
using namespace std;
// const int mod = 1e9+7;
// const int mod3 = 1e6 + 3;
const int mod=998'244'353;
//const int mod=1e9+9;

// const int MOD = mod;

const int INF=2e18+10;
// const int INF = 4e8 + 10;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define read(n) \
int n;      \
cin >> n;
#define readv(x, n)   \
vector<int> x(n); \
for (auto &i : x) \
    cin >> i;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

template <typename T1, typename T2>
void set_min(T1 &a, T2 b){
    a = min(a, (T1)b);
}
/* template <typename T1, typename T2> */
bool sort_by_sec(pair<int, int> a, pair<int,int> b)
{
    return make_pair(a.se, a.fi)<make_pair(b.se,b.fi);
}

template<typename T>
vector<int> coordinate_compress(vector<T > a)
{
    set<T> s;
    for(T elem:a)
        s.insert(elem);

    vector<T> temp;
    for(T elem:s)
        temp.push_back(elem);
    map<T, int> counter;
    for(int i=0;i<temp.size();i++)
        counter[temp[i]] = i;
    vector<int> to_return;
    for(T elem:a)
        to_return.push_back(counter[elem]);
    return to_return;

}

int multiply(int a, int b, int in_mod) { return (int)(1LL*a * b % in_mod );}
int mult_identity(int a) { return 1; }


vector<int >multiply(const vector<int>& a, const vector<int>& b,int mod);
vector<int> mult_identity(vector<int> a)
{
    return {1};
}




int power(int a, int b, int in_mod)
{

    int prod = mult_identity(a);
    int mult = a % in_mod;
    b%=(mod-1);
    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
        mult = multiply(mult, mult, in_mod);
        b /= 2;
    }
    return prod;
}
int mod_inv(int q, int in_mod)
{

    return power(q, in_mod - 2, in_mod);
}

// Finds the primitive root modulo p
int generator(int p) {
    vector<int> fact;
    int phi = p-1, n = phi;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        fact.push_back(n);

    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (int factor : fact) {
            if (power(res, phi / factor, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}

// const int root = generator(mod);
// const int root_1 = mod_inv(root, mod);
// const int root_pw = 1<<20;

// const int mod = 998244353;
const int root  = 15311432;
const int root_pw = 1<<23;
// const int root_1 = mod_inv(root, mod);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;


    int mx = 0;

    mx = max({mx, 
              min(a,b)*min(c,d),
              min(a,c)*min(b,d),
              min(a,d)*min(b,c),
             });
    cout<<mx<<endl;
}





signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);
#ifndef ONLINE_JUDGE
    if (fopen("INPUT.txt", "r"))
    {
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    }
#endif
    auto clk = clock();
    // -------------------------------------Code starts here---------------------------------------------------------------------

    int t = 1;
    cin >> t;
// 
    for (int test = 1; test <= t; test++)
    {
        // cout<<"Case #"<<test<<": ";

        solve();
        //cout<<endl;
    }

    // -------------------------------------Code ends here------------------------------------------------------------------

    clk = clock() - clk;
    cerr << fixed << setprecision(6) << "Time: " << ((long double)clk) / CLOCKS_PER_SEC << "\n";
    return 0;
}