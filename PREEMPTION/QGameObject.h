#ifndef QGAMEOBJECT_H
#define QGAMEOBJECT_H

#include <QQuickItem>
#include <cassert>

class QGameObject
{
public:
  QGameObject(QQuickItem *gameObject);
  bool visible()const;
  void setVisible(bool _visible);

protected:
  QQuickItem *instance;
};

#endif // QGAMEOBJECT_H
