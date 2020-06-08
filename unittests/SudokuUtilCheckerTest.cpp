#include "SudokuUtilChecker.h"
#include "SudokuUtilCheckerTest.h"
#include "PuzzleList.h"
#include "gtest/gtest.h"

using namespace Sudoku;


TEST_F(SudokuUtilCheckerTest, ColumnInRangeTest)
{
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   ASSERT_EQ(true, checkCol(unsolvedPuzzle, 47, (ValType)8));
   ASSERT_EQ(true, checkCol(unsolvedPuzzle, 8, (ValType)3));
   ASSERT_EQ(true, checkCol(unsolvedPuzzle, 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, ColumnOutOfRangeTest) 
{
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   // Index out of range
   ASSERT_EQ(false, checkCol(unsolvedPuzzle, -10, (ValType)2));
   ASSERT_EQ(false, checkCol(unsolvedPuzzle, 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkCol(unsolvedPuzzle, 47, (ValType)-20));
   ASSERT_EQ(false, checkCol(unsolvedPuzzle, 59, (ValType)10));
   ASSERT_EQ(false, checkCol(unsolvedPuzzle, 0, (ValType)0));

   // Val already in column
   ASSERT_EQ(false, checkCol(unsolvedPuzzle, 0, (ValType)2));
   ASSERT_EQ(false, checkCol(unsolvedPuzzle, 16, (ValType)1));
   ASSERT_EQ(false, checkCol(unsolvedPuzzle, 77, (ValType)9));

}

TEST_F(SudokuUtilCheckerTest, RowInRangeTest)
{
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   ASSERT_EQ(true, checkRow(unsolvedPuzzle, 47, (ValType)8));
   ASSERT_EQ(true, checkRow(unsolvedPuzzle, 8, (ValType)3));
   ASSERT_EQ(true, checkRow(unsolvedPuzzle, 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, RowOutOfRangeTest) 
{
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   // Index out of range
   ASSERT_EQ(false, checkRow(unsolvedPuzzle, -10, (ValType)2));
   ASSERT_EQ(false, checkRow(unsolvedPuzzle, 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkRow(unsolvedPuzzle, 47, (ValType)-20));
   ASSERT_EQ(false, checkRow(unsolvedPuzzle, 59, (ValType)10));
   ASSERT_EQ(false, checkRow(unsolvedPuzzle, 0, (ValType)0));

   // Val already in Row
   ASSERT_EQ(false, checkRow(unsolvedPuzzle, 0, (ValType)9));
   ASSERT_EQ(false, checkRow(unsolvedPuzzle, 16, (ValType)2));
   ASSERT_EQ(false, checkRow(unsolvedPuzzle, 67, (ValType)5));

}

TEST_F(SudokuUtilCheckerTest, GroupInRangeTest)
{
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   ASSERT_EQ(true, checkGroup(unsolvedPuzzle, 0, (ValType)1));
   ASSERT_EQ(true, checkGroup(unsolvedPuzzle, 32, (ValType)9));
   ASSERT_EQ(true, checkGroup(unsolvedPuzzle, 80, (ValType)9));
}

TEST_F(SudokuUtilCheckerTest, GroupOutOfRangeTest) 
{
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   // Index out of range
   ASSERT_EQ(false, checkGroup(unsolvedPuzzle, -10, (ValType)2));
   ASSERT_EQ(false, checkGroup(unsolvedPuzzle, 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkGroup(unsolvedPuzzle, 47, (ValType)-20));
   ASSERT_EQ(false, checkGroup(unsolvedPuzzle, 59, (ValType)-10));
   ASSERT_EQ(false, checkGroup(unsolvedPuzzle, 0, (ValType)0));

   // Val already in Group
   ASSERT_EQ(false, checkGroup(unsolvedPuzzle, 0, (ValType)5));
   ASSERT_EQ(false, checkGroup(unsolvedPuzzle, 44, (ValType)6));
   ASSERT_EQ(false, checkGroup(unsolvedPuzzle, 59, (ValType)2));

}

TEST_F(SudokuUtilCheckerTest, AllInRangeTest)
{
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   ASSERT_EQ(true, checkAll(unsolvedPuzzle, 49, (ValType)1));
   ASSERT_EQ(true, checkAll(unsolvedPuzzle, 32, (ValType)3));
   ASSERT_EQ(true, checkAll(unsolvedPuzzle, 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, AllOutOfRangeTest) 
{
   PuzzlePtrType unsolvedPuzzle = getPuzzle(PUZZLE_UNSOLVED);
   // Index out of range
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, -10, (ValType)2));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 47, (ValType)-20));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 59, (ValType)10));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 0, (ValType)0));

   // Val already in column
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 0, (ValType)2));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 16, (ValType)1));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 77, (ValType)9));

   // Val already in Row
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 0, (ValType)9));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 16, (ValType)2));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 67, (ValType)5));

   // Val already in Group
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 0, (ValType)5));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 44, (ValType)6));
   ASSERT_EQ(false, checkAll(unsolvedPuzzle, 59, (ValType)2));
}

