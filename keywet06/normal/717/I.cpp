// oct code title CF/CF717G.cpp

#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT  // oct code insert pre-document
#define OCT_CODE_INSERT_PREx2dDOCUMENT

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#ifndef STL_BITS__2F_STDCx2Bx2Bx2FH
#define STL_BITS__2F_STDCx2Bx2Bx2FH
#include <bits/stdc++.h>
#endif

#define debug std::cerr << "Debug(" << __LINE__ << "): "
#define pub push_back
#define pob pop_back
#define pup push
#define mkp make_pair
#define fir first
#define sec second
#define ite iterator
#define lob lower_bound
#define upb upper_bound
#define reg register

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using ldb = long double;
using pi32 = std::pair<int32, int32>;
using pi64 = std::pair<int64, int64>;

namespace oct {

/* Array tn4 is the 4-direction changes in coordinate system.
 * The directions in order is {right, up, left, down}.
 */
const int tn4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int tn8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                       {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const double exp = 1e-8;

void sync(int pre = 8);
template <typename _Tp>
_Tp &mad(_Tp &x, _Tp y);
template <typename _Tp>
_Tp &mid(_Tp &x, _Tp y);
template <typename _Tp>
bool in(_Tp x, _Tp l, _Tp r);
template <typename _Tp>
bool in(_Tp x, _Tp y, _Tp l, _Tp r);
template <typename _Tp>
_Tp sqr(_Tp x);
template <typename _Tp>
_Tp power(_Tp x, int64 m);
template <typename _Tp>
void sort(_Tp &x, _Tp &y);
template <typename _Tp1, typename _Tp2>
std::pair<_Tp1, _Tp2> operator+(std::pair<_Tp1, _Tp2> x,
                                std::pair<_Tp1, _Tp2> y);
template <typename _Tp>
_Tp &operator+=(_Tp &x, _Tp y);
template <typename _Tp>
_Tp gcd(_Tp &x, _Tp &y);

inline void sync(int pre) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.flags(std::ios::fixed);
    std::cout.precision(pre);
    std::cout.setf(std::ios::showpoint);
}
template <typename _Tp>
inline _Tp &mad(_Tp &x, _Tp y) {
    return x = std::max(x, y);
}
template <typename _Tp>
inline _Tp &mid(_Tp &x, _Tp y) {
    return x = std::min(x, y);
}
template <typename _Tp>
inline bool in(_Tp x, _Tp l, _Tp r) {
    return l <= x && x <= r;
}
template <typename _Tp>
inline bool in(_Tp x, _Tp y, _Tp l, _Tp r) {
    return l <= x && y <= r;
}
template <typename _Tp>
inline _Tp sqr(_Tp x) {
    return x * x;
}
template <typename _Tp>
inline _Tp power(_Tp x, int64 m) {
    return m == 1 ? x : (m & 1 ? power(x * x, m / 2) * x : power(x * x, m / 2));
}
template <typename _Tp>
inline void sort(_Tp &x, _Tp &y) {
    if (x > y) std::swap(x, y);
}
template <typename _Tp1, typename _Tp2>
inline std::pair<_Tp1, _Tp2> operator+(std::pair<_Tp1, _Tp2> x,
                                       std::pair<_Tp1, _Tp2> y) {
    return x.fir += y.fir, x.sec += y.sec, x;
}
template <typename _Tp>
inline _Tp &operator+=(_Tp &x, _Tp y) {
    return x = x + y;
}
template <typename _Tp>
inline _Tp gcd(_Tp &x, _Tp &y) {
    return std::__gcd(x, y);
}

}  // namespace oct

#endif  // oct code end pre-document

const int B = 2;
const int N = 100005;

struct vec {
    int64 x, y, z;
};

inline vec operator-(const vec &a, const vec &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}
inline vec operator*(const vec &a, const vec &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x};
}
inline int64 operator^(const vec &a, const vec &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int s, t;
int n[B];
int o[N];
std::vector<std::pair<ldb, pi32> > v;
vec x;
vec p[B];
vec a[B][N];

inline int read() {
    static int x;
    std::cin >> x;
    return x;
}
inline int sgn(int64 x) { return x < 0 ? -1 : x ? 1 : 0; }

int main() {
    for (int t = 0; t < 2; ++t) {
        n[t] = read();
        for (int i = 0; i < n[t]; ++i) a[t][i] = {read(), read(), read()};
        a[t][n[t]] = a[t][0], p[t] = (a[t][1] - a[t][0]) * (a[t][2] - a[t][0]);
    }
    if (x = p[0] * p[1], !(x ^ x)) return std::cout << "NO" << std::endl, 0;
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i <= n[t]; ++i)
            o[i] = sgn((a[t][i] - a[t ^ 1][0]) ^ p[t ^ 1]);
        for (int i = 0; i < n[t]; ++i) {
            if (o[i] ^ o[i + 1]) {
                v.pub({(a[t][i] ^ x) +
                             ((a[t][i + 1] - a[t][i]) ^ x) *
                                 (ldb)(p[t ^ 1] ^ (a[t][i] - a[t ^ 1][0])) /
                                 (p[t ^ 1] ^ (a[t][i] - a[t][i + 1])),
                         {t, o[i] - o[i + 1]}});
            }
        }
    }
    std::sort(v.begin(), v.end());
    for (auto x : v) x.sec.fir ? s += t *x.sec.sec : t += x.sec.sec;
    return std::cout << (s ? "YES" : "NO") << std::endl, 0;
}