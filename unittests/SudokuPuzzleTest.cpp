#include <SudokuCommonTypes.h>
#include "SudokuPuzzle.h"
#include "SudokuPuzzleTest.h"
#include "SudokuCoord.h"
#include "SudokuCell.h"
#include "PuzzleList.h"
#include "gtest/gtest.h"

#include <set>

using namespace Sudoku;

TEST_F(SudokuPuzzleTest, SetAllValidTest)
{
   // Arrange
   Puzzle sudokuPuzzle;
   Cell* solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(solvedPuzzle));

   for(Index  i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      // Act/Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(i), solvedPuzzle[i].getVal());
   }
}

TEST_F(SudokuPuzzleTest, CopyConstructorTest)
{
   // Arrange
   Puzzle sudokuPuzzle;
   Cell* solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(solvedPuzzle));

   Puzzle copyPuzzle = sudokuPuzzle;

   for(Index  i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      // Act/Assert
      ASSERT_EQ(sudokuPuzzle.getValAt(i), copyPuzzle.getValAt(i));
   }
}

TEST_F(SudokuPuzzleTest, SetInvalidTest)
{
   // Arrange
   Puzzle sudokuPuzzle;
   Cell* invalidPuzzle = getPuzzle(PUZZLE_INVALID);

   ASSERT_EQ(false, sudokuPuzzle.initPuzzle(invalidPuzzle));

   for(Index  i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Act/Assert
      ASSERT_NE(invalidPuzzle[i].getVal(), sudokuPuzzle.getValAt(i));
   }
}

TEST_F(SudokuPuzzleTest, RegularUnsolvedPuzzleTest)
{
   // Arrange
   Puzzle sudokuPuzzle;

   Cell* unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);

   // Act/ Assert
   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(unsolvedPuzzle));
}

TEST_F(SudokuPuzzleTest, LastIndexInvalidTest)
{
   // Arrange
   Puzzle sudokuPuzzle;
   Cell* lastIndexInvalidPuzzle = getPuzzle(PUZZLE_INVALID_AT_INDEX_80);

   // Act/Assert
   ASSERT_EQ(false, sudokuPuzzle.initPuzzle(lastIndexInvalidPuzzle));

   for(Index  i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Assert
      // Should had been reset, all elements are 0
      ASSERT_EQ(sudokuPuzzle.getValAt(i), 0);
   }

}

TEST_F(SudokuPuzzleTest, ResetTest)
{
   // Arrange
   Puzzle sudokuPuzzle;
   Cell* solvedPuzzle = getPuzzle(PUZZLE_SOLVED);

   // Act/Assert
   sudokuPuzzle.initPuzzle(solvedPuzzle);

   sudokuPuzzle.resetPuzzle();
   for(Index  i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Assert
      // Should had been reset, all elements are 0
      ASSERT_EQ(sudokuPuzzle.getValAt(i), 0);
   }

}

TEST_F(SudokuPuzzleTest, InitTest)
{
   // Arrange
   Puzzle sudokuPuzzle;
   Cell* solvedPuzzle = getPuzzle(PUZZLE_SOLVED);
   Cell* invalidPuzzle = getPuzzle(PUZZLE_INVALID);

   // Act/Assert
   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(solvedPuzzle));
   ASSERT_EQ(true, sudokuPuzzle.isPuzzleInit());

   ASSERT_EQ(false, sudokuPuzzle.initPuzzle(invalidPuzzle));
   ASSERT_EQ(true, sudokuPuzzle.isPuzzleInit());

   for(Index  i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // Should still be using solvedPuzzle index, because
      // of the invalid init
      ASSERT_EQ(sudokuPuzzle.getValAt(i), solvedPuzzle[i].getVal());
   }

   // Destroy
   sudokuPuzzle.resetPuzzle();
   ASSERT_EQ(false, sudokuPuzzle.isPuzzleInit());

   for(Index  i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
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
   Puzzle sudokuPuzzle;
   Cell* unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);

   std::set<Sudoku::Coord> unmarkedUnsolved;
   for(Index  i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      if(unsolvedPuzzle[i].getVal() == 0)
      {
         unmarkedUnsolved.insert(i);
      }
   }
   // Act / Assert
   ASSERT_EQ(true, sudokuPuzzle.initPuzzle(unsolvedPuzzle));

   // Assert
   for(Index  i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      Coord coord(i);
      ASSERT_EQ(!sudokuPuzzle.isMarkedAt(i),
                unmarkedUnsolved.find(i)!=unmarkedUnsolved.end());
   }
}

TEST_F(SudokuPuzzleTest, OperatorOverloadEqTest)
{
   // Arrange
   Puzzle sudokuPuzzle1, sudokuPuzzle2, sudokuPuzzle3;
   Cell* solvedPuzzle = getPuzzle(PUZZLE_SOLVED);
   Cell* unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);

   sudokuPuzzle1.initPuzzle(solvedPuzzle);
   sudokuPuzzle2.initPuzzle(solvedPuzzle);
   sudokuPuzzle3.initPuzzle(unsolvedPuzzle);

   ASSERT_EQ(true, sudokuPuzzle1==sudokuPuzzle2);
   ASSERT_EQ(false, sudokuPuzzle1==sudokuPuzzle3);
}