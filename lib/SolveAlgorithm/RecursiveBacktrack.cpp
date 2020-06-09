#include "RecursiveBacktrack.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuCoord.h"
#include <vector>

using namespace Sudoku;

// Solve using recursive backtracking
bool RecursiveBacktrack::Solve(Sudoku::SudokuPuzzle& puzzle)
{
   std::vector<SudokuCoord> unmarkedCoordList = puzzle.getUnmarkedCoords();
   size_t unmarkedCoordListSize = unmarkedCoordList.size();

   // Iterate through the unmarked coordinates
   for(unsigned int i = 0; i < unmarkedCoordListSize; i++)
   {
      // brute force all of the values in the puzzle
      for(ValType val = VAL_1; val <= VAL_9; val++)
      {
         uint8_t puzzleVal = puzzle.getValAt(row, col);
         // Make sure there is nothing on the current coord
         if(puzzleVal == 0)
         {
            if(puzzle.setValAt(row, col, val) == true)
            {
               // TODO: create a coord manager
               // Wrap around
               if(col == 9)
               {
                  row++;
                  col = 0;
               }
               else
               {
                  // row stays the same
                  col++;
               }
            }
            else if(puzzleVal == 9)
            {
               // got back
            }
            
         }
         // Go forward
         else
         {
            // TODO: create a coord manager
            // Wrap around
            if(col == 9)
            {
               row++;
               col = 0;
            }
            else
            {
               // row stays the same
               col++;
            }
         }
         
      }
   }
}