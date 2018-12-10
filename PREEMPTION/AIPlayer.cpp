#include "AIPlayer.h"
#include "GameManager.h"
#include <cstring>
#include <random>

AIPlayer::AIPlayer(const QString &name, int color)
  :IPlayer(name,color),imap(nullptr)
{

}

AIPlayer::~AIPlayer()
{
    delete[] imap;
}

int AIPlayer::BeginTurn(GameMap *mmap)
{
    qDebug("[BeginTurn]PlayerID=%x",this);
    static random_device rd;
    ins.clear();
//    if(!imap)
//    {
//        imap=new char*[mmap->getHeight()];
//        for(int i=0;i<mmap->getHeight();i++)
//        {
//            imap[i]=new char[mmap->getWidth()];
//        }
//    }
//    for(int i=0;i<mmap->getHeight();i++)
//    {
//        memset(imap[i],0,sizeof(char)*mmap->getWidth());
//    }
    InsItem it;
    for(it.x1=0;it.x1<mmap->getHeight();it.x1++)
    {
        for(it.y1=0;it.y1<mmap->getWidth();it.y1++)
        {
            CellBase *from=mmap->GetCell(it.x1,it.y1);
            if(from && from->GetOwner()==this)
            {
                int remain=from->GetNum();
                if(remain<=0)continue;
                bool vis[6];
                memset(vis,false,sizeof(vis));
                int dir;
                for(int j=0;j<6 && remain>0;j++)
                {
                    dir=rd()%6;  //在0~5中生成随机数
                    while(vis[dir])dir=(dir+1)%6;
                    vis[dir]=true;
                    CellBase *to=mmap->GetCellOnDir(it.x1,it.y1,dir);
                    if(!to /*|| imap[to->x()][to->y()]&(1<<((dir+3)%6))*/)continue;
                    //imap[it.x1][it.y1] |= 1<<dir;
                    it.dir=dir;
                    if(to->GetOwner()!=this)
                    {
                        if(to->GetNum()<remain && rd()%100<95)
                        {
                            it.num=rd()%(remain-to->GetNum())+to->GetNum()+1; //派过去的兵力要把对方多
                            remain-=it.num;
                            ins.push_back(it);
                        }
                        else if(remain==to->GetNum() && rd()%100<50)
                        {
                            it.num=remain;
                            remain=0;
                            ins.push_back(it);
                        }
                        else if(rd()%100<30)
                        {
                            it.num=rd()%remain+1;
                            remain-=it.num;
                            ins.push_back(it);
                        }
                    }
                    else  //同玩家
                    {
//                        int sum=0;
//                        for(int i=0;i<6;i++)
//                        {
//                            CellBase *t=mmap->GetCellOnDir(it.x1,it.y1,i);
//                            if(t && t->GetOwner()!=this)
//                            {
//                                sum+=t->GetNum();
//                            }
//                        }
//                        if(sum>=to->GetNum() && rd()%100<90)
//                        {
//                            it.num=remain*4/5;
//                            if(it.num==0)it.num=1;
//                            remain-=it.num;
//                            ins.push_back(it);
//                        }
                        if(rd()%100<10)
                        {
                            it.num=rd()%remain+1;
                            remain-=it.num;
                            ins.push_back(it);
                        }
                    }
                }
            }
        }
    }
    GameManager::Sleep(1000);
    return 0;
}
