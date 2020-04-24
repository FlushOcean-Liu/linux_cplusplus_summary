#include <iostream>
#include <stack>

using namespace std;

/*
stack 是一种后进先出的数据结构，也就是LIFO
最后加入栈中的元素先被取出来，在栈的同一端
进行的数据的插入与取出，这一段叫做栈顶 
*/

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
    
    return 0;
}
