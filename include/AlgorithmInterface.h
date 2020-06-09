#pragma once

#include "SudokuCommonTypes.h"

class Sudoku::AlgorithmInterface
{
protected:
   virtual bool Solve(Sudoku::Puzzle& puzzle) = 0;
};