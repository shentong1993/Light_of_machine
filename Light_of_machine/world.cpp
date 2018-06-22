#include "world.h"
#include <windows.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include<algorithm> 
#include <iostream>
using namespace std;

int percenter(int i );
char* ics(int i , char* str);                                    //int -> string


//for      life----------------------------------------------------------------------------------------
bool life::alive(const life& a)
{
	if(a.blood > 0)
		return 1;
	else
		return 0;
}

int life::super_test (life& a, life& b)
{	
	int t=0 , n;                  // t for test whether the skill is happen : t==1 (skill happen)
	vector<skill*>::iterator i;
	n =  a.sk.size();
	if( n >= 2){
		for( i=a.sk.begin() ; (t==0) && (  i!=a.sk.end() ) && ( i < (a.sk.begin()+2) ) ; ++i )                //vector<skill*>      *************************	
			if(      percenter(  (*i)->happen  )      ){
				(*i)->super(a, b);                                                             ///**************************************
				t=1;
				return t;
			}
	}
	else if ( n==1 ){
		i=a.sk.begin();
		if(      percenter(  (*i)->happen  )      ){
			(*i)->super(a, b);                                                           
			t=1;
			return t;
		}
	}
	return t;
}



life& life::learn(skill& k)
{
	skill* p = &k;
	sk.push_back(p);
	return *this;
}


int& life::money_val()
{
	return money;
}



// for robot   -----------------------------------------------------------------------------------------
void robot::current( life& b)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |	FOREGROUND_RED | 
		FOREGROUND_GREEN | 
		FOREGROUND_BLUE);
	cout <<"\t" << name << "������: " << blood<< "                    "<< b.name <<"������: " << b.blood <<endl;
} 

void robot::atk(life& b)
{
	system("cls");
    current( b );                               
	int t;
	t= super_test(*this , b );
	if( !t ){                                              
		int hurt = attack - b.deffend;
		if( hurt >= 0)
			b.blood -= hurt;
		else 
			hurt = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
			FOREGROUND_RED);
		cout << "\n\n\n\n\n \t\t "<< name 	<< " ���𹥻� ,   " << b.name <<"������-" << hurt << endl; 
		Sleep(1500);    //1000��1000���룬��1��
	}
}

void robot::add_mount(life &b)    
{         
	current_mount += b.exper_val();
	level_up();
}

void robot::level_up()
{
	if( current_mount >= mount && current_mount < mount*2.2 ){
		level++;
		stronger();
		current_mount -= mount;
		mount *= 1.2;
	}
	else if( current_mount >= mount* 1.2)
	{
		level += 2;
		stronger();
		stronger();
		current_mount -= (mount * 2.2) ;
		mount *= (1.2 * 1.2);
		level_up();
	}
}

void robot::stronger()
{
	//system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |	FOREGROUND_RED | 
		FOREGROUND_GREEN | 
		FOREGROUND_BLUE);
	cout << "\t\t�ȼ������� ��Ҫʲô����������\n" << "\t\t 1: ����     2:�ֿ�     3:��Ӧ    4������ " << endl;
	int i ,  count=0;                               // **********************************
	while( (count==0) && (i=getch() ) ){
		switch( i ) {
		case 49:
			count++;
			cout <<"\t\t���������������\n\n";
			attack += ( attack / 5);
			break;
		case 50:
			count++;
			cout <<"\t\t���������������\n\n";
			deffend+= ( deffend / 5);
			break; 
		case 51:
			count++;
			cout <<"\t\t�ٶȴ����������\n\n";
			speed += (speed / 5);			
			break; 
		case 52:
			count++;
			cout <<"\t\t���������������\n\n";
			total_blood += (total_blood / 5);
			break; 
		default:  
			cout<< "��������ȷ��ָ�" <<endl;
			break; 
		}
	}
	
}


int robot::level_val()
{
	return level;
}

int robot::stage_val()
{
	return stage;
}


void robot::information ( )                          // *******************************************
{
	int n;
	n= sk.size();
    vector<skill*>::iterator i;
	string  l1("�ȼ�: "),   l2("\n\t\t����: "),     add21("\t\t\t����:"),
		l3("\t\t����: "),    add31("\t����: "),    add32("\t�ٶ�: "),
		l4("\n\t\t����:\n ")  ,l0("����������: ");
	
	cout << "\n\n\n\n\t\t\t     " << l0 << name <<"\n\n"  
		<< "\t\t" << l1 << level << "\t\t\t\t��Ǯ:" << money << "\n"
		<< l2 << blood << "/" << total_blood << add21 << current_mount <<"/" << mount <<"\n\n"
		<< l3 << attack << add31 << deffend << add32 << speed << "\n" 
		<< l4;
	
	if( n>=1 && n<=2 )
		for( i =sk.begin() ;  i != sk.end() ; ++i )
			cout << "\t\t" << (*i)->name_val() << " : " << (*i)->introduction_val() <<"\n\n";
		else if ( n > 2 )
			for( i =sk.begin() ;  i < ( sk.begin()+2) ; ++i )
				cout << "\t\t" << (*i)->name_val() << " : " << (*i)->introduction_val() <<"\n\n";
			else if( n==0 )
				cout << "\t\t\t��ѧϰ������\n" ;
			
}

void robot::change_skill()
{
	system("cls");
	int i(0) ,k1, k2 , n;
	char k;
	vector<skill*>::iterator p, p1 , p2;
    n = sk.size();
	
	if( n>2 ){                                 //************************************
		cout << "\n\n\n\n\t\t\t����ѧϰ�ĸ�����оƬ��\n"<<endl;
		for(  p= sk.begin()+2 ; p!= sk.end() ; p++){
			++i;
			cout << "\t\t\t" << i << " " << (*p)->name_val() <<" : " << (*p)->introduction_val() <<endl;
		}
		while( k = getch() ){
			if (k == 'q')
				return ;
			k1 = k -49;                                  //   ��'1'  k1=0     ,k1 = 0 ~ sk.size()-3
			if( ( k1 >= 0) && ( k1 <= sk.size()-3 ) )
				break;
		}    
		p1 = sk.begin() +2 + k1 ;                        //p1 point to the skill want to learned
		system("cls");
		cout << "\n\n\n\n\t\t  ���滻�ĸ�оƬ��ѧϰһ����һ���� ����������\n" <<endl;
		i=0;
		for ( p=sk.begin(); p < sk.begin()+2 ; p++){
			++i;
			cout << "\t\t" << i << " " << (*p)->name_val() <<" : " << (*p)->introduction_val() <<"\n\n";
		}
		while( k = getch() ){
			k2 = k -49;                                  //   k2 = 0 ~ 1
			if( (k2>= 0) && (k2 <= 1) )
				break;
		}
		p2 = sk.begin() + k2;
		swap( *p1 , *p2);
		system("cls");
		cout << "\n\n\n\n\t\t\t" << (*p2)->name_val() << "ѧϰ�ɹ�\n" << "\t\t\t��������"<<(*p1)->name_val() <<endl;
		Sleep(2500);
	}              //************************************
	else{
		system("cls");
		cout << "\n\n\n\n\n\n\n\t\t\t��û�м���оƬ����ѧϰ��" <<endl;
		Sleep(2000);
	}
}

void robot::got(thing* t)
{
	int have(0);
	for( vector<thing*>::iterator i=bag.begin() ; i!= bag.end() ; i++){
		if( (*i)->name_val() == t->name_val() ){
			have = 1;
			(*i)->add_mount();
			break;
		}
	}
		if( !have )
			bag.push_back(t);
		money -= t->value_val();
}


void robot::add_enermy(int r)
{
	int u = blood + r;
	if ( u <= total_blood )
		blood = u;
	else if(u > total_blood )
		blood = total_blood;
}

//for    monster---------------------------------------------------------------------------------------

void monster::current( life& a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |	FOREGROUND_RED | 
		FOREGROUND_GREEN | 
		FOREGROUND_BLUE);
	cout <<"\t" << a.name << "������: " << a.blood<< "                    "<< name <<"������: " << blood <<endl;
} 

void monster::atk(life& a)
{
	system("cls");
    current( a );                                                 //***************************
	int t;
	t= super_test(*this ,a );
	if( !t ){
		int hurt = attack - a.deffend;
		if( hurt >= 0)
			a.blood -= hurt;
		else 
			hurt = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
			FOREGROUND_BLUE);
		cout << "\n\n\n\n\n \t\t "<< name 	<< " ���𹥻� ,   " << a.name <<"������-" << hurt << endl; 
		Sleep(2000);    //1000��1000���룬��1��
	}
}

int monster::exper_val()
{
	return  exper;                                                           // *************************
}

int monster::drop_money( life& a)
{
	int c , i ;
	double dec(1) ;
	c = ( a.stage - stage ) ;
	if (c == 0)
		return money ;
	else {                                   // c only can > 0 !
		for( i=0; i<c ; i++)
			dec /= 2;
		return ( dec * money );
	}

}


//for     boss---------------------------------------------------------------------------------------

void boss::treasure ()
{
	int n;
	vector<skill*>::iterator p;
	p = find( a->sk.begin(), a->sk.end() , drop );
	srand( (unsigned)time( NULL ) );
	n = ( rand() %100 ) +1 ;
	if( n <= percent  && p== a->sk.end() ){
		a->learn( *drop );
		cout << "��ϲ!! ��ü���оƬ : " << drop->name_val() <<endl;
	}
}

boss& boss::add_treasure(skill& s)
{
	drop = &s;
	return *this;
}

void boss::level_stage()
{
	if( stage > a->stage )                  //***************
	a->stage = stage;
}


int boss::drop_money( life& a)
{
	int c , l ,i;
	double dec(1);
	
	c = a.stage - stage;
	l = c + 1;
	if( c < 0 )
		return money;
	else{
		for( i=0; i< l ; i++ )
			dec /= 2;
		return dec * money;
	} 
}



//for    skill  ---------------------------------------------------------------------------------------

const string& skill::name_val() const
{
	return name;
}  

const string& skill::introduction_val() const 
{
	return introduction;
}

const int& skill::value_val() const
{
	return value;
}

int skill::decrease_number()
{
	number--;
	if( number < 1)
		return 0;
	else 
		return 1;
}

/*for    strong----------------------------------------------------------------------------------------
operator << >> for save and remeber the game
----------------------------------------------------------------------------------------*/
void strong::super(life &a, life &b ) 
{
    system("cls");
    a.current( b );
	int hurt = a.attack - b.deffend + higher;
	if( hurt >= 0)
		b.blood -= hurt;
	else 
		hurt = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
		FOREGROUND_GREEN);
	cout << "\n\n\n\n\n \t\t "<< a.name 	<< " ����"<< name <<"    " << b.name <<" �ܵ��ش� ������-" << hurt << endl;
	Sleep(1500);    //1000��1000���룬��1
}



//for    continu----------------------------------------------------------------------------------------

void continu::super(life &a, life &b )
{
	system("cls");
    a.current( b );
	int i;
	int hurt = a.attack - b.deffend;
	
	if( hurt < 0) 
		hurt = 0;
	
	cout << "\n\n\n\n\n ";
	for(i=0 ; i<times ; i++){
		b.blood -= hurt;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
			FOREGROUND_GREEN);
		cout << " \t\t "<< a.name 	<< " ����"<< name <<"    " << b.name <<" �ܵ��ش� ������-" << hurt << "\n\n";
		Sleep(1500);
	}
	Sleep(1500);	
}


//for    puncture----------------------------------------------------------------------------------------

void puncture::super(life &a , life &b )
{
	system("cls");
    a.current( b );
	int hurt = a.attack ;
	b.blood -= hurt;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
		FOREGROUND_GREEN);
	cout << "\n\n\n\n\n \t\t "<< a.name 	<< " ����"<< name <<"    " << b.name <<" �ܵ��ش� ������-" << hurt << endl;
	Sleep(1500);    //1000��1000���룬��1
}

//for    enrich----------------------------------------------------------------------------------------

void enrich::super(life &a , life &b )
{
	int r;
	system("cls");
    a.current( b );
	r = a.total_blood * percent / 100 ;
	if( a.blood + r <= a.total_blood )
		a.blood += r ;                                             
	else 
		a.blood = a.total_blood;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
		FOREGROUND_GREEN);
	cout << "\n\n\n\n\n \t\t "<< a.name << "����" <<name << " �ָ��� "<< r <<" ���� ";
	Sleep(1500);    //1000��1000���룬��1
}

//-------------------------------------------------------------------------------------------------

int percenter(int i )
{
	Sleep(1500); 
	int a[4] , b , all(0); 
	srand( (unsigned)time( NULL ) );
	for (b=0 ; b< 4 ; b++){
		a[b]=( rand() %100 ) +1 ;
		all+= a[b];
	} 
	b= (all) %4;                                                           
	if(  (a[ b]) > i )
		return 0 ;
	else return 1;
}

char* ics(int i , char* str)
{
    sprintf(str,"%d",i);
	return str;
}


void fight( life& a, life& b)               //  robot   monster
{
	int s = a.speed - b.speed;
	int count(0) , bm;                              // for speed kill
	if( a.deffend >= b.attack && b.deffend >= a.attack ){
		system("cls");
		cout << "\n\n\n\n\n\n\n \t\t\t\t ƽ�֣�";
		Sleep(1500);
	}
	else{
		while ( a.alive(a) && b.alive(b) )
		{
			if(s>=0){
				a.atk(b);
				if( b.blood <= 0 )
					break;
				b.atk(a);
				if( a.blood <= 0 )
					break;
				count += s;                         // if a.speed = 10      , b.speed = 5 ,every two rounds , a attck b extra one time 
				if ( count >= a.speed ){
					system("cls");
					a.current( b );
					cout << "\n\n\n\n\n \t\t "<< a.name << " �� "<< b.name <<" �����ٶ�ѹ�ƣ�";
					Sleep(2000);
					
					a.atk(b);
					if( b.blood <= 0)
						break;
					count = count - a.speed;
				}
			}
			else {
				b.atk(a);
				if( a.blood <= 0 )
					break;
				a.atk(b);
				if( b.blood <= 0 )
					break;
				count += (-s);                        
				if ( count >= b.speed ){
					system("cls");
					a.current( b );
					cout << "\n\n\n\n\n \t\t "<< b.name << " �� "<< a.name <<" �����ٶ�ѹ�ƣ� ";
					Sleep(2000);
					b.atk(a);
					if( a.blood <= 0)
						break;
					count = count - b.speed;
				}
			}
		}
		if(a.alive(a)){
			cout << "\n\t\t\t"<<a.name << " Ӯ " << endl;
			bm = b.drop_money( a );
			cout << "\t\t\t��ý�Ǯ : " << bm <<"\n\n";                    //*********************************
			a.money += bm ;

			cout << "\t\t\t��þ��� : " << b.exper_val() <<"\n\n";
			a.add_mount(b);	                           //after fight robot blood is decrease		
			b.treasure();
			b.level_stage();
		}
		else{
			cout << "\n ս��ʧ��!"<< endl;
			a.blood = 0;
		}
		b.blood = b.total_blood;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |	FOREGROUND_RED | 
			FOREGROUND_GREEN | 
			FOREGROUND_BLUE);
		Sleep(1500);
	}
}
















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

const int& thing::number_val() const
{
	return number;
}


void thing::add_mount()
{
	++number;
}

//for    food  ---------------------------------------------------------------------------------------

int food::recover_val()
{
	int i= recover;
	return i;
}

void food::use( thing* t)
{
	a->add_enermy( t->recover_val() );                          //************************************
	system("cls");
	cout << "\n\n\n\n\n\n\t\tʹ����" << t->name_val() << " , �����ָ�" << t->recover_val() <<endl;
	Sleep(1500);
}

void food::minus_mount()
{
	--number;
}
