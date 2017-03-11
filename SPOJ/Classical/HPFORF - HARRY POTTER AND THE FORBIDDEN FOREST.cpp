#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
#define fori(n) for(int i=1;i<=n;i++)
#define forj(n) for(int j=1;j<=n;j++)
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

const int N = 505;
const int inf = 100000000;
const ll mod = 1000000007;
int countHorcrux = 0;

int vis[N][N];
int sol[N][N];
queue<int> myqx;
queue<int> myqy;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool IsSafe(int x, int y, int n, int m){
	if (x >= 1 && x <= n && y >= 1 && y <= m)return true;
	return false;
}

void dfs(int x, int y, int n, int m){
	//cout<<"x "<<x<<" y "<<y<<endl;
	vis[x][y] = 1;
	myqy.push(y);
	myqx.push(x);
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (IsSafe(xx, yy, n, m) && vis[xx][yy] == -1){
			countHorcrux++;
		}
		else if (IsSafe(xx, yy, n, m) && vis[xx][yy] == 0){
			dfs(xx, yy, n, m);
		}
	}
	return;
}

void WriteHorcruxes(int n, int m){
	while(!myqx.empty()){
		int x=myqx.front();
		int y=myqy.front();
		myqy.pop();
		myqx.pop();
		sol[x][y]=countHorcrux;
	}
}



int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	while (t--)
	{
		int n, m, k;
		sc(n); sc(m); sc(k);
		char c;
		fori(n){
			scanf("%c",&c);
			forj(m){
				sol[i][j] = 0;
				scanf("%c",&c);
				//cin>>c;
				if (c == '*'){
					vis[i][j] = -1;
				}
				else{
					vis[i][j] = 0;
				}
			}
		}
		// fori(n){
		// 	forj(m){
		// 		cout << vis[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		fori(k){
			int x, y;
			sc(x); sc(y);
			if (vis[x][y] == 0){
				countHorcrux = 0;
				dfs(x, y, n, m);
				WriteHorcruxes(n, m);
			}
			//cout << sol[x][y] << endl;
			printf("%d\n",sol[x][y]);
			// fori(n){
			// 	forj(m){
			// 		cout << sol[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }

		}
	}
	
}