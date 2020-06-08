#include "SudokuUtilChecker.h"
#include "SudokuUtilCheckerTest.h"
#include "gtest/gtest.h"

using namespace Sudoku;


TEST_F(SudokuUtilCheckerTest, ColumnInRangeTest)
{
   ASSERT_EQ(true, checkCol(m_puzzle, 47, (ValType)8));
   ASSERT_EQ(true, checkCol(m_puzzle, 8, (ValType)3));
   ASSERT_EQ(true, checkCol(m_puzzle, 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, ColumnOutOfRangeTest) 
{
   // Index out of range
   ASSERT_EQ(false, checkCol(m_puzzle, -10, (ValType)2));
   ASSERT_EQ(false, checkCol(m_puzzle, 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkCol(m_puzzle, 47, (ValType)-20));
   ASSERT_EQ(false, checkCol(m_puzzle, 59, (ValType)10));
   ASSERT_EQ(false, checkCol(m_puzzle, 0, (ValType)0));

   // Val already in column
   ASSERT_EQ(false, checkCol(m_puzzle, 0, (ValType)2));
   ASSERT_EQ(false, checkCol(m_puzzle, 16, (ValType)1));
   ASSERT_EQ(false, checkCol(m_puzzle, 77, (ValType)9));

}

TEST_F(SudokuUtilCheckerTest, RowInRangeTest)
{
   ASSERT_EQ(true, checkRow(m_puzzle, 47, (ValType)8));
   ASSERT_EQ(true, checkRow(m_puzzle, 8, (ValType)3));
   ASSERT_EQ(true, checkRow(m_puzzle, 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, RowOutOfRangeTest) 
{
   // Index out of range
   ASSERT_EQ(false, checkRow(m_puzzle, -10, (ValType)2));
   ASSERT_EQ(false, checkRow(m_puzzle, 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkRow(m_puzzle, 47, (ValType)-20));
   ASSERT_EQ(false, checkRow(m_puzzle, 59, (ValType)10));
   ASSERT_EQ(false, checkRow(m_puzzle, 0, (ValType)0));

   // Val already in Row
   ASSERT_EQ(false, checkRow(m_puzzle, 0, (ValType)9));
   ASSERT_EQ(false, checkRow(m_puzzle, 16, (ValType)2));
   ASSERT_EQ(false, checkRow(m_puzzle, 67, (ValType)5));

}

TEST_F(SudokuUtilCheckerTest, GroupInRangeTest)
{
   ASSERT_EQ(true, checkGroup(m_puzzle, 0, (ValType)1));
   ASSERT_EQ(true, checkGroup(m_puzzle, 32, (ValType)9));
   ASSERT_EQ(true, checkGroup(m_puzzle, 80, (ValType)9));
}

TEST_F(SudokuUtilCheckerTest, GroupOutOfRangeTest) 
{
   // Index out of range
   ASSERT_EQ(false, checkGroup(m_puzzle, -10, (ValType)2));
   ASSERT_EQ(false, checkGroup(m_puzzle, 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkGroup(m_puzzle, 47, (ValType)-20));
   ASSERT_EQ(false, checkGroup(m_puzzle, 59, (ValType)-10));
   ASSERT_EQ(false, checkGroup(m_puzzle, 0, (ValType)0));

   // Val already in Group
   ASSERT_EQ(false, checkGroup(m_puzzle, 0, (ValType)5));
   ASSERT_EQ(false, checkGroup(m_puzzle, 44, (ValType)6));
   ASSERT_EQ(false, checkGroup(m_puzzle, 59, (ValType)2));

}

TEST_F(SudokuUtilCheckerTest, AllInRangeTest)
{
   ASSERT_EQ(true, checkAll(m_puzzle, 49, (ValType)1));
   ASSERT_EQ(true, checkAll(m_puzzle, 32, (ValType)3));
   ASSERT_EQ(true, checkAll(m_puzzle, 80, (ValType)3));
}

TEST_F(SudokuUtilCheckerTest, AllOutOfRangeTest) 
{
   // Index out of range
   ASSERT_EQ(false, checkAll(m_puzzle, -10, (ValType)2));
   ASSERT_EQ(false, checkAll(m_puzzle, 81, (ValType)0));

   // Val out of range
   ASSERT_EQ(false, checkAll(m_puzzle, 47, (ValType)-20));
   ASSERT_EQ(false, checkAll(m_puzzle, 59, (ValType)10));
   ASSERT_EQ(false, checkAll(m_puzzle, 0, (ValType)0));

   // Val already in column
   ASSERT_EQ(false, checkAll(m_puzzle, 0, (ValType)2));
   ASSERT_EQ(false, checkAll(m_puzzle, 16, (ValType)1));
   ASSERT_EQ(false, checkAll(m_puzzle, 77, (ValType)9));

   // Val already in Row
   ASSERT_EQ(false, checkAll(m_puzzle, 0, (ValType)9));
   ASSERT_EQ(false, checkAll(m_puzzle, 16,(ValType) 2));
   ASSERT_EQ(false, checkAll(m_puzzle, 67, (ValType)5));

   // Val already in Group
   ASSERT_EQ(false, checkAll(m_puzzle, 0, (ValType)5));
   ASSERT_EQ(false, checkAll(m_puzzle, 44, (ValType)6));
   ASSERT_EQ(false, checkAll(m_puzzle, 59, (ValType)2));

}

