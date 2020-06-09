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

    void testRowColIndex( Sudoku::SudokuCoord coord,
                        Sudoku::RowType row,
                        Sudoku::ColType col,
                        Sudoku::SudokuIndex index);

    void testCoordDefault(Sudoku::SudokuCoord coord);
};