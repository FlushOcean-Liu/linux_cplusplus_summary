# 容器应用说明

## vector

**1）emplace_back() 与 push_back() 区别**

* 功能相同，都是向vector变量尾部添加一个元素；  
* push_back()向容器添加元素时，先调用构造函数创建元素，再调用拷贝或移动函数将前面创建元素复制到vector尾部，最后销毁开始创建的元素；  
* emplace_back()则是直接在vector尾部调用构造函数创建这个元素。  

由此可初步得出结论emplace_back要比push_back快。  

测试程序：  
```c
#include <iostream>
#include <vector>
#include <sys/time.h>
using namespace std;

#define MAX_NUM  1000*1000

int main()
{
    vector<int> myvector1;
    vector<int> myvector2;
    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int start=static_cast<int>(tv.tv_usec)/1000;
    int i;
    for(i=0;i<MAX_NUM;i++){
        myvector1.emplace_back(i);
    }
    gettimeofday(&tv, NULL);
    int end=static_cast<int>(tv.tv_usec)/1000;
    cout<<"emplace_back spend time: "<<end-start<<" ms"<<endl;


    gettimeofday(&tv, NULL);
    start=static_cast<int>(tv.tv_usec)/1000;
    for(i=0;i<MAX_NUM;i++){
        myvector2.push_back(i);
    }
    gettimeofday(&tv, NULL);
    end=static_cast<int>(tv.tv_usec)/1000;
    cout<<"push_back spend time: "<<end-start<<" ms"<<endl;
    
    return 0;	
}
```
运行结果：  
emplace_back spend time: 17 ms  
push_back spend time: 20 ms


