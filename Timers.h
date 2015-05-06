#pragma once
#include "StructData.h"

void glutTimer(int id)

{
	if (id!=0)
	{
	  NewDraw(); 
	  //ProcessMenu();
	}
	glutTimerFunc(Data::IntervalTimer,glutTimer,id);

}


void glutTimerSnake(int id)

{
	if (id!=0)
	{
	  snake.Draw();
	  glutSwapBuffers();
	}
	glutTimerFunc(Data::IntervalTimer,glutTimer,id);

}


