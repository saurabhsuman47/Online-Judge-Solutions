#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>

using namespace std;

#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define fori(n) for(int i=0;i<n;i++)
typedef long long ll;
const int N = 10005;

int mat_quaternions[5][5] = {	{ 0, 0, 0, 0, 0 },
								{ 0, 1, 2, 3, 4 },
								{ 0, 2, -1, 4, -3 },
								{ 0, 3, -4, -1, 2 },
								{ 0, 4, 3, -2, -1 } };

int a[N];
int mul_all(int n,ll x){
	x = x % 4;
	if (x == 0) return 1;
	int sol = 1;
	fori(n){
		if (sol >= 0){
			sol = mat_quaternions[sol][a[i]];
		}
		else {
			sol = -1 * mat_quaternions[-1 * sol][a[i]];
		}		
	}
	if (sol == 1 || sol == -1){
		if (x == 1 || x==3)return sol;
		else return 1;
	}
	else{
		if (x == 1)return sol;
		else if (x == 2)return -1;
		else if (x == 3)return (-1 * sol);
	}
}

int main()
{	
	freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for(int z=1;z<=t;z++){
		ll l, x;
		scl(l);	scl(x);
		string s;
		
		cin >> s;
		fori(l){
			a[i] = s[i] - 'i' + 2;
		}
		/*fori(l){
			cout << a[i] << " ";
		}
		cout << endl;*/
		int flag = 0;
		ll l1 = 0;
		if (mul_all(l, x)==-1){
			int i = 0;
			int sol = 1;
			
			for (; i < 4 * l;i++){
				if (sol >= 0){
					sol = mat_quaternions[sol][a[i%l]];
				}
				else {
					sol = -1 * mat_quaternions[-1 * sol][a[i%l]];
				}
				if (sol == 2){ flag = 1; break; }
			}
			sol = 1;
			if (flag == 1){
				int idx = i + 1;
				idx = idx%l;
				for (i = idx; i < (idx + 4 * l); i++){
					if (sol >= 0){
						sol = mat_quaternions[sol][a[i%l]];
					}
					else {
						sol = -1 * mat_quaternions[-1 * sol][a[i%l]];
					}
					if (sol == 3){flag = 2; break; }
				}
				l1 = i;
			}
		}
		cout << "Case #" << z <<": ";
		if (flag == 2 && (l*x>l1))cout << "YES" << endl;
		else cout << "NO" << endl;
		



	}
}
