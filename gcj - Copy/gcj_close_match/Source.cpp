#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

#define scl(x) scanf("%lld",&x)
#define sc(x) scanf("%d",&x)
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)
const int N = 20;
const ll inf = 1000000000000000000ll;

ll a[N], b[N];
ll sol = inf;
ll aa = inf + 5;
ll bb = inf + 5;

void update(ll t1, ll t2){
	ll t3 = abs(t1 - t2);
	if (t3 < sol){
		sol = t3;
		aa = t1;
		bb = t2;
	}
	else if (t3 == sol){
		if (t1 < aa){
			sol = t3;
			aa = t1;
			bb = t2;
		}
		else if (t1 == aa){
			if (t2 < bb){
				sol = t3;
				aa = t1;
				bb = t2;
			}
		}
	}

}

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		string s1, s2;
		int l = s1.length();
		sol = inf;
		aa = inf + 5;
		bb = inf + 5;
		fori(l){
			
			if (s1[i] != '?' && s2[i] != '?'){
				forj(l){
					a[j] = s1[j] - '0';
					b[j] = s2[j] - '0';
				}
				if (s1[i] > s2[i]){
					repj(i + 1, l - 1){
						if (s1[j] == '?')a[j] = 0;
						if (s2[j] == '?')b[j] = 9;
					}
					ll t1 = 0, t2 = 0;
					forj(l){
						t1 *= 10; t2 *= 10;
						t1 += a[j]; t2 += b[j];
					}
					update(t1, t2);
					break;
				}
				else if (s1[i] < s2[i]){
					repj(i + 1, l - 1){
						if (s1[j] == '?')a[j] = 9;
						if (s2[j] == '?')b[j] = 0;
					}
					ll t1 = 0, t2 = 0;
					forj(l){
						t1 *= 10; t2 *= 10;
						t1 += a[j]; t2 += b[j];
					}
					update(t1, t2);
					break;
				}
				
			}
			else if (s1[i] == '?' && s2[i] != '?'){
				
				if (s2[i] != '9'){
					forj(l){
						a[j] = s1[j] - '0';
						b[j] = s2[j] - '0';
					}
					a[i]++;
				}
			}
		}
	}
}