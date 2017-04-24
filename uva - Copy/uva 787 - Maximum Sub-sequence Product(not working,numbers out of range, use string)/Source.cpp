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
ll a[N];
ll leastNeg[N];
ll c[N];

ll process(ll n){
	ll result = 1;
	fori(n){
		result = result*a[i];
		a[i] = result;
		if (result == 0)result = 1;
	};
	ll val = 1;
	int flag = 0;
	fori(n){		
		if (a[i] == 0){
			val = 0;
			flag = 0;
			//cout << "here" << endl;
		}
		else if (a[i] < 0 && flag == 0){
			val = a[i];
			flag = 1;
			//cout <<"i "<<i<<" "<<a[i]<< " here1" << endl;
		}
		leastNeg[i] = val;		
	}
	c[0] = a[0];
	repi(1,n-1){
		if (a[i] >= 0){
			c[i] = a[i];
		}
		else {
			if (leastNeg[i - 1]>0){
				c[i] = a[i] / a[i - 1];
			}
			else if (leastNeg[i - 1] == 0){
				c[i] = 0;
			}
			else{
				c[i] = a[i] / leastNeg[i];
			}
		}
	}
	ll maxx = -1 *(ll) inf;
	fori(n){
		maxx = max(maxx, c[i]);
	}
	return maxx;
}

int main(){
	freopen("input.txt", "r", stdin);
	ll n;
	ll i = 0;
	while (cin >> n){
		if (n != -999999){
			a[i] = n;
			i++;
		}
		else {
			printf("%lld\n",process(i));
			/*forj(i){
				cout << a[j] << " ";
			}
			cout << endl;
			forj(i){
				cout << leastNeg[j] << " ";
			}
			cout << endl;
			forj(i){				
				cout << c[j] << " "; 
			}*/
			//cout << endl;
			i = 0;
		}
	}
}