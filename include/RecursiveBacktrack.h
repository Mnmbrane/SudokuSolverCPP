#pragma once
#include "AlgorithmInterface.h"

class RecursiveBacktrack : public virtual AlgorithmInterface
{
public:
   virtual bool Solve(SudokuPuzzle& puzzle);

private:

};