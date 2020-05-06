#include <iostream>
#include <list>

using namespace std;
 template<typename T>
 int search(T arr[], int n, T key)
 {
    int i;
    for (i=0; i<n; i++){
        if(arr[i]==key){
            return i;
         }
     }
     
     return n;
 }
 
 
 template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key)
{
    while(start!=end){
        if(*start==key){
            return start;
        }
        start++;
    }
    return end;
}

int main()
{
    list<int> l;
    
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);
    
    auto it = search(l.begin(), l.end(), 50);
    if(it==l.end()){
        cout<<"element not present"<<endl;
    }else{
        cout<<*it<<endl;
    }
    
    it = search(l.begin(), l.end(), 5);
    if(it==l.end()){
        cout<<"element not present"<<endl;
    }else{
        cout<<*it<<endl;
    }
    
    return 0;
 } 
 
 
 
 
