#ifndef QCELL_H
#define QCELL_H

#include <QQuickItem>
#include "QGameObject.h"
#include "QArrow.h"

class QCell : public QGameObject
{
public:
  friend class QGameCanvas;
public:
  QCell(QQuickItem *cell);
  int color()const;
  void setColor(int _color);
  int num()const;
  void setNum(int _num);
  int x()const;
  void setX(int _x);
  int y()const;
  void setY(int _y);
  QArrow * getArrow(int direction);

private:
  QArrow *arrows[6];
};

#endif // QCELL_H
