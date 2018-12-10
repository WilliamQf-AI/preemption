#include "QCell.h"
#include <QColor>

QCell::QCell(QQuickItem *cell)
  :QGameObject(cell)
{
  for(int i=0;i<6;i++)
    {
      arrows[i]=new QArrow;
    }
}

int QCell::color()const
{
  QColor maskColor=instance->property("maskColor").value<QColor>();
  return (maskColor.red()<<16)|(maskColor.green()<<8)|(maskColor.blue());
}

void QCell::setColor(int _color)
{
  QColor maskColor=QColor::fromRgb(_color>>16,(_color&0x00FF00)>>8,_color&0xFF);
  instance->setProperty("maskColor",maskColor);
}

int QCell::num()const
{
  return instance->property("num").toInt();
}

void QCell::setNum(int _num)
{
  instance->setProperty("num",_num);
}

int QCell::x()const
{
  return instance->property("pos_x").toInt();
}

void QCell::setX(int _x)
{
    instance->setProperty("pos_x",_x);
}

int QCell::y()const
{
  return instance->property("pos_y").toInt();
}

void QCell::setY(int _y)
{
    instance->setProperty("pos_y",_y);
}

QArrow * QCell::getArrow(int direction)
{
  return arrows[direction];
}
