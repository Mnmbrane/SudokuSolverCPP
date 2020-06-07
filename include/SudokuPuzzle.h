#pragma once

#include "common.h"
#include <stdint.h>

class SudokuPuzzle
{
public:
   SudokuPuzzle();

   void resetPuzzle();

   // getters
   uint8_t getValAt(uint8_t row, uint8_t col);

   // setters
   bool setValAt(uint8_t row, uint8_t col, uint8_t val);

   bool setPuzzle(uint8_t* inPuzzle);

private:

   // The puzzle in array format
   uint8_t m_puzzle[PUZZLE_MAX_ELEMENTS];

};