#include "SudokuUtilChecker.h"
#include "SudokuUtilCheckerTest.h"
#include "PuzzleList.h"
#include "gtest/gtest.h"

using namespace Sudoku;


TEST_F(SudokuUtilCheckerTest, ColumnInRangeTest)
{
   ASSERT_EQ(true, checkCol(getPuzzle(PUZZLE_UNSOLVED), 47, (ValType)8));
   ASSERT_EQ(true, checkCol(getPuzzle(PUZZLE_UNSOLVED), 8, (ValType)3));
   ASSERT_EQ(true, checkCol(getPuzzle(PUZZLE_UNSOLVED), 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, ColumnOutOfRangeTest) 
{
   // Index out of range
   ASSERT_EQ(false, checkCol(getPuzzle(PUZZLE_UNSOLVED), -10, (ValType)2));
   ASSERT_EQ(false, checkCol(getPuzzle(PUZZLE_UNSOLVED), 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkCol(getPuzzle(PUZZLE_UNSOLVED), 47, (ValType)-20));
   ASSERT_EQ(false, checkCol(getPuzzle(PUZZLE_UNSOLVED), 59, (ValType)10));
   ASSERT_EQ(false, checkCol(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)0));

   // Val already in column
   ASSERT_EQ(false, checkCol(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)2));
   ASSERT_EQ(false, checkCol(getPuzzle(PUZZLE_UNSOLVED), 16, (ValType)1));
   ASSERT_EQ(false, checkCol(getPuzzle(PUZZLE_UNSOLVED), 77, (ValType)9));

}

TEST_F(SudokuUtilCheckerTest, RowInRangeTest)
{
   ASSERT_EQ(true, checkRow(getPuzzle(PUZZLE_UNSOLVED), 47, (ValType)8));
   ASSERT_EQ(true, checkRow(getPuzzle(PUZZLE_UNSOLVED), 8, (ValType)3));
   ASSERT_EQ(true, checkRow(getPuzzle(PUZZLE_UNSOLVED), 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, RowOutOfRangeTest) 
{
   // Index out of range
   ASSERT_EQ(false, checkRow(getPuzzle(PUZZLE_UNSOLVED), -10, (ValType)2));
   ASSERT_EQ(false, checkRow(getPuzzle(PUZZLE_UNSOLVED), 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkRow(getPuzzle(PUZZLE_UNSOLVED), 47, (ValType)-20));
   ASSERT_EQ(false, checkRow(getPuzzle(PUZZLE_UNSOLVED), 59, (ValType)10));
   ASSERT_EQ(false, checkRow(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)0));

   // Val already in Row
   ASSERT_EQ(false, checkRow(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)9));
   ASSERT_EQ(false, checkRow(getPuzzle(PUZZLE_UNSOLVED), 16, (ValType)2));
   ASSERT_EQ(false, checkRow(getPuzzle(PUZZLE_UNSOLVED), 67, (ValType)5));

}

TEST_F(SudokuUtilCheckerTest, GroupInRangeTest)
{
   ASSERT_EQ(true, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)1));
   ASSERT_EQ(true, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 32, (ValType)9));
   ASSERT_EQ(true, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 80, (ValType)9));
}

TEST_F(SudokuUtilCheckerTest, GroupOutOfRangeTest) 
{
   // Index out of range
   ASSERT_EQ(false, checkGroup(getPuzzle(PUZZLE_UNSOLVED), -10, (ValType)2));
   ASSERT_EQ(false, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 47, (ValType)-20));
   ASSERT_EQ(false, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 59, (ValType)-10));
   ASSERT_EQ(false, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)0));

   // Val already in Group
   ASSERT_EQ(false, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)5));
   ASSERT_EQ(false, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 44, (ValType)6));
   ASSERT_EQ(false, checkGroup(getPuzzle(PUZZLE_UNSOLVED), 59, (ValType)2));

}

TEST_F(SudokuUtilCheckerTest, AllInRangeTest)
{
   ASSERT_EQ(true, checkAll(getPuzzle(PUZZLE_UNSOLVED), 49, (ValType)1));
   ASSERT_EQ(true, checkAll(getPuzzle(PUZZLE_UNSOLVED), 32, (ValType)3));
   ASSERT_EQ(true, checkAll(getPuzzle(PUZZLE_UNSOLVED), 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, AllOutOfRangeTest) 
{
   // Index out of range
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), -10, (ValType)2));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 47, (ValType)-20));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 59, (ValType)10));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)0));

   // Val already in column
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)2));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 16, (ValType)1));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 77, (ValType)9));

   // Val already in Row
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)9));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 16, (ValType)2));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 67, (ValType)5));

   // Val already in Group
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 0, (ValType)5));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 44, (ValType)6));
   ASSERT_EQ(false, checkAll(getPuzzle(PUZZLE_UNSOLVED), 59, (ValType)2));
}

