/*#pragma once
#include<string>
#include<iostream>
#include"conio.h"
#include "world.h"
using namespace std;


class thing{
public:
	thing() {};
	thing( const string& n, const string& i, int v ,int num=1 )               // robot* a1 ,
		:value(v), name(n) , introduction(i) ,  number(num) {}             // a(a1) ,
 
	const string& name_val() const;                                              // *this÷∏’Î “≤ «const 
	const string& introduction_val() const ;
	const int& value_val() const; 
	void add_mount();
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
	food() {};
	food(const string& n, const string& i, int v ,int r)
		: thing( n, i, v ),  recover(r) {}

	void use( thing* );
	int recover_val();
private:
	int recover;
	robot *a;
};


*/
/*
#pragma once
#include<string>
//#include<iostream>
#include"world.h"
using namespace std;*/