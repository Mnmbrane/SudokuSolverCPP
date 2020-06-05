#pragma once

#include "common.h"
#include <stdint.h>

class SudokuPuzzle
{
public:
   SudokuPuzzle(const uint8_t* puzzle);

   // getters
   uint8_t getValAt(uint8_t row, uint8_t col);

   // setters
   void setValAt(uint8_t row, uint8_t col, uint8_t val);

private:
   SudokuPuzzle(){};
   SudokuPuzzle(const SudokuPuzzle&);                 // Prevent copy-construction
   SudokuPuzzle& operator=(const SudokuPuzzle&);      // Prevent assignment

   // The puzzle in array format
   uint8_t m_puzzle[MAX_INDEX];

};