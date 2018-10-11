#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <vector>

class Cell;
class Grid;

class Block {
protected:
	std::vector<Cell *> relatedCell;
	int shape;
	char letter;
	bool inBlock(Cell *c); //check whether cell c is in the block
public:

	Block(int shape, char letter);
	void attachCell(Cell *c);
	void left(Grid &g);
	void right(Grid &g);
	bool down(Grid &g); //return whether move down successfully
	void drop(Grid &g);
	void unset(Grid &g);
	char getletter();
	virtual void init(Grid &g) = 0;
	virtual void clockWise(Grid &g) = 0;
	virtual void counterClockWise(Grid &g) = 0;
	virtual void hint() = 0;
	virtual ~Block() = default;
};


#endif
