//
//  main.cpp
//  find ball
//
//  Created by Sokol Kostya's MacBook on 13.05.11.
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
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int a[4], aa, bb;

int main (int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    a[n] = 1;
    for (int i = 0; i < 3; i++)
    {
        cin >> aa >> bb;
        swap( a[aa], a[bb] );
    }
    for (int i = 0; i < 4; i++) if (a[i] == 1) cout << i;
    return 0;
}