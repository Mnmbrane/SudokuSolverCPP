#include "SudokuPuzzle.h"
#include "SudokuPuzzleTest.h"
#include "gtest/gtest.h"


TEST_F(SudokuPuzzleTest, ExactValTest)
{
   // Arrange
   const uint8_t puzzle1[] =
   {
      0, 0, 0,  0, 0, 9,  0, 0, 0,
      2, 8, 0,  3, 0, 0,  1, 0, 5,
      3, 0, 5,  0, 8, 0,  7, 4, 6,

      7, 0, 0,  0, 0, 0,  0, 6, 0,
      0, 3, 0,  4, 2, 7,  0, 8, 0,
      0, 2, 0,  0, 0, 0,  0, 0, 7,

      8, 1, 3,  0, 5, 0,  6, 0, 2,
      5, 0, 9,  0, 0, 2,  0, 1, 8,
      0, 0, 0,  8, 0, 0,  0, 0, 0
   };
   SudokuPuzzle sudokuPuzzle;

   for(uint8_t i = 0; i < sizeof(puzzle1); i++)
   {
      // Act
      ASSERT_EQ(true, sudokuPuzzle.setValAt(i / 9, i % 9, puzzle1[i]));

      // Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(i / 9, i % 9), puzzle1[i]);
   }
}

TEST_F(SudokuPuzzleTest, OutOfRangeTest)
{
   SudokuPuzzle sudokuPuzzle;
   for(uint8_t i = 0; i < MAX_ELEMENTS; i++)
   {
      // Set all to 10
      sudokuPuzzle.setValAt(i / 9, i % 9, 10);
   }
   // Arrange

   // Act
   for(uint8_t i = 0; i < sizeof(m_puzzle); i++)
   {
      printf("%u\n", m_puzzle[i]);
      // Assert
      ASSERT_NE(sudokuPuzzle.getValAt(i / 9, i % 9), m_puzzle[i]);
   }
}