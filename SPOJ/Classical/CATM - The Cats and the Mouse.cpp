#include <bits/stdc++.h>

using namespace std;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define sc(x) scanf("%d",&(x))
typedef pair<int, int> pii;

const int N=205;
int x,y,x1,yy1,x2,y2;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int vis[N][N];
int flag=0;

bool issafe(int a,int b,int n,int m){
    if(a>=0 && a<=n+1 && b>=0 && b<=m+1)return true;
    else return false;
}

void bfs(int n,int m){
    vis[x][y]=1;
    queue<pii> myq;
    pii mypair;
    mypair=make_pair(x,y);
    myq.push(mypair);
    while(!myq.empty()){
        mypair=myq.front();
        int F=mypair.first;
        int S=mypair.second;
        myq.pop();
        fori(4){
            
            int xx=F+dx[i];
            int yy=S+dy[i];
            if(issafe(xx,yy,n,m) && vis[xx][yy]==0){
                vis[xx][yy]=1;
                if((xx==0 || xx==n+1) || (yy==0 || yy==m+1)){
                    flag=1;
                    break;
                }
                int t1=abs(xx-x)+abs(yy-y);
                //if(t1>max)max=t1;
                int t2=abs(xx-x1)+abs(yy-yy1);
                int t3=abs(xx-x2)+abs(yy-y2);
                
                if(!(t1==t2 || t1==t3)){
                    mypair=make_pair(xx,yy);
                    myq.push(mypair);
                }
            }

        }
        if(flag==1)break;
    }


}
void init(){
    fori(N){
        forj(N){
            vis[i][j]=0;
        }
    }
    flag=0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n,m;
    sc(n);sc(m);
    int t;
    sc(t);
    while(t--){
        init();
        scanf("%d %d",&x,&y);
        scanf("%d %d",&x1,&yy1);
        scanf("%d %d",&x2,&y2);
        bfs(n,m);
        // for(int i=0;i<=n+1;i++){
        //     for(int j=0;j<=m+1;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
       
        
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
}
