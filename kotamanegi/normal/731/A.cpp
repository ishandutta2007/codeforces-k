#define _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	string s;
	cin >> s;
	int ans = 0;
	int now = 'a';
	for (int i = 0;i < s.length();++i) {
		ans += min(abs((int)s[i] - now), 26 - abs(s[i]-now));
		now = (int)s[i];
	}
	cout << ans << endl;
	return 0;
}