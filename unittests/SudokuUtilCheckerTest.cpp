#include "SudokuUtilChecker.h"
#include "SudokuUtilCheckerTest.h"


TEST_F(SudokuUtilCheckerTest, ColInRange)
{
   ASSERT_EQ(true, checkCol(m_puzzle, 47, 8));
   ASSERT_EQ(true, checkCol(m_puzzle, 8, 3));
   ASSERT_EQ(true, checkCol(m_puzzle, 80, 3));
}

TEST_F(SudokuUtilCheckerTest, OutOfRange) 
{
   // Index out of range
   ASSERT_EQ(false, checkCol(m_puzzle, -10, 2));
   ASSERT_EQ(false, checkCol(m_puzzle, 81, 0));

   // Val out of range
   ASSERT_EQ(false, checkCol(m_puzzle, 47, -20));
   ASSERT_EQ(false, checkCol(m_puzzle, 59, 10));
   ASSERT_EQ(false, checkCol(m_puzzle, 0, 0));

   // Val already in column
   ASSERT_EQ(false, checkCol(m_puzzle, 0, 2));
   ASSERT_EQ(false, checkCol(m_puzzle, 16, 1));
   ASSERT_EQ(false, checkCol(m_puzzle, 77, 9));

}

TEST_F(SudokuUtilCheckerTest, InRange)
{
   ASSERT_EQ(true, checkRow(m_puzzle, 47, 8));
   ASSERT_EQ(true, checkRow(m_puzzle, 8, 3));
   ASSERT_EQ(true, checkRow(m_puzzle, 80, 3));
}

TEST_F(SudokuUtilCheckerTest, OutOfRange) 
{
   // Index out of range
   ASSERT_EQ(false, checkRow(m_puzzle, -10, 2));
   ASSERT_EQ(false, checkRow(m_puzzle, 81, 0));

   // Val out of range
   ASSERT_EQ(false, checkRow(m_puzzle, 47, -20));
   ASSERT_EQ(false, checkRow(m_puzzle, 59, 10));
   ASSERT_EQ(false, checkRow(m_puzzle, 0, 0));

   // Val already in Row
   ASSERT_EQ(false, checkRow(m_puzzle, 0, 9));
   ASSERT_EQ(false, checkRow(m_puzzle, 16, 2));
   ASSERT_EQ(false, checkRow(m_puzzle, 67, 5));

}

TEST_F(SudokuUtilCheckerTest, InRange)
{
   ASSERT_EQ(true, checkGroup(m_puzzle, 0, 1));
   ASSERT_EQ(true, checkGroup(m_puzzle, 32, 9));
   ASSERT_EQ(true, checkGroup(m_puzzle, 80, 9));
}

TEST_F(SudokuUtilCheckerTest, OutOfRange) 
{
   // Index out of range
   ASSERT_EQ(false, checkGroup(m_puzzle, -10, 2));
   ASSERT_EQ(false, checkGroup(m_puzzle, 81, 0));

   // Val out of range
   ASSERT_EQ(false, checkGroup(m_puzzle, 47, -20));
   ASSERT_EQ(false, checkGroup(m_puzzle, 59, 10));
   ASSERT_EQ(false, checkGroup(m_puzzle, 0, 0));

   // Val already in Group
   ASSERT_EQ(false, checkGroup(m_puzzle, 0, 5));
   ASSERT_EQ(false, checkGroup(m_puzzle, 44, 6));
   ASSERT_EQ(false, checkGroup(m_puzzle, 59, 2));

}

TEST_F(SudokuUtilCheckerTest, InRange)
{
   ASSERT_EQ(true, checkAll(m_puzzle, 49, 1));
   ASSERT_EQ(true, checkAll(m_puzzle, 32, 3));
   ASSERT_EQ(true, checkAll(m_puzzle, 80, 3));
}

TEST_F(SudokuUtilCheckerTest, OutOfRange) 
{
   // Index out of range
   ASSERT_EQ(false, checkAll(m_puzzle, -10, 2));
   ASSERT_EQ(false, checkAll(m_puzzle, 81, 0));

   // Val out of range
   ASSERT_EQ(false, checkAll(m_puzzle, 47, -20));
   ASSERT_EQ(false, checkAll(m_puzzle, 59, 10));
   ASSERT_EQ(false, checkAll(m_puzzle, 0, 0));

   // Val already in column
   ASSERT_EQ(false, checkAll(m_puzzle, 0, 2));
   ASSERT_EQ(false, checkAll(m_puzzle, 16, 1));
   ASSERT_EQ(false, checkAll(m_puzzle, 77, 9));

   // Val already in Row
   ASSERT_EQ(false, checkAll(m_puzzle, 0, 9));
   ASSERT_EQ(false, checkAll(m_puzzle, 16, 2));
   ASSERT_EQ(false, checkAll(m_puzzle, 67, 5));

   // Val already in Group
   ASSERT_EQ(false, checkAll(m_puzzle, 0, 5));
   ASSERT_EQ(false, checkAll(m_puzzle, 44, 6));
   ASSERT_EQ(false, checkAll(m_puzzle, 59, 2));

}