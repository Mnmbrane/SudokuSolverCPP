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
   
   bool initFlag;
   
   // The puzzle in array format
   ValType m_puzzle[PUZZLE_MAX_ELEMENTS];

   // List of uninitialized positions
   std::vector<SudokuCoord> unmarkedCoordList;
};

}