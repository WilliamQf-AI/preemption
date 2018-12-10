#include "HumanPlayer.h"
#include "GameManager.h"
#include "Instruction.h"

HumanPlayer::HumanPlayer(const QString &name, int color)
    :IPlayer(name,color)
{

}

int HumanPlayer::BeginTurn(GameMap *mmap)
{
    qDebug("[BeginTurn]PlayerID=%x",this);
    //mmap->LoadArrow(&ins);
    while(GameManager::isTurnBegin())
    {
        GameManager::Sleep(100);
    }
    ins.clear();
    InsItem it;
    for(it.x1=0;it.x1<mmap->getHeight();it.x1++)
    {
        for(it.y1=0;it.y1<mmap->getWidth();it.y1++)
        {
            CellBase *cell=mmap->GetCell(it.x1,it.y1);
            if(cell && cell->GetOwner()==this)
            {
                for(int dir=0;dir<6;dir++)
                {
                    if(cell->getArrow(dir)->num()>0)
                    {
                        //it.x2=mmap->GetCellOnDir(it.x1,it.y1,dir)->GetInstance()->x();
                        //it.y2=mmap->GetCellOnDir(it.x1,it.y1,dir)->GetInstance()->y();
                        it.dir=dir;
                        it.num=cell->getArrow(dir)->num();
                        ins.push_back(it);
                    }
                }
            }
        }
    }
    return 0;
}
