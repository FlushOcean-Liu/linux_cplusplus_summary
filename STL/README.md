# 容器应用说明

## vector

1）emplace_back() 与 push_back() 区别
功能相同，都是向vector变量尾部添加一个元素；  

push_back()向容器添加元素时，先调用构造函数创建元素，再调用拷贝或移动函数将前面创建元素复制到vector尾部，最后销毁开始创建的元素；  
emplace_back()则是直接在vector尾部调用构造函数创建这个元素。

