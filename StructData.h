#pragma once
#include "D:\\Движки\freeglut-2.8.1\include\GL\freeglut.h"

#include "Quad.h"
#include "Background.h"
#include "LogSystem.h"
#include "Snake_Obj.h"

typedef struct
{
 int x;
 int y;
} s[20];

s *Vector2Head;
s *Vector2Tail;
s *Vector2PosFruct;

bool firstRun(true);
bool ismod(false);

 int Fruct::Fructs_::countRun = 0;
 bool Fruct::Fructs_::visibleFructs[10] = { true };
 bool SNAKE::Snake_Obj::GameOver = false;
  
  Texture *texture ;
  Texture *fon_ = new Texture;
  Texture *fruct = new Texture;
  Texture *head ;
  Texture *body ;
  Texture *tail ;
  Texture *fonts;
  Texture *life ;
//  Font *ourtext;

  Texture *logo ;
  Texture *buttonMenu ;
  Texture *fonMenu;

  Texture *RenderTextureFon ;
  Texture *RenderTextureSnake;
  Texture *RenderTextureFruct;
  Texture *fontBlockdestroyer;
 
  
  
  GLuint	    fontbase;

namespace Data
{

const int LOGO=0;	
const int MAIN_MENU=1;
const int OPTIONS=2;
const int STARTGAME = 3;
const int LEVELCOMPLETE = 4;
const int RESETGAME = 5;
const int GAME_OVER=6;
const int HI_SCORES=7;
const int EXIT_MENU=8;
const int EXIT_GAME=9;

int   State(LOGO);
float menufade[5];
bool keys[256];
float   menu_items_fade[4]={0.5f,0.5f,0.5f,0.5f};
char    menu_items[4][15]={"New Game","Options","High scores","Exit"};

int	  FPS=100;
int   CurFPS=100;
__int64 oldtime=1;
float	spd=1.0f;

       int Scale = 25;
       int wf = Scale *30;
       int hf = Scale * 20;
       int IntervalTimer = 250;
       int IntervalBonus = 3000;
	   int countFructs = 6;
	   int LevelSpeed = 0;
	   int Level = 1;
	   HDC hDC;
	   int high = 0;
	   int lives = 3;

	   bool blend(false);
	   int id(1);
	   bool GameOver = false;
	   bool Winner = false;
	   bool Starting = false;
	   float depthScore = 0.2f;
	   float depthLevel = 0.3f;
	 

	   float depthFruct(0.7f),depthText(1.0f),depthSnake(0.7f);
	   float stepdepth = 0.01f;
	   float retFructDepth;
	   float depthGraphLog = 0.9f;

  HFONT font;
 Fruct::Fructs_ fructs[10];
 Quad ldrTexture;
 Background fon;
 LogSpace::CLog logFile;
 SNAKE::Snake_Obj snake;
 



using namespace std;

}