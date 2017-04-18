#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char a[200][200];
char b[200][200];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool issafe(int x,int y,int r,int c){
    if(x>=0 && x<r && y>=0 && y<c){
        return true;
    }
    return false;
}


int main() {
    int r,c,n;
    cin>>r>>c>>n;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>a[i][j];
            b[i][j] = a[i][j];
        }
    }
     if(n == 0 || n == 1){
        for(int i = 0; i < r; i++){for(int j = 0; j < c; j++){cout<<a[i][j];}cout<<endl;}    //same 
    }
    else if( n % 2 == 0){
        for(int i = 0; i < r; i++){for(int j = 0; j < c; j++){cout<<'O';}cout<<endl;}       // all
    }
    else{
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(b[i][j] == 'O'){
                    for(int k = 0; k < 4; k++){
                        int ii = i + dx[k];
                        int jj = j + dy[k];
                        if(issafe(ii,jj,r,c))a[ii][jj] = 'x';
                    }
                    a[i][j] = 'x';
                }
            }
        }
        if((n-3) % 4 == 0){
             for(int i = 0; i < r; i++){for(int j = 0; j < c; j++){if(a[i][j] == 'x')cout<<'.';else cout<<'O';}cout<<endl;}
        }
        else{
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    b[i][j] = a[i][j];
                }
            }
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(b[i][j] == '.'){
                        for(int k = 0; k < 4; k++){
                            int ii = i + dx[k];
                            int jj = j + dy[k];
                            if(issafe(ii,jj,r,c))a[ii][jj] = 'y';
                        }
                        a[i][j] = 'y';
                    }
                }
            }
            for(int i = 0; i < r; i++){for(int j = 0; j < c; j++){if(a[i][j] == 'y')cout<<'.';else cout<<'O';}cout<<endl;}
        }
    }
    
}

