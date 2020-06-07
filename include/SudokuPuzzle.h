#pragma once

#include "common.h"
#include <stdint.h>

class SudokuPuzzle
{
public:
   SudokuPuzzle();

   // getters
   uint8_t getValAt(uint8_t row, uint8_t col);

   // setters
   bool setValAt(uint8_t row, uint8_t col, uint8_t val);

private:

   // The puzzle in array format
   uint8_t m_puzzle[MAX_INDEX];

};