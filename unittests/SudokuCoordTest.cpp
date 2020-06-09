#include "SudokuCoordTest.h"
#include "gtest/gtest.h"

#include <vector>

using namespace Sudoku;

void SudokuCoordTest::testRowColIndex(Coord coord,
                                    RowType row,
                                    ColType col,
                                    Index index)
{
   ASSERT_EQ(coord.getRow(), row);
   ASSERT_EQ(coord.getCol(), col);
   ASSERT_EQ(coord.getIndex(), index);

}

void SudokuCoordTest::testCoordDefault(Coord coord)
{
   ASSERT_EQ(coord.getRow(), 0);
   ASSERT_EQ(coord.getCol(), 0);
   ASSERT_EQ(coord.getIndex(), 0);
}

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
   testRowColIndex(coordValidIndex, ROW_6, COL_0, 54);
   testRowColIndex(coordValidRowCol, ROW_5, COL_2, 47);

   // Overload operators
   ASSERT_EQ(true, coordNoParams!=coordValidRowCol);
   ASSERT_EQ(true, coordNoParams==coordNoParams2);

   // Copy constructor
   coordNoParams2 = coordValidIndex;
   testRowColIndex(coordNoParams2, ROW_6, COL_0, 54);

   // Destructor
   coordValidRowCol.~Coord();
   testRowColIndex(coordValidRowCol, ROW_5, COL_2, 47);
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
