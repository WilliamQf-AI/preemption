#ifndef QINPUTBOX_H
#define QINPUTBOX_H
#include "QDialog.h"

class QInputBox : public QDialog
{
public:
  friend class QGameCanvas;
public:
  QInputBox(QQuickItem *dialog=nullptr);
  int value()const;
  void setValue(int val);
  int maxValue()const;
  void setMaxValue(int maxv);
};

#endif // QINPUTBOX_H
