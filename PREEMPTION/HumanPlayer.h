#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "IPlayer.h"
#include "Instruction.h"

class HumanPlayer : public IPlayer
{
public:
  HumanPlayer(const QString &name,int color);
  virtual int BeginTurn(GameMap *mmap);
};

#endif // HUMANPLAYER_H
