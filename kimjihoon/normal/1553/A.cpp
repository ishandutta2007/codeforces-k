#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		cout << (n + 1) / 10 << '\n';
	}
	return 0;
}