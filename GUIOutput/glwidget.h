#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>

//! [0]

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget( QWidget *parent);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int elapsed;
};
//! [0]

#endif
