
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const ll N=100005;
const int inf=100000000;



#define fori(n) for(ll i=0;i<n;i++)
#define forj(n) for(ll j=0;j<n;j++)
#define fork(n) for(ll k=0;k<n;k++)
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

int a[N];
int b[N];


////************
int main()
{	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	int str;
	sc(n);
	sc(str);
	fori(n){
		sc(a[i]);
	}
	int i=0;
	int count=0;
	int flag=0;
	while(i<n && flag!=2){
		if(a[i]<=str){
			count++;
		}
		else{
			flag++;
		}
		i++;
	}
	printf("%d\n",count );



	
}
