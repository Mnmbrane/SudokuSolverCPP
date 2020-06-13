#pragma once

#include <stdint.h>
#include <map>
#include <set>
#include "SudokuCommonTypes.h"
#include "SudokuCell.h"

class Sudoku::Puzzle
{
public:

   Puzzle();
   Puzzle(const Puzzle& puzzle);
   ~Puzzle();

   void resetPuzzle();

   // getters
   ValType getValAt(const Coord& coord) const;

   const UnmarkedCoordMapType getUnmarkedCoords() const;

   //void initAllUnmarkedCoords();

   bool isPuzzleInit();

   // setters
   bool setValAt(const Coord& coord, ValType val);

   bool initPuzzle(Cell* inPuzzle);

   void printPuzzle();

   bool operator==(const Puzzle& rhs);

private:

   bool checkPuzzleValidity(Cell* inPuzzle);
   void setPuzzle(Cell* inPuzzle);
   void initAllUnmarkedCoords();
   // Checker
   bool initialCheck(Index index, ValType val);
   bool checkCol(Cell* puzzle, Index index, ValType val);
   bool checkRow(Cell* puzzle, Index index, ValType val);
   bool checkGroup(Cell* puzzle, Index index, ValType val);
   bool checkAll(Cell* puzzle, Index index, ValType val);
   
   bool initFlag;
   
   // The puzzle in array format
   Cell m_puzzle[PUZZLE_MAX_ELEMENTS];

   // List of uninitialized positions and it's possible values
   UnmarkedCoordMapType unmarkedCoords;
};