#include "SudokuUtilChecker.h"
#include "googletest/include/gtest/gtest.h"

/* Index
 0,  1,  2,   3,  4,  5,   6,  7,  8,
 9, 10, 11,  12, 13, 14,  15, 16, 17,
18, 19, 20,  21, 22, 23,  24, 25, 26,

27, 28, 29,  30, 31, 32,  33, 34, 35,
36, 37, 38,  39, 40, 41,  42, 43, 44,
45, 46, 47,  48, 49, 50,  51, 52, 53,

54, 55, 56,  57, 58, 59,  60, 61, 62,
63, 64, 65,  66, 67, 68,  69, 70, 71,
72, 73, 74,  75, 76, 77,  78, 79, 80
*/
const uint8_t puzzle[] =
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

TEST(ColumnTest, InRange)
{
   ASSERT_EQ(true, checkCol(puzzle, 47, 8));
   ASSERT_EQ(true, checkCol(puzzle, 8, 3));
   ASSERT_EQ(true, checkCol(puzzle, 80, 3));
}

TEST(ColumnTest, OutOfRange) 
{
   // Index out of range
   ASSERT_EQ(false, checkCol(puzzle, -10, 2));
   ASSERT_EQ(false, checkCol(puzzle, 81, 0));

   // Val out of range
   ASSERT_EQ(false, checkCol(puzzle, 47, -20));
   ASSERT_EQ(false, checkCol(puzzle, 59, 10));
   ASSERT_EQ(false, checkCol(puzzle, 0, 0));

   // Val already in column
   ASSERT_EQ(false, checkCol(puzzle, 0, 2));
   ASSERT_EQ(false, checkCol(puzzle, 16, 1));
   ASSERT_EQ(false, checkCol(puzzle, 77, 9));

}

TEST(RowTest, InRange)
{
   ASSERT_EQ(true, checkRow(puzzle, 47, 8));
   ASSERT_EQ(true, checkRow(puzzle, 8, 3));
   ASSERT_EQ(true, checkRow(puzzle, 80, 3));
}

TEST(RowTest, OutOfRange) 
{
   // Index out of range
   ASSERT_EQ(false, checkRow(puzzle, -10, 2));
   ASSERT_EQ(false, checkRow(puzzle, 81, 0));

   // Val out of range
   ASSERT_EQ(false, checkRow(puzzle, 47, -20));
   ASSERT_EQ(false, checkRow(puzzle, 59, 10));
   ASSERT_EQ(false, checkRow(puzzle, 0, 0));

   // Val already in Row
   ASSERT_EQ(false, checkRow(puzzle, 0, 9));
   ASSERT_EQ(false, checkRow(puzzle, 16, 2));
   ASSERT_EQ(false, checkRow(puzzle, 67, 5));

}

TEST(GroupTest, InRange)
{
   ASSERT_EQ(true, checkGroup(puzzle, 0, 1));
   ASSERT_EQ(true, checkGroup(puzzle, 32, 9));
   ASSERT_EQ(true, checkGroup(puzzle, 80, 9));
}

TEST(GroupTest, OutOfRange) 
{
   // Index out of range
   ASSERT_EQ(false, checkGroup(puzzle, -10, 2));
   ASSERT_EQ(false, checkGroup(puzzle, 81, 0));

   // Val out of range
   ASSERT_EQ(false, checkGroup(puzzle, 47, -20));
   ASSERT_EQ(false, checkGroup(puzzle, 59, 10));
   ASSERT_EQ(false, checkGroup(puzzle, 0, 0));

   // Val already in Group
   ASSERT_EQ(false, checkGroup(puzzle, 0, 5));
   ASSERT_EQ(false, checkGroup(puzzle, 44, 6));
   ASSERT_EQ(false, checkGroup(puzzle, 59, 2));

}

TEST(AllTest, InRange)
{
   ASSERT_EQ(true, checkAll(puzzle, 49, 1));
   ASSERT_EQ(true, checkAll(puzzle, 32, 3));
   ASSERT_EQ(true, checkAll(puzzle, 80, 3));
}

TEST(AllTest, OutOfRange) 
{
   // Index out of range
   ASSERT_EQ(false, checkAll(puzzle, -10, 2));
   ASSERT_EQ(false, checkAll(puzzle, 81, 0));

   // Val out of range
   ASSERT_EQ(false, checkAll(puzzle, 47, -20));
   ASSERT_EQ(false, checkAll(puzzle, 59, 10));
   ASSERT_EQ(false, checkAll(puzzle, 0, 0));

   // Val already in column
   ASSERT_EQ(false, checkAll(puzzle, 0, 2));
   ASSERT_EQ(false, checkAll(puzzle, 16, 1));
   ASSERT_EQ(false, checkAll(puzzle, 77, 9));

   // Val already in Row
   ASSERT_EQ(false, checkAll(puzzle, 0, 9));
   ASSERT_EQ(false, checkAll(puzzle, 16, 2));
   ASSERT_EQ(false, checkAll(puzzle, 67, 5));

   // Val already in Group
   ASSERT_EQ(false, checkAll(puzzle, 0, 5));
   ASSERT_EQ(false, checkAll(puzzle, 44, 6));
   ASSERT_EQ(false, checkAll(puzzle, 59, 2));

}

int main(int argc, char **argv) 
{
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}