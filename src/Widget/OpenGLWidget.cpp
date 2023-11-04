#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent)
	:QWidget(parent, Qt::MSWindowsOwnDC)
{
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_NoSystemBackground);
	setAutoFillBackground(true);
	m_WindowHandle = (WindowHandle)winId();
	m_DC = OpenGLContextApi::GetDeviceContext(m_WindowHandle);
	//创建OpenGL上下文
	bool ret = OpenGLContextApi::CreateOpenGLContext(m_DC, 4, 6, m_OpenGLContextHandle);
	assert(ret);
	ret = OpenGLContextApi::MakeCurrent(m_DC, m_OpenGLContextHandle);
	assert(ret);
	//时间事件(收到时间事件就渲染一次)
	startTimer(10);
}

OpenGLWidget::~OpenGLWidget()
{
	OpenGLContextApi::ReleaseDeviceContext(m_WindowHandle,m_DC);
}

void OpenGLWidget::SwapBuffer()
{
	OpenGLContextApi::SwapBuffers(m_DC);
}

bool OpenGLWidget::event(QEvent* event)
{
	if (event->type() == QEvent::Timer)
	{
		OnRender();
		return true;
	}
	return QWidget::event(event);
}
