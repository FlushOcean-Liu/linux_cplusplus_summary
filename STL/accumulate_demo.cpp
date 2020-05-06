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
    }
    
    long sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum of values == "<< sum<<endl;
    
    long product = accumulate(v.begin(), v.end(), 0);
    cout<<"Product of values == "<<product<<endl;
    
    return 0;
}
