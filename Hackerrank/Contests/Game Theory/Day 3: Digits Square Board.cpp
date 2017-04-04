#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)

int a[31][31];
int b[31][31];
int g[31][31][31][31];

int n;

void init(){
	fori(n){
		forj(n){
			fork(n){
				for (int l = 0; l < n; l++){
					if (i == k && j == l)g[i][j][k][l] = 0;
					else g[i][j][k][l] = -1;
				}
			}
		}
	}
}

bool IsSafe(int x, int y){
	if (x >= 0 && y >= 0 && x < n && y < n){
		return true;
	}
	return false;
}

int check(int x1, int y1, int x2, int y2){
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	if(IsSafe(x2,y2))t1 = b[x2][y2];
	if (IsSafe(x1 - 1, y1 - 1))t2 = b[x1 - 1][y1 - 1];
	if (IsSafe(x2, y1 - 1))t3 = b[x2][y1 - 1];
	if (IsSafe(x1 - 1, y2))t4 = b[x1 - 1][y2];
	//cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
	if (t1 + t2 - t3 - t4 > 0)return true;
	else return false;
}


int grundy(int x1, int y1, int x2, int y2){
	//check issafe
	if (g[x1][y1][x2][y2] == -1){
		if (check(x1, y1, x2, y2) == false){
			g[x1][y1][x2][y2] = 0;
			return g[x1][y1][x2][y2];
		}
        int mex[61];
		fori(61){
			mex[i] = 0;
		}
		repi(x1 + 1, x2){
			int t1=grundy(x1, y1, i - 1, y2);
			int t2 = grundy(i, y1, x2, y2);
			mex[t1^t2] = 1;
		}
		repj(y1 + 1, y2){
			int t1 = grundy(x1, y1, x2, j-1);
			int t2 = grundy(x1, j, x2, y2);
			mex[t1^t2] = 1;
		}
		fori(61){
			if (mex[i] == 0){
				g[x1][y1][x2][y2] = i;
				break;
			}
		}
	}
	return g[x1][y1][x2][y2];
	
}


int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--){
		
		cin >> n;
		fori(n){
			forj(n){
				cin >> a[i][j];
				b[i][j] = 0;
			}
		}
		fori(n){
			int t1 = 0;
			forj(n){
				if (a[i][j] == 1 || a[i][j] == 4 || a[i][j] == 6 || a[i][j] == 8 || a[i][j] == 9){
					b[i][j] = t1 + 1;
				}
				else{
					b[i][j] = t1;
				}
				t1 = b[i][j];
			}
		}

		forj(n){
			int t1 = 0;
			fori(n){
				b[i][j] = t1 + b[i][j];
				t1 = b[i][j];
			}
		}

		

		/*fori(n){
			forj(n){
				cout << b[i][j] << " ";
			}
			cout << endl;
		}*/
		init();
		//cout << grundy(0, 0, n-1, n-1) << endl;
        if(grundy(0, 0, n-1, n-1) ==0)cout<<"Second"<<endl;
        else cout<<"First"<<endl;






	}
}
