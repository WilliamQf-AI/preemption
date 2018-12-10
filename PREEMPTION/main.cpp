#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickItem>
#include "maskedmousearea.h"
#include "GameManager.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  qmlRegisterType<MaskedMouseArea>("customitems",1,0,"MaskedMouseArea");

  QQmlApplicationEngine *engine=new QQmlApplicationEngine;
  engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine->rootObjects().isEmpty())
      return -1;

  QObject *root=engine->rootObjects().first();
  QQuickItem *gameCanvas=root->findChild<QQuickItem*>("gameCanvas");

  GameManager *game=new GameManager(gameCanvas);
  QObject::connect(gameCanvas,SIGNAL(qmlSignal_inputBox_discard()),
                   game,SLOT(qmlSlot_inputBox_discard()));
  QObject::connect(gameCanvas,SIGNAL(qmlSignal_inputBox_accept()),
                   game,SLOT(qmlSlot_inputBox_accept()));
  QObject::connect(gameCanvas,SIGNAL(qmlSignal_cell_onClick(int,int)),
                   game,SLOT(qmlSlot_cell_onClick(int,int)));
//  QObject::connect(gameCanvas,SIGNAL(qmlSignal_cell_onMouseLeave(int,int)),
//                   &game,SLOT(qmlSlot_cell_onMouseLeave(int,int)));
  QObject::connect(gameCanvas,SIGNAL(qmlSignal_arrow_onClick(int,int,int)),
                   game,SLOT(qmlSlot_arrow_onClick(int,int,int)));
  QObject::connect(gameCanvas,SIGNAL(qmlSignal_btnRun_onClick()),
                   game,SLOT(qmlSlot_btnRun_onClick()));
  QObject::connect(gameCanvas,SIGNAL(qmlSignal_cell_onPositionChange(QVariant)),
                   game,SLOT(qmlSlot_cell_onPositionChange(QVariant)));
  game->Init();
  game->Begin();

  qDebug("##");

  return app.exec();
}
