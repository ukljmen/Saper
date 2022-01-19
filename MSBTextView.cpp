
#include <iostream>
#include "MSBTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard& brdt)
{
    brd=&brdt;
}


void MSBoardTextView::display()
{

    for(int i=-1;i<brd->getBoardHeight()+1;i++)
    {
        for(int j=-1;j<brd->getBoardWidth()+1;j++)
        {
            std::cout<<brd->getFieldInfo(j,i);
        }
        std::cout<<std::endl;
    }

}