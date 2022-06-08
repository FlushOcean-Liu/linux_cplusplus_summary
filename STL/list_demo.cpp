#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <string>

using namespace std;

/*
 * list将元素按顺序存储在链表中，与向量vector相比，它允许快速的插入和删除，但是随机访问比较慢； 
*/

/*
assign()          给list赋值 
back()            返回最后一个元素 
begin()           返回指向第一个元素的迭代器 
clear()           删除所有元素 
empty()           如果list是空的则返回true 
end()             返回末尾的迭代器 
erase()           删除一个元素 
front()           返回第一个元素 
get_allocator()   返回list的配置器 
insert()          插入一个元素到list中 
max_size()        返回list能容纳的最大元素数量 
merge()           合并两个list 
pop_back()        删除最后一个元素 
pop_front()       删除第一个元素 
push_back()       在list的末尾添加一个元素 
push_front()      在list的头部添加一个元素 
rbegin()          返回指向第一个元素的逆向迭代器 
remove()          从list删除元素 
remove_if()       按指定条件删除元素 
rend()            指向list末尾的逆向迭代器 
resize()          改变list的大小 
reverse()         把list的元素倒转 
size()            返回list中的元素个数 
sort()            给list排序 
splice()          合并两个list 
swap()            交换两个list 
unique()          删除list中重复的元素
*/ 



template<class Type>
void Display(list<Type>& vr)
{
    copy(vr.begin(), vr.end(), ostream_iterator<Type>(cout," "));
    cout << endl;
}


void DisplayByFor(list<int>& mylist)
{
    for(auto &x:mylist)
        std::cout<<x<<" ";
    cout << endl;
}

void test_list_emplace()
{
    std::list<std::pair<int, char> > mylist;
    mylist.emplace_front(10, 'a');
    mylist.emplace_front(20, 'b'); 
    mylist.emplace_front(30, 'c');
    
    
    std::cout << "[emplace]mylist contains1:";
    for(auto& x:mylist)
        std::cout << " (" << x.first << ","<<x.second <<")";
    
    std::cout<<std::endl;
    
    mylist.emplace(mylist.begin(), 100, 'x');
    mylist.emplace(mylist.end(), 200, 'y');
    std::cout << "[emplace]mylist contains2:";
    for(auto& x:mylist)
        std::cout << " ("<<x.first<<","<<x.second<<")";
    
    std::cout << std::endl;
     
}

void test_list_erase()
{
    std::list<int> mylist;
    std::list<int>::iterator it1,it2;
    
    for(int i=1;i<10; ++i)
        mylist.push_back(i*10);
    it1=it2=mylist.begin();
    advance(it2,6);
    ++it1;
    
    it1=mylist.erase(it1);
    it2=mylist.erase(it2);
    mylist.erase(it1, it2);
    
    std::cout<<"[erase]mylist contains:";
    Display(mylist);
    
}

void test_list_splice()
{
    std::list<int> mylist1, mylist2;
    std::list<int>::iterator it;
    
    for(int i=1;i<=4;i++){
        mylist1.push_back(i*10);
    }
    
    for(int i=1;i<=3;++i){
        mylist2.push_back(i);
    }
    
    it =  mylist1.begin();
    ++it;
    mylist1.splice(it, mylist2);
    
    mylist2.splice(mylist2.begin(), mylist1, it);
    
    it = mylist1.begin();
    std::advance(it, 3);
    
    mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
    
    std::cout << "[splice]mylist1 contains:";
    Display(mylist1);
    std::cout << "[splice]mylist2 contains:";
    Display(mylist2);
    
}

bool single_digit(const int& value)
{
    return (value<10);
}

struct is_odd{
    bool operator()(const int& value)
    {
        return (value%2)==1;
    }
};

void test_list_remove()
{
    int myints[]={15,36,7,17,20,39,4,1,89};
    std::list<int> mylist(myints, myints+9);
    mylist.remove(89);
    mylist.remove_if(single_digit);
    mylist.remove_if(is_odd());
    
    std::cout<<"[remove]mylist contains:";
    Display(mylist);
}

bool mycomparison(double first, double second)
{
    return (int(first)<int(second));
}

void test_list_merge()
{
    std::list<double> first, second;
    first.push_back(3.1);
    first.push_back(2.2);
    first.push_back(2.9);
    second.push_back(3.7);
    second.push_back(7.1);
    second.push_back(1.4);
    
    first.sort();
    second.sort();
    first.merge(second);
    first.merge(second);
    
    second.push_back(2.1);
    first.merge(second, mycomparison);
    std::cout<<"[merge]first contains:";
    
    Display(first);
}

bool same_integral_part(double first, double second)
{
    return (int(first)==int(second));   
} 

struct is_near
{
    bool operator()(double first, double second)
    {
        return (fabs(first-second)<5.0);
    } 
};

void test_list_unique()
{
    double mydoubles[] = { 12.15,  2.72, 73.0,  12.77,  3.14,
                           12.77, 73.35, 72.25, 15.3,  72.25 };
    std::list<double> mylist(mydoubles, mydoubles+10);
    mylist.sort();
    
    mylist.unique();
    
    mylist.unique();
    
    mylist.unique(same_integral_part);
    mylist.unique(is_near());
    
    std::cout<<"[unique]mylist conatins:";
    Display(mylist);
    
}


void test_list_reverse()
{
    std::list<int> mylist;
    for (int i = 1; i < 10; ++i) mylist.push_back(i);
    mylist.reverse();
    Display(mylist);
}
// comparison, not case sensitive.
bool compare_nocase(const std::string& first, const std::string& second)
{
    unsigned int i = 0;
    while ((i < first.length()) && (i < second.length()))
    {
        if (tolower(first[i]) < tolower(second[i])) return true;
        else if (tolower(first[i]) > tolower(second[i])) return false;
        ++i;
    }
    return (first.length() < second.length());
}
void test_list_sort()
{
    std::list<std::string> mylist;
    std::list<std::string>::iterator it;
    mylist.push_back("one");
    mylist.push_back("two");
    mylist.push_back("Three");
    mylist.sort();

    std::cout << "[sort]mylist contains:";
    Display(mylist);
    mylist.sort(compare_nocase);
    std::cout << "[sort]mylist contains:";
    Display(mylist);
}
void test_list_assign()
{
    std::list<int> first;
    std::list<int> second;
    first.assign(7, 100);                      // 7 ints with value 100
    second.assign(first.begin(), first.end()); // a copy of first
    int myints[] = { 1776,7,4 };
    first.assign(myints, myints + 3);            // assigning from array
    std::cout << "[assign]Size of first: " << int(first.size()) << '\n';
    std::cout << "[assign]Size of second: " << int(second.size()) << '\n';
}

int main()
{
    test_list_emplace();
    test_list_erase();
    test_list_splice();
    test_list_remove();
    test_list_merge();
    test_list_unique();
    test_list_reverse();
    test_list_sort();
    test_list_assign();

    return 0;
}



