#ifndef colores_h
#define colores_h

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <windows.h>

void Gotoxy(int x,int y);
void Say(const char *txt);
void Say(int x,int y,const char *txt);

void Replicate(const char c,int can);
void ReplicateH(int x,int y,const char *c,int can);

void ReplicateV(int x,int y,const char *c,int can);
void Rectangle(int x,int y,int w,int h,const char *c);

void SetColorA(int color,int colorf);

void SetColorB(int color,int colorf);
void SetColorC(int color,int colorf);
void TextColor(int color);
void MSGBOX(const char *m1,const char *m2);
#endif

