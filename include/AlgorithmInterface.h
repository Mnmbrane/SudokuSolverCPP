#pragma once

#include "SudokuCommonTypes.h"
// Forward Declare
class SudokuPuzzle;

class AlgorithmInterface
{
protected:
   virtual bool Solve(Sudoku::SudokuPuzzle& puzzle) = 0;
};