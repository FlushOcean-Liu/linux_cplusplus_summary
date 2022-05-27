# C++ static知识点

## 1.类的静态成员

``` c++
class A
{
private:
    static int s_value
};
```

在c++中必须对其进行初始化：  

``` c++
int A::s_value = 0; /* 注意此处无static修饰 */
```
特点：  
* 1）类的静态成员时该类所有实例的共有成员，可以理解为名为A::s_value的全局变量；
* 2）类的静态成员必须初始化，类中只是声明，在文件中才是初始化。
