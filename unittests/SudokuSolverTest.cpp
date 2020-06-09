#include "SudokuSolverTest.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuSolver.h"
#include "PuzzleList.h"

using namespace Sudoku;

TEST_F(SudokuSolverTest, OperatorOverloadEqTest)
{
   // Arrange
   Puzzle sudokuPuzzle1;
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   sudokuPuzzle1.initPuzzle(unsolvedPuzzle);

   Sudoku::Solver solver;
   sudokuPuzzle1.printPuzzle();
   solver.Solve(sudokuPuzzle1);
}