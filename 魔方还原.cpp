#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<string>
#include<windows.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;
class Face
{
public:
	Face();
	COLORREF color;
	void coordinate(int x1, int y1, int x2, int y2);
	void coloring();

private:
	int iX1, iY1;      //立方体小块涂色坐标
	int iX2, iY2;      //展开图小块涂色坐标
};

Face::Face()
{
	color =  RGB(0, 0, 0);              //初始化
}

void Face::coordinate(int x1, int y1, int x2, int y2)
{	
	iX1 = x1;
	iY1 = y1;
	iX2 = x2;
	iY2 = y2;
}

void Face::coloring()
{
	setfillstyle(0);
	setfillcolor(color);
	floodfill(iX1, iY1, RGB(233, 233, 233));
	floodfill(iX2, iY2, RGB(233, 233, 233));
}

Face F[3][3]; 
Face U[3][3]; 
Face R[3][3]; 
Face L[3][3]; 
Face D[3][3]; 
Face B[3][3]; 

void Right();
void right();
void Up();
void up();
void Left();
void left();
void Down();
void down();
void Front();
void front();
void Back();
void back();
void M();
void m();
void X();
void x();
void Y();
void y();
void Z();
void z();

int main()
{
	void welcome();
	void play();

	welcome();
	play();
	
	return 0;
}

void welcome()       //欢迎界面
{
	void help();
	initgraph(640, 480);
	IMAGE img, btn;
	MOUSEMSG m;		// 定义鼠标消息

	loadimage(&img,".\\资源\\Rubik.jpg",640,480,true);
	putimage(0, 0, &img);
	loadimage(&btn,".\\资源\\按钮.jpg",255,48,true);
	putimage(200, 40, &btn);  //Rubik的按钮
	putimage(200, 400, &btn);  //Help的按钮
	setcolor(RGB(43,160,224));
	setbkmode(TRANSPARENT);      //字体透明背景
	settextstyle(38, 13, _T("华文彩云"));
	outtextxy(300,45,"Rubik");//Rubik
	outtextxy(300,405,"Help");//Help
//	setcolor(RGB(249,180,104));    //按钮定位
//	rectangle(200, 40, 455, 88);
	
	while(true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if(m.x>200&&m.x<455&&m.y>40&&m.y<88&&m.mkLButton)   //Rubik(三阶)的按钮按下
		{
			loadimage(&btn,".\\资源\\按钮（按下后）.jpg",255,48,true);
			putimage(200, 40, &btn);
			outtextxy(265, 45,"Welcome");
			Sleep(500);
			closegraph();
			break;
		}
		else if(m.x>200&&m.x<455&&m.y>400&&m.y<448&&m.mkLButton)  //Help的按钮按下
		{
			loadimage(&btn,".\\资源\\按钮（按下后）.jpg",255,48,true);
			putimage(200, 400, &btn);
			outtextxy(265, 405,"Welcome");
			Sleep(500);
		//	closegraph();   //当新开启绘图界面时，原界面可省略该句，仍能关闭
			help();
			welcome();  //调用自已，用以回到欢迎界面
			break;
		}
	}
}

void help()
{
	MOUSEMSG m;		// 定义鼠标消息
	IMAGE exit;
	graphdefaults();    //重置视图、当前点、绘图色、背景色、线形、填充类型、字体为默认值
	// 画渐变的背景
	initgraph(640, 480);
	float h = 0.0;		// 色相
	float s = 1;		// 饱和度
	float l = 0.7f;		// 亮度
	for(int y = 0; y < 480; y++)    //彩虹背景色
	{
		h += 0.72;
		l += 0.0005f;
		setlinecolor( HSLtoRGB(h, s, l) );
		line(0, y, 639, y);
	}

		//提示框
	setcolor(RGB(255, 174, 201));
	setbkmode(TRANSPARENT);      //字体透明背景
	setlinestyle(PS_SOLID, 10);
	roundrect(40, 40, 600, 440, 50, 50);     //圆角矩形
	
	LOGFONT f;
	//jokerman绿字提示
	gettextstyle(&f);   //获取当前字体设置,字体样式一定要在gettextstyle和settextstyle之间设置
	_tcscpy(f.lfFaceName, _T("jokerman")); 
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿 
	setcolor(GREEN);
	f.lfHeight = 50;  
	settextstyle(&f); 	//字体样式一定要在gettextstyle和settextstyle之间设置
	outtextxy(200, 50, "Rubik's Cube");
	//Ravie紫字提示
	gettextstyle(&f);                     // 获取当前字体设置
	setcolor(RGB(184, 39, 254));		//紫色
	f.lfHeight = 30;                      // 设置字体高度为 30
	_tcscpy(f.lfFaceName, _T("Ravie"));    // 设置字体为“Ravie”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式

	outtextxy(60, 100, "从键盘直接输入字符控制，各字符含义如下：");
	settextstyle(25, 10, 0);
	outtextxy(60, 130, "0:  按数字零退出程序。");
	outtextxy(60, 150, "*:  按星号键执行逆序法还原魔方。");
	outtextxy(60, 170, "+:  按加号键执行魔方传统的'层先法'进行还原。");
	outtextxy(60, 190, "R:  顺时针90°转右面。      r:  逆时针90°转右面。");
	outtextxy(60, 210, "U:  顺时针90°转顶面。      u:  逆时针90°转顶面。");
	outtextxy(60, 230, "L:  顺时针90°转左面。      l:  逆时针90°转左面。");
	outtextxy(60, 250, "D:  顺时针90°转底面。      d:  逆时针90°转底面。");
	outtextxy(60, 270, "F:  顺时针90°转前面。      f:  逆时针90°转前面。");
	outtextxy(60, 290, "B:  顺时针90°转背面。      b:  逆时针90°转背面。");
	outtextxy(60, 310, "M:  向下转中层。            m:  向上转中层。");
	outtextxy(60, 330, "X:  顺着x轴转90°。	        x:  逆着x轴转90°。");
	outtextxy(60, 350, "Y:  顺着y轴转90°。	        y:  逆着y轴转90°。");
	outtextxy(60, 370, "Z:  顺着z轴转90°。	        z:  逆着z轴转90°。");
  
//	setcolor(RGB(249,180,104));    //退出按钮定位
//	rectangle(200, 400, 455, 448);
	loadimage(&exit,".\\资源\\退出按钮.jpg",260,55,true);
	putimage(195, 400, &exit);
	while(true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if(m.x>200&&m.x<455&&m.y>400&&m.y<448&&m.mkLButton) 
		{
			break;
		}
	}
}

void play()
{
	void picture();
	void turn();

	initgraph(1150, 500, SHOWCONSOLE);// SHOWCONSOLE可显示控制台
	mciSendString("open \".\\资源\\background.mp3\" alias mymusic", NULL, 0, NULL);  // 打开背景音乐
	mciSendString("play mymusic repeat", NULL, 0, NULL);  // 播放音乐
	picture();
	turn();
	// 停止播放并关闭音乐
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	closegraph();
}

void picture()          //绘制背景
{
	void coloring();
	int i, j;
	graphdefaults();    //重置视图、当前点、绘图色、背景色、线形、填充类型、字体为默认值
	// 画渐变的背景
	float h = 0.0;		// 色相
	float s = 1;		// 饱和度
	float l = 0.7f;		// 亮度
	for(int y = 0; y < 500; y++)    //彩虹背景色
	{
		h += 0.72;
		l += 0.0005f;
		setlinecolor( HSLtoRGB(h, s, l) );
		line(0, y, 1149, y);
	}

    //立体图
	setlinestyle(PS_SOLID, 2);
	setlinecolor(RGB(233, 233, 233));          //画线
	//正面
	rectangle(50, 100, 200, 250);
	line(50, 150, 200, 150);
	line(50, 200, 200, 200);
	line(100, 100, 100, 250);
	line(150, 100, 150, 250);
	//上面
	line(70, 80, 220, 80);     
	line(90, 60, 240, 60); 
	line(110, 40, 260, 40);

	line(50, 100, 110, 40);
	line(100, 100, 160, 40);
	line(150, 100, 210, 40);
	line(200, 100, 260, 40);  
	//右面
	line(200, 150, 260, 90);
	line(200, 200, 260, 140);
	line(200, 250, 260, 190);

	line(220, 80, 220, 230);
	line(240, 60, 240, 210);
	line(260, 40, 260, 190);

	//展开图                      正方形边长50
	setorigin(500,30);
	for(i = 0; i<9; i++)
	{
		for(j = 0; j<3; j++)
		{
			rectangle(150+j*50, i*50, 200+j*50, i*50+50);
		}
	}

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 12; j++)
		{
			rectangle(j*50, 150+i*50, 50+j*50, 200+i*50);
		}
	}

	setorigin(0,0);
		                     //前面
	F[0][0].coordinate(55, 105, 655, 185);
	F[0][1].coordinate(105, 105, 705, 185);	
	F[0][2].coordinate(155, 105, 755, 185);
	F[1][0].coordinate(55, 155, 655, 235);
	F[1][1].coordinate(105, 155, 705, 235);	
	F[1][2].coordinate(155, 155, 755, 235);
	F[2][0].coordinate(55, 205, 655, 285);
	F[2][1].coordinate(105, 205, 705, 285);	
	F[2][2].coordinate(155, 205, 755, 285);

	                          //上面
	U[0][0].coordinate(115, 45, 655, 35);
	U[0][1].coordinate(165, 45, 705, 35);	
	U[0][2].coordinate(215, 45, 755, 35);
	U[1][0].coordinate(95, 65, 655, 85);
	U[1][1].coordinate(145, 65, 705, 85);	
	U[1][2].coordinate(195, 65, 755, 85);
	U[2][0].coordinate(75, 85, 655, 135);
	U[2][1].coordinate(125, 85, 705, 135);	
	U[2][2].coordinate(175, 85, 755, 135);
	
	                          //右面
	R[0][0].coordinate(205, 105, 805, 185);
	R[0][1].coordinate(225, 85, 855, 185);	
	R[0][2].coordinate(245, 65, 905, 185);
	R[1][0].coordinate(205, 155, 805, 235);
	R[1][1].coordinate(225, 135, 855, 235);	
	R[1][2].coordinate(245, 115, 905, 235);
	R[2][0].coordinate(205, 205, 805, 285);
	R[2][1].coordinate(225, 185, 855, 285);	
	R[2][2].coordinate(245, 165, 905, 285);
	
	                          //左面(只有展开图)
	L[0][0].coordinate(505, 185, 505, 185);
	L[0][1].coordinate(555, 185, 555, 185);	
	L[0][2].coordinate(605, 185, 605, 185);
	L[1][0].coordinate(505, 235, 505, 235);
	L[1][1].coordinate(555, 235, 555, 235);	
	L[1][2].coordinate(605, 235, 605, 235);
	L[2][0].coordinate(505, 285, 505, 285);
	L[2][1].coordinate(555, 285, 555, 285);	
	L[2][2].coordinate(605, 285, 605, 285);

	                          //下面(只有展开图)
	D[0][0].coordinate(655, 335, 655, 335);
	D[0][1].coordinate(705, 335, 705, 335);	
	D[0][2].coordinate(755, 335, 755, 335);
	D[1][0].coordinate(655, 385, 655, 385);
	D[1][1].coordinate(705, 385, 705, 385);	
	D[1][2].coordinate(755, 385, 755, 385);
	D[2][0].coordinate(655, 435, 655, 435);
	D[2][1].coordinate(705, 435, 705, 435);	
	D[2][2].coordinate(755, 435, 755, 435);

	                          //背面(只有展开图)
	B[0][0].coordinate(955, 185, 955, 185);
	B[0][1].coordinate(1005, 185, 1005, 185);	
	B[0][2].coordinate(1055, 185, 1055, 185);
	B[1][0].coordinate(955, 235, 955, 235);
	B[1][1].coordinate(1005, 235, 1005, 235);	
	B[1][2].coordinate(1055, 235, 1055, 235);
	B[2][0].coordinate(955, 285, 955, 285);
	B[2][1].coordinate(1005, 285, 1005, 285);	
	B[2][2].coordinate(1055, 285, 1055, 285);

	static bool nocolor = true;
	if(nocolor)                   //颜色初始化
	{
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				F[i][j].color = RGB(0, 255, 255);  //蓝
				U[i][j].color = RGB(255, 255, 128);  //黄
				R[i][j].color = RGB(253, 4, 98);  //红
				L[i][j].color = RGB(255, 183, 78);  //橙
				D[i][j].color = RGB(255, 255, 255);  //白
				B[i][j].color = RGB(128, 255, 128);  //绿
			}
		}
		nocolor = false;
	}

	coloring();
	//为移动的文字做准备
	settextcolor(RGB(255, 128, 192));		// 设置文字颜色为粉色
	setbkmode(TRANSPARENT);		// 设置文字背景为透明色
	settextstyle(28, 10, _T("华文行楷"));
}

void coloring()           //涂色
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			F[i][j].coloring();  
			U[i][j].coloring();
			R[i][j].coloring();
			L[i][j].coloring();
			D[i][j].coloring();
			B[i][j].coloring();
		}
	}
}

int word(char word[])                               //运动的字
{
	void picture();
	//定义字符串

	setbkmode(TRANSPARENT);      //字体透明背景

	FlushMouseMsgBuffer();   //清除鼠标消息缓冲区

	//定义字符串初始位置
	int x = 10;
	int y = 10;

	//获取字符串高度、宽度
	int w = textwidth(word);
	int h = textheight(word);

	//判断移动方向
	bool isLeft = false;
	bool isUp = false;

	BeginBatchDraw();   //开始批量绘图

	bool flag = true;
	//绘制移动文字
	while(flag)
	{
		FlushBatchDraw();
		picture();         //绘制背景

          //实现用鼠标达到退出动画的效果
		while(MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();
			if((m.x>x)&(m.x<(x+w))&(m.y>y)&(m.y<(y+h)))
			{
				BeginBatchDraw();   //开始批量绘图
				picture(); 
				FlushBatchDraw();  //批量绘图显示picture
				EndBatchDraw();   //结束批量绘图
				flag = false;
				return 0;
			}
		}

		if( x - 10 <= 0 ) isLeft = false;
		if( x + w + 10 >= 1150 ) isLeft = true;
		if( y - 10 <= 0 ) isUp = false;
		if( y + h + 10 >= 500) isUp = true;


		if( isLeft )
		x -= 10;
		else 
		x += 10;
		if( isUp )
		y -= 10;
		else 
		y += 10;


		outtextxy(x, y, word);


		Sleep(100);
	}

	//退出
	EndBatchDraw();
}

void turn()               //转魔方
{
	void computer();
	void coloring();
	char turn[100] = "";
	bool ifwin();
	int word(char word[]);

	system("color BD");  //设置控制台前景色和背景色

	for(int i = 0; i<100; i++)
	{
		turn[i] = '1';
	}
	i = 0;

	cout<<endl<<"你的步骤如下:"<<endl;
	turn[i] = getch(); 
	cout<<turn[i]<<" ";
	while(turn[i]!='0')
	{
		switch(turn[i])
		{	
			case'R':Right();break;
			case'r':right();break;
			case'U':Up();break;
			case'u':up();break;
			case'L':Left();break;
			case'l':left();break;
			case'D':Down();break;
			case'd':down();break;
			case'F':Front();break;
			case'f':front();break;
			case'B':Back();break;
			case'b':back();break;
			case'M':M();break;
			case'm':m();break;
			case'X':X();break;
			case'x':x();break;
			case'Y':Y();break;
			case'y':y();break;
			case'Z':Z();break;
			case'z':z();break;
			case'+':computer();break;  //电脑控制(传统层先法)
//			case'*':break;    //电脑控制(逆序法)
			case'0':exit(1);
			default:break; 
		}

		if(ifwin())        //判断是否复原
		{
			word("复原成功~(碰我重新开始哦^_^)");
			for(i = 0; i<100; i++)    //重新开始，再次初始化
			{
				turn[i] = '1';
			}
			i = 0;
			cout<<endl<<"你的步骤如下:"<<endl;
		}

		if(turn[i]=='*'||turn[i+1]!='1')   //按下‘*’后用逆序步骤的方法复原
		{
			if(turn[i]=='*')
			{
				cout<<endl<<"电脑逆序复原步骤如下:"<<endl;
			}
			i--;
			if(65<=turn[i]&&turn[i]<=90)
			{
				turn[i] = turn[i] + 32;
			}
			else if(97<=turn[i]&&turn[i]<=122)
			{
				turn[i] = turn[i] - 32;
			}
			cout<<turn[i]<<" ";
			Sleep(100);
		}
		else         //没按‘*’或‘+’则继续输入，手工旋转魔方
		{
			i++;
			turn[i] = getch();	
			cout<<turn[i]<<" ";
		}
	}
}

bool ifwin()     //判断是否六面复原
{
	bool f(Face p[][3]);
	if(f(F)&f(R)&f(U)&f(L)&f(D)&f(B))
	{
		return true;
	}
	return false;
}

bool f(Face p[][3])    //判断调入的那个面是否复原
{
	COLORREF need;
	need = p[0][0].color;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(need!=p[i][j].color)
			{
				return false;
			}
		}
	}
	return true;
}

void Circle(Face p[][3])     //顺时针面转圈
{
	COLORREF t;
	t = p[0][0].color;
	p[0][0].color = p[2][0].color;
	p[2][0].color = p[2][2].color;
	p[2][2].color = p[0][2].color;
	p[0][2].color = t;
	t = p[0][1].color;
	p[0][1].color = p[1][0].color;
	p[1][0].color = p[2][1].color;
	p[2][1].color = p[1][2].color;
	p[1][2].color = t;
}

void Right()    //顺时针
{
	BeginBatchDraw(); 
	right();
	right();
	right();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();
}

void right()  //逆时针
{
	COLORREF t;
	void Circle(Face p[][3]);
	for(int i = 0; i < 3; i++)
	{
		t = F[i][2].color;
		F[i][2].color = U[i][2].color;
		U[i][2].color = B[2-i][0].color;
		B[2-i][0].color = D[i][2].color;
		D[i][2].color = t;
	}
	Circle(R);
	Circle(R);
	Circle(R);
	coloring();
}

void Up()   //顺时针
{
	COLORREF t;
	void Circle(Face p[][3]);
	for(int i = 0; i < 3; i++)
	{
		t = F[0][i].color;
		F[0][i].color = R[0][i].color;
		R[0][i].color = B[0][i].color;
		B[0][i].color = L[0][i].color;
		L[0][i].color = t;
	}
	Circle(U);
	coloring();
}

void up()   //逆时针
{
	BeginBatchDraw();   //批量绘图开始
	Up();
	Up();
	Up();
	coloring();
	FlushBatchDraw(); //批量绘图显示
	EndBatchDraw();   //批量绘图结束

}

void Left()   //顺时针
{
	COLORREF t;
	void Circle(Face p[][3]);
	for(int i = 0; i < 3; i++)
	{
		t = F[i][0].color;
		F[i][0].color = U[i][0].color;
		U[i][0].color = B[2-i][2].color;
		B[2-i][2].color = D[i][0].color;
		D[i][0].color = t;
	}
	Circle(L);
	coloring();
}

void left()   //逆时针
{
	BeginBatchDraw(); 
	Left();
	Left();
	Left();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void Down()  //顺时针
{
	BeginBatchDraw(); 
	down();
	down();
	down();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void down()  //逆时针
{
	COLORREF t;
	void Circle(Face p[][3]);
	for(int i = 0; i < 3; i++)
	{
		t = F[2][i].color;
		F[2][i].color = R[2][i].color;
		R[2][i].color = B[2][i].color;
		B[2][i].color = L[2][i].color;
		L[2][i].color = t;
	}
	Circle(D);
	Circle(D);
	Circle(D);
	coloring();
}

void Front()   //顺时针
{
	COLORREF t;
	void Circle(Face p[][3]);
	for(int i = 0; i < 3; i++)
	{
		t = U[2][i].color;
		U[2][i].color = L[2-i][2].color;
		L[2-i][2].color = D[0][2-i].color;
		D[0][2-i].color = R[i][0].color;
		R[i][0].color = t;
	}
	Circle(F);
	coloring();
}

void front()  //逆时针
{
	BeginBatchDraw(); 
	Front();
	Front();
	Front();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void Back()  //顺时针
{
	BeginBatchDraw(); 
	back();
	back();
	back();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void back()   //逆时针
{
	COLORREF t;
	void Circle(Face p[][3]);
	for(int i = 0; i < 3; i++)
	{
		t = U[0][i].color;
		U[0][i].color = L[2-i][0].color;
		L[2-i][0].color = D[2][2-i].color;
		D[2][2-i].color = R[i][2].color;
		R[i][2].color = t;
	}
	Circle(B);
	Circle(B);
	Circle(B);
	coloring();
}

void M()    //顺时针
{
	COLORREF t;
	for(int i = 0; i < 3; i++)
	{
		t = F[i][1].color;
		F[i][1].color = U[i][1].color;
		U[i][1].color = B[2-i][1].color;
		B[2-i][1].color = D[i][1].color;
		D[i][1].color = t;
	}
	coloring();
}

void m()     //逆时针
{
	BeginBatchDraw(); 
	M();
	M();
	M();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void X()     //顺时针
{
	COLORREF t;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			t = F[i][j].color;
			F[i][j].color = D[i][j].color;
			D[i][j].color = B[2-i][2-j].color;
			B[2-i][2-j].color = U[i][j].color;
			U[i][j].color = t;
		}
	}
	Circle(R);
	Circle(L);
	Circle(L);
	Circle(L);
	coloring();
}

void x()    //逆时针
{
	BeginBatchDraw(); 
	X();
	X();
	X();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();
}

void Y()      //顺时针
{
	COLORREF t;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			t = F[i][j].color;
			F[i][j].color = R[i][j].color;
			R[i][j].color = B[i][j].color;
			B[i][j].color = L[i][j].color;
			L[i][j].color = t;
		}
	}
	Circle(U);
	Circle(D);
	Circle(D);
	Circle(D);
	coloring();
}

void y()    //逆时针
{
	BeginBatchDraw(); 
	Y();
	Y();
	Y();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();
}

void Z()    //顺时针
{
	COLORREF t;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			t = R[i][j].color;
			R[i][j].color = U[2-j][i].color;
			U[2-j][i].color = L[2-i][2-j].color;
			L[2-i][2-j].color = D[j][2-i].color;
			D[j][2-i].color = t;
		}
	}
	Circle(F);
	Circle(B);
	Circle(B);
	Circle(B);
	coloring();
}

void z()     //逆时针
{
	BeginBatchDraw(); 
	Z();
	Z();
	Z();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();
}

void Do(char turn[])
{
	int i = 0;
	while(turn[i]!='\0')
	{
		switch(turn[i])
		{
			case'R':Right();break;
			case'r':right();break;
			case'U':Up();break;
			case'u':up();break;
			case'L':Left();break;
			case'l':left();break;
			case'D':Down();break;
			case'd':down();break;
			case'F':Front();break;
			case'f':front();break;
			case'B':Back();break;
			case'b':back();break;
			case'M':M();break;
			case'm':m();break;
			case'X':X();break;
			case'x':x();break;
			case'Y':Y();break;
			case'y':y();break;
			case'Z':Z();break;
			case'z':z();break;
			default:break;
		}
		cout<<turn[i]<<" ";
		Sleep(100);
		i++;
	}
}

void computer()                   //电脑控制(层先法)
{
	void cross(); //底层十字
	void two(); //底层四角
	void three();  //中层棱块
	void four();  //复原四个顶层棱块色相
	void five();  //复原四个顶层角块色相
	void six();  //复原四个顶层角块位置
	void seven();  //复原四个顶层棱块位置

	cout<<endl<<"电脑复原步骤如下:"<<endl;
	while(1)
	{
		if(D[0][1].color==D[1][1].color
			&&D[1][0].color==D[1][1].color
			&&D[1][2].color==D[1][1].color
			&&D[2][1].color==D[1][1].color
			&&F[2][1].color==F[1][1].color
			&&L[2][1].color==L[1][1].color
			&&R[2][1].color==R[1][1].color
			&&B[2][1].color==B[1][1].color)
		{
			cout<<endl<<"底角十字成功复原~"<<endl;
			break;
		}
		cross();    //底层十字
	}

	while(1)
	{
		if(D[0][0].color==D[1][1].color
			&&L[2][2].color==L[1][1].color
			&&F[2][0].color==F[1][1].color
			&&D[0][2].color==D[1][1].color
			&&F[2][2].color==F[1][1].color
			&&R[2][0].color==R[1][1].color
			&&D[2][2].color==D[1][1].color
			&&R[2][2].color==R[1][1].color
			&&B[2][0].color==B[1][1].color
			&&D[2][0].color==D[1][1].color
			&&B[2][2].color==B[1][1].color
			&&L[2][0].color==L[1][1].color)
		{
			cout<<endl<<"四底角成功复原~"<<endl;
			break;
		}
		two();   //底层四角
	}

	while(1)
	{
		if(F[1][0].color==F[1][1].color
			&&L[1][2].color==L[1][1].color
			&&F[1][2].color==F[1][1].color
			&&R[1][0].color==R[1][1].color
			&&R[1][2].color==R[1][1].color
			&&B[1][0].color==B[1][1].color
			&&B[1][2].color==B[1][1].color
			&&L[1][0].color==L[1][1].color)
		{
			cout<<endl<<"中棱成功复原~"<<endl;
			break;
		}
		three(); 
	}

	four();
	five();
	six();
	seven();
}

void seven()  //复原四个顶层棱块位置
{
	void Do(char turn[]);
	while(1)
	{	
		if(F[0][1].color==F[1][1].color
			&&R[0][1].color==R[1][1].color
			&&B[0][1].color==B[1][1].color
			&&L[0][1].color==L[1][1].color)
		{
			break;
		}
		else if(L[0][1].color==F[1][1].color
			&&F[0][1].color==R[1][1].color
			&&R[0][1].color==L[1][1].color)
		{
			Do("RuRURURuruRR"); //x+10
		}
		else if(F[0][1].color==L[1][1].color
			&&L[0][1].color==R[1][1].color
			&&R[0][1].color==F[1][1].color)
		{
			Do("lUlululULULL");  //x+10+10
		}
		else if(L[0][1].color==R[1][1].color
			&&R[0][1].color==L[1][1].color
			&&F[0][1].color==B[1][1].color
			&&B[0][1].color==F[1][1].color)
		{
			Do("mmUmmUUmmUmm");  //x+10+U+10+u
		}
		else if(L[0][1].color==F[1][1].color
			&&F[0][1].color==L[1][1].color
			&&B[0][1].color==R[1][1].color
			&&R[0][1].color==B[1][1].color)
		{
			Do("mUmmUmmUmUUmmu");  //x+10+u+10+U
		}
		else
		{
			Do("y");
		}
	}
	cout<<endl<<"四个顶层棱块位置成功复原~"<<endl;
	cout<<"魔方成功复原~"<<endl;
}

void six()  //复原四个顶层角块位置
{
	void Do(char turn[]);

	while(F[0][0].color!=F[1][1].color
		||F[0][2].color!=F[1][1].color
		||R[0][0].color!=R[1][1].color
		||R[0][2].color!=R[1][1].color
		||B[0][0].color!=B[1][1].color
		||B[0][2].color!=B[1][1].color
		||L[0][0].color!=L[1][1].color
		||L[0][2].color!=L[1][1].color)
	{	
		if(L[0][2].color==L[0][0].color
			&&R[0][2].color!=R[0][0].color)
		{
			Do("RUrurFRRuruRUrf");
		}
		else if(L[0][2].color!=L[0][0].color
			&&R[0][2].color!=R[0][0].color
			&&F[0][2].color!=F[0][0].color
			&&B[0][2].color!=B[0][0].color)
		{
			Do("FRuruRUrfRUrurFRf");
		}
		else
		{
			Do("U");
		}
		
	}
	cout<<endl<<"四个顶层角块位置成功复原~"<<endl;
}

void five()  //复原四个顶层角块色相
{
	void Do(char turn[]);
	while(U[0][0].color!=U[1][1].color
		||U[0][2].color!=U[1][1].color
		||U[2][0].color!=U[1][1].color
		||U[2][2].color!=U[0][0].color)   //7:RUUruRur  8:RUrURUUr
	{  
		//顶层鱼
		if(U[0][2].color==U[1][1].color
			&&U[0][0].color!=U[1][1].color
			&&U[2][0].color!=U[1][1].color
			&&U[2][2].color!=U[1][1].color)
		{
			if(L[0][0].color==U[1][1].color
				&&F[0][0].color==U[1][1].color
				&&R[0][0].color==U[1][1].color)
			{
				Do("RUUruRur"); //7
			}
			else if(L[0][2].color==U[1][1].color
				&&F[0][2].color==U[1][1].color
				&&B[0][2].color==U[1][1].color)
			{
				Do("UURUrURUUr");  //UU+8
			}
		}
		//顶层十字形
		else if(U[0][0].color!=U[1][1].color
			&&U[0][2].color!=U[1][1].color
			&&U[2][0].color!=U[1][1].color
			&&U[2][2].color!=U[1][1].color)
		{   
			 //对称十字
			if(F[0][0].color==U[1][1].color
				&&F[0][2].color==U[1][1].color
				&&B[0][0].color==U[1][1].color
				&&B[0][2].color==U[1][1].color)
			{
				Do("RUUruRurRUUruRur"); //7+7
			}
			else if(L[0][0].color==U[1][1].color
				&&L[0][2].color==U[1][1].color
				&&F[0][2].color==U[1][1].color
				&&B[0][0].color==U[1][1].color)
			{
				Do("RUUruRuruRUUruRur"); //7+u+7
			}
		}
		//顶层由字形
		else if(U[2][0].color==U[1][1].color&&U[2][2].color==U[1][1].color)
		{
			if(B[0][0].color==U[1][1].color&&B[0][2].color==U[1][1].color)
			{
				Do("YRUUruRuruRUrURUUr");  //Y+7+u+8
			}
			else if(L[0][0].color==U[1][1].color&&R[0][2].color==U[1][1].color)
			{
				Do("RUUruRurURUrURUUr");  //7+U+8
			}
		}
		//顶层蝴蝶形
		else if(U[0][0].color==U[1][1].color
			&&U[2][2].color==U[1][1].color
			&&F[0][0].color==U[1][1].color
			&&R[0][2].color==U[1][1].color)
		{
			Do("RUUruRurUURUrURUUr");  //7+UU+8
		}
		Do("U");
	}	
	cout<<endl<<"四个顶层角块色相成功复原~"<<endl;
}

void four()  //复原四个顶层棱块色相
{
	void Do(char turn[]);
	bool flag = false;

	while(!flag)
	{
		if(U[0][1].color==U[1][1].color
			&&U[1][0].color==U[1][1].color
			&&U[1][2].color==U[1][1].color
			&&U[2][1].color==U[1][1].color)
		{
			cout<<endl<<"四个顶层棱块色相成功复原~"<<endl;
			flag = true;
		}
		else
		{
			if(F[0][1].color==U[1][1].color
				&&(U[1][0].color==U[1][1].color
				||R[0][1].color==U[1][1].color))
			{
				Do("FRUruf");
				continue;
			}
			Do("U");
		}
	}
}

void three()  //中层棱块 
{
	void Do(char turn[]);
	int i = 1; 
	while(1)
	{
		if(F[1][2].color==F[1][1].color&&R[1][0].color==R[1][1].color)
		{
			cout<<"正确还原一中层棱块";
			Do("y"); 
			break;
		}
		else
		{
		
				if(F[0][1].color==F[1][1].color&&U[2][1].color==R[1][1].color)
				{
					Do("URurufUF");
				}
				else if(F[0][1].color==F[1][1].color&&U[2][1].color==L[1][1].color)
				{
					Do("ulULUFufy");
				}
				else
				{	
					if(i<4)           
					{
						Do("U");
						i++;	
					}
					else if(i == 4)
					{
						Do("URurufUF");
						Do("y");
						i = 0;
					}
				}
		}
	}
}

void two()   //底层四角
{
	void Do(char turn[]);
	int i = 1; 
	while(1)  
	{
		if(F[2][2].color==F[1][1].color
			&&R[2][0].color==R[1][1].color
			&&D[0][2].color==D[1][1].color)   //该角正确
		{	
			cout<<"正确还原一角块";
			Do("y"); 
			break;
		}
		else
		{
			Do("U");  //Up(); 利用i循环转三次
			if(F[0][2].color==F[1][1].color
				&&R[0][0].color==D[1][1].color
				&&U[2][2].color==R[1][1].color)
			{
				Do("RUr");
			}
			else if(F[0][2].color==D[1][1].color
				&&R[0][0].color==R[1][1].color
				&&U[2][2].color==F[1][1].color)
			{
				Do("URur");
			}
			else if(F[0][2].color==R[1][1].color
				&&R[0][0].color==F[1][1].color
				&&U[2][2].color==D[1][1].color)
			{
				Do("RurUURUr");
			}
			else
			{
				if(i<4)             //寻找顶上四角与底面同色的面
				{
					i++;	
				}
				else if(i == 4)           //顶上四角找不到与底面同色的面
				{
					i++;
					Do("Rur");
				}
				else
				{
					Do("y");
					i = 0;
				}
			}
		}
	}
}

void cross()     //底层十字  
{
	void Do(char turn[]);
		/*FU*/
	if(U[2][1].color==D[1][1].color&&F[0][1].color==F[1][1].color)
	{
		Do("FF");
	}
	else if(U[2][1].color==D[1][1].color&&F[0][1].color==R[1][1].color)
	{
		Do("uRR");
	}
	else  if(U[2][1].color==D[1][1].color&&F[0][1].color==L[1][1].color)
	{
		Do("ULL");
	}
	else if(U[2][1].color==D[1][1].color&&F[0][1].color==B[1][1].color)
	{
		Do("UUBB");
	}
	else if(F[0][1].color==D[1][1].color&&U[2][1].color==F[1][1].color)
	{
		Do("FDrd");
	}
	else if(F[0][1].color==D[1][1].color&&U[2][1].color==R[1][1].color)
	{
		Do("Frf");
	}
	else if(F[0][1].color==D[1][1].color&&U[2][1].color==L[1][1].color)
	{
		Do("FDrd");
	}
	else if(F[0][1].color==D[1][1].color&&U[2][1].color==B[1][1].color)
	{
		Do("UrFR");
	}

		/*RU*/
	else if(U[1][2].color==D[1][1].color&&R[0][1].color==F[1][1].color)
	{
		Do("UFF");
	}

	else if(U[1][2].color==D[1][1].color&&R[0][1].color==R[1][1].color)
	{
		Do("RR");
	}
	else if(U[1][2].color==D[1][1].color&&R[0][1].color==L[1][1].color)
	{
		Do("UULL");
	}
	else if(U[1][2].color==D[1][1].color&&R[0][1].color==B[1][1].color)
	{
		Do("uBB");
	}
	else if(R[0][1].color==D[1][1].color&&U[1][2].color==F[1][1].color)
	{
		Do("rFR");
	}
	else if(R[0][1].color==D[1][1].color&&U[1][2].color==R[1][1].color)
	{
		Do("rdFD");
	}
	else if(R[0][1].color==D[1][1].color&&U[1][2].color==L[1][1].color)
	{
		Do("UfLF");
	}
	else if(R[0][1].color==D[1][1].color&&U[1][2].color==B[1][1].color)
	{
		Do("Rbr");
	}

	/*BU*/
	else if(U[0][1].color==D[1][1].color&&B[0][1].color==F[1][1].color)
	{
		Do("UUFF");
	}
	else if(U[0][1].color==D[1][1].color&&B[0][1].color==R[1][1].color)
	{
		Do("URR");
	}
	else if(U[0][1].color==D[1][1].color&&B[0][1].color==L[1][1].color)
	{
		Do("uLL");
	}
	else if(U[0][1].color==D[1][1].color&&B[0][1].color==B[1][1].color)
	{
		Do("BB");
	}
	else if(B[0][1].color==D[1][1].color&&U[0][1].color==F[1][1].color)
	{
		Do("UrFR");
	}
	else if(B[0][1].color==D[1][1].color&&U[0][1].color==R[1][1].color)
	{
		Do("bRB");
	}
	else if(B[0][1].color==D[1][1].color&&U[0][1].color==B[1][1].color)
	{
		Do("BDld");
	}
	else if(B[0][1].color==D[1][1].color&&U[0][1].color==L[1][1].color)
	{
		Do("Blb");
	}

	/*LU*/
	else if(U[1][0].color==D[1][1].color&&L[0][1].color==F[1][1].color)
	{
		Do("uFF");
	}
	else if(U[1][0].color==D[1][1].color&&L[0][1].color==R[1][1].color)
	{
		Do("UURR");
	}
	else if(U[1][0].color==D[1][1].color&&L[0][1].color==B[1][1].color)
	{
		Do("UBB");
	}
	else if(U[1][0].color==D[1][1].color&&L[0][1].color==L[1][1].color)
	{
		Do("LL");
	}
	else if(L[0][1].color==D[1][1].color&&U[1][0].color==F[1][1].color)
	{
		Do("Lfl");
	}
	else if(L[0][1].color==D[1][1].color&&U[1][0].color==R[1][1].color)
	{
		Do("uFrf");
	}
	else if(L[0][1].color==D[1][1].color&&U[1][0].color==B[1][1].color)
	{
		Do("lbL");
	}
	else if(L[0][1].color==D[1][1].color&&U[1][0].color==L[1][1].color)
	{
		Do("Lfl");
	}

	/*FD*/
	else if(D[0][1].color==D[1][1].color&&F[2][1].color==R[1][1].color)
	{
		Do("RDrdR");
	}
	else if(D[0][1].color==D[1][1].color&&F[2][1].color==B[1][1].color)
	{
		Do("FDDfDDF");
	}
	else if(D[0][1].color==D[1][1].color&&F[2][1].color==L[1][1].color)
	{
		Do("FDfdF");
	}
	else if(F[2][1].color==D[1][1].color&&D[0][1].color==F[1][1].color)
	{
		Do("fDrd");
	}
	else if(F[2][1].color==D[1][1].color&&D[0][1].color==R[1][1].color)
	{
		Do("fr");
	}
	else if(F[2][1].color==D[1][1].color&&D[0][1].color==B[1][1].color)
	{
		Do("fdRD");
	}
	else if(F[2][1].color==D[1][1].color&&D[0][1].color==L[1][1].color)
	{
		Do("FL");
	}

	/*RD*/
	else if(D[1][2].color==D[1][1].color&&R[2][1].color==F[1][1].color)
	{
		Do("RDrdR");
	}
	else if(D[1][2].color==D[1][1].color&&R[2][1].color==B[1][1].color)
	{
		Do("RdrDR");
	}
	else if(D[1][2].color==D[1][1].color&&R[2][1].color==L[1][1].color)
	{
		Do("RDDrDDR");
	}
	else if(R[2][1].color==D[1][1].color&&D[1][2].color==F[1][1].color)
	{
		Do("RF");
	}
	else if(R[2][1].color==D[1][1].color&&D[1][2].color==R[1][1].color)
	{
		Do("RdFD");
	}
	else if(R[2][1].color==D[1][1].color&&D[1][2].color==B[1][1].color)
	{
		Do("rb");
	}
	else if(R[2][1].color==D[1][1].color&&D[1][2].color==L[1][1].color)
	{
		Do("RDFd");
	}

	/*BD*/
	else if(D[2][1].color==D[1][1].color&&B[2][1].color==F[1][1].color)
	{
		Do("FDDfDDF");
	}
	else if(D[2][1].color==D[1][1].color&&B[2][1].color==R[1][1].color)
	{
		Do("RdrDR");
	}
	else if(D[2][1].color==D[1][1].color&&B[2][1].color==L[1][1].color)
	{
		Do("LDldL");
	}
	else if(B[2][1].color==D[1][1].color&&D[2][1].color==F[1][1].color)
	{
		Do("BDRb");
	}
	else if(B[2][1].color==D[1][1].color&&D[2][1].color==R[1][1].color)
	{
		Do("BR");
	}
	else if(B[2][1].color==D[1][1].color&&D[2][1].color==B[1][1].color)
	{
		Do("BdRD");
	}
	else if(B[2][1].color==D[1][1].color&&D[2][1].color==L[1][1].color)
	{
		Do("bL");
	}

	/*LD*/
	else if(D[1][0].color==D[1][1].color&&L[2][1].color==F[1][1].color)
	{
		Do("FDfdF");
	}
	else if(D[1][0].color==D[1][1].color&&L[2][1].color==R[1][1].color)
	{
		Do("RDDrDDR");
	}
	else if(D[1][0].color==D[1][1].color&&L[2][1].color==B[1][1].color)
	{
		Do("LDldL");
	}
	else if(L[2][1].color==D[1][1].color&&D[1][0].color==F[1][1].color)
	{
		Do("lf");
	}
	else if(L[2][1].color==D[1][1].color&&D[1][0].color==R[1][1].color)
	{
		Do("ldfD");
	}
	else if(L[2][1].color==D[1][1].color&&D[1][0].color==B[1][1].color)
	{
		Do("LB");
	}
	else if(L[2][1].color==D[1][1].color&&D[1][0].color==L[1][1].color)
	{
		Do("lDfd");

	}

	/*FR*/
	else if(F[1][2].color==D[1][1].color&&R[1][0].color==F[1][1].color)
	{
		Do("Drd");
	}
	else if(F[1][2].color==D[1][1].color&&R[1][0].color==R[1][1].color)
	{
		Do("r");
	}
	else if(F[1][2].color==D[1][1].color&&R[1][0].color==B[1][1].color)
	{
		Do("drD");
	}
	else if(F[1][2].color==D[1][1].color&&R[1][0].color==L[1][1].color)
	{
		Do("DDrDD");
	}
	else if(R[1][0].color==D[1][1].color&&F[1][2].color==F[1][1].color)
	{
		Do("F");
	}
	else if(R[1][0].color==D[1][1].color&&F[1][2].color==R[1][1].color)
	{
		Do("dFD");
	}
	else if(R[1][0].color==D[1][1].color&&F[1][2].color==B[1][1].color)
	{
		Do("DDFDD");
	}
	else if(R[1][0].color==D[1][1].color&&F[1][2].color==L[1][1].color)
	{
		Do("DFd");
	}

	/*BR*/
	else if(R[1][2].color==D[1][1].color&&B[1][0].color==F[1][1].color)
	{
		Do("DDbDD");
	}
	else if(R[1][2].color==D[1][1].color&&B[1][0].color==R[1][1].color)
	{
		Do("RRFRR");
	}
	else if(R[1][2].color==D[1][1].color&&B[1][0].color==B[1][1].color)
	{
		Do("b");
	}
	else if(R[1][2].color==D[1][1].color&&B[1][0].color==L[1][1].color)
	{
		Do("dbD");
	}
	else if(B[1][0].color==D[1][1].color&&R[1][2].color==F[1][1].color)
	{
		Do("DRd");
	}
	
	else if(B[1][0].color==D[1][1].color&&R[1][2].color==R[1][1].color)
	{
		Do("R");
	}
	else if(B[1][0].color==D[1][1].color&&R[1][2].color==B[1][1].color)
	{
		Do("dRD");
	}
	else if(B[1][0].color==D[1][1].color&&R[1][2].color==L[1][1].color)
	{
		Do("DDRDD");
	}

	/*BL*/
	else if(B[1][2].color==D[1][1].color&&L[1][0].color==F[1][1].color)
	{
		Do("dlD");
	}
	else if(B[1][2].color==D[1][1].color&&L[1][0].color==R[1][1].color)
	{
		Do("DDlDD");
	}
	else if(B[1][2].color==D[1][1].color&&L[1][0].color==B[1][1].color)
	{
		Do("Dld");
	}
	else if(B[1][2].color==D[1][1].color&&L[1][0].color==L[1][1].color)
	{
		Do("l");
	}
	else if(L[1][0].color==D[1][1].color&&B[1][2].color==F[1][1].color)
	{
		Do("LLfLL");
	}
	else if(L[1][0].color==D[1][1].color&&B[1][2].color==R[1][1].color)
	{
		Do("DBd");
	}
	else if(L[1][0].color==D[1][1].color&&B[1][2].color==B[1][1].color)
	{
		Do("B");
	}
	else if(L[1][0].color==D[1][1].color&&B[1][2].color==L[1][1].color)
	{
		Do("dBD");
	}

	/*LF*/	
	else if(L[1][2].color==D[1][1].color&&F[1][0].color==F[1][1].color)
	{
		Do("f");
	}
	else if(L[1][2].color==D[1][1].color&&F[1][0].color==R[1][1].color)
	{
		Do("dfD");
	}
	else if(L[1][2].color==D[1][1].color&&F[1][0].color==B[1][1].color)
	{
		Do("LLbLL");
	}
	else if(L[1][2].color==D[1][1].color&&F[1][0].color==L[1][1].color)
	{
		Do("Dfd");
	}
	else if(F[1][0].color==D[1][1].color&&L[1][2].color==F[1][1].color)
	{
		Do("dLD");
	}
	else if(F[1][0].color==D[1][1].color&&L[1][2].color==R[1][1].color)
	{
		Do("DDLDD");
	}
	else if(F[1][0].color==D[1][1].color&&L[1][2].color==B[1][1].color)
	{
		Do("DLd");
	}
	else if(F[1][0].color==D[1][1].color&&L[1][2].color==L[1][1].color)
	{
		Do("L");
	}
}







