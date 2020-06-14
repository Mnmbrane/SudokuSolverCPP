#pragma once
#include "AlgorithmInterface.h"
#include "SudokuCommonTypes.h"

class Sudoku::NakedOnes : public virtual Sudoku::AlgorithmInterface
{
public:
   NakedOnes(){};
   virtual bool Solve(Sudoku::Puzzle& puzzle, CandidateSetMapType& unmarkedCoordList); 

private:

};