int solveHelper(int i, int j, const vector<int> &A, vector<vector<int>> & dp, int n){
    if(dp[i][j] != -1)return dp[i][j];
    int diff = A[j] - A[i];
    int flag = 0;
    int temp = 0;
    for(int k = j + 1; k < n; k++){
        if(A[k] - A[j] == diff){
            flag = 1;
            temp = solveHelper(j, k, A, dp, n);
            break;
        }
    }
    if(flag == 1)dp[i][j] = 1 + temp;
    else dp[i][j] = 2;
    return dp[i][j];
}


int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n == 1)return 1;
    vector<vector<int>> dp;
    vector<int> temp;
    for(int i = 0; i < n; i++){
        temp.push_back(-1);
    }
    for(int i = 0; i < n; i++){
        dp.push_back(temp);
    }
    
    int sol = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(dp[i][j] = -1){
                solveHelper(i, j, A, dp, n);
            }
            sol = max(sol, dp[i][j]); 
        }
    }
    return sol;
}



