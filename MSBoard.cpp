
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "MSBoard.h"

MinesweeperBoard::MinesweeperBoard(int w,int h, GameMode g)
{
    width=w;
    height=h;
    revealedcount=0;
    state=RUNNING;
    mode=g;
    minecount=(height*width/10)*g;
    srand(time(NULL));
    int arr[minecount+1][2];
    int k,l;
    for(unsigned int i=0;i<minecount+1;i++)
    {
        k=rand()%width;
        l=rand()%height;
        arr[i][0]=k;
        arr[i][1]=l;
        if(i>0)
        {
            for(unsigned int j=0;j<i;j++)
            {
                if(arr[i][0]==arr[j][0] && arr[i][1]==arr[j][1])
                {
                    i--;
                    break;
                }
            }
        }
    }
    reserveX=arr[minecount][0];
    reserveY=arr[minecount][1];

    for(unsigned int i=0;i<minecount;i++)
    {
        board[arr[i][0]][arr[i][1]].hasMine=true;
    }

}


void MinesweeperBoard::setField(int w, int h,const Field& field)
{
    if (w < this->width && h < this->height) {
        this->board[w][h] = field;
    }
}

void MinesweeperBoard::debug_display()
{
    for(int i=0;i<this->height;i++)
    {
        for(int j=0;j<this->width;j++)
        {
            std::cout<<"[";

            if(board[j][i].hasMine==true)
            {
                std::cout<<"M";
            }
            else {std::cout<<".";}
            if(board[j][i].isRevealed==true)
            {
                std::cout<<"o";
            }
            else {std::cout<<".";}
            if(board[j][i].hasFlag==true)
            {
                std::cout<<"f";
            }
            else {std::cout<<".";}

            std::cout<<"]";
        }
        std::cout<<std::endl;
    }

}


int MinesweeperBoard::getBoardWidth() const
{
    return this->width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return this->height;
}

int MinesweeperBoard::getMineCount() const
{
    return this->minecount;
}

int MinesweeperBoard::countMines(int x, int y) const
{
    int c=0;
    if(board[x][y].isRevealed==false)
    {
        return -1;
    }
    if(x>=width || y>=height || x<0 || y<0)
    {
        return -1;
    }

    if(x-1>=0 && board[x-1][y-1].hasMine==true)
    {c++;}
    if(board[x][y-1].hasMine==true)
    {c++;}
    if(board[x+1][y-1].hasMine==true)
    {c++;}
    if(x-1>=0 && board[x-1][y].hasMine==true)
    {c++;}
    if(board[x+1][y].hasMine==true)
    {c++;}
    if(x-1>=0 && board[x-1][y+1].hasMine==true)
    {c++;}
    if(board[x][y+1].hasMine==true)
    {c++;}
    if(board[x+1][y+1].hasMine==true)
    {c++;}
    return c;
}

bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if(board[x][y].hasFlag==true)
    {return true;}
    else {if(x>=width || y>=height || x<0 || y<0 || board[x][y].hasFlag==false || board[x][y].isRevealed==true)
    {return false;}}
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
    if(board[x][y].isRevealed==false && board[x][y].hasFlag==false )
    {board[x][y].hasFlag=true;}
    else{ if(board[x][y].isRevealed==false && board[x][y].hasFlag==true )
        {board[x][y].hasFlag=false;}}
}

void MinesweeperBoard::revealField(int x, int y)
{
    if(x>=width || y>=height || x<0 || y<0 || board[x][y].isRevealed==true || state!=RUNNING|| board[x][y].hasFlag==true)
    {}
    else
    {
        board[x][y].isRevealed=true;
        revealedcount++;
        if(revealedcount==1 && board[x][y].hasMine==true)
        {
            board[x][y].hasMine=false;
            board[reserveX][reserveY].hasMine=true;
        }

        if(board[x][y].hasMine==true)
        {
            state=FINISHED_LOSS;
        }
        else if(revealedcount==height*width-minecount)
        {
            state=FINISHED_WIN;
        }
    }

}

bool MinesweeperBoard::isRevealed(int x, int y) const
{
    if(board[x][y].isRevealed==true)
    {return true;}
    if(board[x][y].isRevealed==false)
    {return false;}
}


GameState MinesweeperBoard::getGameState() const
{
    return state;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    if(x>=width || y>=height || x<0 || y<0)
    {return '#';}
    if(board[x][y].isRevealed==false && board[x][y].hasFlag==true )
    {return 'F';}
    if(board[x][y].isRevealed==false && board[x][y].hasFlag==false )
    {return '_';}
    if(board[x][y].isRevealed==true && board[x][y].hasMine==true )
    {return 'x';}
    if(board[x][y].isRevealed==true && countMines(x,y)==0 )
    {return ' ' ;}
    if(board[x][y].isRevealed==true && countMines(x,y)>0 )
    {return countMines(x,y)+48;}
    return '#';
}
