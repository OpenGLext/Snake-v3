#pragma once
#include <sstream>
#include "Fructs_.h"
#include "StructData.h"
//#include "Source.cpp"
#include "Quad.h"
#include "Background.h"
#include "LogSystem.h"
#include "Snake_Obj.h"
#include "Font.h"
#include "DefineTexture.h"
#include "Texturing.h"
#include "Fonts.h"
#include <windef.h>
#include <atltypes.h>
#include "Fonts_blockDestroyer.h"
#include "Frustum.h"
 
using namespace LogSpace;
using namespace Data;

void DrawVisibleFructs()
{
	for(int i=0; i<10; i++)
	{
		if (Fruct::Fructs_::visibleFructs[i] == true) 
		   {
			logFile<< LogSpace::color("gray") << LogSpace::color("green") << "visibleFructs["<<i<<"]"<< " True"<< LogSpace::endl;
		   }
		else
			logFile<< LogSpace::color("gray") << LogSpace::color("green") << "visibleFructs["<<i<<"]"<< "False"<< LogSpace::endl;
	 
	}
}

 
 inline GLvoid box(float x1, float y1, float x2, float y2)
{
	glBegin(GL_QUADS);	
        	glTexCoord2f(0.0f, 0.0f); glVertex2f(x1,y1);
			glTexCoord2f(1.0f, 0.0f); glVertex2f(x2,y1);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(x2,y2);
			glTexCoord2f(0.0f, 1.0f); glVertex2f(x1,y2);
			
	glEnd();
}
inline void Times()
{
	//__int64 time;											// time Will Hold A 64 Bit Integer
	//QueryPerformanceCounter((LARGE_INTEGER *) &time);	// Grab The Current Performance Time
	int time;
	time = GetTickCount();
	CurFPS++;

	if( time - oldtime > 1000 )
	{
		oldtime = time;
		FPS = CurFPS;
		CurFPS = 0;
	}
	spd = (float)100 / (float)FPS;
	if ( spd < 2.0f) spd = 1.0f;
	//Pauseval -= 1.0f * spd ;            // 20.0 - 2..4..6
}
std::string GetStr(const char* mess,const float value,const int valueInt=0)
{
	std::string ScoreFloat="";
	std::stringstream StrStream;

	StrStream<<value;
	StrStream>>ScoreFloat;
	ScoreFloat = mess + ScoreFloat ;
	 
	return ScoreFloat;
}
 void DrawBlackQuad(int x, int y)
 {
	 glColor3f(0.0f,0.0f,0.0f);
	 box(x,y,x+25.0f,y+25.0f);
 }
 void ResetGame()
 {
	// fructs[0].SetVisible(false,0);
	 glClearColor(0,0,0,0);
	 //DrawBlackQuad(fructs[0].GetPosXFruct(),fructs[0].GetPosYFruct());

	 glClear(GL_COLOR_BUFFER_BIT);
	 //glDrawBuffer(GL_FRONT);
	// glClear(GL_FRONT);
	// glClear(GL_DEPTH_BUFFER_BIT);
 }
 // Ещё одна новая функция: создаёт пустую текстуру для рендера в неё
 void CreateRenderTexture(Texture textureArray, int size, int channels, int type, int textureID)
{
    // указатель для сохранения данных текстуры
    unsigned int *pTexture = NULL;

    // Нужно создать пустую текстуру для рендера динамической текстуры.
    // Чтобы сделать это, просто создаем массив для хранинея данных и
    // передаем его OpenGL. Текстура хранится в видеокарте, так что мы можем
    // уничтожить массив в любой момент.
    // Эта функция принимает текстурный массив для сохранения текстуры,
    // размер текстуры, высоту и ширину, каналы (1,3,4), тип (RGB, RGBA, etc)
    // и текстурный ID.

    // Инициализируем память под массив текстуры и привяжем к pTexture
    pTexture = new unsigned int [size * size * channels];
    memset(pTexture, 0, size * size * channels * sizeof(unsigned int));

    // Зарегистрируем текстуру в OpenGL и привяжем к ID
    glGenTextures(1, &textureArray.texID);
    glBindTexture(GL_TEXTURE_2D, textureArray.texID);

    // Создаем текстуру и сохраняем в памяти
    glTexImage2D(GL_TEXTURE_2D, 0, channels, size, size, 0, type, GL_UNSIGNED_INT, pTexture);

    // Устанавливаем качество
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    // Сохранив текстуру с пом. OpenGL, мы можем удалить временные данные
    delete [] pTexture;
}
 void OutLogotype()
 {
	// Font *ourtext = new Font(hDC,"times",15,25,30);
	
  glColor3f(0.0f,0.0f,0.3f);
  //ourtext->put(250, 460, 1.0f, "Snake v3.5");
 
  //delete ourtext;
 }
 void GraphicLog(const char *mess)
 { 
  Font *ourtext = new Font(hDC,"times",15,25,30);
  glDisable(GL_TEXTURE_2D);
  glColor3f(0.0f,0.0f,0.9f);
  ourtext->put(20, 430, depthGraphLog, mess);
  delete ourtext;
  glEnable(GL_TEXTURE_2D);
 }
 void DrawBackground()
 {
	
	 BindingTexture(fon_);
  fon.DrawHorizontLine(0,0,0,0);

		
 }
 void OutHigh()
 {
	 glDrawBuffer(GL_FRONT);
	 glEnable(GL_TEXTURE_2D);
	
	// if (ourtext == NULL ) { MessageBox(0,L"ourtext is null",L"info",MB_OK);}

    std::string ScoreStr="Score: ";
	std::string ScoreInt="";
	std::string levelStr="Level: ";
	std::string levelInt="";

	std::stringstream StrStream, levelStream;
	StrStream<<Data::high;
	StrStream>>ScoreInt;
	ScoreStr += ScoreInt;
	
	levelStream<<Data::Level;
	levelStream>>levelInt;
	levelStr += levelInt;

	Font *ourtext = new Font(Data::hDC,"Courier New",20,20,15);
 
          //glColor3f(1.0f,0.7f,0.5f);

	std::string lifes = GetStr("Life: ",Data::lives);

	glColor3f(1.0f,0.0f,0.0f);
		  
		  ourtext->put(550,470, 0.8f, levelStr.c_str());
          ourtext->put(550,450, 0.0f,ScoreStr.c_str());
		  ourtext->put(550,430, 0.8f, lifes.c_str());
		  delete ourtext;
		  glFlush();
		 // glutSwapBuffers();
 }
 void DrawSnake()
 {
 
   // snake.SetTimeDraw(spd);
	/*std::string str = GetStr("FPS",0,FPS);
	glColor3f(0.0f,1.0f,0.0f);
	glRasterPos2d(100,100);
	glPrint(100,100,1,str.c_str());*/
   // logFile<< LogSpace::color("gray") << LogSpace::color("green") << "spd" << spd << LogSpace::endl;
//	snake.SetDepthSnake(Data::depthSnake); 

   // BindingTexture(head);
    snake.Draw();
	//logFile<< LogSpace::color("gray") << LogSpace::color("green") << "Data::depthsnake" << snake.GetDepthSnake() << LogSpace::endl;
 
 }
 void DrawFruct()
 {
	/* retFructDepth=fructs[0].GetDepthFruct();
	 std::string str = GetStr("keys depth fruct o[-],p[+] : ",retFructDepth);
	 GraphicLog(str.c_str());*/
	 
	// logFile<< LogSpace::color("gray") << LogSpace::color("green") << "Data::depthFruct" << fructs[0].GetDepthFruct() << LogSpace::endl;
	// fructs[0].SetDepthFruct(Data::depthFruct);
    //  BindingTexture(fruct);
	 fructs[0].SetVisible(true,0);
	 glColor3f(0.0f,1.0f,0.0f);
       fructs[0].DrawApple(); 
	   
 }
 void LoadGameOver()
{
	      glEnable(GL_BLEND);
		  //glBlendFunc();

         // glDisable(GL_TEXTURE_2D);
		
          //glColor3f(1.0f,0.0f,0.0f);
	     // ourtext.put(250, 250, 0.0f, "Game Over");

		 // Data::GameOver = false;
        //  snake.SetLenghtBody(4); 

		  //glColor3f(0.0f,0.0f,1.0f);
		  //ourtext_.put(150,15,0.0f,"Press space to Start game or ESC to Exit");
		 // glEnable(GL_TEXTURE_2D);

	/*
	* Для отладки в качестве заглушки 
	* сделаю проверку 
	* гейм овер будет красным экраном
	*/
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

		Font *ourtext = new Font(Data::hDC,"Courier New",10,10,15);
 
          glColor3f(1.0f,0.7f,0.5f);
		  
		  ourtext->put( 10,15,0.0f,"Press space to Start game or ESC to Exit");
		  delete ourtext;
	
}
 void LevelComplete()
 {
	   
   // ResetGame(); 
		 // glClearColor(0.0f,0.5f,0.5f,0.0f);
	
	     // ourtext.put(150, 250, 0.0f, "Level is complete...");

	/*
	* Для отладки в качестве заглушки 
	* сделаю проверку 
	* конец уровня будет синим экраном
	*/
	//glClearColor(0.0f,0.0f,1.0f,0.5f);
	//glClear(GL_COLOR_BUFFER_BIT);

	 glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

		Font *ourtext = new Font(Data::hDC,"Courier New",10,10,15);
 
          glColor3f(1.0f,0.7f,0.5f);
		  
		  ourtext->put( 10,15,0.0f,"Level is complete...");
		  delete ourtext;
	
		Sleep(900);
 }
 void ResetLives()
  {
	  if ( Data::lives == 1) { State = GAME_OVER; LoadGameOver();  Sleep(900); }
	  else Data::lives -= 1;
  }
 void OutLives()
  {

  }
 void Draw()
{   
	// glDrawBuffer(GL_FRONT);

	glEnable(GL_TEXTURE_2D); 
	//ResetGame(); 

	 if (!Data::GameOver) 
		 { 
	
			//OutLives(); 
	  // DrawBackground();
        //Sleep(30);
        //Times();
		//DrawSnake();
		// Sleep(30);
          
		if (firstRun || ismod)
		{
          DrawFruct(); 
		
		}

		snake.Draw();
         
			// OutLogotype();
			//OutHigh();
			
		  if ( snake.GetCollision()) 
		  {
			  ismod = true; 
			  Data::high += 100;
			  snake.SetCollision(false);
			  ResetGame();
		  }
		  
		  //DrawVisibleFructs(); } 
		  //else {DrawVisibleFructs();}

	if ( snake.IsGameOver())  {  ResetLives(); } 
	     
	if ( snake.GetLenBody() == Data::countFructs) 
	   { 
		   if (Data::Level == 3)
		   { 
			   Data::Level = 1;
		   } 

	      else 
			{
				State = LEVELCOMPLETE;
				LevelComplete();
				Data::Level += 1;
		        //snake.SetLenghtBody(4); 
				//fructs[0].New(); 
		     }
	}
	
	//OutHigh(); 
	
	 //}
	
	 }

	/* if (( !Data::Starting) && (Data::GameOver))
	 {
		 LoadGameOver();
		
	 }*/


	 if (firstRun || ismod)

	 {
		  ismod = false;
		  firstRun = false;
	    glutSwapBuffers(); 
     	glDisable(GL_TEXTURE_2D);
	 }
	
		 //ResetGame();
		// glDrawBuffer(GL_BACK);
		
		//glClear(GL_FRONT);
		 //glFlush();
}
 int DrawLogo(float n)
{
	glEnable(GL_TEXTURE_2D);
	BindingTexture(logo);
	//glBindTexture(GL_TEXTURE_2D, logo->texID);			// logo.tga
	box(0.0f,0.0f,Data::wf,Data::hf);	
	

	//if (n>=1){ // если конец игры вывести рекорд таблицу
		//glColor3f(1.0f,1.0f,1.0f);								// Set Color To Purple
		//if ((GameTime/100) % 2==0) 
			//glPrint(300,600,0,"press button to menu");							// Write GRID CRAZY On The Screen
	//}
	return TRUE;											
}
 int DrawMenu(float n,int ID)
{
	// BACKGROUND
	BindingTexture(fonMenu);		// backmenu.tga
	//box(20.0f-400*(1-n),120.0f,330.0f-400*(1-n),360.0f);	
	box(300,150,450,300);

	// MENU ITEMS
	BindingTexture(buttonMenu);		// button.tga
	for (int i=0;i<4;i++)
	{
	if (i!=ID) if (menu_items_fade[i]>0.5f){menu_items_fade[i]-=0.002f; }
	if (ID==i) if (menu_items_fade[i]<1.0f){menu_items_fade[i]+=0.008f; } 
	glColor3f(menu_items_fade[i],menu_items_fade[i],menu_items_fade[i]);
	
	//box(40.0f-400*(1-n),150.0f+i*50,300.0f-400*(1-n),195.0f+i*50);	
	glColor4f(0.0f,0.0f,0.0f,0.5f);
	box(320,280,430,320);
	}

    BindingTexture(fonMenu);		// backmenu.tga
	for (int i=0;i<4;i++)
	{
		glColor3f(menu_items_fade[i],menu_items_fade[i],menu_items_fade[i]);
		//glPrint(50.0f-400.0f*(1.0f-n),155.0f+i*50.0f,0,menu_items[i]);							// Write GRID CRAZY On The Screen
	}
	
	return TRUE;											
}
 void RenderSnake()
 {
	 // считываем пикселы сцены

	 // проверяем если это не хвост и не голова т.е все тело то сотрем
 }
 void LoadReset()
 {
	 snake.SetLenghtBody(4);
	 Data::lives = 3;
	 fructs[0].New();

 }
 inline void CheckBodySnake()
 {
	 switch (snake.GetDir())
	 {

	 case 0 : 
		 

			 for (int i=0; i<snake.GetLenBody(); i++)
				// if () {}
		 
		 break;

	 case 1 : break;
	 case 2 : break;
	 case 3 : break;

	 }
 }
 void ClearScreen()
 {
	 for (int i=0; i< Data::hf; i+=Data::Scale)
	 {
		 for (int j=0; j< Data::wf; j+=Data::Scale)
		 {
			 if (snake.GetHeadPosX() != j && snake.GetHeadPosY() != i) 
			 {
				 if ( snake.GetPosTailX() != j && snake.GetPosTailY() != i)
				 {
				   if (fructs[0].GetPosXFruct() != j && fructs[0].GetPosYFruct() != i)
				    {
				      DrawBlackQuad(j,i);
				    }
			 }
			 }
		 }
	 }
 }
 void NewDraw()
 {
	 // ClearScreen(); // стираем все кроме змейки и фрукта,вместо очистки всего буфера цвета
	
	  ResetGame(); // стираю весь экран

	  if (firstRun)
	  {
          DrawFruct();
	  }
	  snake.Draw();

	  if (snake.GetCollision()) { snake.SetCollision(false); ResetGame(); 
	                              DrawFruct(); firstRun = false; } //fructs[0].SetVisible(false,0);
	  
      
	  glutSwapBuffers();
 }

   /****************************** 
	 * попробуем сделать
	 через мышку попадание точки 
	 курсора
	 в плоскость  кнопки сравнение 
	 по миним и максимуму
	 if (curx > xminButton && curx < xmaxButton)
	 {
	   if cury > yminButton && cury < ymaxButton )
	   {
	     // попали в кнопку дергаем указатель на фу-ии обработчика нажатия
		 или даже просто вызываем нужный обработчик
	   }
	 }
	 *
	 ******************************
	 */
	 
 void DrawMenu()
 {
	 float posMenuX(200),posMenuY(150),MenuScale(2.5f);
	 

	 glEnable(GL_TEXTURE_2D);
	 /****************************** 
	 * главная рамка меню задняя
	 *
	 ******************************
	 */
	
	 gluBuild2DMipmaps(GL_TEXTURE_2D, fonMenu->bpp / 8,  fonMenu->width,  fonMenu->height, fonMenu->type, GL_UNSIGNED_BYTE,  fonMenu->imageData);		
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		
     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

	 box(posMenuX,posMenuY,posMenuX*MenuScale,posMenuY*MenuScale);


	  /****************************** 
	 * рисуем 3 кнопки старт опции и выход,
	   для начала хотя бы одну 
	   сделать рабочую старт 
	 *
	 ******************************
	 */
	 posMenuX = 220; posMenuY = 355;
	 gluBuild2DMipmaps(GL_TEXTURE_2D, buttonMenu->bpp / 8,  buttonMenu->width,  buttonMenu->height, buttonMenu->type, GL_UNSIGNED_BYTE,  buttonMenu->imageData);		
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

	 box(posMenuX,posMenuY,posMenuX+MenuScale,posMenuY+MenuScale);

	 //glDisable(GL_TEXTURE_2D);
 }
 void ProcessMenu()
 {
	 Times();

	 if ( State == LOGO)            {  DrawLogo(menufade[LOGO]);        }
	 if ( State == MAIN_MENU)       {  DrawMenu(); } //DrawMenu(menufade[MAIN_MENU],0); }
	 if ( State == STARTGAME)       {  Draw();                          }
	 if ( State == LEVELCOMPLETE )  {  LevelComplete();                 }
	 if ( State == GAME_OVER     )  {  LoadGameOver();                  }
	 if ( State == RESETGAME     )  {  LoadReset();                     }
	 
	glutSwapBuffers(); 
	glDisable(GL_TEXTURE_2D);
 }

