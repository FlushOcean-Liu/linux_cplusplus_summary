/*
 * vector 模板使用
 *成员函数：
 *push_back() 添加元素,pop_back()删除元素 
 *size()返回容器大小
 *capacity()返回当前容器能容纳的元素
 *empty()判断容器是否为空
 *clear()清零 

*/ 

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a;
	a.reserve(4);     /* reserve 预留空间，新元素没有构造，不能使用[]访问*/ 
	cout<<"[1]capacity is "<<a.capacity()<<" size is "<<a.size()<<endl;
	a = {1,2,5,0,-2}; /* c++11 赋值方式 */ 
	cout<<"[2]capacity is "<<a.capacity()<<" size is "<<a.size()<<endl;
	a.resize(10);    /* 分配100空间，不占用原有空*/
	cout<<"[3]capacity is "<<a.capacity()<<" size is "<<a.size()<<endl;
	
	/* 使用iterator遍历容器元素 */ 
	for(vector<int>::iterator it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	
	/* 使用auto遍历容器元素 */ 
	for(auto ch:a) {	
		cout<<ch<<" ";
	}
	cout<<endl;
	cout<<"front is "<<a.front()<<" back is "<<a.back()<<" 下标2的元素"<<a.at(2)<<endl;
	
	a.pop_back();
	a.push_back(19);
	for(int i=0;i<a.size();++i){
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	
	return 0;
}

