#ifndef QGAMECANVAS_H
#define QGAMECANVAS_H

#include <QQuickItem>
#include "QGameObject.h"
#include "QInputBox.h"
#include "QCell.h"
#include "QArrow.h"
#include "QButton.h"
#include "QMessageBox.h"

class QGameCanvas : public QGameObject
{
public:
  QGameCanvas(QQuickItem *canvas);
  bool active()const;
  void setActive(bool flag);
  int offsetX()const;
  void setOffsetX(int _x);
  int offsetY()const;
  void setOffsetY(int _y);

  QInputBox * inputBox();
  QButton * btnRun();
  QMessageBox* msgbox();

  QCell* CreateCell(int x=0,int y=0,int color=0xFFFFFF,int num=0);

private:
  QInputBox qinputbox;
  QButton qbtnRun;
  QMessageBox qmsgbox;
};

#endif // QGAMECANVAS_H
