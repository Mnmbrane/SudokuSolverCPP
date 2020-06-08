#include "SudokuPuzzle.h"
#include "SudokuPuzzleTest.h"
#include "SudokuCoord.h"
#include "PuzzleList.h"
#include "gtest/gtest.h"

using namespace Sudoku;

TEST_F(SudokuPuzzleTest, GetExactValTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;

   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);

   // Act
   sudokuPuzzle.initPuzzle(unsolvedPuzzle);

   for(SudokuIndex i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      SudokuCoord coord(i);
      // Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(coord), unsolvedPuzzle[i]);
   }
}

TEST_F(SudokuPuzzleTest, SetAllValidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType solvedPuzzle = getPuzzle(PUZZLE_SOLVED);
   for(SudokuIndex i = 0; i < PUZZLE_MAX_INDEX; i++)
   {
      SudokuCoord coord(i);
      // Set all to 10
      // Act/Assert
      ASSERT_EQ(true, sudokuPuzzle.setValAt(coord, solvedPuzzle[i]));
   }
}

TEST_F(SudokuPuzzleTest, SetInvalidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType invalidPuzzle = getPuzzle(PUZZLE_INVALID);
   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      SudokuCoord coord(i);
      // Set all to 10
      // Act/Assert
      ASSERT_EQ(false, sudokuPuzzle.setValAt(coord, invalidPuzzle[i]));
   }
}

TEST_F(SudokuPuzzleTest, SetEntirePuzzleValidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   // Act/Assert
   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(solvedPuzzle));

   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      SudokuCoord coord(i);
      // Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(coord), solvedPuzzle[i]);
   }

}

TEST_F(SudokuPuzzleTest, SetEntirePuzzleInvalidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType invalidAtIndex80Puzzle = getPuzzle(PUZZLE_INVALID_AT_INDEX_80);

   // Act/Assert
   ASSERT_EQ(false, sudokuPuzzle.initPuzzle(invalidAtIndex80Puzzle));

   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      SudokuCoord coord(i);
      // Assert
      // Should had been reset, all elements are 0
      ASSERT_EQ(sudokuPuzzle.getValAt(coord), 0);
   }

}

TEST_F(SudokuPuzzleTest, ResetTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   // Act/Assert
   sudokuPuzzle.initPuzzle(solvedPuzzle);

   sudokuPuzzle.resetPuzzle();
   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      SudokuCoord coord(i);
      // Assert
      // Should had been reset, all elements are 0
      ASSERT_EQ(sudokuPuzzle.getValAt(coord), 0);
   }

}