#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

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

typedef vector<int> myv;
myv arr[21];
int m, c;
myv dp1;
bool a[21];

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){

		sc(m); sc(c);

		fori(c){
			int t1;
			sc(t1);
			arr[i].clear();
			forj(t1){
				int t2; sc(t2);
				arr[i].push_back(t2);
			}
		}

		fori(arr[0].size()){
			dp1.push_back(arr[0][i]);
		}
		forj(dp1.size()){
			cout << dp1[j] << " ";
		}
		cout << endl;

		repi(1, c - 1){
			cout << "i " << i << endl;
			forj(dp1.size()){
				fork(arr[i].size()){
					if (dp1[j] + arr[i][k]<=m)a[dp1[j] + arr[i][k]] = 1;
				}
			}
			//cout << "here" << endl;
			dp1.clear();
			forj(m + 1){
				if (a[j] == 1){
					dp1.push_back(j);
					a[j] = false;
				}
			}
			//cout << "here" << endl;
			forj(dp1.size()){
				cout << dp1[j] << " ";
			}
			cout << endl;
			
		}
		
		if (dp1.size() == 0){
			printf("no solution\n");
		}
		else printf("%d\n", dp1[dp1.size()-1]);

	}
}