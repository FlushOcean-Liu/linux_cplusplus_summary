#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, int> m;
    
    m.insert(make_pair("Mango",100));
    
    pair<string, int> p;
    p.first="Apple";
    p.second=120;
    m.insert(p);
    
    m["Banana"]=20;
    
    cout<<"Please input a fruit:";
    string fruit;
    cin>>fruit;
    
    m[fruit]+=22;
    
    cout<<"find input ["<<fruit<<"]"<<endl;
    auto it =m.find(fruit);
    if(it!=m.end()){
        cout<<"price of ["<<fruit<<"] is "<<m[fruit]<<endl;
    }else{
        cout<<"fruit is not present "<<endl;
    }
    
    cout<<"start to delete ["<<fruit<<"]"<<endl;
    m.erase(fruit);
    cout<<"start to find ["<<fruit<<"]"<<endl;
    if(m.count(fruit)){
        cout<<"Price is "<<m[fruit]<<endl;
    }else{
        cout<<"Could not find "<<endl;
    }
    
    m["Litchi"]=60;
    m["Pineapple"]=80;
    
    cout<<"=================================="<<endl;
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<" and "<<it->second<<endl;
    }
    cout<<"=================================="<<endl;
    for(auto p:m){
        cout<<p.first<<" : "<<p.second<<endl;
    }
    
    return 0;
}
