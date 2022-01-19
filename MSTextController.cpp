
#include <iostream>
#include "MSTextController.h"


MSTextController::MSTextController(MinesweeperBoard& cboard, MSBoardTextView& cview)
{
   mboard=&cboard;
    tview=&cview;

}
void MSTextController::play()
{
    char a;
    int x, y;
    while(mboard->getGameState()==RUNNING)
    {


std::cout<<"MINESWEEPER"<<std::endl;
        tview->display();
        std::cout<<"moves: \n reveal field-r \n toggle flag-f"<<std::endl;
        std::cin>>a;
        std::cout<<std::endl;
        if(a=='r')
        {
            std::cout<<"x coordinate: ";
            std::cin>>x;
            std::cout<<"y coordinate: ";
            std::cin>>y;
            if(x<0 || x>=mboard->getBoardWidth() || y<0 || y>mboard->getBoardHeight() )
            {
                std::cout<<"Coordinates must be in range: \nx - from 0 to "<<mboard->getBoardWidth()-1<<"\ny - from 0 to "<<mboard->getBoardHeight()-1;
                continue;
            }
            mboard->revealField(x,y);

        }
        if(a=='f')
        {
            std::cout<<"x coordinate: ";
            std::cin>>x;
            std::cout<<"y coordinate: ";
            std::cin>>y;
            if(x<0 || x>=mboard->getBoardWidth() || y<0 || y>mboard->getBoardHeight() )
            {
                std::cout<<"Coordinates must be in range: \nx - from 0 to "<<mboard->getBoardWidth()-1<<"\ny - from 0 to "<<mboard->getBoardHeight()-1;
                continue;
            }
            mboard->toggleFlag(x,y);
        }


    }
    tview->display();
    if(mboard->getGameState()==FINISHED_WIN)
    {
        std::cout<<"CONGRATULATIONS! YOU WON!";
    }

    if(mboard->getGameState()==FINISHED_LOSS)
    {
        std::cout<<"You lost, why don't you try again?";
    }


}
