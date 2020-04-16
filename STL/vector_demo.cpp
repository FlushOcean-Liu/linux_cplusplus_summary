#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a;
	a.reserve(4);
	cout<<"capacity is "<<a.capacity()<<endl;
	a = {1,2,5,0,-2};
	cout<<"capacity is "<< a.capacity()<<endl;
	
	for(vector<int>::iterator it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	for(auto ch:a) {
		
		cout<<ch<<" ";
	}
	cout<<endl;
	cout<<"front is "<<a.front()<<" back is "<<a.back()<<" ÏÂ±ê2µÄÔªËØ"<<a.at(2)<<endl;
	
	a.pop_back();
	a.push_back(19);
	for(int i=0;i<a.size();++i){
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	
	return 0;
}
