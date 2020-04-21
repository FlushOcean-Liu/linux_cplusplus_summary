#include <set>
#include <iostream>

using namespace std;

/*
(name).insert() ²åÈëÔªËØµ½¼¯ºÏÖÐ 

(name).clear()  Çå³ý¼¯ºÏÀïËùÓÐÔªËØ 

(name).erase()  É¾³ý¼¯ºÏÔªËØ 

(name).find()   ²éÑ¯ÔªËØÊÇ·ñ´æÔÚ 

(name).count()  ·µ»ØÄ³¸öÔªËØ³öÏÖÁË¼¸´Î 

(name).empty()   ÅÐ¶ÏÔªËØÊÇ·ñÎª¿Õ 

(name).size()    ²éÑ¯¼¯ºÏÖÐÔªËØ×ÜÊý 

(name).(r)begin() ·µ»ØµÚÒ»¸öÖ¸ÏòÔªËØµÄµü´úÆ÷ 

(name).(r)end()    ·µ»Ø×îºóÒ»¸öÖ¸ÏòÔªËØµÄµü´úÆ÷ 

(name).lower_bound() ·µ»ØµÚÒ»¸öÐ¡ÓÚµÈÓÚ¸ø¶¨ÖµµÄµØÖ· 

(name).upper_bound() ·µ»ØµÄ¸ç´óÓÚ¸ø¶¨ÖµµÄµØÖ· 

*/

int main()
{
    int i;
    int arr[5]={0, 1, 2, 3, 4};
    set<int> iset(arr, arr+5);
    
    iset.insert(5);
    cout<<"size:"<<iset.size()<<endl;
    cout<<"2 count "<<iset.count(3)<<endl;
    
    iset.erase(1);
    
    set<int>::iterator ite1 = iset.begin();
    set<int>::iterator ite2 = iset.end();
    
    for(;ite1!=ite2;ite1++){
        cout<<*ite1<<" ";
    }
    cout<<endl;
    
    ite1 = iset.find(3);
    if(ite1!=iset.end())
        cout<<"3 found"<<endl;
        
    ite1 = iset.find(1);
    if(ite1!=iset.end())
        cout<<"1 found"<<endl;  
    else
        cout<<"1 not found"<<endl; 
    
    
    return 0;
}
