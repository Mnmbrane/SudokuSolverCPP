#include "SudokuSolver.h"
#include "SudokuCommonTypes.h"
#include "IterativeBacktrack.h"

using namespace Sudoku;

bool Solver::Solve(Sudoku::Puzzle& puzzle)
{
   Iterative algo;
   return algo.Solve(puzzle);
}