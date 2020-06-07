#include "SudokuPuzzle.h"
#include "SudokuPuzzleTest.h"
#include "PuzzleList.h"
#include "gtest/gtest.h"


TEST_F(SudokuPuzzleTest, GetExactValTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;

   uint8_t* unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);

   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Act/Assert
      sudokuPuzzle.setValAt(INDEX_TO_ROW(i), INDEX_TO_COL(i), unsolvedPuzzle[i]);

      // Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(INDEX_TO_ROW(i), INDEX_TO_COL(i)), unsolvedPuzzle[i]);
   }
}

TEST_F(SudokuPuzzleTest, SetAllValidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   uint8_t* solvedPuzzle = getPuzzle(PUZZLE_SOLVED);
   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Set all to 10
      // Act/Assert
      ASSERT_EQ(true, sudokuPuzzle.setValAt(INDEX_TO_ROW(i), INDEX_TO_COL(i), solvedPuzzle[i]));
   }
}

TEST_F(SudokuPuzzleTest, SetInvalidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   uint8_t* invalidPuzzle = getPuzzle(PUZZLE_INVALID);
   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Set all to 10
      // Act/Assert
      ASSERT_EQ(false, sudokuPuzzle.setValAt(INDEX_TO_ROW(i), INDEX_TO_COL(i), invalidPuzzle[i]));
   }
}

TEST_F(SudokuPuzzleTest, SetEntirePuzzleValidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   uint8_t* solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   // Act/Assert
   ASSERT_EQ(true, sudokuPuzzle.setPuzzle(solvedPuzzle));

   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(INDEX_TO_ROW(i), INDEX_TO_COL(i)), solvedPuzzle[i]);
   }

}

TEST_F(SudokuPuzzleTest, SetEntirePuzzleInvalidTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   uint8_t* invalidAtIndex80Puzzle = getPuzzle(PUZZLE_INVALID_AT_INDEX_80);

   // Act/Assert
   ASSERT_EQ(false, sudokuPuzzle.setPuzzle(invalidAtIndex80Puzzle));

   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Assert
      // Should had been reset, all elements are 0
      ASSERT_EQ(sudokuPuzzle.getValAt(INDEX_TO_ROW(i), INDEX_TO_COL(i)), 0);
   }

}

TEST_F(SudokuPuzzleTest, ResetTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   uint8_t* solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   // Act/Assert
   sudokuPuzzle.setPuzzle(solvedPuzzle);

   sudokuPuzzle.resetPuzzle();
   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Assert
      // Should had been reset, all elements are 0
      ASSERT_EQ(sudokuPuzzle.getValAt(INDEX_TO_ROW(i), INDEX_TO_COL(i)), 0);
   }

}