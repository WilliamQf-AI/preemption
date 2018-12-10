#pragma once
#include <QObject>
#include <vector>
#include "QGameCanvas.h"
#include "QInputBox.h"
#include "CellBase.h"
#include "GameMap.h"
#include "IPlayer.h"
using namespace std;

class GameManager : public QObject
{
  Q_OBJECT
public:
  explicit GameManager(QQuickItem *gameCanvas,QObject *parent = nullptr);
  void Init();
  void Begin();
  void LoadMap();
  static bool isGameOver();
  static bool isTurnBegin();
  static void Sleep(int ms);

public:
  QGameCanvas * canvas();
  //void setCanvas(QGameCanvas *cvs);
  static const double CELL_RADIUS;

private:
  void Battle(int &atk,int &def);
  void Move(int x,int y,int dir,int num);

private:
  QGameCanvas gameCanvas;
  vector<IPlayer*> players;
  GameMap *gameMap;

  static bool gameOver;
  static bool turnBegin;

  IPlayer *currentPlayer;
  struct
  {
    int x=-1,y=-1,dir=-1;
  }currentArrow;
  struct
  {
      int x=-1,y=-1;
  }currentCell;

signals:
    //void onCompleted();
public slots:
  void qmlSlot_gameCanvas_onCompleted(QVariant sender);
  void qmlSlot_gameCanvas_onDestroyed();
  void qmlSlot_inputBox_discard();
  void qmlSlot_inputBox_accept();
  void qmlSlot_cell_onClick(int x,int y);
  void qmlSlot_arrow_onClick(int x,int y,int dir);
  void qmlSlot_btnRun_onClick();
  void qmlSlot_cell_onPositionChange(QVariant sender);
};
