#ifndef OUTPUTPAINTER_H
#define OUTPUTPAINTER_H

#include <QOpenGLWidget>

class OutputPainter : public QOpenGLWidget
{
public:
    OutputPainter(QWidget *parent = 0);
    ~OutputPainter();
    QSize sizeHint() const {  return QSize(400, 400); }

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
};

#endif // OUTPUTPAINTER_H
