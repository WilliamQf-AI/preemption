#include "GameMap.h"
#include<iostream>
#include <cstring>
#include "QGameCanvas.h"
#include "IPlayer.h"
using namespace std;

GameMap::GameMap(int wid, int heig, QGameCanvas *gameCanvas)
{
	width = wid;
	height = heig;
    this->gameCanvas=gameCanvas;
	mmap = new CellBase*[width*height];
	memset(mmap,0,sizeof(CellBase*)*width*height);
}

GameMap::~GameMap()
{
	delete[] mmap;
}

void GameMap::CreateCell(int x, int y, CellBase* item)
{
    mmap[x*width + y] = item;
    item->SetInstance(gameCanvas->CreateCell(x,y,item->GetOwner()->GetColor(),item->GetNum()));
}

void GameMap::RemoveCell(int x, int y)
{
    assert(0); //not finished yet
    mmap[x*width+y]=nullptr;
}

int GameMap::getWidth()const
{
	return width;
}

int GameMap::getHeight()const
{
	return height;
}

CellBase* GameMap::GetCell(int x, int y)
{
    return mmap[x*width + y];
}

CellBase* GameMap::GetCellOnDir(int x,int y, int dir)
{
    switch(dir)
    {
    case 0:
        x--;
        break;
    case 1:
        if(y&1)x--;  //Y与1为1：为奇数，1就是00000001
        y++;
        break;
    case 2:
        if(!(y&1))x++;
        y++;
        break;
    case 3:
        x++;
        break;
    case 4:
        if(!(y&1))x++;
        y--;
        break;
    case 5:
        if(y&1)x--;
        y--;
        break;
    default:
        assert(0); //unreachable
    }
    if(x<0 || x>=height || y<0 || y>=width)return nullptr;
    return mmap[x*width+y];
}

void GameMap::LoadArrow(const Instruction *ins)
{
    ClearArrow();
    for(auto it:*ins)  //auto:用来申明自动变量。
    {
        QArrow *arrow=GetCell(it.x1,it.y1)->getArrow(it.dir);
        arrow->setNum(it.num);
        arrow->setVisible(true);
    }
}

void GameMap::ClearArrow()
{
    for(int x=0;x<height;x++)
    {
        for(int y=0;y<width;y++)
        {
            CellBase *cell=GetCell(x,y);
            if(cell)
            {
                for(int dir=0;dir<6;dir++)
                {
                    cell->getArrow(dir)->setNum(0);
                    cell->getArrow(dir)->setVisible(false);
                }
            }
        }
    }
}
