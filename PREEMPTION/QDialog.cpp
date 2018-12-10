#include "QDialog.h"

QDialog::QDialog(QQuickItem *dialog):QGameObject(dialog)
{

}

void QDialog::Show()const
{
  QMetaObject::invokeMethod(instance,"show");
}
