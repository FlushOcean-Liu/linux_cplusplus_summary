#include <iostream>
#include <vector>

using namespace std;

/*
 * brief: vector 模板使用
 *
 * 成员函数：
 *     push_back() 添加元素,pop_back()删除元素 
 *     size()返回容器大小
 *     capacity()返回当前容器能容纳的元素
 *     empty()判断容器是否为空
 *     clear()清零 
 *
*/

int test_vector_int(void)
{

    vector<int> v_int;

    v_int.reserve(4);     /* reserve 预留空间，新元素没有构造，不能使用[]访问*/ 

    cout<<"[1]capacity is "<<v_int.capacity()
        <<" size is "<<v_int.size()<<endl;
    v_int = {1,2,5,0,-2}; /* c++11 赋值方式 */ 
    cout<<"[2]capacity is "<<v_int.capacity()
        <<" size is "<<v_int.size()<<endl;
    v_int.resize(10);    /* 分配100空间，不占用原有空*/
    cout<<"[3]capacity is "<<v_int.capacity()
        <<" size is "<<v_int.size()<<endl;

    /* 使用iterator遍历容器元素 */ 
    cout<<"[4]all element is:";
    for(vector<int>::iterator it=v_int.begin();it!=v_int.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    /* 使用auto遍历容器元素 */ 
    cout<<"[5]use auto print element:";
    for(auto ch:v_int) {    
        cout<<ch<<" ";
    }
    cout<<endl;
    cout<<"front is "<<v_int.front()
        <<" back is "<<v_int.back()
        <<" 下标2的元素"<<v_int.at(2)<<endl;

    v_int.pop_back();
    v_int.push_back(19);
    for(int i=0;i<v_int.size();++i){
        cout<<v_int[i]<<" ";
    }

    cout<<endl;

    return 0;
}


int main()
{
    test_vector_int();

    return 0;
}

