#include <iostream>

using namespace std;

class Hurt
{
public:
    virtual void blood()=0;
};

class AdcHurt:public Hurt
{
public:
    void blood() override
    {
        cout<<"Adc Hurt, Blood loss"<<endl;
    }
};

class ApcHurt:public Hurt
{
public:
    void blood() override
    {
        cout<<"Apc Hurt, Blood loss"<<endl;
    }
};


class Soldier
{
public:
    Soldier(Hurt* hurt):m_pHurt(hurt)
    {
    }
    
    void attack()
    {
        m_pHurt->blood();    
    }

private:
    Hurt* m_pHurt;
};

/*¶¨Òå²ßÂÔ±êÇ©*/
typedef enum
{
    Hurt_Type_Adc,
    Hurt_Type_Apc,
    Hurt_Type_Num
}HurtType;


/* »·¾³½ÇÉ«Àà£¬ ÓÎÏ·½ÇÉ«·¨Ê¦£¬´«ÈëÒ»¸ö²ßÂÔ±êÇ©²ÎÊý*/
class Mage
{
public:
    Mage(HurtType type)
    {
        switch(type){
        case Hurt_Type_Adc:
            m_pHurt=new AdcHurt();
            break;
        case Hurt_Type_Apc:
            m_pHurt=new ApcHurt();
            break;
        default:
            break;
        }
    }
    
    ~Mage()
    {
        delete m_pHurt;
        m_pHurt=nullptr;
        cout<<"~Mage()"<<endl;
    }
    
    void attach()
    {
        m_pHurt->blood();
    }

private:
    Hurt* m_pHurt;    
    
};

template<typename T>
class Archer
{
public:
    void attack()
    {
        m_hurt.blood();
    }
private:
    T m_hurt;
};

int main()
{
    Archer<ApcHurt>* arc=new Archer<ApcHurt>;
    arc->attack();
    
    delete arc;
    arc=nullptr;
    
    return 0;
}




