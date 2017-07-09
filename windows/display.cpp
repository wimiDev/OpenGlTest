#include "display.h"

Display::Display()
{
}

Display::Display(int width, int height, string & title)
{
	SDL_Init(SDL_INIT_EVERYTHING);	

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glwindow = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,width,height,SDL_VIDEO_OPENGL);
	glcontext = SDL_GL_CreateContext(glwindow);

	GLenum state = glewInit();
	if (state != GLEW_OK)
	{
		isClose = true;
		cerr << "glwe init fial!" << endl;
		cout << "errcode:" <<glewGetErrorString(state)<< endl;
	}
	isClose = false;
}

void Display::Update()
{
	SDL_GL_SwapWindow(glwindow);
	SDL_Event _event;
	while (SDL_PushEvent (&_event))
	{
		if (_event.type == SDL_QUIT)
		{
			isClose = true;
		}
	}
}

bool Display::getisClose()
{
	return isClose;
}

void Display::glclear(float r, float g, float b, float a)
{
	glClearColor(0.16f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

Display::~Display()
{
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(glwindow);
	SDL_Quit();
}
