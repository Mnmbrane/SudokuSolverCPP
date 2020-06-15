#pragma once
#include "AlgorithmInterface.h"
#include "SudokuCommonTypes.h"

class Sudoku::HiddenOnes : public virtual Sudoku::AlgorithmInterface
{
public:
   HiddenOnes(){};
   virtual bool Solve(Sudoku::Puzzle& puzzle, CandidateSetMapType& unmarkedCoordList); 

private:
   Coord checkRow(RowType row, ValType val);
   Coord checkCol(ColType col, ValType val);
   Coord checkGroup();
};