#include "HiddenOnes.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuCoord.h"
#include <stdio.h>
#include <set>

using namespace Sudoku;


// Try to get all of the naked ones first before going to the next algorithm
bool HiddenOnes::Solve(Sudoku::Puzzle &puzzle, CandidateSetMapType &unmarkedCoordList)
{
   // Check every val for a hidden candidates
   for(ValType val = VAL_1; val <= VAL_9; ++val)
   {

   }
   return false;
}