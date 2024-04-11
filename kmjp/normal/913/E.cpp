#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;

map<string,string> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	S["00000000"]="!x&x";
	S["10000000"]="!(x|y|z)";
	S["01000000"]="!x&!y&z";
	S["11000000"]="!x&!y";
	S["00100000"]="!x&!z&y";
	S["10100000"]="!x&!z";
	S["01100000"]="!(!y&!z|x|y&z)";
	S["11100000"]="!(x|y&z)";
	S["00010000"]="!x&y&z";
	S["10010000"]="!(!y&z|!z&y|x)";
	S["01010000"]="!x&z";
	S["11010000"]="!(!z&y|x)";
	S["00110000"]="!x&y";
	S["10110000"]="!(!y&z|x)";
	S["01110000"]="!x&(y|z)";
	S["11110000"]="!x";
	S["00001000"]="!y&!z&x";
	S["10001000"]="!y&!z";
	S["01001000"]="!(!x&!z|x&z|y)";
	S["11001000"]="!(x&z|y)";
	S["00101000"]="!(!x&!y|x&y|z)";
	S["10101000"]="!(x&y|z)";
	S["01101000"]="!(!x&!y|x&y|z)|!x&!y&z";
	S["11101000"]="!((x|y)&z|x&y)";
	S["00011000"]="!x&y&z|!y&!z&x";
	S["10011000"]="!x&y&z|!y&!z";
	S["01011000"]="!x&z|!y&!z&x";
	S["11011000"]="!x&z|!y&!z";
	S["00111000"]="!x&y|!y&!z&x";
	S["10111000"]="!x&y|!y&!z";
	S["01111000"]="!x&(y|z)|!y&!z&x";
	S["11111000"]="!x|!y&!z";
	S["00000100"]="!y&x&z";
	S["10000100"]="!(!x&z|!z&x|y)";
	S["01000100"]="!y&z";
	S["11000100"]="!(!z&x|y)";
	S["00100100"]="!x&!z&y|!y&x&z";
	S["10100100"]="!x&!z|!y&x&z";
	S["01100100"]="!x&!z&y|!y&z";
	S["11100100"]="!x&!z|!y&z";
	S["00010100"]="!x&y&z|!y&x&z";
	S["10010100"]="!(!x&z|!z&x|y)|!x&y&z";
	S["01010100"]="!(x&y)&z";
	S["11010100"]="!(!z&x|y)|!x&z";
	S["00110100"]="!x&y|!y&x&z";
	S["10110100"]="!(!y&z|x)|!y&x&z";
	S["01110100"]="!x&y|!y&z";
	S["11110100"]="!x|!y&z";
	S["00001100"]="!y&x";
	S["10001100"]="!(!x&z|y)";
	S["01001100"]="!y&(x|z)";
	S["11001100"]="!y";
	S["00101100"]="!x&!z&y|!y&x";
	S["10101100"]="!x&!z|!y&x";
	S["01101100"]="!x&!z&y|!y&(x|z)";
	S["11101100"]="!x&!z|!y";
	S["00011100"]="!x&y&z|!y&x";
	S["10011100"]="!(!x&z|y)|!x&y&z";
	S["01011100"]="!x&z|!y&x";
	S["11011100"]="!x&z|!y";
	S["00111100"]="!x&y|!y&x";
	S["10111100"]="!(!x&!y&z|x&y)";
	S["01111100"]="!x&(y|z)|!y&x";
	S["11111100"]="!x|!y";
	S["00000010"]="!z&x&y";
	S["10000010"]="!(!x&y|!y&x|z)";
	S["01000010"]="!x&!y&z|!z&x&y";
	S["11000010"]="!x&!y|!z&x&y";
	S["00100010"]="!z&y";
	S["10100010"]="!(!y&x|z)";
	S["01100010"]="!x&!y&z|!z&y";
	S["11100010"]="!x&!y|!z&y";
	S["00010010"]="!x&y&z|!z&x&y";
	S["10010010"]="!(!x&y|!y&x|z)|!x&y&z";
	S["01010010"]="!x&z|!z&x&y";
	S["11010010"]="!(!z&y|x)|!z&x&y";
	S["00110010"]="!(x&z)&y";
	S["10110010"]="!(!y&x|z)|!x&y";
	S["01110010"]="!x&z|!z&y";
	S["11110010"]="!x|!z&y";
	S["00001010"]="!z&x";
	S["10001010"]="!(!x&y|z)";
	S["01001010"]="!x&!y&z|!z&x";
	S["11001010"]="!x&!y|!z&x";
	S["00101010"]="!z&(x|y)";
	S["10101010"]="!z";
	S["01101010"]="!x&!y&z|!z&(x|y)";
	S["11101010"]="!x&!y|!z";
	S["00011010"]="!x&y&z|!z&x";
	S["10011010"]="!(!x&y|z)|!x&y&z";
	S["01011010"]="!x&z|!z&x";
	S["11011010"]="!(!x&!z&y|x&z)";
	S["00111010"]="!x&y|!z&x";
	S["10111010"]="!x&y|!z";
	S["01111010"]="!x&(y|z)|!z&x";
	S["11111010"]="!x|!z";
	S["00000110"]="!y&x&z|!z&x&y";
	S["10000110"]="!(!x&y|!y&x|z)|!y&x&z";
	S["01000110"]="!y&z|!z&x&y";
	S["11000110"]="!(!z&x|y)|!z&x&y";
	S["00100110"]="!y&x&z|!z&y";
	S["10100110"]="!(!y&x|z)|!y&x&z";
	S["01100110"]="!y&z|!z&y";
	S["11100110"]="!(!y&!z&x|y&z)";
	S["00010110"]="!x&y&z|!y&x&z|!z&x&y";
	S["10010110"]="!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
	S["01010110"]="!(x&y)&z|!z&x&y";
	S["11010110"]="!(!z&x|y)|!x&z|!z&x&y";
	S["00110110"]="!(x&z)&y|!y&x&z";
	S["10110110"]="!(!y&x|z)|!x&y|!y&x&z";
	S["01110110"]="!(x&y)&z|!z&y";
	S["11110110"]="!x|!y&z|!z&y";
	S["00001110"]="!(y&z)&x";
	S["10001110"]="!(!x&y|z)|!y&x";
	S["01001110"]="!y&z|!z&x";
	S["11001110"]="!y|!z&x";
	S["00101110"]="!y&x|!z&y";
	S["10101110"]="!y&x|!z";
	S["01101110"]="!y&(x|z)|!z&y";
	S["11101110"]="!y|!z";
	S["00011110"]="!(y&z)&x|!x&y&z";
	S["10011110"]="!(!x&y|z)|!x&y&z|!y&x";
	S["01011110"]="!(x&y)&z|!z&x";
	S["11011110"]="!x&z|!y|!z&x";
	S["00111110"]="!(x&z)&y|!y&x";
	S["10111110"]="!x&y|!y&x|!z";
	S["01111110"]="!x&y|!y&z|!z&x";
	S["11111110"]="!(x&y&z)";
	S["00000001"]="x&y&z";
	S["10000001"]="!(x|y|z)|x&y&z";
	S["01000001"]="!x&!y&z|x&y&z";
	S["11000001"]="!x&!y|x&y&z";
	S["00100001"]="!x&!z&y|x&y&z";
	S["10100001"]="!x&!z|x&y&z";
	S["01100001"]="!(!y&!z|x|y&z)|x&y&z";
	S["11100001"]="!(x|y&z)|x&y&z";
	S["00010001"]="y&z";
	S["10010001"]="!(x|y|z)|y&z";
	S["01010001"]="!x&z|y&z";
	S["11010001"]="!x&!y|y&z";
	S["00110001"]="!x&y|y&z";
	S["10110001"]="!x&!z|y&z";
	S["01110001"]="!x&(y|z)|y&z";
	S["11110001"]="!x|y&z";
	S["00001001"]="!y&!z&x|x&y&z";
	S["10001001"]="!y&!z|x&y&z";
	S["01001001"]="!(!x&!z|x&z|y)|x&y&z";
	S["11001001"]="!(x&z|y)|x&y&z";
	S["00101001"]="!(!x&!y|x&y|z)|x&y&z";
	S["10101001"]="!(x&y|z)|x&y&z";
	S["01101001"]="!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
	S["11101001"]="!((x|y)&z|x&y)|x&y&z";
	S["00011001"]="!y&!z&x|y&z";
	S["10011001"]="!y&!z|y&z";
	S["01011001"]="!x&z|!y&!z&x|y&z";
	S["11011001"]="!(x&z|y)|y&z";
	S["00111001"]="!x&y|!y&!z&x|y&z";
	S["10111001"]="!(x&y|z)|y&z";
	S["01111001"]="!x&(y|z)|!y&!z&x|y&z";
	S["11111001"]="!x|!y&!z|y&z";
	S["00000101"]="x&z";
	S["10000101"]="!(x|y|z)|x&z";
	S["01000101"]="!y&z|x&z";
	S["11000101"]="!x&!y|x&z";
	S["00100101"]="!x&!z&y|x&z";
	S["10100101"]="!x&!z|x&z";
	S["01100101"]="!x&!z&y|!y&z|x&z";
	S["11100101"]="!(x|y&z)|x&z";
	S["00010101"]="(x|y)&z";
	S["10010101"]="!(x|y|z)|(x|y)&z";
	S["01010101"]="z";
	S["11010101"]="!x&!y|z";
	S["00110101"]="!x&y|x&z";
	S["10110101"]="!(!y&z|x)|x&z";
	S["01110101"]="!x&y|z";
	S["11110101"]="!x|z";
	S["00001101"]="!y&x|x&z";
	S["10001101"]="!y&!z|x&z";
	S["01001101"]="!y&(x|z)|x&z";
	S["11001101"]="!y|x&z";
	S["00101101"]="!x&!z&y|!y&x|x&z";
	S["10101101"]="!(x&y|z)|x&z";
	S["01101101"]="!x&!z&y|!y&(x|z)|x&z";
	S["11101101"]="!x&!z|!y|x&z";
	S["00011101"]="!y&x|y&z";
	S["10011101"]="!(!x&z|y)|y&z";
	S["01011101"]="!y&x|z";
	S["11011101"]="!y|z";
	S["00111101"]="!x&y|!y&x|x&z";
	S["10111101"]="!x&!z|!y&x|y&z";
	S["01111101"]="!x&y|!y&x|z";
	S["11111101"]="!x|!y|z";
	S["00000011"]="x&y";
	S["10000011"]="!(x|y|z)|x&y";
	S["01000011"]="!x&!y&z|x&y";
	S["11000011"]="!x&!y|x&y";
	S["00100011"]="!z&y|x&y";
	S["10100011"]="!x&!z|x&y";
	S["01100011"]="!x&!y&z|!z&y|x&y";
	S["11100011"]="!(x|y&z)|x&y";
	S["00010011"]="(x|z)&y";
	S["10010011"]="!(x|y|z)|(x|z)&y";
	S["01010011"]="!x&z|x&y";
	S["11010011"]="!(!z&y|x)|x&y";
	S["00110011"]="y";
	S["10110011"]="!x&!z|y";
	S["01110011"]="!x&z|y";
	S["11110011"]="!x|y";
	S["00001011"]="!z&x|x&y";
	S["10001011"]="!y&!z|x&y";
	S["01001011"]="!x&!y&z|!z&x|x&y";
	S["11001011"]="!(x&z|y)|x&y";
	S["00101011"]="!z&(x|y)|x&y";
	S["10101011"]="!z|x&y";
	S["01101011"]="!x&!y&z|!z&(x|y)|x&y";
	S["11101011"]="!x&!y|!z|x&y";
	S["00011011"]="!z&x|y&z";
	S["10011011"]="!(!x&y|z)|y&z";
	S["01011011"]="!x&z|!z&x|x&y";
	S["11011011"]="!x&!y|!z&x|y&z";
	S["00111011"]="!z&x|y";
	S["10111011"]="!z|y";
	S["01111011"]="!x&z|!z&x|y";
	S["11111011"]="!x|!z|y";
	S["00000111"]="(y|z)&x";
	S["10000111"]="!(x|y|z)|(y|z)&x";
	S["01000111"]="!y&z|x&y";
	S["11000111"]="!(!z&x|y)|x&y";
	S["00100111"]="!z&y|x&z";
	S["10100111"]="!(!y&x|z)|x&z";
	S["01100111"]="!y&z|!z&y|x&y";
	S["11100111"]="!x&!y|!z&y|x&z";
	S["00010111"]="(x|y)&z|x&y";
	S["10010111"]="!(x|y|z)|(x|y)&z|x&y";
	S["01010111"]="x&y|z";
	S["11010111"]="!x&!y|x&y|z";
	S["00110111"]="x&z|y";
	S["10110111"]="!x&!z|x&z|y";
	S["01110111"]="y|z";
	S["11110111"]="!x|y|z";
	S["00001111"]="x";
	S["10001111"]="!y&!z|x";
	S["01001111"]="!y&z|x";
	S["11001111"]="!y|x";
	S["00101111"]="!z&y|x";
	S["10101111"]="!z|x";
	S["01101111"]="!y&z|!z&y|x";
	S["11101111"]="!y|!z|x";
	S["00011111"]="x|y&z";
	S["10011111"]="!y&!z|x|y&z";
	S["01011111"]="x|z";
	S["11011111"]="!y|x|z";
	S["00111111"]="x|y";
	S["10111111"]="!z|x|y";
	S["01111111"]="x|y|z";
	S["11111111"]="!x|x";
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		cout<<S[s]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}