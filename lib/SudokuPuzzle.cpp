#include "SudokuPuzzle.h"
#include "SudokuUtilChecker.h"
#include "string.h"

SudokuPuzzle::SudokuPuzzle()
{
   memset(m_puzzle, 0, sizeof(m_puzzle));
}

// getters
uint8_t SudokuPuzzle::getValAt(uint8_t row, uint8_t col)
{
   return m_puzzle[(row * 9) + col];
}

// setters
bool SudokuPuzzle::setValAt(uint8_t row, uint8_t col, uint8_t val)
{
   uint8_t index = (row * 9) + col;

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