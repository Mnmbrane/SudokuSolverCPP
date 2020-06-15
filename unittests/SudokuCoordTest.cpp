#include "SudokuCoordTest.h"
#include "gtest/gtest.h"

#include <vector>

using namespace Sudoku;

void SudokuCoordTest::testRowColIndex(Coord coord,
                                      RowType row,
                                      ColType col,
                                      GroupType group,
                                      Index index)
{
   ASSERT_EQ(coord.getRow(), row);
   ASSERT_EQ(coord.getCol(), col);
   ASSERT_EQ(coord.getGroup(), group);
   ASSERT_EQ(coord.getIndex(), index);

}

void SudokuCoordTest::testCoordDefault(Coord coord)
{
   ASSERT_EQ(coord.getRow(), 0);
   ASSERT_EQ(coord.getCol(), 0);
   ASSERT_EQ(coord.getGroup(), 0);
   ASSERT_EQ(coord.getIndex(), 0);
}

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

TEST_F(SudokuCoordTest, TestValidConstruction)
{
   // Arrange

   // Act
   Coord coordNoParams;
   Coord coordNoParams2;
   Coord coordValidIndex(54);
   Coord coordValidRowCol(ROW_5, COL_2);

   // Assert
   // Constructor
   testCoordDefault(coordNoParams);
   testRowColIndex(coordValidIndex, ROW_6, COL_0, GRP_6, 54);
   testRowColIndex(coordValidRowCol, ROW_5, COL_2, GRP_3, 47);

   // Overload operators
   ASSERT_EQ(true, coordNoParams!=coordValidRowCol);
   ASSERT_EQ(true, coordNoParams==coordNoParams2);

   // Copy constructor
   coordNoParams2 = coordValidIndex;
   testRowColIndex(coordNoParams2, ROW_6, COL_0, GRP_6, 54);

   // Destructor
   coordValidRowCol.~Coord();
   testRowColIndex(coordValidRowCol, ROW_5, COL_2, GRP_3, 47);
}

TEST_F(SudokuCoordTest, TestInvalidConstruction)
{
   // Arrange/act
   Coord coordInalidIndex(-1);
   Coord coordInalidIndex2(1000);
   Coord coordInvalidRowCol((RowType)-5, (ColType)39);

   // Assert
   testCoordDefault(coordInalidIndex);
   testCoordDefault(coordInalidIndex2);
   testCoordDefault(coordInvalidRowCol);
}
