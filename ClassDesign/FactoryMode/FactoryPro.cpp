/*
工厂方法模式：
    定义一个创建对象的接口，其子类去实现这个接口以完成具体的创建工作，
    如果需要增加新的产品类，只需要扩展一个相应的工厂类即可。 
    
    缺点：
    产品类数据较多时，需要实现大量的工厂类，增加代码量 
*/ 

#include <iostream>

using namespace std;

class Tank
{
public:
    virtual const string& type() = 0;
 } ;
 
class Tank56:public Tank
{
public:
    Tank56():Tank(),m_strType("Tank56")
    {
    }
    
    const string& type() override
    {
        cout << m_strType.data()<<endl;
        return m_strType;
    }

private:
    string m_strType;
};


class Tank96:public Tank
{
public:
    Tank96():Tank(),m_strType("Tank96")
    {
    }   
    
    const string& type() override
    {
        cout << m_strType.data()<<endl;
        return m_strType;
    }
private:
    string m_strType;
};


class TankFactory
{
public:
    virtual Tank* createTank()=0;
};


class Tank56Factory:public TankFactory
{
public:
    Tank* createTank() override
    {
        return new Tank56();
    }
};

class Tank96Factory:public TankFactory
{
public:
    Tank* createTank() override
    {
        return new Tank96();
    }
};

int main()
{
    TankFactory* factory56= new Tank56Factory();
    Tank* tank56= factory56->createTank();
    tank56->type();
    
    TankFactory* factory96= new Tank96Factory();
    Tank* tank96= factory96->createTank();
    tank96->type();
    
    delete tank96;
    tank96=nullptr;
    delete factory96;
    factory96=nullptr;
    
    delete tank56;
    tank56=nullptr;
    delete factory56;
    factory56=nullptr;
    
    return 0;
}


