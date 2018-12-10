#include "GameManager.h"
#include "NeutralPlayer.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "CellBase.h"
#include "GameMap.h"
#include <Windows.h>
#include <QTime>
#include <random>

bool GameManager::gameOver=false;
bool GameManager::turnBegin=false;
const double GameManager::CELL_RADIUS=63;

GameManager::GameManager(QQuickItem *qcanvas,QObject *parent)
    : QObject(parent),gameCanvas(qcanvas)
{

}

void GameManager::Init()
{
    qDebug("GameManager::Init()");
    //gameCanvas.setActive(false);
    players.push_back(new NeutralPlayer("",0x8F8F8F));
    players.push_back(new HumanPlayer("You",0x0000FF));
    players.push_back(new AIPlayer("AI",0xFF0000));
    LoadMap();
    turnBegin=false;
    gameOver=false;
    //emit onCompleted();
}

void GameManager::Begin()
{
    qDebug("GameManager::Begin()");
    assert(players.size()>2); //less than two players
    gameCanvas.setActive(true);
    int i=1;
    bool first=true;
    while(!gameOver)
    {
        currentPlayer=players[i];

        //is game over?
        int ncell=0;
        for(int x=0;x<gameMap->getHeight();x++)
        {
            for(int y=0;y<gameMap->getWidth();y++)
            {
                auto cell=gameMap->GetCell(x,y);
                if(cell && cell->GetOwner()==currentPlayer)ncell++;
            }
        }
        if(ncell==0)
        {
            players.erase(players.begin()+i);
            if(players.size()==2)
            {
                gameCanvas.msgbox()->setText(players[1]->GetName()+" win.");
                gameCanvas.msgbox()->Show();
                gameOver=true;
                gameCanvas.setActive(false);
                break;
            }
            else
            {
                if(i==players.size())i=1;
                continue;
            }
        }

        //multiply
        if(!first)
        {
            for(int x=0;x<gameMap->getHeight();x++)
            {
                for(int y=0;y<gameMap->getWidth();y++)
                {
                    auto cell=gameMap->GetCell(x,y);
                    if(cell && cell->GetOwner()==currentPlayer)
                    {
                        cell->SetNum(cell->GetNum()+1);
                    }
                }
            }
        }
        first=false;

        //let the player operate
        turnBegin=true;
        currentPlayer->BeginTurn(gameMap);
        turnBegin=false;

        //show arrow on map
        gameMap->LoadArrow(currentPlayer->GetInstruction());
        Sleep(1000);

        //move
        for(auto it:*(currentPlayer->GetInstruction()))
        {
            Move(it.x1,it.y1,it.dir,it.num);
        }
        gameMap->ClearArrow();

        //next
        i=i+1 < players.size() ? i+1 : 1;
    }
}

void GameManager::LoadMap()
{
    gameMap=new GameMap(7,3,&gameCanvas);
    gameCanvas.setOffsetX(200);
    gameCanvas.setOffsetY(200);
    gameMap->CreateCell(0,0,new CellBase(players[0],0));
    gameMap->CreateCell(0,1,new CellBase(players[0],0));
    gameMap->CreateCell(0,2,new CellBase(players[0],0));
    gameMap->CreateCell(0,4,new CellBase(players[0],0));
    gameMap->CreateCell(0,5,new CellBase(players[0],0));
    gameMap->CreateCell(0,6,new CellBase(players[0],0));
    gameMap->CreateCell(1,0,new CellBase(players[0],0));
    gameMap->CreateCell(1,1,new CellBase(players[1],5));
    gameMap->CreateCell(1,2,new CellBase(players[0],0));
    gameMap->CreateCell(1,3,new CellBase(players[0],0));
    gameMap->CreateCell(1,4,new CellBase(players[0],0));
    gameMap->CreateCell(1,5,new CellBase(players[2],5));
    gameMap->CreateCell(1,6,new CellBase(players[0],0));
    gameMap->CreateCell(2,1,new CellBase(players[0],0));
    gameMap->CreateCell(2,5,new CellBase(players[0],0));
}

bool GameManager::isGameOver()
{
    return gameOver;
}

bool GameManager::isTurnBegin()
{
    return turnBegin;
}

void GameManager::Sleep(int ms)
{
    QTime timer;
    timer.start();
    while(timer.elapsed()<ms)
    {
        QCoreApplication::processEvents();
    }
}

void GameManager::Battle(int &atk,int &def)
{
    static random_device rd;
    qDebug("battle begin");
    while(atk && def)
    {
        qDebug("atk=%d def=%d",atk,def);
        if(rd()%100<5)atk--;
        else if(rd()%100<10) def--;
        else atk--,def--;
    }
}

void GameManager::Move(int x,int y,int dir,int num)
{
    CellBase *from=gameMap->GetCell(x,y);
    from->SetNum(from->GetNum()-num);
    CellBase *to=gameMap->GetCellOnDir(x,y,dir);
    if(currentPlayer!=to->GetOwner())
    {
        int enemy=to->GetNum();
        Battle(num,enemy);
        if(num==0 && enemy>=0)
        {
            to->SetNum(enemy);
        }
        else
        {
            to->SetNum(num);
            to->SetOwner(currentPlayer);
        }
    }
    else
    {
        to->SetNum(to->GetNum()+num);
    }
}

QGameCanvas * GameManager::canvas()
{
    return &gameCanvas;
}

//void GameManager::setCanvas(QGameCanvas *cvs)
//{
//    gameCanvas=cvs;
//}

void GameManager::qmlSlot_gameCanvas_onCompleted(QVariant sender)
{
    qDebug("qmlSlot_gameCanvas_onCompleted");
    //gameCanvas.instance=sender.value<QQuickItem*>();
}

void GameManager::qmlSlot_gameCanvas_onDestroyed()
{
    qDebug("qmlSlot_gameCanvas_onDestroyed");
    gameOver=true;
}

void GameManager::qmlSlot_inputBox_discard()
{
    qDebug("qmlSlot_inputBox_discard");
    gameMap->GetCell(currentArrow.x,currentArrow.y)
            ->getArrow(currentArrow.dir)->setNum(0);
}

void GameManager::qmlSlot_inputBox_accept()
{
    qDebug("qmlSlot_inputBox_accept");
    qDebug()<<gameCanvas.inputBox()->value();
    gameMap->GetCell(currentArrow.x,currentArrow.y)
            ->getArrow(currentArrow.dir)->setNum(gameCanvas.inputBox()->value());
    qDebug()<<gameMap->GetCell(currentArrow.x,currentArrow.y)->getArrow(currentArrow.dir)->num();
}

void GameManager::qmlSlot_cell_onClick(int x,int y)
{
    qDebug("qmlSlot_cell_onClick x=%d y=%d",x,y);
    CellBase *cell;
    if(currentCell.x>=0 && currentCell.y>=0)
    {
        cell=gameMap->GetCell(currentCell.x,currentCell.y);
        for(int i=0;i<6;i++)
        {
            if(cell->getArrow(i)->num()==0)
            {
                cell->getArrow(i)->setVisible(false);
            }
        }
        if(currentCell.x==x && currentCell.y==y)
        {
            currentCell.x=currentCell.y=-1;
            return;
        }
    }

    assert(0<=x && x<gameMap->getHeight() && 0<=y && y<gameMap->getWidth()); //coordinate out of range
    cell=gameMap->GetCell(x,y);
    assert(cell); //imposible click
    currentCell.x=x;
    currentCell.y=y;
    if(cell->GetOwner()!=currentPlayer)return;
    for(int i=0;i<6;i++)
    {
        CellBase *ad=gameMap->GetCellOnDir(x,y,i);
        if(ad && ad->getArrow((i+3)%6)->num()==0)
        {
            cell->getArrow(i)->setVisible(true);
        }
    }
}

//void GameManager::qmlSlot_cell_onMouseLeave(int x,int y)
//{
//    qDebug("qmlSlot_cell_onMouseLeave x=%d y=%d",x,y);
//    assert(0<=x && x<gameMap->getHeight() && 0<=y && y<gameMap->getWidth()); //coordinate out of range
//    auto cell=gameMap->GetCell(x,y);
//    assert(cell); //imposible click
//    if(cell->GetOwner()!=currentID)return;
//    for(int i=0;i<6;i++)
//    {
//        if(cell->GetInstance()->getArrow(i)->num()==0)
//        {
//            cell->GetInstance()->getArrow(i)->setVisible(false);
//        }
//    }
//}

void GameManager::qmlSlot_arrow_onClick(int x,int y,int dir)
{
    qDebug("qmlSlot_arrow_onClick x=%d y=%d dir=%d",x,y,dir);
    currentArrow.x=x;
    currentArrow.y=y;
    currentArrow.dir=dir;
    CellBase *cell=gameMap->GetCell(x,y);
    gameCanvas.inputBox()->setValue(cell->getArrow(dir)->num());
    int sum=0;
    for(int i=0;i<6;i++)
    {
        if(i==dir)continue;
        sum+=cell->getArrow(i)->num();
    }
    sum=cell->GetNum()-sum;
    assert(sum>=0);
    gameCanvas.inputBox()->setMaxValue(sum);
    gameCanvas.inputBox()->Show();
}

void GameManager::qmlSlot_btnRun_onClick()
{
    qDebug("qmlSlot_btnRun_onClick");
    turnBegin=false;
}

void GameManager::qmlSlot_cell_onPositionChange(QVariant sender)
{
    qDebug("qmlSlot_cell_onPositionChange");
    QQuickItem *cell=sender.value<QQuickItem*>();
    int hex_y=cell->property("hex_x").toInt();
    int hex_x=cell->property("hex_y").toInt();
    double y = hex_y * sqrt(3) * CELL_RADIUS;
    if ((hex_x % 2) != 0)
    {
        y -= (sqrt(3)*CELL_RADIUS) / 2;
    }
    double x = (3 * CELL_RADIUS*hex_x) / 2;
    cell->setProperty("rect_x",x);
    cell->setProperty("rect_y",y);
}
