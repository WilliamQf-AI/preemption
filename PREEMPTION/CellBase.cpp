#include "IPlayer.h"
#include "CellBase.h"
#include<iostream>
using namespace std;

CellBase::CellBase(IPlayer* id0, int num0)
{
	id = id0;
	num = num0;
}

CellBase::~CellBase()
{

}

int CellBase::x()const
{
    return instance->x();
}

int CellBase::y()const
{
    return instance->y();
}

IPlayer* CellBase::GetOwner()const
{
	return id;
}

void CellBase::SetOwner(IPlayer *id2)
{
	id = id2;
    instance->setColor(id->GetColor());
}

int CellBase::GetNum()const
{
	return num;
}

void CellBase::SetNum(int n)
{
	num = n;
    instance->setNum(num);
}

QArrow* CellBase::getArrow(int dir)
{
    return instance->getArrow(dir);
}

//QCell* CellBase::GetInstance()
//{
//	return instance;
//}

void CellBase::SetInstance(QCell *ins) //设置实例
{
  instance=ins;
}
