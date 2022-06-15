#include <iostream>
#include <map>

using namespace std;

void show(map<char, string> Map)
{
    cout<<"Map element:"<<endl;
    for(auto im:Map){
        cout<<im.first<<":"<<im.second<<" ";
    }
    cout<<"\n\n";
}


void show1(map<char,string> Map)
{
    cout<<"iterator map:\n";
    for(auto it=Map.cbegin();it!=Map.cend();++it){
        cout<<it->first<<":"<<it->second<<" ";
    }
    cout<<"\n\n";
}

void Insert(pair<map<char,string>::iterator, bool> it)
{
    if(it.second){
        cout<<"it->second = "<<it.second<<endl;
        cout<<"it.first->first="<<it.first->first<<",it->first->second="<<it.first->second<<endl;
    }else{
        cout << "it.second = " << it.second << endl;
        cout << "it.first->first = " << it.first-> first << ",it.first -> second = " << it.first->second << endl;
    }
    
    cout<<"\n\n";
}

int main(int argc, char *argv[])
{
    map<char, string> Map = { {'c',"chen"},
                              {'w',"wang"},
                              {'l',"li"},
                              {'z',"zhao"},
                              {'s',"sun"},
                              {'q',"qian"},
                              {'z',"zhou"}
                            };
    cout << "Map.size() = "<< Map.size() << endl;
    show(Map);
    auto a = Map.insert({'a',"aozi"});
    Insert(a);

    auto b = Map.insert({'b',"bao"});
    Insert(b);

    auto it1 = Map.insert(make_pair('c',"cao"));
    Insert(it1);

    cout << "Map.size() = "<< Map.size() << endl;
    show(Map);

    cout << "Map['a'] = " << Map['a'] << endl;
    cout << "Map['x'] = " << Map['x'] << endl;

    Map['x'] = "xiao";
    cout << "Map['x'] = " << Map['x'] << "\n\n";

    cout << "Map.at('a') = " << Map.at('a') << "\n\n";
    //cout << "Map.at('m') = " << Map.at('m') << "\n\n";
    
    auto it2 = Map.insert({'e',"elicpse"});
    Insert(it2);

    auto it3 = Map.find('a');
    cout << "auto it3 = Map.find('a'),it3->first = " << it3->first << ", it3->second = "<< it3->second << endl;
    //auto it1 = Map.find('y');
    //cout << "auto it1 = Map.find('y'),it1->first = " << it1->first << ", it1->second = "<<it1->second << endl;
    
    cout << "Map.count('a') = " << Map.count('a') << "\n\n";

    cout << "erase a:" << Map.erase('a') << "\n\n";
    return 0;
}
