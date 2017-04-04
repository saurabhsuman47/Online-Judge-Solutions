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

int main() {
    
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
                    if(a[ii][jj]==0){
                        a[i][j]=1;
                        break;
                    }
                }               
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
                    if(a[ii][jj]==0){
                        a[i][j]=1;
                        break;
                    }
                }               
            }
                
        }
        
    }
    
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(a[x][y]==0){
            cout<<"Second"<<endl;
        }
        else{
            cout<<"First"<<endl;
        }
    }
    
    return 0;
}

