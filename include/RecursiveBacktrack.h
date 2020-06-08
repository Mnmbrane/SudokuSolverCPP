#pragma once
#include "AlgorithmInterface.h"
#include "SudokuCommonTypes.h"

class RecursiveBacktrack : public virtual AlgorithmInterface
{
public:
   virtual bool Solve(Sudoku::SudokuPuzzle& puzzle);

private:

};