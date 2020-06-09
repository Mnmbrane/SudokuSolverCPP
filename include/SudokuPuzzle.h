#pragma once

#include <stdint.h>
#include <vector>
#include "SudokuCommonTypes.h"

class Sudoku::Puzzle
{
public:

   Puzzle();
   ~Puzzle();

   void resetPuzzle();

   // getters
   ValType getValAt(const Coord& coord) const;

   const std::vector<Coord> getUnmarkedCoords() const;

   bool isPuzzleInit();

   // setters
   bool setValAt(const Coord& coord, ValType val);

   bool initPuzzle(PuzzlePtrType inPuzzle);

   void printPuzzle();

   bool operator==(const Puzzle& rhs);

private:
   // Checker
   bool initialCheck(Index index, ValType val);
   bool checkCol(const PuzzlePtrType puzzle, Index index, ValType val);
   bool checkRow(const PuzzlePtrType puzzle, Index index, ValType val);
   bool checkGroup(const PuzzlePtrType puzzle, Index index, ValType val);
   bool checkAll(const PuzzlePtrType puzzle, Index index, ValType val);
   
   bool initFlag;
   
   // The puzzle in array format
   ValType m_puzzle[PUZZLE_MAX_ELEMENTS];

   // List of uninitialized positions
   std::vector<Coord> unmarkedCoordList;
};