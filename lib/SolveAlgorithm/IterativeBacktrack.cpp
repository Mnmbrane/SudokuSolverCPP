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
   std::set<Coord> unmarkedCoordList = puzzle.getUnmarkedCoords();
   std::set<Coord>::iterator it = unmarkedCoordList.begin();

   // Iterate through the unmarked coordinates
   while(it != unmarkedCoordList.end())
   {
   //    printf("i == [%d]\n", i);
      // brute force all of the values in the puzzle
      for(ValType val = ValType((puzzle.getValAt(*it) + 1) % 10); val <= ValType::VAL_9; ++val)
      {

         // Overflowed we need to go back to the previous unmarked in the list
         if(val == ValType::VAL_UNMARKED)
         {
            // Set current to unmarked
            puzzle.setValAt(*it, ValType::VAL_UNMARKED);
            // Go to previous unmarked index

            // Went all the way back to the beginning
            // Return false
            if(it == unmarkedCoordList.begin())
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
            if(puzzle.setValAt(*it, val) == true)
            {
               it++;
               break;
            }
            
         }
      }
   }
   return true;
}