#ifndef QARROW_H
#define QARROW_H

#include <QQuickItem>
#include "QGameObject.h"

class QArrow : public QGameObject
{
public:
  friend class QGameCanvas;
public:
  QArrow(QQuickItem *arrow=nullptr);
  int num()const;
  void setNum(int _num);
};

#endif // QARROW_H
