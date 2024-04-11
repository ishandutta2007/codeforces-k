//
//  main.cpp
//  epic game
//
//  Created by Sokol Kostya's MacBook on 15.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int nod(int a, int b)
{
    if (a != 0) return nod(b % a, a); else return b;
}

double sqr(double x)
{
    return x * x;
}

int a[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 774, 777, 747};

int main (int argc, const char * argv[])
{
    int n, k;
    double res = 0, x1, x2, y1, y2;
    cin >> n >> k >> x1 >> y1;
    for (int i = 1; i < n; i++)
    {
        cin >> x2 >> y2;
        res += sqrt(sqr(x1 - x2) + sqr(y1 - y2));
        y1 = y2;
        x1 = x2;
    }
    res = 1.0 * res * k / 50;
    cout << fixed << setprecision(7) << res;
    return 0;
}