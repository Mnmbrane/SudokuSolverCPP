#include "RecursiveBacktrack.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuCoord.h"
#include <vector>

using namespace Sudoku;

// Solve using recursive backtracking
bool RecursiveBacktrack::Solve(Sudoku::Puzzle& puzzle)
{
   int i = 0;
   std::vector<Coord> unmarkedCoordList = puzzle.getUnmarkedCoords();
   int unmarkedCoordListSize = unmarkedCoordList.size();

   // Iterate through the unmarked coordinates
   while(i < unmarkedCoordListSize && i >= 0)
   {
      // brute force all of the values in the puzzle
      for(ValType val = (ValType)(puzzle.getValAt(unmarkedCoordList[i]) + 1); val <= ValType::VAL_9; ++val)
      {
         // Overflowed we need to go back to the previous unmarked in the list
         if(val == 0)
         {
            // Set current to unmarked
            puzzle.setValAt(unmarkedCoordList[i], ValType::VAL_UNMARKED);
            // Go to previous unmarked
            i--;
         }
         else if(puzzle.setValAt(unmarkedCoordList[i], val))
         {
            i++;
            break;
         }
      }
   }

   if(i == -1)
   {
      return false;
   }
   else
   {
      return true;
   }
   
}