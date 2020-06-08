#pragma once

#include <stdint.h>
#include <vector>
#include "SudokuCommonTypes.h"

class Sudoku::SudokuPuzzle
{
public:

   SudokuPuzzle();
   ~SudokuPuzzle();

   void resetPuzzle();

   // getters
   ValType getValAt(const SudokuCoord& coord);

   const std::vector<SudokuCoord> getUnmarkedCoords() const;

   bool isPuzzleInit();

   // setters
   bool setValAt(const SudokuCoord& coord, ValType val);

   bool initPuzzle(PuzzlePtrType inPuzzle);

private:
   // Checker
   bool initialCheck(SudokuIndex index, ValType val);
   bool checkCol(const PuzzlePtrType puzzle, SudokuIndex index, ValType val);
   bool checkRow(const PuzzlePtrType puzzle, SudokuIndex index, ValType val);
   bool checkGroup(const PuzzlePtrType puzzle, SudokuIndex index, ValType val);
   bool checkAll(const PuzzlePtrType puzzle, SudokuIndex index, ValType val);
   
   bool initFlag;
   
   // The puzzle in array format
   ValType m_puzzle[PUZZLE_MAX_ELEMENTS];

   // List of uninitialized positions
   std::vector<SudokuCoord> unmarkedCoordList;
};