
#include "glwidget.h"
#include "window.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

//! [0]
Window::Window()
{
    setWindowTitle(tr("2D Painting on Native and OpenGL Widgets"));

    GLWidget *openGL = new GLWidget(this);
    QLabel *nativeLabel = new QLabel(tr("Native"));
    nativeLabel->setAlignment(Qt::AlignHCenter);
    QLabel *openGLLabel = new QLabel(tr("OpenGL"));
    openGLLabel->setAlignment(Qt::AlignHCenter);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(openGL, 0, 0);
    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, openGL, &GLWidget::animate);
    timer->start(50);
}
//! [0]
