#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)

typedef long long ll;
const ll mod=1000000007;
int a[10000];
int vis[10000];

int main()
{
	a[0]=1;a[1]=1;
	for(int i=2;i<=100;i++)
	{
		for(int j=2;j*i<=10000;j++)
			a[i*j]=1;

	}
	int t;
	sc(t);
	while(t--)
	{
		int x,y;
		sc(x);sc(y);
		queue<int> Q;
		Q.push(x);
		int count=0;
		int flag=0;
		for(int i=0;i<10000;i++)vis[i]=0;
		vis[x]=1;
		while(!Q.empty())
		{
			int t1=Q.front();
			int t3=vis[t1];
			Q.pop();
			
			//vis[t1]=count;
			count++;
			if(t1==y){flag=1;break;}
			int arr[4];
			for(int i=0;i<4;i++)
			{
				arr[i]=t1%10;
				t1/=10;
			}
			int t2;
			for(int i=1;i<=9;i++){t2=(arr[0]+i)%10+arr[1]*10+arr[2]*100+arr[3]*1000;if(vis[t2]==0 && a[t2]==0){Q.push(t2);vis[t2]=t3+1;}}//cout<<t2<<" "<<vis[t2]<<endl;}}
			for(int i=1;i<=9;i++){t2=arr[0]+((arr[1]+i)%10)*10+arr[2]*100+arr[3]*1000;if(vis[t2]==0 && a[t2]==0){Q.push(t2);vis[t2]=t3+1;}}//cout<<t2<<" "<<vis[t2]<<endl;}}
			for(int i=1;i<=9;i++){t2=arr[0]+arr[1]*10+((arr[2]+i)%10)*100+arr[3]*1000;if(vis[t2]==0 && a[t2]==0){Q.push(t2);vis[t2]=t3+1;}}//cout<<t2<<" "<<vis[t2]<<endl;}}
			for(int i=1;i<=9;i++){t2=arr[0]+arr[1]*10+arr[2]*100+((arr[3]+i)%10)*1000;if(vis[t2]==0 && a[t2]==0 && (arr[3]+i)%10!=0){Q.push(t2);vis[t2]=t3+1;}}//cout<<t2<<" "<<vis[t2]<<endl;}}
		}
		//cout<<"flag "<<flag<<endl;

		if(flag==0)printf("%s\n","Impossible");
		else printf("%d\n",vis[y]-1);

	}
	//cin>>t;
	

}
