#include "SudokuSolver.h"
#include "SudokuCommonTypes.h"

using namespace Sudoku;

void Solver::Solve(Sudoku::Puzzle& puzzle)
{
   RecursiveBacktrack algo;
   algo.Solve(puzzle);
}