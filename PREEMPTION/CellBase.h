#pragma once
#include "QCell.h"
#include "QArrow.h"

class IPlayer;

class CellBase
{
public:
    CellBase(IPlayer* id0, int num0);
	~CellBase();
    int x()const;
    int y()const;
    IPlayer* GetOwner()const;
    void SetOwner(IPlayer* id2);
	int GetNum()const;
	void SetNum(int n);
    QArrow* getArrow(int dir);
    //QCell* GetInstance();
	void SetInstance(QCell *ins);

private:
    IPlayer *id;
	int num;
	QCell *instance;
};





















