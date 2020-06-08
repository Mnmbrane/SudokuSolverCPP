#pragma once

#include <stdint.h>
#include <vector>
#include "SudokuCommonTypes.h"

namespace Sudoku
{

class SudokuCoord;

class SudokuPuzzle
{
public:

   SudokuPuzzle();

   void resetPuzzle();

   // getters
   ValType getValAt(SudokuCoord coord);

   const std::vector<SudokuCoord> getUnmarkedCoords() const;

   // setters
   bool setValAt(SudokuCoord coord, ValType val);

   bool initPuzzle(PuzzlePtrType inPuzzle);

private:
   
   bool initFlag;
   
   // The puzzle in array format
   ValType m_puzzle[PUZZLE_MAX_ELEMENTS];

   // List of uninitialized positions
   std::vector<SudokuCoord> unmarkedCoordList;
};

}