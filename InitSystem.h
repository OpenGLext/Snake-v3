#pragma once
#include "Draws.h"
#include "StructData.h"
#include "LogSystem.h"

char *h    = "head.tga";
char *back = "background.tga";
char *fr   = "fruct.tga";
char *lf   = "life.tga";
char *logo_ = "MyLogo.tga";
char *buttonMenu_ = "button.tga";
char *fonMenu_ = "backmenu-2.tga";
char *fontDestroyer_ = "font_blockdestroyer.tga";

char *buffer;
LPWSTR buf;

inline void GetCur()
{
	GetCurrentDirectory(sizeof(buffer),buf);
}
bool LoadRes()
{
	const int maxRes=8;

	char *b[maxRes]={"\\Data\\head.tga","\\Data\\backgroundTwo.tga","\\Data\\fruct.tga",
		         "\\Data\\life.tga","\\Data\\logo.tga","\\Data\\button.tga",
				 "\\Data\\backmenu-2.tga", "\\Data\\font_blockdestroyer.tga"};
	Texture *texturesPoints[maxRes] = {head,fon_,fruct,life,logo,buttonMenu,fonMenu,fontBlockdestroyer};
	
	LPWSTR path=L"..";
	SetCurrentDirectory(path);

	for(int i=0;i<maxRes; i++)	
	  ldrTexture.LoadTexture(texturesPoints[i],b[i]);


	return true;
}
void LoadTextures()
 {
	 fontBlockdestroyer = new Texture;
	
	// ourtext  

	 head = new Texture;
   ldrTexture.LoadTexture(head, h); 
  // glGenTextures(1, &head->texID); 

   ldrTexture.LoadTexture(fon_,back);
   //glGenTextures(1, &fon_->texID); 

   ldrTexture.LoadTexture(fruct, fr);
   glGenTextures(1, &fruct->texID); 

  // BindingTexture(fruct);
   life = new Texture;
   ldrTexture.LoadTexture(life, lf);

   logo = new Texture;
   ldrTexture.LoadTexture(logo,logo_);
  // glGenTextures(1, &logo->texID); 

   buttonMenu = new Texture;
   ldrTexture.LoadTexture(buttonMenu,buttonMenu_);
   glGenTextures(1, &buttonMenu->texID); 

   fonMenu = new Texture;
   ldrTexture.LoadTexture(fonMenu,fonMenu_);
   glGenTextures(1, &fonMenu->texID); 

   ldrTexture.LoadTexture(fontBlockdestroyer,fontDestroyer_);
  // glGenTextures(1, &fontBlockdestroyer->texID); 

  Vector2Head = new s[0];
  Vector2Tail = new s[20]; // хвост пока на конечном элементе массива позже поправить выз метод длину тела и поправить индекс
                           // Vector2Tail = new s[snakeGetLenBody()];
  Vector2PosFruct = new s[0]; // пока пусть будет один фрукт если будет 10 то исправим индекс
 }
void InitGL()
{
	
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,Data::wf,0,Data::hf);
glEnable(GL_SMOOTH);
if (Data::blend )
{
glEnable(GL_BLEND); glBlendFunc(GL_ZERO,  GL_SRC_ALPHA_SATURATE);

}



LoadTextures();
State = STARTGAME;
menufade[0] = 0.019f;
		
 
}