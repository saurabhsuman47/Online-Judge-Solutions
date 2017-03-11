#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll mod=1000000007ll;
double eps=1e-8;
const int N=100001;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

int a[2001][2001];

////************
int main()
{
	int t;
	sc(t);
	while(t--)
	{
		string s1,s2;
		cin>>s1;
		cin>>s2;
		int l1=s1.length();
		int l2=s2.length();
		//for(int i=0;i<=l1;i++){for(int j=0;j<=l2;j++)a[i][j]=0;}
		for(int i=0;i<=l1;i++)a[i][0]=i;
		for(int j=0;j<=l2;j++)a[0][j]=j;
		//a[0][0]=0;
		for(int i=1;i<=l1;i++)
		{
			for(int j=1;j<=l2;j++)
			{
				if(s1[i-1]==s2[j-1]){a[i][j]=min(min(a[i][j-1]+1,a[i-1][j]+1),a[i-1][j-1]);}
				else{a[i][j]=min(min(a[i][j-1]+1,a[i-1][j]+1),a[i-1][j-1]+1);}
			}
		}
		//for(int i=0;i<=l1;i++){for(int j=0;j<=l2;j++){cout<<a[i][j]<<" ";}cout<<endl;}
		printf("%d\n", a[l1][l2]);

	}
	
	


}