#include <bits/stdc++.h>
using namespace std;

int a[33554432];

int main(){
a[3] = 1;
a[7] = 1;
a[15] = 5;
a[31] = 1;
a[63] = 21;
a[127] = 1;
a[255] = 85;
a[511] = 73;
a[1023] = 341;
a[2047] = 89;
a[4095] = 1365;
a[8191] = 1;
a[16383] = 5461;
a[32767] = 4681;
a[65535] = 21845;
a[131071] = 1;
a[262143] = 87381;
a[524287] = 1;
a[1048575] = 349525;
a[2097151] = 299593;
a[4194303] = 1398101;
a[8388607] = 178481;
a[16777215] = 5592405;
a[33554431] = 1082401;
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int x;
        scanf("%d", &x);
        if(a[x]) printf("%d\n", a[x]);
        else{
            int t = 3;
            while(t <= x) t = 2 * t + 1;
            printf("%d\n", t);
        }
    }
}