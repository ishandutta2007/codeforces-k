#include <bits/stdc++.h>
using namespace std;

int T;
int x, y;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &x, &y);
		printf("%d %d\n", x - 1, y);
	}
    return 0;
}