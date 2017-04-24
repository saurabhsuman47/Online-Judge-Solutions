#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define repi(a,b) for(int i=a;i<=b;i++)
#define fori(n) for(int i=0;i<n;i++)
typedef long long ll;
const int N = 10005;



int main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		int n;
		sc(n);
		string s;
		cin >> s;
		int add_required = 0;
		int sum = s[0] - '0';
		repi(1,n){
			int t1 = s[i] - '0';
			if (sum >= i){
				sum += t1;
			}
			else{
				//cout << "here" << i << endl;
				add_required += (i - sum);
				sum = (i+t1);
			}
		}
		cout << "Case #" << z << ": " << add_required << endl;




	}
}
