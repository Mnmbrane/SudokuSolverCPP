#include "SudokuCoordTest.h"
#include "gtest/gtest.h"

#include "SudokuCommonTypes.h"
#include "SudokuCoord.h"
#include <vector>

using namespace Sudoku;

TEST_F(SudokuCoordTest, TestConstruction)
{
   // Arrange

   // Act
   SudokuCoord coordNoParams;
   SudokuCoord coordNoParams2;
   SudokuCoord coordValidIndex(54);
   SudokuCoord coordValidRowCol(ROW_5, COL_2);

   // Assert
   ASSERT_EQ(coordNoParams.getRow(), 0);
   ASSERT_EQ(coordNoParams.getCol(), 0);
   ASSERT_EQ(coordNoParams.getIndex(), 0);

   ASSERT_EQ(coordValidIndex.getRow(), ROW_6);
   ASSERT_EQ(coordValidIndex.getCol(), COL_0);
   ASSERT_EQ(coordValidIndex.getIndex(), 54);

   ASSERT_EQ(coordValidRowCol.getRow(), ROW_5);
   ASSERT_EQ(coordValidRowCol.getCol(), COL_2);
   ASSERT_EQ(coordValidRowCol.getIndex(), 47);

   // Overload operators
   ASSERT_EQ(true, coordNoParams!=coordValidRowCol);
   ASSERT_EQ(true, coordNoParams==coordNoParams2);

   // Copy constructor
   coordNoParams2 = coordValidIndex;
   ASSERT_EQ(coordNoParams2.getRow(), ROW_6);
   ASSERT_EQ(coordNoParams2.getCol(), COL_0);
   ASSERT_EQ(coordNoParams2.getIndex(), 54);
}