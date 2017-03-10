#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;



const ll mod=1000000007ll;
double eps=1e-8;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define fori(n) for(int i=1;i<=n;i++)
#define forj(n) for(int j=1;j<=n;j++)

int vis[101][101];
int a[101][101];
int b[101][101];


void dij(int n,int m)
{	int count=0;
	while(count<=(n*m))

	{
		int mini,minj,min=1000000005;
		for(int ii=1;ii<=n;ii++)
		{
			for(int jj=1;jj<=m;jj++)
				if(vis[ii][jj]==0){if(min>b[ii][jj]){min=b[ii][jj];mini=ii;minj=jj;}}
		}
		count++;
			int i=mini;int j=minj;
			vis[i][j]=1;
			//cout<<"i "<<i<<" j "<<j<<endl;
			int t[5];for(int k=1;k<=4;k++)t[k]=100000000;
			//int flag[5];for(int k=1;k<=4;k++)flag[k]=0;
			if(i+1<=n){if(vis[i+1][j]!=1) {t[1]=b[i][j]+a[i+1][j];if(b[i+1][j]>t[1])b[i+1][j]=t[1];}}
			if(i-1>=1){if(vis[i-1][j]!=1) {t[2]=b[i][j]+a[i-1][j];if(b[i-1][j]>t[2])b[i-1][j]=t[2];}}
			if(j+1<=m){if(vis[i][j+1]!=1) {t[3]=b[i][j]+a[i][j+1];if(b[i][j+1]>t[3])b[i][j+1]=t[3];}}
			if(j-1>=1){if(vis[i][j-1]!=1) {t[4]=b[i][j]+a[i][j-1];if(b[i][j-1]>t[4])b[i][j-1]=t[4];}}

	}
		
		
	
}

////************
int main()
{
	int tt;
	sc(tt);
	while(tt--)
	{
		int n,m;
		sc(n);sc(m);
		
		fori(n){forj(m)sc(a[i][j]);}
		fori(n){forj(m)vis[i][j]=0;}
		fori(n){forj(m){b[i][j]=1000000000;}}
		b[1][1]=a[1][1];
		int t1,t2,t3;
		sc(t1);sc(t2);sc(t3);
		dij(n,m);
		if(b[t1][t2]>t3)printf("NO\n");
		else {
			printf("YES\n");
			printf("%d\n",t3-b[t1][t2]);
		}
		


	}
}