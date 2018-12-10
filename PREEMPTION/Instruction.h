#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
using namespace std;

struct InsItem
{
  int x1,y1;
  int dir;
  //int x2,y2;
  int num;
};

using Instruction=vector<InsItem>;

#endif // INSTRUCTION_H
