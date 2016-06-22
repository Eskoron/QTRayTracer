#include "outputpainter.h"

//#include <gl/GL.h>


OutputPainter::OutputPainter(QWidget *parent):QOpenGLWidget(parent){

}

OutputPainter::~OutputPainter(){

}

 voidOutputPainter::initializeGL(){

}

void OutputPainter::paintGL(){
    QSize viewport_size = size();
    glViewport(0, 0, viewport_size.width(), viewport_size.height());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 5, 7); // near and far match your triangle Z distance

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(-1.5f,0.0f,-6.0f);

        glBegin(GL_TRIANGLES);
         glVertex3f( 0.0f, 1.0f, 0.0f);
         glVertex3f(-1.0f,-1.0f, 0.0f);
         glVertex3f( 1.0f,-1.0f, 0.0f);
        glEnd();
        swapBuffers();
}

void OutputPainter::resizeGL(int w, int h)
{
    QGLWidget::resize(w,h);
}
