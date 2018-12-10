#include "QMessageBox.h"

QMessageBox::QMessageBox(QQuickItem *msgbox)
    :QDialog(msgbox)
{

}

QString QMessageBox::text()const
{
    return instance->property("text").toString();
}

void QMessageBox::setText(const QString &str)
{
    instance->setProperty("text",str);
}
