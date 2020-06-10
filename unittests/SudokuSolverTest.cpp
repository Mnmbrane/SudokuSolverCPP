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
   ASSERT_EQ(true, unsolvedPuzzle.initPuzzle(getPuzzle(PUZZLE_UNSOLVED)));
   ASSERT_EQ(true, solvedPuzzle.initPuzzle(getPuzzle(PUZZLE_SOLVED)));
 
   Sudoku::Solver solver;
   ASSERT_EQ(true, solver.Solve(unsolvedPuzzle));

   ASSERT_EQ(true, unsolvedPuzzle==solvedPuzzle);
}

TEST_F(SudokuSolverTest, SolverIterativeUnsolvableTest)
{
   // Arrange
   Puzzle unsolvablePuzzle, solvedPuzzle;
   ASSERT_EQ(true, unsolvablePuzzle.initPuzzle(getPuzzle(PUZZLE_UNSOLVABLE)));
   ASSERT_EQ(true, solvedPuzzle.initPuzzle(getPuzzle(PUZZLE_SOLVED)));
 
   Sudoku::Solver solver;
   ASSERT_EQ(false, solver.Solve(unsolvablePuzzle));

   ASSERT_EQ(false, unsolvablePuzzle==solvedPuzzle);
}

TEST_F(SudokuSolverTest, SolverIterativeAllZeroesTest)
{
   // Arrange
   Puzzle allZeroesPuzzle, solvedPuzzle;
   ASSERT_EQ(true, allZeroesPuzzle.initPuzzle(getPuzzle(PUZZLE_ALL_ZEROES)));
   ASSERT_EQ(true, solvedPuzzle.initPuzzle(getPuzzle(PUZZLE_ALL_ZEROES_SOLVED)));
   Sudoku::Solver solver;
   ASSERT_EQ(true, solver.Solve(allZeroesPuzzle));
   ASSERT_EQ(true, allZeroesPuzzle==solvedPuzzle);
}