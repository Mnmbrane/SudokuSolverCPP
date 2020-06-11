#pragma once

#include <stdint.h>
#include <map>
#include <set>
#include "SudokuCommonTypes.h"

class Sudoku::Puzzle
{
public:

   Puzzle();
   Puzzle(const Puzzle& puzzle);
   ~Puzzle();

   void resetPuzzle();

   // getters
   ValType getValAt(const Cell& cell) const;

   const UnmarkedCellMapType getUnmarkedCells() const;

   //void initAllUnmarkedCells();

   bool isPuzzleInit();

   void unmark(const Cell& cell);

   // setters
   bool setValAt(const Cell& cell, ValType val);

   bool initPuzzle(PuzzlePtrType inPuzzle);

   void printPuzzle();

   bool operator==(const Puzzle& rhs);

private:

   bool checkPuzzleValidity(PuzzlePtrType inPuzzle);
   void setPuzzle(PuzzlePtrType inPuzzle);
   void initAllUnmarkedCells();
   // Checker
   bool initialCheck(Index index, ValType val);
   bool checkCol(const PuzzlePtrType puzzle, Index index, ValType val);
   bool checkRow(const PuzzlePtrType puzzle, Index index, ValType val);
   bool checkGroup(const PuzzlePtrType puzzle, Index index, ValType val);
   bool checkAll(const PuzzlePtrType puzzle, Index index, ValType val);
   
   bool initFlag;
   
   // The puzzle in array format
   ValType m_puzzle[PUZZLE_MAX_ELEMENTS];

   // List of uninitialized positions and it's possible values
   UnmarkedCellMapType unmarkedCells;
};