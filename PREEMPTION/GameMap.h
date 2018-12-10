#pragma once
#include "CellBase.h"
#include "Instruction.h"

class QGameCanvas;

class GameMap
{
public:
    GameMap(int width, int height, QGameCanvas *gameCanvas=nullptr);
	~GameMap();
    void CreateCell(int x, int y, CellBase* item);
	void RemoveCell(int x, int y);
	int getWidth()const;
	int getHeight()const;

    CellBase* GetCell(int x, int y);
    CellBase* GetCellOnDir(int x,int y, int dir);
    void LoadArrow(const Instruction *ins);
    void ClearArrow();

private:
	int width;
	int height;
	CellBase **mmap;
    QGameCanvas *gameCanvas;
};
