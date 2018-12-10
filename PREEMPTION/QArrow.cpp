#include "QArrow.h"

QArrow::QArrow(QQuickItem *arrow)
  :QGameObject(arrow)
{

}

int QArrow::num()const
{
  return instance->property("num").toInt();
}

void QArrow::setNum(int _num)
{
  instance->setProperty("num",_num);
}
