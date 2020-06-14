#pragma once

#include "SudokuCommonTypes.h"

class Sudoku::AlgorithmInterface
{
public:
   virtual bool Solve(Sudoku::Puzzle& puzzle, CandidateSetMapType& unmarkedCoordList) = 0;
};