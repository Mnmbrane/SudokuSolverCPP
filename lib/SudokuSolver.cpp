#include "SudokuSolver.h"
#include "SudokuCommonTypes.h"
#include "Iterative.h"

using namespace Sudoku;

void Solver::Solve(Sudoku::Puzzle& puzzle)
{
   Iterative algo;
   algo.Solve(puzzle);
}