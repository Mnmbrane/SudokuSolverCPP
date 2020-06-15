#pragma once

#include "SudokuCommonTypes.h"
#include "SudokuCoord.h"
#include "gtest/gtest.h"

class SudokuCoordTest : public ::testing::Test
{
protected:
   virtual void SetUp()
   {
   }

   virtual void TearDown()
   {
   }

   void testRowColIndex(Sudoku::Coord coord,
                        Sudoku::RowType row,
                        Sudoku::ColType col,
                        Sudoku::GroupType group,
                        Sudoku::Index index);

   void testCoordDefault(Sudoku::Coord coord);
};