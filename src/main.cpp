#include <QApplication>
#include <QWidget.h>
#include "Platform/OpenGLContextApi.h"
#include <assert.h>
#include <iostream>
#include "Widget/OpenGLWidget.h"
#include "GL/glew.h"
int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	//init opengl extension api
	QWidget dummyWindow;
	bool ret=OpenGLContextApi::Init((WindowHandle)dummyWindow.winId());
	assert(ret);
	OpenGLWidget widget;
	widget.show();
	glClearColor(0.4, 0.5, 0.6, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	widget.SwapBuffer();
	std::cout << OpenGLContextApi::CurrentContextVersion() << std::endl;
	return app.exec();
}