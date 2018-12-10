#include "QGameCanvas.h"

QGameCanvas::QGameCanvas(QQuickItem *gameCanvas)
  :QGameObject(gameCanvas),qinputbox(),qbtnRun()
{
  qinputbox.instance=gameCanvas->findChild<QQuickItem*>("inputBox");
  assert(qinputbox.instance);
  qbtnRun.instance=gameCanvas->findChild<QQuickItem*>("btnRun");
  assert(qbtnRun.instance);
  qmsgbox.instance=gameCanvas->findChild<QQuickItem*>("msgbox");
  assert(qmsgbox.instance);
}

QInputBox * QGameCanvas::inputBox()
{
  return &qinputbox;
}

QButton * QGameCanvas::btnRun()
{
  return &qbtnRun;
}

QMessageBox* QGameCanvas::msgbox()
{
    return &qmsgbox;
}

bool QGameCanvas::active()const
{
  return instance->property("active").toBool();
}

void QGameCanvas::setActive(bool flag)
{
  instance->setProperty("active",flag);
}

int QGameCanvas::offsetX()const
{
  return instance->property("offsetX").toInt();
}

void QGameCanvas::setOffsetX(int _x)
{
  instance->setProperty("offsetX",_x);
}

int QGameCanvas::offsetY()const
{
  return instance->property("offsetY").toInt();
}

void QGameCanvas::setOffsetY(int _y)
{
  instance->setProperty("offsetY",_y);
}

QCell* QGameCanvas::CreateCell(int x,int y,int color,int num)
{
  qDebug("CreateCell");
  QVariant ret;
  QMetaObject::invokeMethod(instance, "createCell", Qt::DirectConnection,
                            Q_RETURN_ARG(QVariant, ret),
                            Q_ARG(QVariant, x),
                            Q_ARG(QVariant, y),
                            Q_ARG(QVariant, QColor::fromRgb(color>>16,(color&0xFF00)>>8,color&0xFF)),
                            Q_ARG(QVariant, num));
  QQuickItem *item=ret.value<QQuickItem*>();
  assert(item);
  QCell *cell=new QCell(item);
  for(int i=0;i<6;i++)
    {
      cell->arrows[i]->instance=item->findChild<QQuickItem*>(QString().sprintf("arrow%d",i),Qt::FindDirectChildrenOnly);
    }
  return cell;
}
