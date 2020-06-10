#include "SudokuSolver.h"
#include "SudokuCommonTypes.h"
#include "IterativeBacktrack.h"

using namespace Sudoku;

Solver::Solver()
{
   constructAlgoPipeline();
}

void Solver::constructAlgoPipeline()
{

}

bool Solver::Solve(Sudoku::Puzzle& puzzle)
{
   Iterative algo;
   return algo.Solve(puzzle);
}