#include <QWidget>
#include "../Platform/OpenGLContextApi.h"
#include <QEvent>

class OpenGLWidget :public QWidget
{
	Q_OBJECT
public:
	OpenGLWidget(QWidget* parent=nullptr);
	virtual ~OpenGLWidget() ;
	virtual void OnRender() {}
	void SwapBuffer();
	
protected:
	virtual bool event(QEvent* event)override;
	virtual QPaintEngine* paintEngine() const override { return nullptr; }
	WindowHandle m_WindowHandle;
	OpenGLContextHandle m_OpenGLContextHandle;
	DeviceContextHandle m_DC;
};