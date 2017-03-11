#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const ll mod=1000000007ll;
double eps=1e-8;
const int N=100001;
const int inf=1000000009;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)

ll M_init[3][3]={{1,0,0},{1,0,1},{1,1,1}};
ll M[3][3];
ll result [3][3];

void init(){
	fori(3){
		forj(3){
			M[i][j]=M_init[i][j];
			result[i][j]=(i==j)?1:0;
		}
	}
}

void multiplyM(){
	ll temp_matrix[3][3];
	fori(3){
		forj(3){
			temp_matrix[i][j]=0;
			fork(3){
				ll temp=(M[i][k]*M[k][j])%mod;
				temp_matrix[i][j]=(temp_matrix[i][j]+temp)%mod;
			}
		}
	}
	fori(3){
		forj(3){
			M[i][j]=temp_matrix[i][j];
		}
	}	
}

void multiplyR(){
	ll temp_matrix[3][3];
	fori(3){
		forj(3){
			temp_matrix[i][j]=0;
			fork(3){
				ll temp=(result[i][k]*M[k][j])%mod;
				temp_matrix[i][j]=(temp_matrix[i][j]+temp)%mod;
			}
		}
	}
	fori(3){
		forj(3){
			result[i][j]=temp_matrix[i][j];
		}
	}
}


void exp(int b){
	init();
	while(b>0){
		if(b%2==1){
			multiplyR();
		}
		multiplyM();
		b/=2;
	}

}



////************
int main()
{
	//freopen("input.txt","r",stdin);
	int t;
	sc(t);

	while(t--){		

		ll a[3]={1,0,1};
		int m,n;
		sc(m);sc(n);
		exp(n-1);
		ll t1=0,t2=0;
		fori(3){
			t1=(t1+result[i][0]*a[i])%mod;
		}
		if(n==0){
			t1=0;
		}

		exp(m-2);
		fori(3){
			t2=(t2+result[i][0]*a[i])%mod;
		}
		if(m==0 || m==1){
			t2=0;
		}		
		
		ll solution = (t1-t2+mod)%mod;
		printf("%lld\n", solution);
	}
	
	


}