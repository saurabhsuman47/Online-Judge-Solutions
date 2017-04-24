#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)

const ll mod = 1000000007ll;
const int inf = 1000000000;
const int N = 100005;

ll dp[55][55][2];

void init(){
	fori(55){
		forj(55){
			fork(2){
				dp[i][j][k] = -1;
			}
		}
	}
}

ll bc(int a, int b, int c,int d){
	//cout << a << " " << b << " " << d << endl;
	if (a > 0 && a <= c && b == 1 && d == 1)return 1;

	if (a <= 0 || b <= 0 || a<b)return 0;

	if (dp[a][b][d] != -1)return dp[a][b][d];
	ll t1 = 0;
	repi(1, c){
		if (a - i > 0){
			t1 += bc(a - i, b - 1, c, (d + 1) % 2);
		}
		else break;
	}
	return dp[a][b][d] = t1;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int a, b, c;
	while (cin >> a >> b >> c){
		//cout << a<<" " << b << " " << c << endl;
		init();
		ll t1 = bc(a, b, c, b%2);
		printf("%lld\n", t1);
		
	}
}