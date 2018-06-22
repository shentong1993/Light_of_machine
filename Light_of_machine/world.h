#pragma once
#pragma warning(disable : 4786)
#include <string>
#include <vector>
#include<iostream>
#include "shopping.h"
using namespace std;

class robot;
class monster;
class life;
class thing;
class boss;
class strong;
class continu;
void fight( life& , life& );



class skill{
protected:
	string name ;
	string introduction ;
	int happen, value ,number ;            // number for shop in the skil_shop
public:
	friend class life;
	friend int percenter(int,int);
	
	skill(){}
	skill(const string& n, const string& i, int v,int h):                               // name , introduction ,value, happen
	   name(n), introduction(i) ,value(v) ,happen(h) ,number(1) {}
	   
	   const string& name_val() const;                                              // *this指针 也是const 
	   const string& introduction_val() const ;
	   const int& value_val() const;
	   int happen_val() { return happen; }
	   int decrease_number();                                                   // if the shop has this skill , return 1
	   virtual void super(life & , life & )   {}
	   
    friend ostream& operator<< ( ostream& os , const skill& s)         //1、写的时候，string的内容可以用c_str函数取得；
                                                                      //2、读的时候，先读到一个char[]的缓冲，然后再转换为string类型即可。
	{
		const char* b1 =  s.name.c_str();
        os.write( b1 , sizeof(b1));
		os <<"\n";
		const char* b2 =  s.introduction.c_str();
		os.write( b2 , sizeof(b2));
		os <<"\n";
	//	os << s.name.c_str() <<endl;
	//	os << s.introduction <<endl;
		os << s.happen << "\n" << s.value << "\n" << s.number ;
		return os;
	}

};


class strong :public skill{
public:
	strong(const string& n, const string& i, int v ,int h, int hi): skill(n , i ,v ,h), higher(hi) {}
    void super(life & , life & );

	friend istream& operator>> ( istream& in, strong& s)
	{
		in >> s.name >> s.introduction >> s.happen  >> s.value >> s.number >> s.higher ;
		return in;
	}

    friend ostream& operator<< ( ostream& os , const strong& s)
	{
		os << s.name <<endl;
		os << s.introduction <<endl;
		os << s.happen << "\n" << s.value << "\n" << s.number << "\n" << s.higher <<endl;
		return os;
	}

private:
	int higher;
};


/***************************************
        attack many times
	 ****************************************/
class continu :public skill{
public:
	continu(const string& n, const string& i,  int v ,int h , int t ): skill(n , i ,v ,h), times(t)  {} 
    void super(life & , life & ); 

    friend istream& operator>> ( istream& in, continu& s)
	{
		in >> s.name >> s.introduction >> s.happen  >> s.value >> s.number >> s.times ;
		return in;
	}
	
	friend ostream& operator<< ( ostream& os, const continu& s)
	{
		os << s.name <<endl;
		os << s.introduction <<endl;
		os << s.happen << "\n" << s.value << "\n" << s.number << "\n" << s.times <<endl;
		return os;
	}
		
private:
	int times;
};


/***************************************
         ignore the monster's defend
	 ****************************************/
class puncture :public skill{
public:
	puncture(const string& n, const string& i,  int v ,int h ): skill(n , i ,v ,h)  {} 
    void super(life & , life & ); 
};


/***************************************
        recover in the battle
	 ****************************************/
class enrich :public skill{
public:
	enrich(const string& n, const string& i,  int v ,int h ,int p): skill(n , i ,v ,h) ,percent(p) {} 
    void super(life & , life & );
private:
	int percent;
};



class life{
protected:                                                // 不是private  
	string name;
	int attack , deffend , speed , blood ,total_blood , money , stage;
	vector<skill*> sk;
public:
	friend class robot;
    friend class monster;
	friend class boss;
	friend class food;
	friend void fight( life& , life& );
	friend void level_up( life &);                        //level :attack , deffend , speed , blood or name 
    friend class skill;
	friend void strong::super(life &, life &);
	friend void continu::super(life &a, life &b );
	friend void puncture::super(life &, life &);
	friend void enrich::super(life &a, life &b );
	friend void current(life& , life& );  
	
	life() {}                                               //***************************************
	life(int a, int d , int s, int b ,int m, int st ,const char* n):         
	attack(a) , deffend(d) , speed(s) , blood(b) , money(m), stage(st) ,name(n), total_blood(b)  {}
	
    bool alive(const life&) ;
	int& money_val();	
	int super_test (life& , life& );                     //test whether super skill can happen 
	life& learn(skill& );
    
	virtual void current( life& ) =0;               // show the robot and monster current blood
	virtual void atk(life& ) =0;                          //    robot . atk (monster)
    virtual void add_mount(life &) {}                     //    a .  add experiment from b
	//virtual  int mount_val() { return 0;}
    virtual int exper_val() {return 0;}              // robot and monster can both level up , so the both can get experiment from each other 
    virtual void information ( ) {}
	virtual void treasure () {}                     // if you win you can got treasure from the boss 
	virtual void level_stage() {}                    // win the boss ,you can got the boss 's stage
	virtual int drop_money(life & ) { return 0; }             // for monster and boss drop money for you   
};



class robot : public life{
public:
	//friend void quatum::display();
	friend class skill;
	friend class space;                                            //************************************************
	friend class food;
	friend class boss;
    friend class save;
	friend class remeber;
	
	robot() {}
	robot(int a, int d , int s ,int b ,int m,  const char* n )
		:life(a , d , s , b, m ,0 , n) , mount(10), current_mount(0) ,level(1) {}                 //开始有100钱
	
	void current( life& ) ;  
	void atk(life& );
	void add_mount(life &);
	void level_up();
	void stronger();
	
    int stage_val();    
	int level_val();                                
	//int exper_val();                                           // boss can level up by this
    void information ( );
    void change_skill();                                    // show the skill that not use
	void got(thing* );
	void add_enermy(int);
	
private:                        
	int  mount, current_mount , level ;                               // kill monster get the mount the level up
	vector<thing*> bag;                                                  // kill boss to get the stage up
};



class monster : public life{
public:
	monster (){}
	monster	(int a, int d , int s ,int b ,int m, int st ,const char* n , int e):
	life(a , d , s , b, m , st ,n) , exper(e)  {}
	
    void current( life& ) ;  
	void atk(life& );
    int exper_val();
	int drop_money( life& );
	
protected:
	int exper;                                     // killer get from the monster  
};


class boss : public monster{
public:
	boss() {}
	boss(int a, int d , int s ,int b ,int m, int st , const char* n , int e,  int p , robot* a1):
	monster(a , d , s , b, m, st ,n, e),  percent(p), a(a1) {}

	void treasure ();           
	boss& add_treasure(skill& );                          // add the skill that you may got
	void level_stage();
	int drop_money( life& );
	
private:
	skill* drop;
	int percent ;
    robot* a;
};





class thing{
public:
	 friend class save;
	//thing() {}
	thing( const string& n, const string& i, int v ,int num )               // robot* a1 ,
		:value(v), name(n) , introduction(i) ,  number(num) {}             // a(a1) ,
	
	const string& name_val() const;                                              // *this指针 也是const 
	const string& introduction_val() const ;
	const int& value_val() const; 
	const int& number_val() const;
	void add_mount();
	virtual void minus_mount() {}
	virtual int recover_val() { return 0; }
    virtual void use( thing* ) {}
    
protected:
	int value;
	int number ;
	string name ;
	string introduction ;	
};

class food : public thing{
public:
//	food() {}
	food(const string& n, const string& i, int v ,int num ,int r, robot* a1)
		: thing( n, i, v ,num ),  recover(r), a(a1) {}
	
	void use( thing* );
	int recover_val();
	void minus_mount();
private:
	int recover;
	robot* a; 
};




