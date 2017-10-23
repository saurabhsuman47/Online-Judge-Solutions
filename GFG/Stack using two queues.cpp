/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}
//Making pop operation more costly//
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code 
        int t1;
        if(q1.empty())return -1;
        while(!q1.empty()){
            t1 = q1.front();
            q1.pop();
            if(!q1.empty()){
                q2.push(t1);
            }
        }
        swap(q1, q2);
        return t1;
}

