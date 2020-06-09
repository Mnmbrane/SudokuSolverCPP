#include "SudokuCommonTypesTest.h"
#include "gtest/gtest.h"
#include "SudokuCommonTypes.h"

using namespace Sudoku;

TEST_F(SudokuCommonTypesTest, ValTypeOverloadOp)
{
   ValType val = VAL_UNMARKED;
   for(int i = 0; i < 100; ++i)
   {
      ASSERT_EQ((i+1) % (VAL_MAX+1), ++val);
   }

   val = VAL_UNMARKED;
   for(int i = 0; i < 100; ++i)
   {
      ASSERT_EQ(i % (VAL_MAX+1), val++);
   }
   // TODO
   // val = VAL_UNMARKED;
   // for(int i = 100; i >= 0; --i)
   // {
   //    printf("[%d] [%d]", (i-1) % (VAL_MAX+1), val - 1);
   //    ASSERT_EQ((i-1) % (VAL_MAX+1), --val);
   // }

   // val = VAL_UNMARKED;
   // for(int i = 100; i >= 0; --i)
   // {
   //    ASSERT_EQ(i % (VAL_MAX+1), val--);
   // }
}