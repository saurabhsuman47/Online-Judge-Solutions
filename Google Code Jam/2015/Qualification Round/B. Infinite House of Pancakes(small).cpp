#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

const int N = 1005;
const int inf = 100000000;
const ll mod = 1000000007;


int a[N];



int main(){
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		int d, m = 0;
		sc(d);
		fori(d){
			sc(a[i]);
			if (a[i] > m)m = a[i];
		}
		int sol = inf;
		for (int i = 1; i <= m; i++){
			int temp_sol = i;
			forj(d){
				int t1 = a[j] / i;
				if (a[j] % i == 0)t1--;
				temp_sol += t1;
			}
			if (temp_sol < sol){
				sol = temp_sol;
			}

		}
		cout << "Case #" << z << ": " << sol << endl;
	}
}