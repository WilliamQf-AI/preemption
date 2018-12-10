#include "IPlayer.h"

IPlayer::IPlayer(const QString &_name, int _color)
{
    name=_name;
    color=_color;
}

const QString& IPlayer::GetName() const
{
    return name;
}

//void IPlayer::SetName(const QString &s)
//{
//    name=s;
//}

int IPlayer::GetColor()const
{
    return color;
}

const Instruction* IPlayer::GetInstruction()const
{
    return &ins;
}
