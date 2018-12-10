#include "NeutralPlayer.h"

NeutralPlayer::NeutralPlayer(const QString &name, int color)
    :IPlayer(name,color)
{

}

int NeutralPlayer::BeginTurn(GameMap *mmap)
{
    qDebug("[BeginTurn]PlayerID=%x",this);
    assert(0); //should not be called
    return 0;
}
