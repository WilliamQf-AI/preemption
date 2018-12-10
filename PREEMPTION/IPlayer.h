#pragma once
#include "GameMap.h"
#include "Instruction.h"

class IPlayer
{
public:
    IPlayer(const QString &_name="",int _color=0xFFFFFF);
    const QString& GetName()const;
    //void SetName(const QString &s);
	int GetColor()const;
    const Instruction* GetInstruction()const;
    virtual int BeginTurn(GameMap *mmap) = 0;
protected:
    QString name;
	int color;
    Instruction ins;
};

