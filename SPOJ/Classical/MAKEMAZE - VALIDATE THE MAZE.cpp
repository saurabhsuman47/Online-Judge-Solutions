#include <iostream>
#include <stdio.h>

//#include <bits/stdc++.h>
using namespace std;

char a[20][20];
int vis [20][20];
int row[4]={-1,0,0,1};
int col[4]={0,-1,1,0};
int issafe(int x,int y,int m,int n)
{
	if(x>=0 && x<m && y>=0 && y<n)return 1;
	else return 0;
}


void dfs(int x,int y,int m,int n)
{
	if(issafe(x,y,m,n)==1)
	{
		if(a[x][y]=='.' && vis[x][y]==0)vis[x][y]=1;
		else return;
		for(int k=0;k<4;k++)
		{
			dfs(x-row[k],y-col[k],m,n);
		}
	}
	else return;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		for(int i=0;i<x;i++)
		{
			char c;
			scanf("%c",&c);
			for(int j=0;j<y;j++)
			{
				scanf("%c",&a[i][j]);
			}
		}
		int m,n;
		int m1,n1;
		int count=0;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				if((i==0 && a[i][j]=='.')||(j==0 && a[i][j]=='.')||(i==x-1 && a[i][j]=='.')||(j==y-1 && a[i][j]=='.'))
					{count++;if(count==1){m=i;n=j;}if(count==2){m1=i;n1=j;}}
			}
		}
		//cout<<count<<endl;
		if(count!=2)printf("%s\n","invalid" );
		else
		{
			for(int i=0;i<x;i++)
				for(int j=0;j<y;j++)vis[i][j]=0;
			dfs(m,n,x,y);
			if(vis[m1][n1]==1)printf("%s\n","valid" );
			else printf("%s\n","invalid" );
		}

		
		
	}
	
	
}
