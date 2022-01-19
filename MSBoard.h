
#ifndef SEPER_MSBOARD_H
#define SEPER_MSBOARD_H



#include <iostream>
#include "Field.h"

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };



class MinesweeperBoard
{
public:
    MinesweeperBoard(int,int,GameMode);
    void setField(int, int,const Field&);
    void debug_display();
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int x, int y) const;
    bool hasFlag(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    bool isRevealed(int x, int y) const;
    GameState getGameState() const;
    char getFieldInfo(int x, int y) const;

private:
    Field board[100][100];
    unsigned int width;
    unsigned int height;
    unsigned int minecount;
    GameState state;
    GameMode mode;
    int revealedcount;
    int reserveX, reserveY;

};

#endif //SEPER_HED_H
