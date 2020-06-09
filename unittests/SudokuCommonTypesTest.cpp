#include "SudokuCommonTypesTest.h"
#include "gtest/gtest.h"
#include "SudokuCommonTypes.h"

using namespace Sudoku;

TEST_F(SudokuCommonTypesTest, ValTypeOverloadOp)
{
   ValType val = VAL_UNMARKED;
   ASSERT_EQ(val++, VAL_UNMARKED);
   ASSERT_EQ(val++, VAL_1);
   ASSERT_EQ(val++, VAL_2);
   ASSERT_EQ(val++, VAL_3);
   ASSERT_EQ(val++, VAL_4);
   ASSERT_EQ(val++, VAL_5);
   ASSERT_EQ(val++, VAL_6);
   ASSERT_EQ(val++, VAL_7);
   ASSERT_EQ(val++, VAL_8);
   ASSERT_EQ(val++, VAL_9);
   ASSERT_EQ(val, VAL_UNMARKED);

   ASSERT_EQ(++val, VAL_1);
   ASSERT_EQ(++val, VAL_2);
   ASSERT_EQ(++val, VAL_3);
   ASSERT_EQ(++val, VAL_4);
   ASSERT_EQ(++val, VAL_5);
   ASSERT_EQ(++val, VAL_6);
   ASSERT_EQ(++val, VAL_7);
   ASSERT_EQ(++val, VAL_8);
   ASSERT_EQ(++val, VAL_9);
   ASSERT_EQ(++val, VAL_UNMARKED);

   ASSERT_EQ(val--, VAL_UNMARKED);
   ASSERT_EQ(val--, VAL_9);
   ASSERT_EQ(val--, VAL_8);
   ASSERT_EQ(val--, VAL_7);
   ASSERT_EQ(val--, VAL_6);
   ASSERT_EQ(val--, VAL_5);
   ASSERT_EQ(val--, VAL_4);
   ASSERT_EQ(val--, VAL_3);
   ASSERT_EQ(val--, VAL_2);
   ASSERT_EQ(val--, VAL_1);
   ASSERT_EQ(val, VAL_UNMARKED);

   ASSERT_EQ(--val, VAL_9);
   ASSERT_EQ(--val, VAL_8);
   ASSERT_EQ(--val, VAL_7);
   ASSERT_EQ(--val, VAL_6);
   ASSERT_EQ(--val, VAL_5);
   ASSERT_EQ(--val, VAL_4);
   ASSERT_EQ(--val, VAL_3);
   ASSERT_EQ(--val, VAL_2);
   ASSERT_EQ(--val, VAL_1);
   ASSERT_EQ(--val, VAL_UNMARKED);
}