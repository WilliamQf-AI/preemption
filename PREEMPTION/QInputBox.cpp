#include "QInputBox.h"

QInputBox::QInputBox(QQuickItem *dialog)
  :QDialog(dialog)
{

}

int QInputBox::value()const
{
  return instance->property("value").toInt();
}

void QInputBox::setValue(int val)
{
  instance->setProperty("value",val);
}

int QInputBox::maxValue()const
{
  return instance->property("maxValue").toInt();
}

void QInputBox::setMaxValue(int maxv)
{
  instance->setProperty("maxValue",maxv);
}
