#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <windows.h>

#include "colores.h"
void Gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }



void Say(const char *txt)
{
	printf("%s",txt);
}

void Say(int x,int y,const char *txt)
{
	Gotoxy(x,y);printf("%s",txt);
}

void Replicate(const char c,int can)
{
	for(int i=0;i<can;i++)
	 {
		printf("%c",c);
	 }
}

void ReplicateH(int x,int y,const char *c,int can)
{
	for(int i=0;i<can;i++)
	 {
		Say(x+i,y,c);
	 }
}

void ReplicateV(int x,int y,const char *c,int can)
{
	for(int i=0;i<can;i++)
	 {
		Say(x,y+i,c);
	 }
}

void Rectangle(int x,int y,int w,int h,const char *c)
{
		ReplicateH(x,y,c,w);//fila 1
		ReplicateH(x,y+h,c,w);//fila 2
		ReplicateV(x,y,c,h);//col 1
		ReplicateV(x+w-1,y,c,h);//col 2

}




void SetColorA(int color,int colorf)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | colorf | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
}

void SetColorB(int color,int colorf)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | colorf | BACKGROUND_INTENSITY );
}

void SetColorC(int color,int colorf)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | colorf);
}


void TextColor(int color)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



void MSGBOX(const char *m1,const char *m2)
{
     MessageBox(NULL,m1 ,m2,MB_ICONEXCLAMATION);
}
