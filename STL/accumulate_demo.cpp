#include <iostream>
#include <numeric>
#include <vector> 
#include <functional>

using namespace std;

#define MAX 10
std::vector<long> v(MAX);
int main()
{
    int i;
    for(i=0; i<MAX; i++){
        v.push_back(i);
    }
    
    /* accumulate 对指定范围内元素进行求和 */   
    long sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum of values == "<< sum<<endl;
    
    for(i=0;i<MAX;i++){
	v.push_back(2*i);
    }

    long product = accumulate(v.begin(), v.end(), 0);
    cout<<"Product of values == "<<product<<endl;
    
    return 0;
}
