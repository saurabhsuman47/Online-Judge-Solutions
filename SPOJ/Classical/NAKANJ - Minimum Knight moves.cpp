#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

const int N = 100005;;
const int inf = 100000000;
const ll mod = 1000000007;

int vis[8][8];

struct node{
	int x, y;
};

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

queue <node*> myq;

bool issafe(int x,int y){
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)return true;
	else return false;
}

void init(){
	fori(8)
		forj(8)
			vis[i][j] = -1;
}

void bfs(string s, string d){
	init();
	int x = s[0] - 'a';
	int y = s[1] - '1';
	vis[x][y] = 0;
	node* a = new node{ x, y };
	myq.push(a);
	while (!myq.empty()){
		a = myq.front();
		myq.pop();
		x = a->x;
		y = a->y;
		fori(8){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (issafe(xx, yy) && vis[xx][yy] == -1){
				vis[xx][yy] = vis[x][y] + 1;
				a = new node{ xx, yy };
				myq.push(a);
			}
		}
		
	}

	x = d[0] - 'a';
	y = d[1] - '1';
	cout << vis[x][y] << endl;


}


int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	while (t--){
		string src, dst;
		cin >> src >> dst;
		bfs(src,dst);
		//fori(8){forj(8)cout << vis[i][j] << " "; cout << endl;}

	}
}