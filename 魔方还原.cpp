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
	int iX1, iY1;      //������С��Ϳɫ����
	int iX2, iY2;      //չ��ͼС��Ϳɫ����
};

Face::Face()
{
	color =  RGB(0, 0, 0);              //��ʼ��
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

void welcome()       //��ӭ����
{
	void help();
	initgraph(640, 480);
	IMAGE img, btn;
	MOUSEMSG m;		// ���������Ϣ

	loadimage(&img,".\\��Դ\\Rubik.jpg",640,480,true);
	putimage(0, 0, &img);
	loadimage(&btn,".\\��Դ\\��ť.jpg",255,48,true);
	putimage(200, 40, &btn);  //Rubik�İ�ť
	putimage(200, 400, &btn);  //Help�İ�ť
	setcolor(RGB(43,160,224));
	setbkmode(TRANSPARENT);      //����͸������
	settextstyle(38, 13, _T("���Ĳ���"));
	outtextxy(300,45,"Rubik");//Rubik
	outtextxy(300,405,"Help");//Help
//	setcolor(RGB(249,180,104));    //��ť��λ
//	rectangle(200, 40, 455, 88);
	
	while(true)
	{
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if(m.x>200&&m.x<455&&m.y>40&&m.y<88&&m.mkLButton)   //Rubik(����)�İ�ť����
		{
			loadimage(&btn,".\\��Դ\\��ť�����º�.jpg",255,48,true);
			putimage(200, 40, &btn);
			outtextxy(265, 45,"Welcome");
			Sleep(500);
			closegraph();
			break;
		}
		else if(m.x>200&&m.x<455&&m.y>400&&m.y<448&&m.mkLButton)  //Help�İ�ť����
		{
			loadimage(&btn,".\\��Դ\\��ť�����º�.jpg",255,48,true);
			putimage(200, 400, &btn);
			outtextxy(265, 405,"Welcome");
			Sleep(500);
		//	closegraph();   //���¿�����ͼ����ʱ��ԭ�����ʡ�Ըþ䣬���ܹر�
			help();
			welcome();  //�������ѣ����Իص���ӭ����
			break;
		}
	}
}

void help()
{
	MOUSEMSG m;		// ���������Ϣ
	IMAGE exit;
	graphdefaults();    //������ͼ����ǰ�㡢��ͼɫ������ɫ�����Ρ�������͡�����ΪĬ��ֵ
	// ������ı���
	initgraph(640, 480);
	float h = 0.0;		// ɫ��
	float s = 1;		// ���Ͷ�
	float l = 0.7f;		// ����
	for(int y = 0; y < 480; y++)    //�ʺ米��ɫ
	{
		h += 0.72;
		l += 0.0005f;
		setlinecolor( HSLtoRGB(h, s, l) );
		line(0, y, 639, y);
	}

		//��ʾ��
	setcolor(RGB(255, 174, 201));
	setbkmode(TRANSPARENT);      //����͸������
	setlinestyle(PS_SOLID, 10);
	roundrect(40, 40, 600, 440, 50, 50);     //Բ�Ǿ���
	
	LOGFONT f;
	//jokerman������ʾ
	gettextstyle(&f);   //��ȡ��ǰ��������,������ʽһ��Ҫ��gettextstyle��settextstyle֮������
	_tcscpy(f.lfFaceName, _T("jokerman")); 
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ����� 
	setcolor(GREEN);
	f.lfHeight = 50;  
	settextstyle(&f); 	//������ʽһ��Ҫ��gettextstyle��settextstyle֮������
	outtextxy(200, 50, "Rubik's Cube");
	//Ravie������ʾ
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	setcolor(RGB(184, 39, 254));		//��ɫ
	f.lfHeight = 30;                      // ��������߶�Ϊ 30
	_tcscpy(f.lfFaceName, _T("Ravie"));    // ��������Ϊ��Ravie��
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ

	outtextxy(60, 100, "�Ӽ���ֱ�������ַ����ƣ����ַ��������£�");
	settextstyle(25, 10, 0);
	outtextxy(60, 130, "0:  ���������˳�����");
	outtextxy(60, 150, "*:  ���Ǻż�ִ�����򷨻�ԭħ����");
	outtextxy(60, 170, "+:  ���Ӻż�ִ��ħ����ͳ��'���ȷ�'���л�ԭ��");
	outtextxy(60, 190, "R:  ˳ʱ��90��ת���档      r:  ��ʱ��90��ת���档");
	outtextxy(60, 210, "U:  ˳ʱ��90��ת���档      u:  ��ʱ��90��ת���档");
	outtextxy(60, 230, "L:  ˳ʱ��90��ת���档      l:  ��ʱ��90��ת���档");
	outtextxy(60, 250, "D:  ˳ʱ��90��ת���档      d:  ��ʱ��90��ת���档");
	outtextxy(60, 270, "F:  ˳ʱ��90��תǰ�档      f:  ��ʱ��90��תǰ�档");
	outtextxy(60, 290, "B:  ˳ʱ��90��ת���档      b:  ��ʱ��90��ת���档");
	outtextxy(60, 310, "M:  ����ת�в㡣            m:  ����ת�в㡣");
	outtextxy(60, 330, "X:  ˳��x��ת90�㡣	        x:  ����x��ת90�㡣");
	outtextxy(60, 350, "Y:  ˳��y��ת90�㡣	        y:  ����y��ת90�㡣");
	outtextxy(60, 370, "Z:  ˳��z��ת90�㡣	        z:  ����z��ת90�㡣");
  
//	setcolor(RGB(249,180,104));    //�˳���ť��λ
//	rectangle(200, 400, 455, 448);
	loadimage(&exit,".\\��Դ\\�˳���ť.jpg",260,55,true);
	putimage(195, 400, &exit);
	while(true)
	{
		// ��ȡһ�������Ϣ
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

	initgraph(1150, 500, SHOWCONSOLE);// SHOWCONSOLE����ʾ����̨
	mciSendString("open \".\\��Դ\\background.mp3\" alias mymusic", NULL, 0, NULL);  // �򿪱�������
	mciSendString("play mymusic repeat", NULL, 0, NULL);  // ��������
	picture();
	turn();
	// ֹͣ���Ų��ر�����
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);
	closegraph();
}

void picture()          //���Ʊ���
{
	void coloring();
	int i, j;
	graphdefaults();    //������ͼ����ǰ�㡢��ͼɫ������ɫ�����Ρ�������͡�����ΪĬ��ֵ
	// ������ı���
	float h = 0.0;		// ɫ��
	float s = 1;		// ���Ͷ�
	float l = 0.7f;		// ����
	for(int y = 0; y < 500; y++)    //�ʺ米��ɫ
	{
		h += 0.72;
		l += 0.0005f;
		setlinecolor( HSLtoRGB(h, s, l) );
		line(0, y, 1149, y);
	}

    //����ͼ
	setlinestyle(PS_SOLID, 2);
	setlinecolor(RGB(233, 233, 233));          //����
	//����
	rectangle(50, 100, 200, 250);
	line(50, 150, 200, 150);
	line(50, 200, 200, 200);
	line(100, 100, 100, 250);
	line(150, 100, 150, 250);
	//����
	line(70, 80, 220, 80);     
	line(90, 60, 240, 60); 
	line(110, 40, 260, 40);

	line(50, 100, 110, 40);
	line(100, 100, 160, 40);
	line(150, 100, 210, 40);
	line(200, 100, 260, 40);  
	//����
	line(200, 150, 260, 90);
	line(200, 200, 260, 140);
	line(200, 250, 260, 190);

	line(220, 80, 220, 230);
	line(240, 60, 240, 210);
	line(260, 40, 260, 190);

	//չ��ͼ                      �����α߳�50
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
		                     //ǰ��
	F[0][0].coordinate(55, 105, 655, 185);
	F[0][1].coordinate(105, 105, 705, 185);	
	F[0][2].coordinate(155, 105, 755, 185);
	F[1][0].coordinate(55, 155, 655, 235);
	F[1][1].coordinate(105, 155, 705, 235);	
	F[1][2].coordinate(155, 155, 755, 235);
	F[2][0].coordinate(55, 205, 655, 285);
	F[2][1].coordinate(105, 205, 705, 285);	
	F[2][2].coordinate(155, 205, 755, 285);

	                          //����
	U[0][0].coordinate(115, 45, 655, 35);
	U[0][1].coordinate(165, 45, 705, 35);	
	U[0][2].coordinate(215, 45, 755, 35);
	U[1][0].coordinate(95, 65, 655, 85);
	U[1][1].coordinate(145, 65, 705, 85);	
	U[1][2].coordinate(195, 65, 755, 85);
	U[2][0].coordinate(75, 85, 655, 135);
	U[2][1].coordinate(125, 85, 705, 135);	
	U[2][2].coordinate(175, 85, 755, 135);
	
	                          //����
	R[0][0].coordinate(205, 105, 805, 185);
	R[0][1].coordinate(225, 85, 855, 185);	
	R[0][2].coordinate(245, 65, 905, 185);
	R[1][0].coordinate(205, 155, 805, 235);
	R[1][1].coordinate(225, 135, 855, 235);	
	R[1][2].coordinate(245, 115, 905, 235);
	R[2][0].coordinate(205, 205, 805, 285);
	R[2][1].coordinate(225, 185, 855, 285);	
	R[2][2].coordinate(245, 165, 905, 285);
	
	                          //����(ֻ��չ��ͼ)
	L[0][0].coordinate(505, 185, 505, 185);
	L[0][1].coordinate(555, 185, 555, 185);	
	L[0][2].coordinate(605, 185, 605, 185);
	L[1][0].coordinate(505, 235, 505, 235);
	L[1][1].coordinate(555, 235, 555, 235);	
	L[1][2].coordinate(605, 235, 605, 235);
	L[2][0].coordinate(505, 285, 505, 285);
	L[2][1].coordinate(555, 285, 555, 285);	
	L[2][2].coordinate(605, 285, 605, 285);

	                          //����(ֻ��չ��ͼ)
	D[0][0].coordinate(655, 335, 655, 335);
	D[0][1].coordinate(705, 335, 705, 335);	
	D[0][2].coordinate(755, 335, 755, 335);
	D[1][0].coordinate(655, 385, 655, 385);
	D[1][1].coordinate(705, 385, 705, 385);	
	D[1][2].coordinate(755, 385, 755, 385);
	D[2][0].coordinate(655, 435, 655, 435);
	D[2][1].coordinate(705, 435, 705, 435);	
	D[2][2].coordinate(755, 435, 755, 435);

	                          //����(ֻ��չ��ͼ)
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
	if(nocolor)                   //��ɫ��ʼ��
	{
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				F[i][j].color = RGB(0, 255, 255);  //��
				U[i][j].color = RGB(255, 255, 128);  //��
				R[i][j].color = RGB(253, 4, 98);  //��
				L[i][j].color = RGB(255, 183, 78);  //��
				D[i][j].color = RGB(255, 255, 255);  //��
				B[i][j].color = RGB(128, 255, 128);  //��
			}
		}
		nocolor = false;
	}

	coloring();
	//Ϊ�ƶ���������׼��
	settextcolor(RGB(255, 128, 192));		// ����������ɫΪ��ɫ
	setbkmode(TRANSPARENT);		// �������ֱ���Ϊ͸��ɫ
	settextstyle(28, 10, _T("�����п�"));
}

void coloring()           //Ϳɫ
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

int word(char word[])                               //�˶�����
{
	void picture();
	//�����ַ���

	setbkmode(TRANSPARENT);      //����͸������

	FlushMouseMsgBuffer();   //��������Ϣ������

	//�����ַ�����ʼλ��
	int x = 10;
	int y = 10;

	//��ȡ�ַ����߶ȡ����
	int w = textwidth(word);
	int h = textheight(word);

	//�ж��ƶ�����
	bool isLeft = false;
	bool isUp = false;

	BeginBatchDraw();   //��ʼ������ͼ

	bool flag = true;
	//�����ƶ�����
	while(flag)
	{
		FlushBatchDraw();
		picture();         //���Ʊ���

          //ʵ�������ﵽ�˳�������Ч��
		while(MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();
			if((m.x>x)&(m.x<(x+w))&(m.y>y)&(m.y<(y+h)))
			{
				BeginBatchDraw();   //��ʼ������ͼ
				picture(); 
				FlushBatchDraw();  //������ͼ��ʾpicture
				EndBatchDraw();   //����������ͼ
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

	//�˳�
	EndBatchDraw();
}

void turn()               //תħ��
{
	void computer();
	void coloring();
	char turn[100] = "";
	bool ifwin();
	int word(char word[]);

	system("color BD");  //���ÿ���̨ǰ��ɫ�ͱ���ɫ

	for(int i = 0; i<100; i++)
	{
		turn[i] = '1';
	}
	i = 0;

	cout<<endl<<"��Ĳ�������:"<<endl;
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
			case'+':computer();break;  //���Կ���(��ͳ���ȷ�)
//			case'*':break;    //���Կ���(����)
			case'0':exit(1);
			default:break; 
		}

		if(ifwin())        //�ж��Ƿ�ԭ
		{
			word("��ԭ�ɹ�~(�������¿�ʼŶ^_^)");
			for(i = 0; i<100; i++)    //���¿�ʼ���ٴγ�ʼ��
			{
				turn[i] = '1';
			}
			i = 0;
			cout<<endl<<"��Ĳ�������:"<<endl;
		}

		if(turn[i]=='*'||turn[i+1]!='1')   //���¡�*������������ķ�����ԭ
		{
			if(turn[i]=='*')
			{
				cout<<endl<<"��������ԭ��������:"<<endl;
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
		else         //û����*����+����������룬�ֹ���תħ��
		{
			i++;
			turn[i] = getch();	
			cout<<turn[i]<<" ";
		}
	}
}

bool ifwin()     //�ж��Ƿ����渴ԭ
{
	bool f(Face p[][3]);
	if(f(F)&f(R)&f(U)&f(L)&f(D)&f(B))
	{
		return true;
	}
	return false;
}

bool f(Face p[][3])    //�жϵ�����Ǹ����Ƿ�ԭ
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

void Circle(Face p[][3])     //˳ʱ����תȦ
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

void Right()    //˳ʱ��
{
	BeginBatchDraw(); 
	right();
	right();
	right();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();
}

void right()  //��ʱ��
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

void Up()   //˳ʱ��
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

void up()   //��ʱ��
{
	BeginBatchDraw();   //������ͼ��ʼ
	Up();
	Up();
	Up();
	coloring();
	FlushBatchDraw(); //������ͼ��ʾ
	EndBatchDraw();   //������ͼ����

}

void Left()   //˳ʱ��
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

void left()   //��ʱ��
{
	BeginBatchDraw(); 
	Left();
	Left();
	Left();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void Down()  //˳ʱ��
{
	BeginBatchDraw(); 
	down();
	down();
	down();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void down()  //��ʱ��
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

void Front()   //˳ʱ��
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

void front()  //��ʱ��
{
	BeginBatchDraw(); 
	Front();
	Front();
	Front();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void Back()  //˳ʱ��
{
	BeginBatchDraw(); 
	back();
	back();
	back();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void back()   //��ʱ��
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

void M()    //˳ʱ��
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

void m()     //��ʱ��
{
	BeginBatchDraw(); 
	M();
	M();
	M();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();

}

void X()     //˳ʱ��
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

void x()    //��ʱ��
{
	BeginBatchDraw(); 
	X();
	X();
	X();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();
}

void Y()      //˳ʱ��
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

void y()    //��ʱ��
{
	BeginBatchDraw(); 
	Y();
	Y();
	Y();
	coloring();
	FlushBatchDraw();
	EndBatchDraw();
}

void Z()    //˳ʱ��
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

void z()     //��ʱ��
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

void computer()                   //���Կ���(���ȷ�)
{
	void cross(); //�ײ�ʮ��
	void two(); //�ײ��Ľ�
	void three();  //�в����
	void four();  //��ԭ�ĸ��������ɫ��
	void five();  //��ԭ�ĸ�����ǿ�ɫ��
	void six();  //��ԭ�ĸ�����ǿ�λ��
	void seven();  //��ԭ�ĸ��������λ��

	cout<<endl<<"���Ը�ԭ��������:"<<endl;
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
			cout<<endl<<"�׽�ʮ�ֳɹ���ԭ~"<<endl;
			break;
		}
		cross();    //�ײ�ʮ��
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
			cout<<endl<<"�ĵ׽ǳɹ���ԭ~"<<endl;
			break;
		}
		two();   //�ײ��Ľ�
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
			cout<<endl<<"����ɹ���ԭ~"<<endl;
			break;
		}
		three(); 
	}

	four();
	five();
	six();
	seven();
}

void seven()  //��ԭ�ĸ��������λ��
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
	cout<<endl<<"�ĸ��������λ�óɹ���ԭ~"<<endl;
	cout<<"ħ���ɹ���ԭ~"<<endl;
}

void six()  //��ԭ�ĸ�����ǿ�λ��
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
	cout<<endl<<"�ĸ�����ǿ�λ�óɹ���ԭ~"<<endl;
}

void five()  //��ԭ�ĸ�����ǿ�ɫ��
{
	void Do(char turn[]);
	while(U[0][0].color!=U[1][1].color
		||U[0][2].color!=U[1][1].color
		||U[2][0].color!=U[1][1].color
		||U[2][2].color!=U[0][0].color)   //7:RUUruRur  8:RUrURUUr
	{  
		//������
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
		//����ʮ����
		else if(U[0][0].color!=U[1][1].color
			&&U[0][2].color!=U[1][1].color
			&&U[2][0].color!=U[1][1].color
			&&U[2][2].color!=U[1][1].color)
		{   
			 //�Գ�ʮ��
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
		//����������
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
		//���������
		else if(U[0][0].color==U[1][1].color
			&&U[2][2].color==U[1][1].color
			&&F[0][0].color==U[1][1].color
			&&R[0][2].color==U[1][1].color)
		{
			Do("RUUruRurUURUrURUUr");  //7+UU+8
		}
		Do("U");
	}	
	cout<<endl<<"�ĸ�����ǿ�ɫ��ɹ���ԭ~"<<endl;
}

void four()  //��ԭ�ĸ��������ɫ��
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
			cout<<endl<<"�ĸ��������ɫ��ɹ���ԭ~"<<endl;
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

void three()  //�в���� 
{
	void Do(char turn[]);
	int i = 1; 
	while(1)
	{
		if(F[1][2].color==F[1][1].color&&R[1][0].color==R[1][1].color)
		{
			cout<<"��ȷ��ԭһ�в����";
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

void two()   //�ײ��Ľ�
{
	void Do(char turn[]);
	int i = 1; 
	while(1)  
	{
		if(F[2][2].color==F[1][1].color
			&&R[2][0].color==R[1][1].color
			&&D[0][2].color==D[1][1].color)   //�ý���ȷ
		{	
			cout<<"��ȷ��ԭһ�ǿ�";
			Do("y"); 
			break;
		}
		else
		{
			Do("U");  //Up(); ����iѭ��ת����
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
				if(i<4)             //Ѱ�Ҷ����Ľ������ͬɫ����
				{
					i++;	
				}
				else if(i == 4)           //�����Ľ��Ҳ��������ͬɫ����
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

void cross()     //�ײ�ʮ��  
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







