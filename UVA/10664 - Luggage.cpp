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
{int t;
scanf("%d",&t);
char cc;scanf("%c",&cc);
for(int p=0;p<t;p++)
	{	char c=' ';
		int a[20]={0};
		int i=0;
		int total=0;; 
		while(c==32)
		{
			string s;
			cin>>s;
			istringstream ss(s);
			ss>>a[i];
			total+=a[i];
			i++;
			
			scanf("%c",&c);
			
		}
		
		//cout<<"n "<<i<<endl;
		/*for(int j=0;j<i;j++)
			cout<<a[j]<<" ";
		cout<<endl;*/
		int b[201]={0};
		b[0]=1;
		//cout<<total<<endl;
		if(total%2==0)
		{	int t=total/2;
			for(int z=0;z<i;z++)
			{
				for(int q=t;q>=a[z];q--)
				{
					if(b[q-a[z]]==1)b[q]=1;
					if(b[t]==1) {cout<<"YES"<<endl;break;}
				}
				if(b[t]==1) break;
			}
			if(b[t]==0) cout<<"NO"<<endl;
		}
		else cout<<"NO"<<endl;


	}

}