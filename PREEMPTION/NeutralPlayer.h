#ifndef NEUTRALPLAYER_H
#define NEUTRALPLAYER_H
#include "IPlayer.h"
#include "Instruction.h"

class NeutralPlayer : public IPlayer
{
public:
  NeutralPlayer(const QString &name,int color);
  virtual int BeginTurn(GameMap *mmap);
};

#endif // NEUTRALPLAYER_H
