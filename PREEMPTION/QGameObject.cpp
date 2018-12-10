#include "QGameObject.h"

QGameObject::QGameObject(QQuickItem *gameObject)
{
  instance=gameObject;
}

bool QGameObject::visible()const
{
  return instance->property("visible").toBool();
}

void QGameObject::setVisible(bool val)
{
  instance->setVisible(val);
}
