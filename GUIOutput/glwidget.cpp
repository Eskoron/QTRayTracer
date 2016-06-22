#include "glwidget.h"

#include <QPainter>
#include <QImage>
//! [0]
GLWidget::GLWidget( QWidget *parent)
    : QOpenGLWidget(parent)
{
    elapsed = 0;
    setFixedSize(200, 200);
    setAutoFillBackground(false);
}
//! [0]

//! [1]
void GLWidget::animate()
{
    update();
}


//! [1]

//! [2]
void GLWidget::paintEvent(QPaintEvent *event)
{
    int w = 200;
    int h = 200;
    unsigned char* buffer_;
    buffer_ = new unsigned char[4 * w * h];

    for(int i = 0; i < h; i++){
     for(int j = 0; j < w; j++){

      unsigned char r, g, b;
      r=220;
      g= 0;
      b=220;

      buffer_[4 * (i * w + j)    ] = r;
      buffer_[4 * (i * w + j) + 1] = g;
      buffer_[4 * (i * w + j) + 2] = b;
     }
    }

    QImage image(buffer_, w, h, QImage::Format_RGB32);

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawImage(QPoint(0, 0), image);

    painter.end();

    delete buffer_;

}
//! [2]
