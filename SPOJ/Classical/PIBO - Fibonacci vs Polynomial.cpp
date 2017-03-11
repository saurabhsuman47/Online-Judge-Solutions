#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const ll mod=1111111111ll;
	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)

ll coeff[102];
ll M[103][103];
ll result[103][103];
ll base_val[103];
ll temp_matrix[103][103];

void init(int d){
	int size=d+3;
	fori(size){
		result[i][i]=1;
	}
	M[1][0]=1;
	M[0][1]=1;
	M[1][1]=1;
	M[2][2]=1;
	fori(d+1){
		M[i+2][1]=coeff[i];
	}
	for(int j=3;j<size;j++){
		for(int i=2;i<=j;i++){
			M[i][j]=(M[i-1][j-1]+M[i][j-1])%mod;
		}
	}	
	base_val[0]=1;
	base_val[1]=1;
	base_val[2]=1;
	for(int i=3;i<size;i++){
		base_val[i]=(base_val[i-1]*2)%mod;
	}	
}

void multiplyR(int size){
	
	fori(size){
		forj(size){
			temp_matrix[i][j]=0;
			fork(size){
				temp_matrix[i][j]=(temp_matrix[i][j]+result[i][k]*M[k][j])%mod;
			}
		}
	}
	fori(size){
		forj(size){
			result[i][j]=temp_matrix[i][j];
		}
	}
}

void multiplyM(int size){
	
	fori(size){
		forj(size){
			temp_matrix[i][j]=0;
			fork(size){
				temp_matrix[i][j]=(temp_matrix[i][j]+M[i][k]*M[k][j])%mod;
			}
		}
	}
	fori(size){
		forj(size){
			M[i][j]=temp_matrix[i][j];
		}
	}
}

void exp(int b,int size){
	
	while(b>0){
		if(b%2==1){
			multiplyR(size);
		}
		multiplyM(size);
		b/=2;
	}
}

////************
int main()
{	
	int n,d;
	sc(n);sc(d);
	fori(d+1){
		scl(coeff[i]);
	}
	init(d);
	int size=d+3;
	
	if(n<2)printf("%d\n",n);
	else{
		exp(n-1,size);			
		ll solution=0;
		fori(size){
			solution=(solution+base_val[i]*result[i][1])%mod;
		}	
		printf("%lld\n",solution);
	}		
	

}

		
