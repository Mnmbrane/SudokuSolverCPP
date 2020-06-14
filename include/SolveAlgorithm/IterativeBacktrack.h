#pragma once
#include "AlgorithmInterface.h"
#include "SudokuCommonTypes.h"

class Sudoku::IterativeBacktrack : public virtual Sudoku::AlgorithmInterface
{
public:
   IterativeBacktrack(){};
   virtual bool Solve(Sudoku::Puzzle& puzzle, CandidateSetMapType& unmarkedCoordList);

private:

};