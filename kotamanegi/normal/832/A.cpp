#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include<fstream>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define f(n) for(int i=0;i<n;++i)
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	long long n, k;
	cin >> n >> k;
	if ((n / k) % 2 == 1) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}