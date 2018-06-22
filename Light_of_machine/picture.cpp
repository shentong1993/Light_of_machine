#include "picture.h"
#include "windows.h"
#include "world.h"
#include <ctime>
using namespace std;


void see::show()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=false;
	SetConsoleCursorInfo(hOut,&cci);
	
	//system("color F0");
	int i ,j ;
	for(i=0 ; i< vertical ; i++)
		cout << " \n " ;
	
	for(i=0 ; i< txt.size() ; i++ ){
		for(j=0 ; j< horiz ; j++)
			cout << " \t ";	
		cout << txt[i] <<endl;
	}
}


/*for normal --------------------------------------------------------------------------
key point:  map<char ,see*> if 
see point to a picture ,goto it
else     it is a function() 
*/
void normal::display()
{
	system("cls");
	show();
	char k  , test(0);
	k=getch();
	for(map<char , see*>::iterator i= dp.begin(); i!= dp.end() ; i++ ){
		if( k== i->first ){
			test = 1;
			if ( i->second )
				focus( i->second );
			else{
				if(k=='1'){
					system("cls");
					a->information ();
					while( k=getch() ){                   //quit the function(), return this picture    
						if(k=='q')
							focus( this );
					}
				}
				else if(k=='2'){                          
					int num ,r;
					num = little_m.size();
					srand( (unsigned)time( NULL ) );
					r=( rand() % 4 ) ;
                    fight(*a, little_m[r] ); 
					focus( this );
				}
				else if(k=='3'){
					fight(*a,*b);
					focus( this );
				}
				else if(k=='4'){
					a->change_skill();
					focus( this );
				}
				else if(k=='i'){                                //check the states in the  map , return this picture
					system("cls");
					a->information ();
					while( k=getch() ){                       
						if(k=='q')
							focus( this );
					}
				}
				
			}
		}
	}
	if( !test )
		focus( this );
} 


normal& normal::add_button( pair<char , see*>& b)
{
	dp.insert(b);
	return *this;
}

normal& normal::add_monster(const monster& m)
{
	little_m.push_back(m);
	return *this;
}

//for quatum --------------------------------------------------------------------------
quatum& quatum::add_button( pair<char , see*>& b)
{
	dp.insert(b);
	return *this;
}

quatum& quatum::add_picture( pair<int , see*>& b)
{
	qp.insert(b);
	return *this;
}


void quatum::display()
{
	system("cls");
	int l = a->stage_val() ,i3 , lc ;                                //*************************************
	lc= l+1;
	for( map<int , see*>::iterator i1= qp.begin(); i1 != qp.end() ; i1++){
		if ( l== i1->first )
			i1->second->show();
	}
	char b;
	while ( b= getch() ){                    
		i3=0;
		for(map<char , see*>::iterator i2= dp.begin();  i3 < lc ; i2++ ){
			i3++;
			if( b== i2->first )
				focus( i2->second);
		}
		break;
	}
	focus( this );
}


//for movie --------------------------------------------------------------------------
movie& movie::add_frame( see* s )
{
	mp.push_back(s);
	return *this;
}

void movie::display()
{
	int all;
	system("cls");
	//all =( (a->stage_val()) +1 ) * 3;                       //***********************************************************
	all = 2;
	vector<see*>::iterator i;
	while( all>=0 ){
		for( i= mp.begin(); i != mp.end()-1; i++){
			(*i)->show();
			all -= 1;                                //  all -=  ufo_speed
			Sleep(1000);                             //**********************************************************
			system("cls");
		}
	}
    system("cls");
    focus( mp.back() );
}

//for shop --------------------------------------------------------------------------
shop& shop::add_button( pair<char , see*>& b)
{
	dp.insert(b);
	return *this;
}

shop& shop::add_thing(pair<char ,thing* >& t)
{
	commodity.insert(t);
	return *this;
}

void shop::display()
{
	system("cls");
	int n(1) , afford;                                            
	char k;
	cout << "\n\n\n\n";
	for(map<char ,thing* >::iterator i = commodity.begin(); i!= commodity.end(); i++){
		cout << "\t\t\t" << n <<" "<<i->second->name_val() <<" : " << i->second->value_val() <<"钱\n"
			<<  "\t\t\t" << "  :"<< i->second->introduction_val() << "\n\n";
		n++;
	}
	k= getch();
	for(i = commodity.begin(); i!= commodity.end(); i++ )  
		if(i->first == k){
			afford = a->money_val() - i->second->value_val();                            //**************************************
			if( afford >= 0 ){
				a->got( i->second );
				system("cls");
				cout <<"\n\n\n\n\t\t\t购买成功！"<<endl;
				Sleep(700);
				focus(this);
			}
			else {
				system("cls");
				cout <<"\n\n\n\n\n\n\t\t金钱不是万能的，但是你没带够钱是万万不行的！\n";
				Sleep(1500);
				focus(this);
			}
		}
		for(map<char , see*>::iterator i2= dp.begin(); i2!= dp.end() ; i2++ ){
			if(i2->first == k)
				focus(i2->second);
		}
		focus(this);
}


//for space --------------------------------------------------------------------------
space& space::add_button( pair<char , see*>& b)
{
	dp.insert(b);
	return *this;
}

void space::display()
{
	int c(1) , num , k2;                  //num : 按 '1' -> int = 1
	char k;
	thing* t;
	vector< thing* >::iterator i;
	
	if( !a->bag.empty() ){
		system("cls");
		cout <<"\n\n";
		for( i = a->bag.begin(); i!= a->bag.end(); i++){
			cout << "\n\n\t物品"<< c <<"  " <<(*i)->name_val() << " *"<< (*i)->number_val()
				<<" :"<<  (*i)->introduction_val() <<endl;
			c++;
		}
		k = getch();
		num = a->bag.size();      
		k2 = k -48; 
		
		if( k2 >= 1 && k2 <= num ){
			t = *( a->bag.begin() +k2 -1 );
			if( t->number_val() > 1 ){
				t->minus_mount();
				t->use( t); 
				focus( this );
			}
			else if( t->number_val()==1 ){
				t->use( t);
				a->bag.erase( a->bag.begin() +k2 -1  );               //删除数量为0的物品
				focus( this );
			}
		}
		for(map<char , see*>::iterator i2 =dp.begin(); i2 != dp.end() ; i2++ ){
			if( k == i2->first )
				focus( i2-> second);
		}
		focus(this);	
	}
	else{
		system("cls");
		cout << "\n\n\n\n\n\n\n\t\t\t\t没有物品！"<<endl;
		k = getch();
		for(map<char , see*>::iterator i2 =dp.begin(); i2 != dp.end() ; i2++ ){
			if( k == i2->first )
				focus( i2-> second);
			focus(this);
		}
		
	}
	
}

//for skill_shop --------------------------------------------------------------------------


skill_shop& skill_shop::add_skill( pair<char , skill*>&  s)
{
	ss.insert(s);
	return *this;
}


skill_shop& skill_shop::add_button( pair<char , see*>& b)
{
	dp.insert(b);
	return *this;
}


void skill_shop::display()
{
	int n(1) , afford;
	char k;
	map<char , skill*>::iterator i;
	
	system("cls");
	cout <<"\n\n\n\n\n\t\t\t 欢迎来到技能商店！";
	Sleep(1200);
	system("cls");
	cout << "\n\n\n\n\n";
	if( ss.empty() ){
		cout <<"\n\n\n\n\n\t\t\t 商品都卖光了！";
	}
	else{
		for( i= ss.begin() ; i != ss.end(); i++)
			cout << "\t\t\t" << i->first <<" "<< i->second->name_val() <<" : " 
			<< i->second->value_val() << "钱\n\n";
	}
	
	k= getch();
	
	for(i = ss.begin(); i!= ss.end(); i++ )  
		if(i->first == k){
			afford = a->money_val() - i->second->value_val();                            //**************************************
			if( afford >= 0 ){
				a->learn( *(i->second) );
				system("cls");
				cout <<"\n\n\n\n\t\t\t购买成功！"<<endl;
				a->money_val() -= i->second-> value_val() ;                                                      //**************************************     
				
				if(  !(i->second->decrease_number())  ){                               	// remove the skill that  its num is 0
					ss.erase( i );
				}
				
				Sleep(700);
				focus(this);
			}
			else {
				system("cls");
				cout <<"\n\n\n\n\n\n\t\t金钱不是万能的，但是你没带够钱是万万不行的！\n";
				Sleep(1500);
				focus(this);
			}
		}
		for(map<char , see*>::iterator i2= dp.begin(); i2!= dp.end() ; i2++ ){
			if(i2->first == k)
				focus(i2->second);
		}
		focus(this);
}


//for chat  --------------------------------------------------------------------------

chat& chat::add_information( pair<int , char*>& p)
{
	inform.insert(p);
	return *this;
}

chat& chat::add_button( pair<char , see*>& b)
{
	dp.insert(b);
	return *this;
}

void chat::display()                                            //the first button must be back  
{
	int r , n , l;
	char k;
	map< int , char* >::iterator i;
	map<char , see* >::iterator i2;
	
	system("cls");
	n = inform.size() ;
	
	srand( (unsigned)time( NULL ) );
	r = rand() % n;
	i = inform.begin() ;
	
	for ( l=0; l < r ; l++)
		i++;
	
	cout << "\n\n\n\n\n\n\n\t\t" << i->second  <<endl;
	//	Sleep(2000);
	
	k= getch();
	for( i2 = dp.begin() ; i2 != dp.end() ; i2++){
		if( k == i2->first )
			focus ( i2->second );
	}
	i2 = dp.begin();
	focus( i2->second );
}


//for smart  --------------------------------------------------------------------------

smart& smart::add_chat( pair<int , see* > &p)
{
	dp.insert(p);
	return *this;
}

void smart::display()
{
	int s , m;
	system("cls");
	s = a->stage_val();
	m = a->money_val() /20 ;
    a->money_val() -= m; 
	cout << "\n\n\n\n\n\n\n\t\t\t看智能消息，花掉 "<< m <<"钱";//****************************
	Sleep(1700);
	for (map<int , see* >::iterator i = dp.begin(); i != dp.end() ; i++ ){
		if ( s == i->first )
			focus( i->second);
	}
	
}



//for save  --------------------------------------------------------------------------

save& save::add_button( see* s)
{
	dp.push_back(s);
	return *this;
}


void save::display()
{
	system("cls");
	vector<int> n;
	for( vector<skill*>::iterator i2= a->sk.begin(); i2 != a->sk.end(); i2++ ){
		a->money += (*i2)->value_val();
	}
	
	for( vector<thing*>::iterator i3 =a->bag.begin(); i3 != a->bag.end() ; i3++ )
	{
		a->money += (*i3)->value_val(); 
	}
	
	n.push_back( a->attack );
	n.push_back( a->deffend);
	n.push_back( a->speed);
	n.push_back( 0 );                                              //this will delete but your record will wrong  so... keep it
	n.push_back( a->blood);
	n.push_back( a->total_blood);
	n.push_back( a->money);
	n.push_back( a->current_mount);
	n.push_back( a->mount);
	n.push_back( a->level);
	n.push_back( a->stage);
	
	ofstream out("c:\\game1.bin");
	for( vector<int>::iterator i = n.begin(); i!= n.end(); i++){
		out << *i <<endl;
	}
	
	
	for(  i2= a->sk.begin(); i2 != a->sk.end(); i2++ ){
		a->money -= (*i2)->value_val();
	}
	for( i3 =a->bag.begin(); i3 != a->bag.end() ; i3++ ){
		a->money += (*i3)->value_val(); 
	}
	out.close();
	
	/*
	vector<skill> bag;
    ofstream out2("c:\\game2.txt");             //**********************************   哎  太难了
	for( vector<skill*>::iterator i2 = a->sk.begin() ; i2 != a->sk.end(); i2++){
	bag.push_back( *(*i2) );
	}
	for (int i3= 0; i3  < bag.size(); i3++)
	out2 << bag[i3] <<endl; */
	
	
	/*	for( vector<skill>::iterator i3 = bag.begin() ; i3 != bag.end(); i3++){
	out2 <<  *i3  <<endl ; 
}*/
	
	
	cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t保存成功！";
	Sleep(1500);
	focus( dp.front() );
}




//for remeber  --------------------------------------------------------------------------
remeber& remeber::add_button(  see* s)
{
	dp.push_back(s);
	return *this;
}

void remeber::display()
{
	vector<int> v;
	int null;
	
	ifstream in("c:\\game1.bin");
	if( !in ){
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t没有存档！";
		Sleep(1500);
		focus( dp.back() );
	}
	for(int i; in>>i ;  )
		v.push_back( i);
	
	a->attack = v[0];
	a->deffend = v[1];
	a->speed = v[2];
	null = v[3];
	a->blood = v[4];
	a->total_blood = v[5];
	a->money = v[6];
	a->current_mount = v[7];
	a->mount = v[8];
	a->level = v[9];
	a->stage = v[10];
	
	
	
	focus( dp.front() );
}








/*

  vector<skill> bag;
  for( vector<skill*>::iterator i2 = a->sk.begin() ; i2 != a->sk.end(); i2++){
		bag.push_back( *(*i2) );
		}
		
		  ofstream out2("c:\\game2.bin");
		  for( vector<skill>::iterator i3 = bag.begin() ; i3 != bag.end(); i3++){
		  out2.write( (char *)( &(*i3) ), sizeof(*i3)  );
		  }
		  
			
			  
				
				  ifstream in2("c:\\game2.bin");
				  vector<skill> bag;
				  for( vector<skill>::iterator i3 = bag.begin() ; i3 != bag.end(); i3++){
				  in2.read( (char *)( &(*i3) ), sizeof(*i3)  );
				  a->sk.push_back( &(*i3) );
				  }
				  
*/