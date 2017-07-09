#pragma once
#include<string>
#include"SDL2\SDL.h"
#include"GL\glew.h" 
#include<iostream>
using namespace std;

class Display
{
public:
	Display();
	Display(int width,int height,string &title);
	void Update();
	bool getisClose();
	void glclear(float r,float g,float b,float a);
	~Display();
protected:
	SDL_Window* glwindow;
	SDL_GLContext glcontext;
	bool isClose;
private:
};
