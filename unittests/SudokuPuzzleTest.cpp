#include "SudokuPuzzle.h"
#include "SudokuPuzzleTest.h"
#include "SudokuCoord.h"
#include "PuzzleList.h"
#include "gtest/gtest.h"

#include <vector>

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

TEST_F(SudokuPuzzleTest, RegularUnsolvedPuzzleTest)
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

   // 0, 0, 0,  0, 0, 9,  0, 0, 0,
   // 2, 8, 0,  3, 0, 0,  1, 0, 5,
   // 3, 0, 5,  0, 8, 0,  7, 4, 6,

   // 7, 0, 0,  0, 0, 0,  0, 6, 0,
   // 0, 3, 0,  4, 2, 7,  0, 8, 0,
   // 0, 2, 0,  0, 0, 0,  0, 0, 7,

   // 8, 1, 3,  0, 5, 0,  6, 0, 2,
   // 5, 0, 9,  0, 0, 2,  0, 1, 8,
   // 0, 0, 0,  8, 0, 0,  0, 0, 0

TEST_F(SudokuPuzzleTest, UnmarkedPositionTest)
{
   // Arrange
   SudokuPuzzle sudokuPuzzle;
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   PuzzlePtrType solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   std::vector<Sudoku::SudokuCoord> unmarkedUnsolved;
   std::vector<Sudoku::SudokuCoord> unmarkedSolved;

   for(SudokuIndex i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      if(unsolvedPuzzle[i] == 0)
      {
         unmarkedUnsolved.push_back(i);
      }

      if(solvedPuzzle[i] == 0)
      {
         unmarkedSolved.push_back(i);
      }
   }

   // Act / Assert
   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(unsolvedPuzzle));

   std::vector<Sudoku::SudokuCoord> unsolvedPuzzleUnmarked = sudokuPuzzle.getUnmarkedCoords();
   // Assert
   for(unsigned int i = 0; i < unsolvedPuzzleUnmarked.size(); i++)
   {
      ASSERT_EQ(unmarkedUnsolved[i], unsolvedPuzzleUnmarked[i]);
   }


   sudokuPuzzle.~SudokuPuzzle();

   std::vector<Sudoku::SudokuCoord> solvedPuzzleUnmarked = sudokuPuzzle.getUnmarkedCoords();
   ASSERT_EQ((unsigned int)0, unmarkedSolved.size());
}