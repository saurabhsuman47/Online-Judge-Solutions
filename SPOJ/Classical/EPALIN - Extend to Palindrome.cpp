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

int pi[N];
void preKMP(char s[],int l)
{
	//int l=strlen(s);
	pi[0]=-1;
	//cout<<l<<endl;
	int k=-1;
	for(int q=1;q<l;q++)
	{
		while(k>=0 && s[q]!=s[k+1])
			k=pi[k];
		if(s[q]==s[k+1])
			k=k+1;
		pi[q]=k;
	}
}


////************
int main()
{
	char T[N];
	while(scanf("%s",T)!=EOF)
	{
		
		int l=strlen(T);
		//cout<<l<<endl;
		char s[2*N];
		fori(l){pi[i]=0;s[i]=T[l-1-i];}
		
		//cout<<s<<endl;
		//cout<<T<<endl;
		preKMP(s,l);
		int q=-1;
		fori(l)
		{
			while(q>=0 && s[q+1]!=T[i])
				q=pi[q];
			if(s[q+1]==T[i])
				q+=1;
		}
		//cout<<q<<endl;
		//printf("%s\n",s);
		cout<<T;
		for(int i=q+1;i<l;i++)
			printf("%c",s[i]);
		printf("\n");
		


	}
	


}