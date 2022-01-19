#include <iostream>
#include "MSBoard.h"
#include "MSBTextView.h"
#include "MSTextController.h"

int main()
{
    MinesweeperBoard board(20,10,GameMode::EASY);

    MSBoardTextView view (board);

   MSTextController ctrl (board,view);
   ctrl.play();
    return 0;

}
