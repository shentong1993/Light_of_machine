/*#include "shopping.h"
#include "windows.h"
#include <ctime>


//for    thing  ---------------------------------------------------------------------------------------
const string& thing::name_val() const
{
	return name;
}

const string& thing::introduction_val() const 
{
	return introduction;
}

const int& thing::value_val() const
{
	return value;
}


void thing::add_mount()
{
	++number;
}

//for    food  ---------------------------------------------------------------------------------------
int food::recover_val()
{
	return recover;
}

void food::use( thing* t)
{
	int n;
	n = a->blood + t->recover_val();
	if( n <= a->total_blood )
		a->blood = n;
	else 
		a->blood = a->total_blood;
	system("cls");
	cout << "\n\n\n\n\n\n\t\t使用了" << t->name_val() << " , 能量恢复" << t->recover_val() <<endl;
	Sleep(1500);
}*/