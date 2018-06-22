#pragma warning(disable : 4786)
#pragma once
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include <fstream>
#include"conio.h"
#include "world.h"
using namespace std;

class normal;

class see{
protected:
	int vertical, horiz , number ;                     //        (y, x)
	vector<string> txt;
public:
	friend class normal;

	see(){};
	see(int y , int x , char** p , int n ):                           //   char* init[] ={" ", " "}
	vertical(y) , horiz(x) , number(n) {
		int i;
		for (i=0 ; i< n ;i++)
			txt.push_back( p[i]);
	}
	void show();
    virtual void display() {}
};


class normal:public see{
public:
    normal( see& s, robot* a1, boss* b2):
	  see(s) , a(a1) ,b(b2) {}

	  void display();
	  normal& add_button( pair<char , see*>&);
	  normal& add_monster( const monster&);
private:
	map<char , see*> dp;                                               // for display normal picture
    vector<monster> little_m;                                          // for little monster  
	robot* a;              //***************************
	boss* b;
};


/****************************************************************************
  quatum : for one time ,there is a picture in many states ,and we only see
           one of them this time!
***************************************************************************/
class quatum :public see{
public:
	quatum(robot* a1): a(a1) {}

    quatum& add_button( pair<char , see*>&);
	quatum& add_picture( pair<int , see*>&);

	 void display();
private:
	map<int , see*> qp;
	map<char , see*> dp;
	robot* a;
};



class movie :public see{
public:
	movie(	robot* a1):a(a1) {}
	movie& add_frame( see* );
	 void display();
private:
	vector<see*> mp;
		robot* a;
	//int all , ufo_speed;                                    //**********************************以后加飞船   就有速度了
};

/***************************************
             for sale food can eat
	 ****************************************/
class shop : public see{
public:
	shop( robot* a1): a(a1)  {}
	
    shop& add_thing(pair<char ,thing* >& );
	shop& add_button( pair<char , see*>&);
	void display();
private:
	map<char ,thing* > commodity;                                     //things for sale
    map<char , see*> dp;                                               //for return 
		robot* a;
};



/***************************************
     for store the thing that you buy from the shop 
	 ****************************************/
class space :public see{
public:
	space( robot* a1): a(a1) {}

	space& add_button( pair<char , see*>&);
    void display();
private:
	map<char , see*> dp;
	robot* a;
};





/***************************************
      for store the skill that you  can buy from the skill_shop 
	 ****************************************/
class skill_shop : public see{
public:
	skill_shop( robot* a1): a(a1) {}
	skill_shop& add_skill(  pair<char , skill*>& );
    skill_shop& add_button( pair<char , see*>& );
	void display();
private:
	map<char , skill*> ss;
	map<char , see* >  dp;
	robot* a;
};




/***************************************
      map for the NPC to talk with you      from <1, char*>...
	 ****************************************/
class chat : public see{
public:
	chat() {}
	chat& add_information( pair<int , char*>& );
	chat& add_button( pair<char , see*>& );
	void display();
private:
	map<int , char*> inform;
	map<char , see* >  dp;
};


/***************************************
      this can according your appearing thing ,give you suggest!   <0, see*>   for moon
	 ****************************************/
class smart :public see{
public:
	smart(robot *a1): a(a1) {}
	smart& add_chat( pair<int , see* >& );
	void display();
private:
	map<int , see* > dp;
	robot *a;
};



/***************************************
      save the game 
	 ****************************************/
class save :public see{
public:
	save(robot *a1): a(a1) {}
	save& add_button(  see* );
	void display();
    
private:
	vector< see* >  dp;
	robot *a;
};



/***************************************
      remeber the game
	 ****************************************/
class remeber :public see{
public:
	remeber(robot *a1): a(a1) {}
	remeber& add_button(  see* );
	void display();
    
private:
	vector< see* >  dp;
	robot *a;
};





class focus{
public:
	focus() {}
	focus(see* s) : p(s) {
		p->display();
	}
private:
	see* p;
};
