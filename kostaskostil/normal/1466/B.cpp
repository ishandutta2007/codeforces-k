#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 2e5 + 100;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _ = 0; _ < ___; _++)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i:v)
            cin>>i;
        for (int i=1; i<n; i++)
            if (v[i] <= v[i-1])
                v[i]++;

        set<int> s(v.begin(), v.end());
        cout<<s.size()<<"\n";
    }
}