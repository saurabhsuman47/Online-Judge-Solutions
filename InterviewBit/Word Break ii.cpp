void wordBreakSolver(vector<string> &sol, vector<string> current, string A, int index, int n, unordered_set<string> &us){
    
    if(index == n){
        string str = "";
        for(int i = 0; i < current.size(); i++){
            str += current[i];
            if(i != current.size() -1)str += ' ';
        }
        sol.push_back(str);
    }
    for(int i = index; i < n; i++){
        string str = A.substr(index, i - index + 1);
        if(us.find(str) != us.end()){
            current.push_back(str);
            wordBreakSolver(sol, current, A, i+1, n, us);
            current.pop_back();
        }
        
    }
    return;
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //cout<<A<<endl;
    sort(B.begin(), B.end());
    vector<string> current;
    vector<string> sol;
    unordered_set<string> us;
    for(int i = 0; i < B.size(); i++){
        us.insert(B[i]);
    }
    wordBreakSolver(sol, current, A, 0, A.length(), us);
    return sol;
    
}



