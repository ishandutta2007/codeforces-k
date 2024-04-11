#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LOG = 17;
const int QLEN = 102;
const int BASE = 31;

const int MY = 1e9 + 7;

struct Hash {
    int x, y;
    Hash(int x = 0, int64_t y = 0) {
        this->x = x;
        this->y = y % MY;
    }
    Hash(const string &s) {
        x = y = 0;
        for (char c : s) {
            append(c);
        }
    }
    void append(char c) {
        x = x * BASE + (c - 'a') + 1;
        y = (1LL * y * BASE + (c - 'a') + 1) % MY;
    }
    void mul() {
        x = x * BASE;
        y = 1LL * y * BASE % MY;
    }
};

struct HashHash {
    size_t operator()(const Hash &x) const { return (size_t)x.y; }
};

Hash operator*(const Hash &a, const Hash &b) { return Hash(a.x * b.x, 1LL * a.y * b.y); }

Hash operator-(const Hash &a, const Hash &b) { return Hash(a.x - b.x, a.y - b.y + MY); }

Hash power[QLEN];

void init_hash() {
    power[0] = Hash(1, 1);
    for (int i = 1; i < QLEN; ++i) {
        power[i] = power[i - 1];
        power[i].mul();
    }
}

bool operator==(const Hash &a, const Hash &b) { return a.x == b.x && a.y == b.y; }

bool operator<(const Hash &a, const Hash &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

struct Query {
    Hash value;
    int len;
    int index;
    int mul;
    Query(int index, int len, const Hash &value, int mul) {
        this->index = index;
        this->len = len;
        this->value = value;
        this->mul = mul;
    }
};

int n, q;
vector<pair<int, char> > a[N];
vector<Query> Q[N];

int par[N];
int sz[N];
int Top[N];
char par_edge[N];
int depth[N];
int tin[N];
int ans[N];

int timestamp;

void dfs_init(int u) {
    tin[u] = ++timestamp;
    if (u != 1) {
        for (int i = 0; i < a[u].size(); ++i) {
            if (a[u][i].first == par[u]) {
                a[u].erase(a[u].begin() + i);
                break;
            }
        }
    }
    sz[u] = 1;
    for (auto e : a[u]) {
        int v = e.first;
        par[v] = u;
        par_edge[v] = e.second;
        depth[v] = depth[u] + 1;
        dfs_init(v);
        sz[u] += sz[v];
    }
}

void Dfs2(int u) {
    int Maxs = 0;
    int HSon = 0;
    for (auto e : a[u]) {
        int v = e.first;
        if (sz[v] > Maxs) {
            Maxs = sz[v];
            HSon = v;
        }
    }
    for (auto e : a[u]) {
        int v = e.first;
        if (v == HSon) {
            Top[v] = Top[u];
        } else {
            Top[v] = v;
        }
        Dfs2(v);
    }
}

int get_lca(int u, int v) {
    while (Top[u] != Top[v]) {
        if (depth[Top[u]] < depth[Top[v]]) {
            v = par[Top[v]];
        } else {
            u = par[Top[u]];
        }
    }
    if (depth[u] < depth[v]) return u;
    return v;
}

void init_descendants() {
    auto cmp = [](const pair<int, char> &x, const pair<int, char> &y) { return tin[x.first] < tin[y.first]; };
    for (int u = 1; u <= n; ++u) {
        sort(a[u].begin(), a[u].end(), cmp);
    }
}

int get_descendant(int p, int u) {
    int l = 0, r = (int)a[p].size() - 1;
    int res = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (tin[a[p][mid].first] <= tin[u]) {
            res = a[p][mid].first;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int go_down(int from, int to, int step) {
    while (step > 0) {
        step -= 1;
        from = get_descendant(from, to);
    }
    return from;
}

string get_string_up(int u, int p) {
    string res;
    while (u != p) {
        res += par_edge[u];
        u = par[u];
    }
    return res;
}

int naive_count(const string &s, const string &t) {
    vector<Hash> H(s.size() + 1);
    for (int i = 0; i < s.size(); ++i) {
        H[i + 1] = H[i];
        H[i + 1].append(s[i]);
    }
    Hash target(t);
    int res = 0;
    for (int i = t.size(); i < H.size(); ++i) {
        res += (H[i] - H[i - t.size()] * power[t.size()]) == target;
    }
    return res;
}

unordered_set<Hash, HashHash> SAdd;

vector<Hash> H1;
unordered_map<Hash, int, HashHash> cnt[QLEN];

void update_cnt(int u, int v, int inc) {
    for (int i = 1; i < QLEN && i < H1.size(); ++i) {
        Hash new_hash = H1.back() - H1[H1.size() - i - 1] * power[i];
        if (SAdd.count(new_hash) && (cnt[i][new_hash] += inc) == 0) {
            cnt[i].erase(new_hash);
        }
    }
}

void dfs_solve(int u) {
    while (!Q[u].empty()) {
        Query query = Q[u].back();
        Q[u].pop_back();
        if (cnt[query.len].count(query.value)) {
            ans[query.index] += query.mul * cnt[query.len][query.value];
        }
    }
    for (auto e : a[u]) {
        int v = e.first;
        char c = e.second;
        H1.push_back(H1.back());
        H1.back().append(c);
        update_cnt(u, v, +1);
        dfs_solve(v);
        update_cnt(u, v, -1);
        H1.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_hash();
    SAdd.reserve(N);
    for (int i = 1; i < QLEN; ++i) cnt[i].reserve(4096);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        a[u].push_back({v, c});
        a[v].push_back({u, c});
    }
    dfs_init(1);
    Top[1] = 1;
    Dfs2(1);
    init_descendants();
    cin >> q;
    for (int it = 1; it <= q; ++it) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        int len = s.size();
        int p = get_lca(u, v);
        int pu = go_down(p, u, min(len - 1, depth[u] - depth[p]));
        int pv = go_down(p, v, min(len - 1, depth[v] - depth[p]));
        string mid = get_string_up(pv, p);
        reverse(mid.begin(), mid.end());
        mid = get_string_up(pu, p) + mid;
        ans[it] = naive_count(mid, s);
        if (depth[v] - depth[p] >= len) {
            Hash h_forward(s);
            Q[v].push_back(Query(it, s.size(), h_forward, +1));
            Q[pv].push_back(Query(it, s.size(), h_forward, -1));
            SAdd.insert(h_forward);
        }
        if (depth[u] - depth[p] >= len) {
            reverse(s.begin(), s.end());
            Hash h_backward(s);
            Q[u].push_back(Query(it, s.size(), h_backward, +1));
            Q[pu].push_back(Query(it, s.size(), h_backward, -1));
            SAdd.insert(h_backward);
        }
    }
    H1.push_back(Hash());
    dfs_solve(1);
    for (int i = 1; i <= q; ++i) cout << ans[i] << endl;
    return 0;
}