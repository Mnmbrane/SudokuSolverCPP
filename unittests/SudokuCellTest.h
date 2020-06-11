#pragma once

#include "SudokuCommonTypes.h"
#include "SudokuCell.h"
#include "gtest/gtest.h"

class SudokuCellTest : public ::testing::Test
{
protected:

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    void testRowColIndex( Sudoku::Cell cell,
                        Sudoku::RowType row,
                        Sudoku::ColType col,
                        Sudoku::Index index);

    void testCellDefault(Sudoku::Cell cell);
};