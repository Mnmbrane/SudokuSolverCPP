#include "SudokuCellTest.h"
#include "gtest/gtest.h"

#include <vector>

using namespace Sudoku;

void SudokuCellTest::testRowColIndex(Cell cell,
                                    RowType row,
                                    ColType col,
                                    Index index)
{
   ASSERT_EQ(cell.getRow(), row);
   ASSERT_EQ(cell.getCol(), col);
   ASSERT_EQ(cell.getIndex(), index);

}

void SudokuCellTest::testCellDefault(Cell cell)
{
   ASSERT_EQ(cell.getRow(), 0);
   ASSERT_EQ(cell.getCol(), 0);
   ASSERT_EQ(cell.getIndex(), 0);
}

TEST_F(SudokuCellTest, TestValidConstruction)
{
   // Arrange

   // Act
   Cell cellNoParams;
   Cell cellNoParams2;
   Cell cellValidIndex(54);
   Cell cellValidRowCol(ROW_5, COL_2);

   // Assert
   // Constructor
   testCellDefault(cellNoParams);
   testRowColIndex(cellValidIndex, ROW_6, COL_0, 54);
   testRowColIndex(cellValidRowCol, ROW_5, COL_2, 47);

   // Overload operators
   ASSERT_EQ(true, cellNoParams!=cellValidRowCol);
   ASSERT_EQ(true, cellNoParams==cellNoParams2);

   // Copy constructor
   cellNoParams2 = cellValidIndex;
   testRowColIndex(cellNoParams2, ROW_6, COL_0, 54);

   // Destructor
   cellValidRowCol.~Cell();
   testRowColIndex(cellValidRowCol, ROW_5, COL_2, 47);
}

TEST_F(SudokuCellTest, TestInvalidConstruction)
{
   // Arrange/act
   Cell cellInalidIndex(-1);
   Cell cellInalidIndex2(1000);
   Cell cellInvalidRowCol((RowType)-5, (ColType)39);

   // Assert
   testCellDefault(cellInalidIndex);
   testCellDefault(cellInalidIndex2);
   testCellDefault(cellInvalidRowCol);
}
