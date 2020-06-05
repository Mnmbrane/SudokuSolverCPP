#include "SudokuPuzzle.h"


SudokuPuzzle::SudokuPuzzle(const uint8_t* puzzle)
{
   // Copy everything over to member variable puzzle
   for(uint8_t i = 0; i < MAX_INDEX; i++)
   {
      m_puzzle[i] = puzzle[i];
   }
}

// getters
uint8_t SudokuPuzzle::getValAt(uint8_t row, uint8_t col)
{
   return m_puzzle[(row * 9) + col];
}

// setters
void SudokuPuzzle::setValAt(uint8_t row, uint8_t col, uint8_t val)
{
   m_puzzle[(row * 9) + col] = val;
}