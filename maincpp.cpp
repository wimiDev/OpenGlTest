#include<iostream>
#include"GL\glew.h"
#include"windows\display.h"
using namespace std;

int main(int argc,char** argv)
{
	Display display(1366,768,string("wimidev"));
	while (!display.getisClose())
	{
		display.glclear(0.16f, 0.1f, 0.1f, 1.0f);
		display.Update();
	}
	return 0;
}