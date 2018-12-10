#ifndef QDIALOG_H
#define QDIALOG_H
#include "QGameObject.h"

class QDialog : public QGameObject
{
public:
    QDialog(QQuickItem *dialog=nullptr);
    void Show()const;
};

#endif // QDIALOG_H
