#include "SudokuPuzzle.h"
#include "SudokuUtilChecker.h"
#include "string.h"
#include "stdio.h"

SudokuPuzzle::SudokuPuzzle()
{
   resetPuzzle();
}

void SudokuPuzzle::resetPuzzle()
{
   memset(m_puzzle, 0, sizeof(m_puzzle));
}

// getters
uint8_t SudokuPuzzle::getValAt(uint8_t row, uint8_t col)
{
   return m_puzzle[ROW_COL_TO_INDEX(row, col)];
}

// setters
bool SudokuPuzzle::setValAt(uint8_t row, uint8_t col, uint8_t val)
{
   uint8_t index = ROW_COL_TO_INDEX(row, col);
   if(checkAll(m_puzzle, index, val) == false)
   {
      m_puzzle[index] = 0;
      return false;
   }
   else
   {
       m_puzzle[index] = val;
       return true;
   }
}

bool SudokuPuzzle::setPuzzle(uint8_t* inPuzzle)
{
   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      if(setValAt(INDEX_TO_ROW(i), INDEX_TO_COL(i), inPuzzle[i]) == false)
      {
         resetPuzzle();
         return false;
      }
   }

   return true;
}