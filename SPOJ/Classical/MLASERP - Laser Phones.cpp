#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)

const ll mod = 1000000007ll;
const int inf = 1000000000;
const int N = 105;

int n, m;
char a[N][N];
int vis[N][N];
int cost[N][N];
int flag = 0;
pii src, des;
queue <pii> myq;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool is_safe(int x, int y){
	if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*')return true;
	return false;
}

void bfs(pii src){
	myq.push(src);
	vis[src.first][src.second] = 1;
	cost[src.first][src.second] = -1;
	while (!myq.empty()){
		pii t1 = myq.front();
		myq.pop();
		int x = t1.first; int y = t1.second;
		fork(4){
			fori(N){
				int xx = x + i*dx[k];
				int yy = y + i*dy[k];
				if (is_safe(xx, yy)){
					if (!vis[xx][yy]){
						vis[xx][yy] = 1;
						cost[xx][yy] = cost[x][y] + 1;
						myq.push(make_pair(xx, yy));
					}
				}
				else{
					break;
				}
			}
		}
	}
}

int main(){
	
	//freopen("input.txt", "r", stdin);
	sc(m); sc(n);
	string s;
	fori(n){
		cin >> s;	
		forj(m){
			a[i][j] = s[j];
			if (s[j] == 'C' && flag == 0){
				src = make_pair(i, j);
				flag = 1;
			}
			else if (s[j] == 'C' && flag == 1){
				des = make_pair(i, j);
			}
		}
	}
	bfs(src);
	/*fori(n){
		forj(m){
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}*/
	printf("%d\n", cost[des.first][des.second]);
	
}