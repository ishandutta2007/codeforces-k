#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    printf("YES\n");
    while(n--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",(abs(a%2)*2+abs(b%2))+1);
    }
}