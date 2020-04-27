#include <string>
#include <iostream>

using namespace std;

/*³éÏóÉÏÒÂÀà*/
class Coat
{
public:
	virtual const string& color() = 0;
};


/*ºÚÉ«ÉÏÒÂÀà*/ 
class BlackCoat : public Coat
{
public:
	BlackCoat():Coat(),m_strColor("Black Coat")
	{
	}
	
	const string& color() override
	{
		cout<<m_strColor.data()<<endl;
		return m_strColor;
	}
private:
	string m_strColor;
};



/*°×É«ÉÏÒÂÀà*/
class WhiteCoat:public Coat
{
public:
	WhiteCoat():Coat(),m_strColor("White Coat")
	{
	}
	
	const string& color() override
	{
		cout<<m_strColor.data()<<endl;
		return m_strColor;
	}
	
private:
	string m_strColor;
	
};



/*³éÏó¿ã×ÓÀà*/
class Pants
{
public:
	virtual const string& color()=0;
};

/*ºÚÉ«¿ã×ÓÀà*/
class BlackPants:public Pants
{
public:
	BlackPants():Pants(),m_strColor("Black Pants")
	{
	}
	const string &color() override
	{
		cout <<m_strColor.data()<<endl;
		return m_strColor;
	}

private:
	string m_strColor;
};


/* °×É«¿ã×ÓÀà */
class WhitePants:public Pants
{
public:
	WhitePants():Pants(),m_strColor("White Pants")
	{
		
	}
	
	const string& color() override
	{
		cout<<m_strColor.data()<<endl;
		return m_strColor;
	}

private:
	string m_strColor;

} ;

/*³éÏó¹¤³§Àà£¬Ìá¹©ÒÂ·þ´´½¨½Ó¿Ú*/
class Factory
{
public:
	virtual Coat* createCoat()=0;
	virtual Pants* createPants()=0;
 } ;
 
class WhiteFactory:public Factory
{
public:
	Coat* createCoat() override
	{
		return new WhiteCoat();
	}
	
	Pants* createPants() override
	{
		return new WhitePants();
	}
};

class BlackFactory:public Factory
{
public:
	Coat* createCoat() override
	{
		return new BlackCoat();
	}
	
	Pants* createPants() override
	{
		return new BlackPants();
	}
};
 	

int main()
{
	WhiteFactory* whiteData= new WhiteFactory();
	BlackFactory* BlackData= new BlackFactory();
	
	Coat* whiteCoat=whiteData->createCoat();
	whiteCoat->color(); 
	Pants* whitePants=whiteData->createPants();
	whitePants->color();
	
	Coat* blackCoat=whiteData->createCoat();
	blackCoat->color();
	Pants* blackPants=whiteData->createPants();
	blackPants->color();


	return 0;	
}



