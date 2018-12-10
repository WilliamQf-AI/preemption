#ifndef QBUTTON_H
#define QBUTTON_H

#include <QQuickItem>
#include "QGameObject.h"

class QButton : public QGameObject
{
public:
  friend class QGameCanvas;
public:
  QButton(QQuickItem *button=nullptr);
};

#endif // QBUTTON_H
