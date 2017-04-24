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
const int N = 105;

int a[N];
float dp[N][10005];
int val;

void init(){
	fori(N){
		forj(10004){
			dp[i][j] = -1.0;
		}
	}
}

float foo(int idx, int sum){
	if (idx == -1){
		if (sum > 5000){
			return (100.0*val) / sum;
		}
		else return -2.0;
	}
	if (dp[idx][sum] != -1.0)return dp[idx][sum];

	return dp[idx][sum] = max(foo(idx - 1, sum), foo(idx - 1, sum + a[idx]));
}


int main(){
	freopen("input.txt", "r", stdin);
	int n, idx;
	while (true){
		sc(n); sc(idx);
		if (n == 0 && idx == 0)break;
		int ii = 0;
		fori(n){
			int t1, t2;
			if (i == idx - 1){				
				scanf("%d.%d", &t1,&t2);
				val = t1 * 100 + t2;
				continue;
			}
			scanf("%d.%d", &t1, &t2);
			a[ii] = t1 * 100 + t2;
			ii++;
		}
		/*fori(n - 1){
			cout << a[i] << " ";
		}
		cout << endl;
		cout << val <<  endl;*/
		init();
		float t1;
		if (n == 1) t1 = 100.00;
		else t1 = foo(n-2, val);
		printf("%.2f\n", t1);
	}
}