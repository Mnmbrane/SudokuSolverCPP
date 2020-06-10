#pragma once
#include "AlgorithmInterface.h"
#include "SudokuCommonTypes.h"

class Sudoku::Iterative : public virtual Sudoku::AlgorithmInterface
{
public:
   virtual bool Solve(Sudoku::Puzzle& puzzle);

private:

};