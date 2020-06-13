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
   ValType getValAt(const Coord& coord) const;

   const UnmarkedCoordMapType getUnmarkedCoords() const;

   //void initAllUnmarkedCoords();

   bool isPuzzleInit();

   void unmark(const Coord& coord);

   // setters
   bool setValAt(const Coord& coord, ValType val);

   bool initPuzzle(PuzzlePtrType inPuzzle);

   void printPuzzle();

   bool operator==(const Puzzle& rhs);

private:

   bool checkPuzzleValidity(PuzzlePtrType inPuzzle);
   void setPuzzle(PuzzlePtrType inPuzzle);
   void initAllUnmarkedCoords();
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
   UnmarkedCoordMapType unmarkedCoords;
};