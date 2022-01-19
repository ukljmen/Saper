

#ifndef SEPER_MSTEXTCONTROLLER_H
#define SEPER_MSTEXTCONTROLLER_H


#include<iostream>

#include "MSBoard.h"
#include "MSBTextView.h"

class MSTextController
{
private:
    MinesweeperBoard *mboard;
    MSBoardTextView *tview;

public:
    MSTextController(MinesweeperBoard&, MSBoardTextView&);
    void play();
};

#endif //SEPER_MSTEXTCONTROLLER_H
