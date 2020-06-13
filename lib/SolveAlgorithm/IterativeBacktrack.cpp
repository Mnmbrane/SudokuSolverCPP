#include "IterativeBacktrack.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuCoord.h"
#include <stdio.h>
#include <set>

using namespace Sudoku;

// Solve using recursive backtracking
bool IterativeBacktrack::Solve(Sudoku::Puzzle& puzzle)
{
   UnmarkedCoordMapType unmarkedCoordList = puzzle.getUnmarkedCoords();
   UnmarkedCoordMapType::iterator it = unmarkedCoordList.begin();

   // Iterate through the unmarked coordinates
   while(it != unmarkedCoordList.end())
   {

      // brute force all of the values in the puzzle
      for(ValType val = ValType((puzzle.getValAt(it->first) + 1) % 10); val <= ValType::VAL_MAX; ++val)
      {
         //printf("val == [%d]\n", val);
         // Overflowed we need to go back to the previous unmarked in the list
         if(val == ValType::VAL_UNMARKED)
         {
            // Set current to unmarked
            puzzle.setValAt(it->first, ValType::VAL_UNMARKED);
            // Go to previous unmarked index

            // Went all the way back to the beginning
            // Return false
            if(it == unmarkedCoordList.begin())
            {
               //printf("Iterative::Exiting %s\n", __func__);
               return false;
            }
            else
            {
               it--;
               break;
            }
         }
         else
         {
            if(puzzle.setValAt(it->first, val) == true)
            {
               it++;
               break;
            }
            
         }
      }
   }
   return true;
}