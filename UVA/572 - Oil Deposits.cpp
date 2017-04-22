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
char a[101][101];

void dfs(int i,int j,int m,int n)
{
	//cout<<"i "<<i<<" j "<<j<<endl;
	vis[i][j]=1;
	for(int ki=-1;ki<=1;ki++)
	{
		int ii=i+ki;
		for(int kj=-1;kj<=1;kj++)
		{
			int jj=j+kj;
			if(ii<=m && ii>=1 && jj<=n && jj>=1 && vis[ii][jj]==0 && a[ii][jj]=='@')
				{dfs(ii,jj,m,n);}
		}
	}
}



////************
int main()
{	
	int m,n;
	while(cin>>m>>n && m!=0)
	{
		fori(m)
		{
			forj(n){cin>>a[i][j];vis[i][j]=0;}
		}
	
		int count=0;
		
		fori(m)
		{	
			forj(n)
			{
				if(vis[i][j]==0 && a[i][j]=='@'){dfs(i,j,m,n);count++;}
			}
		}
		cout<<count<<endl;

	}
}