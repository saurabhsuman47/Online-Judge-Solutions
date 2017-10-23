/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
stack<int> sortedInsert(stack<int> s, int x){
    if(s.empty() || s.top() <= x){
        s.push(x);
    }
    else{
        int temp = s.top();
        s.pop();
        s = sortedInsert(s, x);
        s.push(temp);
    }
    return s;
}
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   if(!s.empty()){
       int temp = s.top();
       s.pop();
       sort();
       s = sortedInsert(s, temp);
   }
}


