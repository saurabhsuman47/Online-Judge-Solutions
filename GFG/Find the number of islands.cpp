
/*you are required to complete this method*/

int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

bool issafe(int i, int j, int x, int y){
    if(i >= 0 && j >=0 && i < x && j <y)return true;
    return false;
}

int dfs(int a[MAX][MAX], int i, int j, int n, int m){
    a[i][j] = -1;
    for(int k = 0; k < 8; k++){
        int ii = i + dx[k];
        int jj = j + dy[k];
        if(issafe(ii, jj, n, m) && a[ii][jj] == 1){
            dfs(a, ii, jj, n, m);
        }
    }
}

int findIslands(int A[MAX][MAX], int N, int M)
{
//Your code here 
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(A[i][j] == 1){
                dfs(A, i, j, N, M);
                count++;
            }
        }
    }
    return count;
}
