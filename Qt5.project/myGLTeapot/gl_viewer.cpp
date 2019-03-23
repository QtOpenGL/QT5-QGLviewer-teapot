/****************************************************************************

 Copyright (C) 2002-2014 Gilles Debunne. All rights reserved.

 This file is part of the QGLViewer library version 2.7.1.

 http://www.libqglviewer.com - contact@libqglviewer.com

 This file may be used under the terms of the GNU General Public License 
 versions 2.0 or 3.0 as published by the Free Software Foundation and
 appearing in the LICENSE file included in the packaging of this file.
 In addition, as a special exception, Gilles Debunne gives you certain 
 additional rights, described in the file GPL_EXCEPTION in this package.

 libQGLViewer uses dual licensing. Commercial/proprietary software must
 purchase a libQGLViewer Commercial License.

 This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#include "teapot.h"
#include "gl_viewer.h"
#include <math.h>
#include <QDebug>

using namespace qglviewer;
using namespace std;

//////////////////////////////////  V i e w e r  ///////////////////////////////////////////

void Viewer::init() {
  restoreStateFromFile();

  // Make camera the default manipulated frame.
  setManipulatedFrame(camera()->frame());

  setMouseBinding(Qt::AltModifier, Qt::LeftButton, QGLViewer::CAMERA,
                  QGLViewer::ROTATE);
  setMouseBinding(Qt::AltModifier, Qt::RightButton, QGLViewer::CAMERA,
                  QGLViewer::TRANSLATE);
  setMouseBinding(Qt::AltModifier, Qt::MidButton, QGLViewer::CAMERA,
                  QGLViewer::ZOOM);
  setWheelBinding(Qt::AltModifier, QGLViewer::CAMERA, QGLViewer::ZOOM);

  setMouseBinding(Qt::NoModifier, Qt::LeftButton, QGLViewer::FRAME,
                  QGLViewer::ROTATE);
  setMouseBinding(Qt::NoModifier, Qt::RightButton, QGLViewer::FRAME,
                  QGLViewer::TRANSLATE);
  setMouseBinding(Qt::NoModifier, Qt::MidButton, QGLViewer::FRAME,
                  QGLViewer::ZOOM);
  setWheelBinding(Qt::NoModifier, QGLViewer::FRAME, QGLViewer::ZOOM);
}

void Viewer::draw() {
/*
  // Draw the ground
  glColor3f(0.4f, 0.4f, 0.4f);
  const float nbPatches = 100;
  glNormal3f(0.0, 0.0, 1.0);
  for (int j = 0; j < nbPatches; ++j) {
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= nbPatches; ++i) {
        glVertex2f((2 * i / nbPatches - 1.0), (2 * j / nbPatches - 1.0));
        glVertex2f((2 * i / nbPatches - 1.0), (2 * (j + 1) / nbPatches - 1.0));
        }
    glEnd();
    }
*/

  /*
   * Position figure
   */
glPushMatrix();
glMultMatrixd(frameTeapot->matrix());

  //glTranslatef(0.0,0.0,.25);
  // Red color used to draw.
  //glColor3f(0.8, 0.2, 0.1);
  // changing in transformation matrix.
  // rotation about X axis
  //glRotatef(90,1.0,0.0,0.0);
  // rotation about Y axis
  //glRotatef(0,0.0,1.0,0.0);
  // rotation about Z axis
  //glRotatef(0,0.0,0.0,1.0);
  // scaling transfomation
  glScalef(mfScale,mfScale,mfScale);
  glEnable(GL_NORMALIZE);//To preventing lighting change after scaled!

  drawingTeapot();

  // Flush buffers to screen
  glFlush();
glPopMatrix();
}

void Viewer::drawWithNames() {
  // Render scene with objects ids
  //mygl.draw(true);
}

void Viewer::postSelection(const QPoint &) {
  qDebug() << Q_FUNC_INFO;


}


