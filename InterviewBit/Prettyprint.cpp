vector<vector<int> > Solution::prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector <vector<int>> arr;
    for(int i=0;i<2*A-1;i++){
        vector<int> temp;
        for(int j=0;j<2*A-1;j++){
            temp.push_back(1);
        }
        arr.push_back(temp);
    }
  for(int k=A;k>=1;k--){
  		int t1=A-k;
  		int t2=2*A-2-t1;
  		for(int i=t1;i<=t2;i++){
  			arr[i][t1]=k;
  			arr[i][t2]=k;
  			arr[t1][i]=k;
  			arr[t2][i]=k;
  		}

  }
   return arr;


    
}

