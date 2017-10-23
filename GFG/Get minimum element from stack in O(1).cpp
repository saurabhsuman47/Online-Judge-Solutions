/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   
   if(s.empty())return -1;
   return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty())return -1;
   int temp = s.top();
   s.pop();
   if(temp > 0){
       return temp;
   }
   else{
       int temp2 = minEle;
       minEle = -1 * temp;
       return temp2;
   }
}
/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
    if(s.empty()){
        s.push(x);
        minEle = x;
    }
    else{
        if(x >= minEle)s.push(x);
        else{
            s.push(-1*minEle);
            minEle = x;
        }
    }
}

