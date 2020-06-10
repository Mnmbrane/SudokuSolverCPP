#include "SudokuSolverTest.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuSolver.h"
#include "PuzzleList.h"

using namespace Sudoku;

TEST_F(SudokuSolverTest, SolverIterativeSolveTest)
{
   // Arrange
   Puzzle unsolvedPuzzle, solvedPuzzle;
   unsolvedPuzzle.initPuzzle(getPuzzle(PUZZLE_UNSOLVED));
   solvedPuzzle.initPuzzle(getPuzzle(PUZZLE_SOLVED));
 
   Sudoku::Solver solver;
   solver.Solve(unsolvedPuzzle);

   ASSERT_EQ(true, unsolvedPuzzle==solvedPuzzle);
}