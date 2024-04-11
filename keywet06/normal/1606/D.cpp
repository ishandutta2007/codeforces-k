#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

const int N = 1000069;

int64 n, m, a[N], pn[2][2][N];
int64 t, rr, i, j, ii, jj, u, u2, u3, k, p, p2;

pair<int64, int64> as[N];

bitset<N> sq;

int main() {
    scanf("%lld", &t);
    for (rr = 0; rr < t; ++rr) {
        scanf("%lld%lld", &n, &m);
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= m; ++j) {
                p = (i - 1) * m + j;
                scanf("%lld", a + p);
            }
            as[i] = {a[(i - 1) * m + 1], i};
            sq[i] = 0;
        }
        sort(as + 1, as + n + 1);
        for (ii = 0; ii < 2; ++ii) {
            u = !ii * 2 - 1;
            for (jj = 0; jj < 2; ++jj) {
                u2 = !jj * 2 - 1;
                u3 = u * u2;
                for (i = 1 + (n - 1) * ii; i && i <= n; i += u) {
                    k = as[i].second;
                    for (j = 1 + (m - 1) * jj; j && j <= m; j += u2) {
                        p = (k - 1) * m + j;
                        p2 = (i - 1) * m + j;
                        pn[ii][jj][p2] = a[p];
                        if (i != 1 + (n - 1) * ii) {
                            pn[ii][jj][p2] = max(pn[ii][jj][p2] * u3,
                                                 pn[ii][jj][p2 - m * u] * u3) *
                                             u3;
                        }
                        if (j != 1 + (m - 1) * jj) {
                            pn[ii][jj][p2] = max(pn[ii][jj][p2] * u3,
                                                 pn[ii][jj][p2 - u2] * u3) *
                                             u3;
                        }
                    }
                }
            }
        }
        for (i = 1; i < n; ++i) {
            k = as[i].second;
            sq[k] = 1;
            for (j = 1; j < m; ++j) {
                p = (i - 1) * m + j;
                if (pn[0][0][p] < pn[1][0][p + m] &&
                    pn[0][1][p + 1] > pn[1][1][p + m + 1]) {
                    break;
                }
            }
            if (j < m) break;
        }
        if (i < n) {
            printf("YES\n");
            for (i = 1; i <= n; ++i) printf("%c", "RB"[sq[i]]);
            printf(" %lld\n", j);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}