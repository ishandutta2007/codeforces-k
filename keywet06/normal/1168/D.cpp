#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 223456;

char t[N], s[30];

int n, q, dep, idx, cnts;
int id[N], idpar[N], par[N], depc[N], sumd[N], invalid[N];
int dp[N][30], cnt[N][30];

vector<int> son[N], scomp[N];

void dfs(int u, int d) {
    if (son[u].empty()) {
        if (dep == -1) dep = d;
        if (d != dep) {
            for (int i = 0; i < q; ++i) printf("Fou\n");
            exit(0);
        }
    }
    depc[id[u]] = max(depc[id[u]], d);
    for (auto v : son[u]) {
        if (u == 1 || (int)son[u].size() >= 2) {
            id[v] = ++idx;
            idpar[idx] = id[u];
            scomp[id[u]].push_back(idx);
        } else {
            id[v] = id[u];
        }
        dfs(v, d + 1);
    }
}

void modify(int u, int c, int delta) {
    if (c < 0) return;
    u = id[u];
    cnt[u][c] += delta;
    while (true) {
        sumd[u] -= dp[u][c];
        cnts -= invalid[u];
        dp[u][c] = 0;
        for (auto v : scomp[u]) {
            dp[u][c] = max(dp[u][c], dp[v][c] + cnt[v][c]);
        }
        sumd[u] += dp[u][c];
        invalid[u] = sumd[u] > dep - depc[u];
        cnts += invalid[u];
        if (u == 0) break;
        u = idpar[u];
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; ++i) {
        scanf("%d %s", &par[i], s);
        t[i] = s[0];
        son[par[i]].push_back(i);
    }
    dep = -1;
    dfs(1, 0);
    for (int i = 2; i <= n; ++i) modify(i, t[i] - 'a', 1);
    for (int i = 0; i < q; ++i) {
        int u;
        scanf("%d %s", &u, s);
        modify(u, t[u] - 'a', -1);
        t[u] = s[0];
        modify(u, t[u] - 'a', 1);
        if (cnts) {
            printf("Fou\n");
            continue;
        }
        int64 ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += (i + 1) * (dep - (sumd[0] - dp[0][i]));
        }
        printf("Shi %lld\n", ans);
    }
    return 0;
}