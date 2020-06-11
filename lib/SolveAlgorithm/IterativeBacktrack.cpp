#include "IterativeBacktrack.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuCell.h"
#include <stdio.h>
#include <set>

using namespace Sudoku;

// Solve using recursive backtracking
bool IterativeBacktrack::Solve(Sudoku::Puzzle& puzzle)
{
   UnmarkedCellMapType unmarkedCellList = puzzle.getUnmarkedCells();
   UnmarkedCellMapType::iterator it = unmarkedCellList.begin();

   // Iterate through the unmarked cellinates
   while(it != unmarkedCellList.end())
   {
   //    printf("i == [%d]\n", i);
      // brute force all of the values in the puzzle
      for(ValType val = ValType((puzzle.getValAt(it->first) + 1) % 10); val <= ValType::VAL_9; ++val)
      {

         // Overflowed we need to go back to the previous unmarked in the list
         if(val == ValType::VAL_UNMARKED)
         {
            // Set current to unmarked
            puzzle.setValAt(it->first, ValType::VAL_UNMARKED);
            // Go to previous unmarked index

            // Went all the way back to the beginning
            // Return false
            if(it == unmarkedCellList.begin())
            {
               printf("Iterative::Exiting %s\n", __func__);
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