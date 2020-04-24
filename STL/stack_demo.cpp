#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
stack 是一种后进先出的数据结构，也就是LIFO
最后加入栈中的元素先被取出来，在栈的同一端
进行的数据的插入与取出，这一段叫做栈顶 
*/

template<typename T>
class Stack{
    queue<T> q1,q2;
public:
    void push(T x){
        q1.push(x);
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        
        while(q1.size()>1){
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        
        q1.pop();
        swap(q1,q2);
    }
    
    T top(){
        while(q1.size()>1){
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        
        T element = q1.front();
        q1.pop();
        q2.push(element);
        
        swap(q1,q2);
        return element;
    }
    
    int size(){
        return q1.size()+q2.size();
    }
    
    bool empty(){
        return size()==0;
    }   
};


int main()
{
    stack<int> s;
    for(int i; i<=5;i++){
        s.push(i);
    }
    
    while(!s.empty()){
        cout<<s.top()<<",";
        s.pop();
    }
    cout<<"\n";
    
    Stack<int> sp;
    sp.push(1);
    sp.push(2);
    sp.push(3);
    
    while(!sp.empty()){
        cout<<sp.top()<<" ";
        sp.pop();
    }
    cout<<"\n";
    
    return 0;
}
