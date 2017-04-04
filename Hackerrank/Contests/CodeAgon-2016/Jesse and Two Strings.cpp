#include <bits/stdc++.h>

using namespace std;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define sc(x) scanf("%d",&(x))
typedef pair<int, int> pii;
const int N=1005;

string A;
string B;
int maxA;
int maxB;
int lps[N][N];
int cntA[26];
int cntB[26];
void calc_lps(string S){
	int n=S.length();
	// for(int i=1;i<=n;i++){
	// 	lps[i][n+1]=1;
	// }
	// for(int i=1;i<=n;i++){
	// 	lps[0][i]=1;
	// }
	for(int k=1;k<=n;k++){
		int i=1;
		int j=n-k+1;
		while(j<=n){
			int ii=i-1;
			int jj=j-1;
			if(S[ii]==S[jj]){
				if(ii!=jj)lps[i][j]=lps[i-1][j+1]+2;
				else{
					lps[i][j]=lps[i-1][j+1]+1;
				}
			}
			else{
				lps[i][j]=max(lps[i][j+1],lps[i-1][j]);
			}
			i++;j++;
		}
	}
}
void process_lpsA(){
	fori(A.length()+2){
		forj(A.length()+2){
			if(maxA<lps[i][j])maxA=lps[i][j];
		}
	}

	fori(A.length()+2){
		if(lps[i][i]==maxA){
			cntA[A[i-1]-'a']++;
		}
	}
	
}
void process_lpsB(){
	fori(B.length()+2){
		forj(B.length()+2){
			if(maxB<lps[i][j])maxB=lps[i][j];
		}
	}
	fori(B.length()+2){
		if(lps[i][i]==maxB){
			cntB[B[i-1]-'a']++;
		}
	}
}

void init(){
	fori(N){
		forj(N){
			lps[i][j]=0;
		}
	}
	
}

int main()
{
	//freopen("input.txt","r",stdin);
	int t;
	sc(t);
	while(t--){
		maxA=0;
		maxB=0;
		fori(26){cntB[i]=0;cntA[i]=0;}
		init();
		cin>>A;
		calc_lps(A);
		// fori(A.length()+2){
		//     forj(A.length()+2){
		//         cout<<lps[i][j]<<" ";
		//     }
		//     cout<<endl;
		// } 
		process_lpsA();
		init();
		cin>>B;
		calc_lps(B);
		// fori(B.length()+2){
		//     forj(B.length()+2){
		//         cout<<lps[i][j]<<" ";
		//     }
		//     cout<<endl;
		// }
		process_lpsB();
		if(maxA%2 && maxB%2){
			int flag=0;
			fori(26){
				if(cntA[i]&&cntB[i]){
					flag=1;
					cout<<maxA+maxB<<endl;
					break;
				}
			}
			if(flag==0){
				cout<<maxA+maxB-1<<endl; 
			}
		}
		else{
			cout<<maxA+maxB<<endl;
		}
	}
	
	
}

