class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        while(true){
            if(idx >= str.length()){
                break;
            }
            else if(str[idx] == ' '){
                idx++;
            }            
            else{
                break;
            }            
        }
        if(idx >= str.length())return 0;
        int flag = 1;
        if(str[idx] == '-'){
            flag = -1;
            idx++;
        }
        else if(str[idx] == '+'){
            idx ++;
        }
        vector<int> v;
        int count = 0;
        while(true){
            if(str[idx] < '0' || str[idx] > '9' || count > 10){
                break;
            }
            else{
                v.push_back((int)(str[idx] - '0'));
                idx++;
                count++;
            }
        }
        //if(count > 10)return 0;
        long long y = 0;
        for(int i = 0; i < v.size(); i++){
            y *= 10;
            y += v[i];
        }
        y *= flag;
        if(y > (long long)INT_MAX){
            return INT_MAX;
        }
        else if(y < (long long)INT_MIN){
            return INT_MIN;
        }
        else{
            return (int)y;
        }
    }
};
