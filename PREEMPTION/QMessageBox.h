#ifndef QMESSAGEBOX_H
#define QMESSAGEBOX_H
#include "QDialog.h"
#include <string>

class QMessageBox : public QDialog
{
    friend class QGameCanvas;
public:
    QMessageBox(QQuickItem *msgbox=nullptr);
    QString text()const;
    void setText(const QString &str);
};

#endif // QMESSAGEBOX_H
