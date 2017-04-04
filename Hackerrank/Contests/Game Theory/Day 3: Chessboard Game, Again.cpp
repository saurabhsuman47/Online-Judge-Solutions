#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsSafe(int x,int y){
	if(x>=1 && y>=1 && x<=15 && y<=15)return true;
	else return false;
}

int dx[4]={1,-1,-2,-2};
int dy[4]={-2,-2,-1,1};
int a[16][16];
int mex[10];

void grundy(){
	for(int i=1;i<=15;i++){
		for(int j=1;j<=15;j++){
			a[i][j]=0;
		}
	}
	for(int k=1;k<=15;k++){
		for(int i=1;i<=k;i++){
			int j=k+1-i;
			for(int l=0;l<4;l++){
				int ii=i+dx[l];
				int jj=j+dy[l];
				if(IsSafe(ii,jj)){
					mex[a[ii][jj]]=1;					
				} 
				             
			}
			for(int jj=0;jj<10;jj++){
				if(mex[jj]==0){
					a[i][j]=jj;
					break;
				}
			}
			for(int jj=0;jj<10;jj++){
				mex[jj]=0;
			}
				
		}
		
	} 
	 for(int k=1;k<=14;k++){
		for(int i=15;i>k;i--){
			int j=16+k-i;
			//cout<<"i "<<i<<" j "<<j<<endl;
			for(int l=0;l<4;l++){
				int ii=i+dx[l];
				int jj=j+dy[l];
				if(IsSafe(ii,jj)){
					mex[a[ii][jj]]=1;					
				} 
				               
			}
			for(int jj=0;jj<10;jj++){
				if(mex[jj]==0){
					a[i][j]=jj;
					break;
				}
			}
			for(int jj=0;jj<10;jj++){
				mex[jj]=0;
			}
				
		}
		
	}
}

int main() {
	//freopen("input.txt","r",stdin);
	grundy();
	// for(int i=1;i<=15;i++){
	// 	for(int j=1;j<=15;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sol=0;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			sol^=a[x][y];
		}
			
		if(sol==0){
			cout<<"Second"<<endl;
		}
		else{
			cout<<"First"<<endl;
		}
	}
	
	return 0;
}

