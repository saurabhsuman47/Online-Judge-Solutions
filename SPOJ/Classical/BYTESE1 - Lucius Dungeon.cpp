    #include <stdio.h>  
    #include <string.h>  
    #include <iostream>  
    #include <queue>   
    using namespace std;  
      
    #define MX 110  
    int r, c;  
    int a, b;  
    int g[MX][MX], dis[MX][MX];  
    bool vis[MX][MX];  
    int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};  
      
    queue< pair<int, int> > Q;  
      
    int spfa() {  
        memset(dis, 0x3f, sizeof(dis));  
        memset(vis, 0, sizeof(vis));  
        Q.push(make_pair(1, 1));  
        vis[1][1] = 1;  
        dis[1][1] = g[1][1];  
        while(!Q.empty()) {  
            pair<int, int> t = Q.front();  
            Q.pop();  
            int x = t.first;  
            int y = t.second;  
            vis[x][y] = 0;  
            for(int i = 0; i < 4; ++i) {  
                int X = x + d[i][0];  
                int Y = y + d[i][1];  
                if(X >= 1 && Y >= 1 && X <= r && Y <= c && dis[X][Y] > dis[x][y] + g[X][Y]) {  
                    dis[X][Y] = dis[x][y] + g[X][Y];  
                    if(X == a && Y == b) continue;  
                    if(!vis[X][Y]) {  
                        vis[X][Y] = 1;  
                        Q.push(make_pair(X, Y));  
                    }  
                }  
            }  
        }  
        return dis[a][b];  
    }  
      
    int main() {  
        int T;  
        scanf("%d", &T);  
        while(T--) {  
              
            scanf("%d%d", &r, &c);  
            for(int i = 1; i <= r; ++i) {  
                for(int j = 1; j <= c; ++j) {  
                    scanf("%d", &g[i][j]);  
                }  
            }  
            int T;  
            scanf("%d%d%d", &a, &b, &T);  
            int ans = spfa();  
        //  printf("%d\n", ans);  
            if(ans <= T) printf("YES\n%d\n", T - ans);  
            else printf("NO\n");  
        }     
        return 0;  
    }   