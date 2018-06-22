#include "world.h"
#include "picture.h"
#include "conio.h"
#include "windows.h"
#include <iostream>
using namespace std;

char* inits0[]= {"1 新的开始\n\n", "2 云端读取"};
char* inits00[]= {"2040 ，人类的人工智能有了惊人的突破，传说中的\n", "奇点就这样到来了 。一种别样与目前物种的新的\n","生命诞生了，他们能交流，有情感，故事从这里开始。。。"};
char* init[]= { "     ios 100 操作系统\n\n", "1 状态        2 智能聊天\n" ,"3 星际冒险    4 技能芯片\n" ,"5 虚拟购物    6 异空间\n","7 记录云端"};//异空间
char* init01[]= {"地球------------->1 月球", "                     |", "                     |", "                     |", "                    XXXX"};
char* init02[]= {"地球------------->1 月球", "                     |", "                     |", "                     |", "XXXX<-------------2 火星"};
char* init03[]= {"地球------------->1 月球", "                     |", "                     |", "                     |", "3 仙王座δ星------2 火星" , "|                     ","|                     ","|                     ","4 XXXXX"};
char* init29[]= {"地球------------->1 月球", "                     |", "                     |", "                     |", "3 仙王座δ星------2 火星" , "|                     ","|                     ","|                     ","4 更远的地方" };
char* init04[]= { "1 撤退\t\t2 挑战\t\t3 boss战\n" ,"4 芯片商店\t\t 5 与月亮人交谈\n\n\n", "月球：古老的环形山布满了星际基地 "};
char* init05[]= { "1 撤退\t\t2 挑战\t\t3 boss战\n\n\n\n" , "火星：远方是太阳系最高的山：奥林帕斯山和最大的峡谷：\n\n\t\t\t水手号峡谷。整个星球似乎有着失落的文明"};
char* init06[]= { "\t\t火星地下城市！\n" , "1 返回星球表面\t    2 淘宝\t    3 与火星居民交谈\n"};
char* init07[]= { "1 撤退\t\t2 切磋\t\t3 传说中\n" ,"4 芯片商店\t\t 5 与人交谈\n\n\n", "仙王座δ星：这里的太阳是蓝色的，有很多不可思议的生物。"};
char* init08[]= { "degined by sh零en！\n\n" , "\tcode by the same people！\n\n","\t\tsurport by yours!\n\n\n\t\t\tthanks for game!\n\n\n\t\tBYE"};
char* init09[]= {"开发中...."};
char* init10[]= {"请输入正确的指令！"};
char* init11[]= { "飞往月球中." };
char* init12[]= { "飞往月球中.." };
char* init13[]= { "飞往月球中..." };
char* init14[]= { "拼命奔向火星中." };
char* init15[]= { "拼命奔向火星中.." };
char* init16[]= { "拼命奔向火星中..." };
char* init17[]= { "探测中." };
char* init18[]= { "探测中.." };
char* init19[]= { "探测中..." };
char* init20[]= {"回家中."};
char* init21[]= {"回家中.."};
char* init22[]= {"回家中..."};
char* init23[]= { "开启曲速引擎驶向仙王座δ星." };
char* init24[]= { "开启曲速引擎驶向仙王座δ星.." };
char* init25[]= { "开启曲速引擎驶向仙王座δ星..." };
char* init26[]= { "通过虫洞中." };
char* init27[]= { "通过虫洞中.." };
char* init28[]= { "通过虫洞中..." };

char* init44  =  "这里都太强了。。。" ;
char* init45  =  "知道金子塔吗，很久很久以前我们还帮你们造过！" ;
char* init46  =  "哎，你挺厉害啊，来到了这里。" ;
char* init47  =  "UFO。。。" ;
char* init48  =  "我要是没记错的话，大约70年前，地球人类第一次来过这里。" ;
char* init49  =  "我们生活的方式很奇特，一般有两个家，一个在月球\n\t\t一直有光的一面，一个在背面。" ;
char* init50  =  "很久以前，火星拥有比你们更繁荣的文明。。。" ;
char* init51  =  " 钬鯹乆亻衣繎詪牜槎！(火星语。。。)";
char* init52  =  " 游戏界面一般按 q 就能返回， 若不能就按数字提示操作。";
char* init53  =  " 每次击败boss， 都会开启新地图！";
char* init54  =  " 最好是把属性加到攻击和血量上！";
char* init55  =  " 月球使者拥有技能！";
char* init56  =  " 每个地图里都有跑的很快的怪，不要着急！";
char* init57  =  " 有的界面不用按键子，自动返回，等一会，若不回，再按 q 。";

char* init60  =  " 火星可不止表面那样简单，你知道吗？";
char* init61  =  " 大海里面有鱼！哈哈";
char* init62  =  " 火星的太阳是蓝色的！";


char* init70  =  " 最近怪比较难打啊！";
char* init71  =  " 你现在距离世界的尽头很近啊，加油吧！";

char* init80  =  " 感谢游戏，code by 沈仝！， play by you!";




int main()
{                           
	robot a(30 , 10 , 5 , 150 , 200,"atom");                    

	robot* ap=&a;

	monster b1(38 ,  7 ,  5,  100 ,  40 , 0 , "探测烧饼" ,  2) ;                 // experent
	monster b2(25 ,  5 ,  8,  120 ,  75 , 0 , "哨兵"     ,  2) ;                 // attack , deffend , speed , blood ,  money, stage, name
	monster b3(28 , 23 ,  6,   91 ,  70 , 0 , "鉄甲覆人" ,  3) ;
    monster b4(45 , 17 ,  5 , 137 ,  90 , 0 ,"小异型"   ,  4) ;
	boss    b5(36 , 21 ,  5 , 240 ,  150 , 1 , "月球使者" ,  3 , 10 , ap);                  //  int percent ,robot* a1
	
              

	monster b6(42 , 30 ,  6 ,  220 ,  90 , 1 ,  "双头蜥" ,     4) ;                 
	monster b7(25 , 18 ,  10,  280 , 104 , 1 ,  "冰胡子",      5) ;
	monster b8(21 , 53 ,  6 ,  250 ,  70 , 1 ,  "铁斧巨人" ,   7) ;
    monster b9(28 , 48 ,  7 ,  280 , 103 , 1 ,  "棕精灵"   ,   8) ;
    boss    b10(33, 65 ,  6 ,  320 ,  200 , 2 ,  "战神玛尔斯" , 6 , 0 , ap);     


	monster b11(50 , 45 ,  7 ,  470 , 120 , 2 ,  "少卫" ,     16) ;                 
	monster b12(35 , 70 ,  15,  420 , 130 , 2 ,  "天柱",      15) ;
	monster b13(55 , 70 ,  8 ,  500 ,  135, 2 ,  "蛇发魔女" ,19) ;
    monster b14(60 , 75 ,  8 ,  550 , 140 , 2 ,  "造父"   ,   22) ;
    boss    b15(220 , 400 , 10 , 1800 , 300 , 3 ,  "仙王克甫斯" ,25 , 0 , ap); 

	
	boss* mp5 , *mp10 , *mp15 , *nmp=0;
	mp5 = &b5;
	mp10 = &b10;
	mp15 = &b15;

     // name , introduction ,value, happen  **             
	strong s1("铁甲钢拳！","二代钢铁侠护手，铁拳攻击。\n\t\t\t  18%几率发动 ", 800, 18, 30);
	continu s2("光闪！","活化身体能量，闪电侠风格，速度提升，\n\t\t\t 产生2连击。23%几率发动 ",1400, 23, 2);
	strong s3("迫击炮！","从手心发出能量弹。 20%几率发动 ", 1200 ,  20, 40);
	strong s4("手斧重击！", "" , 0 ,  22 , 35);
	continu s5("眼花缭乱！","", 0 ,  25, 3);
    strong s50("满月斩！","", 0 ,  20, 28);
	strong s51("半月斩！","与月能使者交战，习得的能力。",800, 23, 35);
	enrich s52("吃自己一口！","",0, 15,20);
	strong s60("魂之挽歌！","", 0 , 25 , 37);
	strong s70("诸神黄昏", "" , 0 , 30 , 150);
	enrich s71("圣心！","",0, 15,12);
	puncture s72("死灵的终焉之击！","", 0, 25);
	enrich s73("暗心！","",0, 15,11);
	strong s74("破天冀！","", 0 , 35 , 50);
    continu s75("灵动！","", 0, 23, 3);

	continu s8("光影和弦！","是3连击，不过也很强啦！\n\t\t\t\t 24%几率发动", 6000,  24, 3);
    strong s9("真*诺亚之眼！","唤出刀灵，发出强力击。\n\t\t\t\t30%几率发动 ", 10000 , 30, 300);
	puncture s10("雷贯一击！","手臂化为雷电 ，贯穿敌人防御，\n\t\t\t     破防，4%几率发动 ", 2400, 4);
	enrich  s11 ("自然恢复！","能感知星系暗的能量，转化到自身，\n\t\t\t    战斗中自恢复，23%几率发动 ",2900,23,15);
	
    
   
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
    food f1("小苹果" ,"很久以前红遍大江南北的苹果，能量+50" ,20 ,1 ,50 , ap);
	food f2("奥利奥" ,"宋小宝激动地握住了赵本山的手，能量+100" ,50 ,1 ,100 , ap);
	food f3("超级圣代" ,"肯不肯旗舰产品，能量+200" , 100 ,1 ,200 , ap);
	food f4("仙丹" ,"龙珠里卖的，能量+500" , 249 ,1 ,500 , ap);
	
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
	movie  map09     (ap);                                          //去火星动画
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
//	boss    b5(36 , 21 ,  5 , 10 , 100 , "月球使者" ,  5 , 10 , 1, ap);  

//	boss    b10(33, 65 ,  6 ,  32 , 120 ,  "战神玛尔斯" , 10 , 0 , 2, ap);       //*******************************
 //	boss    b15(90 , 24 , 10 , 6 , 145 ,  "仙王克甫斯" ,25 , 0 , 3, ap); 

 //	a.learn(s8).learn(s9).learn(s10);
	//int y , int x , char** p , int n, map<char , see*> m, vector<monster> v, robot& a1 , monster& b2):
	//normal base( 4 , 3 , init ,3 , );
//	v.insert(&b1);
    
    
	

	/*                              c风格创地图 第4个图就懵了   c++完爆了c
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
							if( i== 49){                                            //  -路费
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
	strong s1("螺旋丸！","hh", 20, 30);
	continu s2("千鸟！","hhh",15,2);
	
	  robot a(30 ,10 ,5 ,100 , "atom");                          // attack , deffend , speed , blood , name
	  a.learn(s1);
	  a.learn(s2);
	  // a.information();
	  monster b(20 , 8, 6, 15 , "火星人" , 10);
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