
#ifndef SEPER_MSBTEXTVIEW_H
#define SEPER_MSBTEXTVIEW_H



#include <iostream>
#include "MSBoard.h"


class MSBoardTextView
{
private:
    MinesweeperBoard *brd;
public:
    MSBoardTextView(MinesweeperBoard& );
   void  display();

};


#endif //SEPER_MSBTEXTVIEW_H