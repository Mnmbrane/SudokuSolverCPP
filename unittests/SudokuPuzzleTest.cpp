#include "SudokuPuzzle.h"
#include "SudokuPuzzleTest.h"
#include "SudokuCoord.h"
#include "PuzzleList.h"
#include "gtest/gtest.h"

using namespace Sudoku;


TEST_F(SudokuPuzzleTest, SetAllValidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(solvedPuzzle));

   for(SudokuIndex i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      // Act/Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(i), solvedPuzzle[i]);
   }
}

TEST_F(SudokuPuzzleTest, GetExactValTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;

   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);

   // Act/ Assert
   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(unsolvedPuzzle));

   for(SudokuIndex i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      // Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(i), unsolvedPuzzle[i]);
   }
}

TEST_F(SudokuPuzzleTest, SetInvalidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType invalidPuzzle = getPuzzle(PUZZLE_INVALID);

   ASSERT_EQ(false, sudokuPuzzle.initPuzzle(invalidPuzzle));

   for(SudokuIndex i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Set all to 10
      // Act/Assert
      ASSERT_EQ(false, sudokuPuzzle.setValAt(i, invalidPuzzle[i]));
   }
}

TEST_F(SudokuPuzzleTest, LastIndexInvalidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType lastIndexInvalidPuzzle = getPuzzle(PUZZLE_INVALID_AT_INDEX_80);

   // Act/Assert
   ASSERT_EQ(false, sudokuPuzzle.initPuzzle(lastIndexInvalidPuzzle));

   for(SudokuIndex i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Assert
      // Should had been reset, all elements are 0
      ASSERT_EQ(sudokuPuzzle.getValAt(i), 0);
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
   for(SudokuIndex i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Assert
      // Should had been reset, all elements are 0
      ASSERT_EQ(sudokuPuzzle.getValAt(i), 0);
   }

}

TEST_F(SudokuPuzzleTest, InitTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType solvedPuzzle = getPuzzle(PUZZLE_SOLVED);
   PuzzlePtrType invalidPuzzle = getPuzzle(PUZZLE_INVALID);

   // Act/Assert
   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(solvedPuzzle));
   ASSERT_EQ(true, sudokuPuzzle.isPuzzleInit());

   ASSERT_EQ(false, sudokuPuzzle.initPuzzle(invalidPuzzle));
   ASSERT_EQ(true, sudokuPuzzle.isPuzzleInit());

   for(SudokuIndex i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Should still be using solvedPuzzle index, because
      // of the invalid init
      ASSERT_EQ(sudokuPuzzle.getValAt(i), solvedPuzzle[i]);
   }

   // Destroy
   sudokuPuzzle.~SudokuPuzzle();
   ASSERT_EQ(false, sudokuPuzzle.isPuzzleInit());

   for(SudokuIndex i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Should still be using solvedPuzzle index, because
      // of the invalid init
      ASSERT_EQ(sudokuPuzzle.getValAt(i), 0);
   }

   ASSERT_EQ(false, sudokuPuzzle.initPuzzle(invalidPuzzle));
   ASSERT_EQ(false, sudokuPuzzle.isPuzzleInit());
}