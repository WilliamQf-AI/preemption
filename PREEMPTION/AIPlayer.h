#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "IPlayer.h"
#include "Instruction.h"
using namespace std;

class AIPlayer : public IPlayer
{
public:
  AIPlayer(const QString &name,int color);
  ~AIPlayer();
  virtual int BeginTurn(GameMap *mmap);
private:
    char **imap;
    struct Moves
    {
      InsItem instruct;
      int score;
//      bool operator==(const Moves &rhs)const
//      {
//          return
//      }
      bool operator<(const Moves &rhs)const
      {
          return this->score < rhs.score;
      }
    };
};

#endif // AIPLAYER_H
