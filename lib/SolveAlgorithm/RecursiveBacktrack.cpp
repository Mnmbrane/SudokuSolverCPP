#include "RecursiveBacktrack.h"
#include "SudokuPuzzle.h"

using namespace Sudoku;

// Solve using recursive backtracking
bool RecursiveBacktrack::Solve(Sudoku::SudokuPuzzle& puzzle)
{
   uint8_t row = 0, col = 0;

   // Iterate through the entire puzzle
   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i=(row + col))
   {
      // brute force all of the values in the puzzle
      for(uint8_t val = 1; val <= 9; val++)
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