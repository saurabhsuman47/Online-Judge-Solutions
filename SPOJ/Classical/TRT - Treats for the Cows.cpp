#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
double eps=1e-8;
typedef long long ll;

int main() 
{
		int n;
		scanf("%d",&n);
		int a[n+1];
		a[0]=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j+1]);
		}
		
		int** b=new int*[n+1];
		for(int pp=0;pp<=n;pp++)
		b[pp]=new int[n+1];
		for(int j=0;j<=n;j++)
		{    for(int k=0;k<=n;k++)
			{
				b[j][k]=0;
			}
        }
		for(int j=1;j<=n;j++)
			{
				b[j][j]=n*a[j];
			}
		int n1=n-1;
		for(int l=2;l<=n;l++)
		{	if(n==1)break;
		//cout<<"n1="<<n1<<" ";
		
		for(int i=1;i<=n-l+1;i++)
			{	int q=-1;
				int j=i+l-1;
				q=max((b[i+1][j]+a[i]*n1),(b[i][j-1]+a[j]*n1));
				b[i][j]=q;
				//cout<<"q "<<q<<" ";
			}
			
			n1--;
		/*	cout<<endl;
			for(int j=0;j<=n;j++)
		{    for(int k=0;k<=n;k++)
			{
				cout<<b[j][k]<<" ";
			}
			cout<<endl;
        }
        cout<<endl;*/
		}
		int sol=b[1][n];
		//cout<<b[1][n-1]<<" "<<b[2][n]<<endl;
			cout<<sol<<endl;
	
	//char cc;
	//cin>>cc;
}
