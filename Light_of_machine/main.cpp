#include "world.h"
#include "picture.h"
#include "conio.h"
#include "windows.h"
#include <iostream>
using namespace std;

char* inits0[]= {"1 �µĿ�ʼ\n\n", "2 �ƶ˶�ȡ"};
char* inits00[]= {"2040 ��������˹��������˾��˵�ͻ�ƣ���˵�е�\n", "�������������� ��һ�ֱ�����Ŀǰ���ֵ��µ�\n","���������ˣ������ܽ���������У����´����￪ʼ������"};
char* init[]= { "     ios 100 ����ϵͳ\n\n", "1 ״̬        2 ��������\n" ,"3 �Ǽ�ð��    4 ����оƬ\n" ,"5 ���⹺��    6 ��ռ�\n","7 ��¼�ƶ�"};//��ռ�
char* init01[]= {"����------------->1 ����", "                     |", "                     |", "                     |", "                    XXXX"};
char* init02[]= {"����------------->1 ����", "                     |", "                     |", "                     |", "XXXX<-------------2 ����"};
char* init03[]= {"����------------->1 ����", "                     |", "                     |", "                     |", "3 ����������------2 ����" , "|                     ","|                     ","|                     ","4 XXXXX"};
char* init29[]= {"����------------->1 ����", "                     |", "                     |", "                     |", "3 ����������------2 ����" , "|                     ","|                     ","|                     ","4 ��Զ�ĵط�" };
char* init04[]= { "1 ����\t\t2 ��ս\t\t3 bossս\n" ,"4 оƬ�̵�\t\t 5 �������˽�̸\n\n\n", "���򣺹��ϵĻ���ɽ�������Ǽʻ��� "};
char* init05[]= { "1 ����\t\t2 ��ս\t\t3 bossս\n\n\n\n" , "���ǣ�Զ����̫��ϵ��ߵ�ɽ��������˹ɽ������Ͽ�ȣ�\n\n\t\t\tˮ�ֺ�Ͽ�ȡ����������ƺ�����ʧ�������"};
char* init06[]= { "\t\t���ǵ��³��У�\n" , "1 �����������\t    2 �Ա�\t    3 ����Ǿ���̸\n"};
char* init07[]= { "1 ����\t\t2 �д�\t\t3 ��˵��\n" ,"4 оƬ�̵�\t\t 5 ���˽�̸\n\n\n", "���������ǣ������̫������ɫ�ģ��кܶ಻��˼������"};
char* init08[]= { "degined by sh��en��\n\n" , "\tcode by the same people��\n\n","\t\tsurport by yours!\n\n\n\t\t\tthanks for game!\n\n\n\t\tBYE"};
char* init09[]= {"������...."};
char* init10[]= {"��������ȷ��ָ�"};
char* init11[]= { "����������." };
char* init12[]= { "����������.." };
char* init13[]= { "����������..." };
char* init14[]= { "ƴ�����������." };
char* init15[]= { "ƴ�����������.." };
char* init16[]= { "ƴ�����������..." };
char* init17[]= { "̽����." };
char* init18[]= { "̽����.." };
char* init19[]= { "̽����..." };
char* init20[]= {"�ؼ���."};
char* init21[]= {"�ؼ���.."};
char* init22[]= {"�ؼ���..."};
char* init23[]= { "������������ʻ������������." };
char* init24[]= { "������������ʻ������������.." };
char* init25[]= { "������������ʻ������������..." };
char* init26[]= { "ͨ���涴��." };
char* init27[]= { "ͨ���涴��.." };
char* init28[]= { "ͨ���涴��..." };

char* init44  =  "���ﶼ̫ǿ�ˡ�����" ;
char* init45  =  "֪���������𣬺ܾúܾ���ǰ���ǻ������������" ;
char* init46  =  "������ͦ�����������������" ;
char* init47  =  "UFO������" ;
char* init48  =  "��Ҫ��û�Ǵ�Ļ�����Լ70��ǰ�����������һ���������" ;
char* init49  =  "��������ķ�ʽ�����أ�һ���������ң�һ��������\n\t\tһֱ�й��һ�棬һ���ڱ��档" ;
char* init50  =  "�ܾ���ǰ������ӵ�б����Ǹ����ٵ�����������" ;
char* init51  =  " ���]�X���¿�ԋ��鶣�(���������)";
char* init52  =  " ��Ϸ����һ�㰴 q ���ܷ��أ� �����ܾͰ�������ʾ������";
char* init53  =  " ÿ�λ���boss�� ���Ὺ���µ�ͼ��";
char* init54  =  " ����ǰ����Լӵ�������Ѫ���ϣ�";
char* init55  =  " ����ʹ��ӵ�м��ܣ�";
char* init56  =  " ÿ����ͼ�ﶼ���ܵĺܿ�Ĺ֣���Ҫ�ż���";
char* init57  =  " �еĽ��治�ð����ӣ��Զ����أ���һ�ᣬ�����أ��ٰ� q ��";

char* init60  =  " ���ǿɲ�ֹ���������򵥣���֪����";
char* init61  =  " ���������㣡����";
char* init62  =  " ���ǵ�̫������ɫ�ģ�";


char* init70  =  " ����ֱȽ��Ѵ򰡣�";
char* init71  =  " �����ھ�������ľ�ͷ�ܽ��������Ͱɣ�";

char* init80  =  " ��л��Ϸ��code by ���ڣ��� play by you!";




int main()
{                           
	robot a(30 , 10 , 5 , 150 , 200,"atom");                    

	robot* ap=&a;

	monster b1(38 ,  7 ,  5,  100 ,  40 , 0 , "̽���ձ�" ,  2) ;                 // experent
	monster b2(25 ,  5 ,  8,  120 ,  75 , 0 , "�ڱ�"     ,  2) ;                 // attack , deffend , speed , blood ,  money, stage, name
	monster b3(28 , 23 ,  6,   91 ,  70 , 0 , "⟼׸���" ,  3) ;
    monster b4(45 , 17 ,  5 , 137 ,  90 , 0 ,"С����"   ,  4) ;
	boss    b5(36 , 21 ,  5 , 240 ,  150 , 1 , "����ʹ��" ,  3 , 10 , ap);                  //  int percent ,robot* a1
	
              

	monster b6(42 , 30 ,  6 ,  220 ,  90 , 1 ,  "˫ͷ��" ,     4) ;                 
	monster b7(25 , 18 ,  10,  280 , 104 , 1 ,  "������",      5) ;
	monster b8(21 , 53 ,  6 ,  250 ,  70 , 1 ,  "��������" ,   7) ;
    monster b9(28 , 48 ,  7 ,  280 , 103 , 1 ,  "�ؾ���"   ,   8) ;
    boss    b10(33, 65 ,  6 ,  320 ,  200 , 2 ,  "ս�����˹" , 6 , 0 , ap);     


	monster b11(50 , 45 ,  7 ,  470 , 120 , 2 ,  "����" ,     16) ;                 
	monster b12(35 , 70 ,  15,  420 , 130 , 2 ,  "����",      15) ;
	monster b13(55 , 70 ,  8 ,  500 ,  135, 2 ,  "�߷�ħŮ" ,19) ;
    monster b14(60 , 75 ,  8 ,  550 , 140 , 2 ,  "�츸"   ,   22) ;
    boss    b15(220 , 400 , 10 , 1800 , 300 , 3 ,  "�����˸�˹" ,25 , 0 , ap); 

	
	boss* mp5 , *mp10 , *mp15 , *nmp=0;
	mp5 = &b5;
	mp10 = &b10;
	mp15 = &b15;

     // name , introduction ,value, happen  **             
	strong s1("���׸�ȭ��","�������������֣���ȭ������\n\t\t\t  18%���ʷ��� ", 800, 18, 30);
	continu s2("������","���������������������ٶ�������\n\t\t\t ����2������23%���ʷ��� ",1400, 23, 2);
	strong s3("�Ȼ��ڣ�","�����ķ����������� 20%���ʷ��� ", 1200 ,  20, 40);
	strong s4("�ָ��ػ���", "" , 0 ,  22 , 35);
	continu s5("�ۻ����ң�","", 0 ,  25, 3);
    strong s50("����ն��","", 0 ,  20, 28);
	strong s51("����ն��","������ʹ�߽�ս��ϰ�õ�������",800, 23, 35);
	enrich s52("���Լ�һ�ڣ�","",0, 15,20);
	strong s60("��֮��裡","", 0 , 25 , 37);
	strong s70("����ƻ�", "" , 0 , 30 , 150);
	enrich s71("ʥ�ģ�","",0, 15,12);
	puncture s72("���������֮����","", 0, 25);
	enrich s73("���ģ�","",0, 15,11);
	strong s74("���켽��","", 0 , 35 , 50);
    continu s75("�鶯��","", 0, 23, 3);

	continu s8("��Ӱ���ң�","��3����������Ҳ��ǿ����\n\t\t\t\t 24%���ʷ���", 6000,  24, 3);
    strong s9("��*ŵ��֮�ۣ�","�������飬����ǿ������\n\t\t\t\t30%���ʷ��� ", 10000 , 30, 300);
	puncture s10("�׹�һ����","�ֱۻ�Ϊ�׵� ���ᴩ���˷�����\n\t\t\t     �Ʒ���4%���ʷ��� ", 2400, 4);
	enrich  s11 ("��Ȼ�ָ���","�ܸ�֪��ϵ����������ת��������\n\t\t\t    ս�����Իָ���23%���ʷ��� ",2900,23,15);
	
    
   
	b1.learn(s52);
	b5.learn(s50);     b5.add_treasure(s51);

	b8.learn(s4);     
	b9.learn(s5);
	b10.learn(s60);

	b11.learn(s75);
	b12.learn(s74);
	b13.learn(s73);
	b14.learn(s72);
	b15.learn(s70).learn(s71);

	//b6 ***********************************************



	//const string& n, const string& i, int v ,int num ,int r, robot* a1
    food f1("Сƻ��" ,"�ܾ���ǰ�����ϱ���ƻ��������+50" ,20 ,1 ,50 , ap);
	food f2("������" ,"��С����������ס���Ա�ɽ���֣�����+100" ,50 ,1 ,100 , ap);
	food f3("����ʥ��" ,"�ϲ����콢��Ʒ������+200" , 100 ,1 ,200 , ap);
	food f4("�ɵ�" ,"���������ģ�����+500" , 249 ,1 ,500 , ap);
	
                 	//inform(4,3,  init07 ,1)       (y , x)	
	see base  ( 4, 3, init,   5 )    , s0    ( 8, 4, inits0 ,2) ,
		s00    ( 6, 2, inits00 ,3)   , going11(8, 4, init11, 1 )   ,
		warn  ( 6, 3, init10, 1 )    , base01( 4, 1 ,init01 ,5  )  ,
		base02( 4 ,1 ,init02, 5 )    , base03( 4, 1, init03 , 9 )  ,
		base04( 2, 2, init04, 3 )    , base05( 4,2, init05 , 2 )   ,
		base06( 2, 2, init06, 2 )    , base07( 4,2, init07 , 2 )   ,
		base08( 4 ,2, init08 , 3 )   ,
		base11( 6, 3, init11, 1 )    , base12( 6, 3, init12, 1 )   ,
		base13( 6, 3, init13, 1 )    , base14( 6, 3, init14 ,1 )   ,
		base15( 6, 3, init15 ,1 )    , base16( 6, 3, init16 ,1 )   ,
		base17( 6, 3, init17, 1 )    , base18( 6, 3, init18, 1 )   ,
		base19( 6, 3, init19, 1 )    , base20( 6, 3, init20, 1 )   ,
		base21( 6, 3, init21, 1 )    , base22( 6, 3, init22, 1 )   ,
		base23( 6, 3, init23, 1 )    , base24( 6, 3, init24, 1 )   ,
		base25( 6, 3, init25, 1 )    , base26( 6, 3, init26, 1 )   , 
        base27( 6, 3, init27, 1 )    , base28( 6, 3, init28, 1 )   ,
		base29( 4, 1, init29 , 9 )   ,
		 fmap1( 6,2, init04 , 2 )  ;
   
     
    
        

	

    
	
    normal  maps0    ( s0 , 0 , 0 );
	normal  maps00   ( s00, 0 , 0 );
	remeber maps1    ( ap );
	save    maps2    ( ap );

                                                  
    normal map0      ( base   , ap , 0  );             // see& s, robot* a1, boss* b2
	normal map01     ( base01 , ap ,0  );
	quatum map02     (ap);                            // const robot& a1
	normal map04     ( base04 , ap , mp5 );
	movie  map03     (ap);                           // const robot& a1
	movie  map05     (ap); 
	shop   map06     (ap);                                        // ( map<char , see*> m,  robot* a1) 
	space  map07     (ap);                                           //( robot* a1):
	skill_shop map08 (ap);
	movie  map09     (ap);                                          //ȥ���Ƕ���
	normal map10     ( base05 , ap , mp10 );
	movie  map11     (ap);
	normal map12     ( base06 , ap , nmp );
	skill_shop map13 (ap);
	chat   map14 ;                                //NPC
	smart  map15     (ap);
	chat   map16;                                 //stage 0
	chat   map17;                                 //NPC on the moon
	chat   map18;                                 //stage 1
	chat   map19;                                 //stage 2
	                                              
	movie  map20     (ap);
	normal map21     ( base07  , ap , mp15 );          
	skill_shop map22 (ap);
	chat   map23;
	movie  map24     (ap);
	normal map25     ( base08 , 0 ,0  );
	chat   map26;                                 //stage 3

	
    

    maps0.add_button( pair<char , see*>('1',&maps00) ).add_button( pair<char , see*>('2',&maps1) );
	maps00.add_button( pair<char , see*>(' ',&map0) );
	maps1.add_button(  &map0 ).add_button(  &maps0 );
	maps2.add_button(  &map0 );
	map0.add_button( pair<char , see*>('1',0 ) ).add_button( pair<char , see*>('2', &map15 ) )
		.add_button( pair<char , see*>('3', &map02 ) ).add_button( pair<char , see*>('4', 0 ) )
		.add_button( pair<char , see*>('5', &map06 ) ).add_button( pair<char , see*>('6', &map07 ) )
		.add_button( pair<char , see*>('7', &maps2 ) ); 
//	coding09.add_button( pair<char , see*>('q', &map0) );      // the map can foto which other map
    
	     //add_picture (pair<int , see*>() )       0 stage show the base01
	map02.add_picture( pair<int, see*>(0 , &base01 ) ).add_picture( pair<int, see*>(1 , &base02 ) )
		.add_picture( pair<int, see*>(2 , &base03 ) ).add_picture( pair<int, see*>(3 , &base29 ) ) ;
	map02.add_button( pair<char , see*>('1', &map03) ).add_button( pair<char , see*>('2', &map09) )
		.add_button( pair<char , see*>('3', &map20) ).add_button( pair<char , see*>('4', &map24) );

	    //movie& movie::add_frame( see* s )          the last frame is the final of the movie
	map03.add_frame( &base11).add_frame( &base12).add_frame( &base13).add_frame( &map04);
	map05.add_frame( &base20).add_frame( &base21).add_frame( &base22).add_frame( &map0);
	
    map04.add_button( pair<char , see*>('1', &map05) ).add_button( pair<char , see*>('2',0) )
		.add_button( pair<char , see*>('3',0) ).add_button( pair<char , see*>('4', &map08) )
		.add_button( pair<char , see*>('i',0) );
	map04.add_monster(b1).add_monster(b2).add_monster(b3).add_monster(b4)
		.add_button( pair<char , see*>('5', &map17) );

	   //shop& add_thing(pair<char ,thing* >& );
	map06.add_button( pair<char , see*>('q', &map0) ).add_thing(pair<char ,thing* > ('1', &f1) )
		.add_thing(pair<char ,thing* > ('2', &f2) ).add_thing(pair<char ,thing* > ('3', &f3) )
		.add_thing(pair<char ,thing* > ('4', &f4) );
	map07.add_button( pair<char , see*>('q', &map0) );
	map08.add_button( pair<char , see*>('q', &map04) ).add_skill( pair<char , skill*>('1', &s1));

	map09.add_frame( &base14).add_frame( &base15).add_frame( &base16).add_frame( &map10);
    map10.add_button( pair<char , see*>('1', &map05) ).add_button( pair<char , see*>('2',0) )
		.add_button( pair<char , see*>('3',0) ).add_button( pair<char , see*>('8', &map11) )
		.add_button( pair<char , see*>('i',0) );
	map10.add_monster(b6).add_monster(b7).add_monster(b8).add_monster(b9);
		//.add_button( pair<char , see*>('5', &map17) );

	map11.add_frame( &base17).add_frame( &base18).add_frame( &base19).add_frame( &map12);
	map12.add_button( pair<char , see*>('1', &map10) ).add_button( pair<char , see*>('2', &map13) )
		.add_button( pair<char , see*>('3', &map14) );
    map13.add_button( pair<char , see*>('q', &map12) ).add_skill( pair<char , skill*>('1', &s2))
		.add_skill( pair<char , skill*>('2', &s3));

	map14.add_button( pair<char , see*>('q', &map12) ).add_information( pair<int , char*>(1, init50))
		.add_information( pair<int , char*>(2, init51));
    map15.add_chat( pair<int , see* >(0, &map16)).add_chat( pair<int , see* >(1, &map18))
		.add_chat( pair<int , see* >(2, &map19)).add_chat( pair<int , see* >(3, &map26));

	map16.add_button( pair<char , see*>('q', &map0) ).add_information( pair<int , char*>(1, init52))
		.add_information( pair<int , char*>(2, init53)).add_information( pair<int , char*>(3, init54))
		.add_information( pair<int , char*>(4, init55)).add_information( pair<int , char*>(5, init56))
		.add_information( pair<int , char*>(6, init57));

	map17.add_button( pair<char , see*>('q', &map04) ).add_information( pair<int , char*>(1, init47))
		.add_information( pair<int , char*>(2, init48)).add_information( pair<int , char*>(3, init49));

	map18.add_button( pair<char , see*>('q', &map0) ).add_information( pair<int , char*>(1, init60))
		.add_information( pair<int , char*>(2, init61)).add_information( pair<int , char*>(3, init62));
	map19.add_button( pair<char , see*>('q', &map0) ).add_information( pair<int , char*>(1, init70))
		.add_information( pair<int , char*>(2, init71));


	map20.add_frame( &base23).add_frame( &base24).add_frame( &base25).add_frame( &map21);

    map21.add_button( pair<char , see*>('1', &map05) ).add_button( pair<char , see*>('2',0) )
		.add_button( pair<char , see*>('3',0) ).add_button( pair<char , see*>('4', &map22) )
		.add_button( pair<char , see*>('5', &map23) ).add_button( pair<char , see*>('i',0) );
	map21.add_monster(b11).add_monster(b12).add_monster(b13).add_monster(b14);
		
	map22.add_button( pair<char , see*>('q', &map21) ).add_skill( pair<char , skill*>('1', &s10))
		.add_skill( pair<char , skill*>('2', &s11)).add_skill( pair<char , skill*>('3', &s8))
		.add_skill( pair<char , skill*>('4', &s9));
	map23.add_button( pair<char , see*>('q', &map21) ).add_information( pair<int , char*>(1, init44))
		.add_information( pair<int , char*>(2, init45)).add_information( pair<int , char*>(3, init46)); 

	map24.add_frame( &base26).add_frame( &base27).add_frame( &base28).add_frame( &map25);   //**********************
	map25.add_button( pair<char , see*>('q', &map05) ); 
	map26.add_button( pair<char , see*>('q', &map0) ).add_information( pair<int , char*>(1, init80));

	focus f0(&maps0);
	return 0;
}


































    
	//map<char , see*>  nm; 
//	vector<monster>  nv;
//	map<int , see*> q02 ,nq;
//	boss    b5(36 , 21 ,  5 , 10 , 100 , "����ʹ��" ,  5 , 10 , 1, ap);  

//	boss    b10(33, 65 ,  6 ,  32 , 120 ,  "ս�����˹" , 10 , 0 , 2, ap);       //*******************************
 //	boss    b15(90 , 24 , 10 , 6 , 145 ,  "�����˸�˹" ,25 , 0 , 3, ap); 

 //	a.learn(s8).learn(s9).learn(s10);
	//int y , int x , char** p , int n, map<char , see*> m, vector<monster> v, robot& a1 , monster& b2):
	//normal base( 4 , 3 , init ,3 , );
//	v.insert(&b1);
    
    
	

	/*                              c��񴴵�ͼ ��4��ͼ������   c++�걬��c
	base.display();
	
	while( i=getch() ){
		switch( i ) {
		case '1':
			system("cls");
			a.information();
			while( i=getch() ){
				if( i== 'q'){
					system("cls");
					base.display();
					break;
				}
				else{ 
					system("cls");
					warn.display();}
			}
			break;
		case '2':
			system("cls");
			coding.display();
			break;
		case '3':
			system("cls");
			if( a.level_val() == 0 ){
				map01.display();
				while( i=getch()  ){
					if(i==49){
						system("cls");
						going11.display();                                          //******************************
						Sleep(1500);
						system("cls");
						fmap1.display();
						
                        while( i=getch()  ){
							if( i== 49){                                            //  -·��
								system("cls");
								backing.display();
								break;
							}
							else if( i==50){
								fight(a , b);
								system("cls");
								fmap1.display();}
						}
					}
					else if(i=='q')
					{
						system("cls");
						base.display();
						break;	}
					else{
						system("cls");
						warn.display();
					}
					
				}
			}
			else if( a.level_val() == 1)
				map02.display();
			else if( a.level_val() == 2)
				map03.display();
			else 
				warn.display();
			
			break;
		case 'q':
			system("cls");
			base.display();
			break;
			
			
			
			//	case 52:
		default:
			system("cls");
			warn.display();
			break; 
		}
	}
	*/
	
	
	
	/*
	strong s1("�����裡","hh", 20, 30);
	continu s2("ǧ��","hhh",15,2);
	
	  robot a(30 ,10 ,5 ,100 , "atom");                          // attack , deffend , speed , blood , name
	  a.learn(s1);
	  a.learn(s2);
	  // a.information();
	  monster b(20 , 8, 6, 15 , "������" , 10);
	  fight(a , b);
    */
	
	/*see base( 4, 3, init , 3);
	base.display();
	Sleep(1000);
	
	  system("cls");
	  see map01(1 ,1 ,init01 ,5)  ;
	  map01.display();
	  see map02(1 ,1 ,init02 ,5);
	  map02.display();
	  see	map03(1,1, init03 , 5);
	  map03.display();
	  see going11(8,4 , init11,1);
	  going11.display();
	  see fmap1( 4,3, init04 , 4);
	  fmap1.display();*/


/*char* stc(string a){                               // string ->char
	char* c;
	const int len = a.length();
	c = new char[len+1];
	strcpy(c,a.c_str());
	return c;    
}
*/