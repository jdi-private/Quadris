#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include <memory>
#include "cell.h"
#include "info.h"
#include "level.h"
#include "textdisplay.h"

class GraphicsDisplay;

using namespace std;
class TextDisplay;
class Observer;
class InvalidMove{};

class Grid {
  std::vector<std::vector<Cell>> theGrid;  // The actual grid.
  TextDisplay *td = nullptr; // The text display.
  //GraphicsDisplay *ob = nullptr;  // Another observer (intent:  graphics)
  // Add private members, if necessary.
public:
  GraphicsDisplay *ob = nullptr;
  
  Block* nextBlock;
  void setUp(int s);

  ~Grid();	
  bool isOccupied(int x, int y);
  Cell* getCell(int x, int y);
  void setObserver(GraphicsDisplay *sOb);
  void setCell(int x, int y, char type_char);
  void setNext(Block* next);
  bool endGame(); // Who has more pieces when the board is full?
  void init(); // Sets up an n x n grid.  Clears old grid, if necessary.
  //	void generateBlock(char type_char);  // Plays piece at row r, col c.
  int checkRows();
  void dropRow(int r);
    //void updateRow(int row);
    //void generateBlock();  // Plays piece at row r, col c.
  //	void levelChange(int i);  // Flips piece at row r, col c.
  void drawGeneralInfo();

  	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
