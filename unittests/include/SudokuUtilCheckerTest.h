#pragma once

#include "gtest/gtest.h"

#include "SudokuUtilChecker.h"
#include "common.h"

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

class SudokuUtilCheckerTest : public ::testing::Test
{
protected:

    uint8_t m_puzzle[MAX_ELEMENTS];

    virtual void SetUp()
    {      
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

        // copy over puzzle
        for(uint8_t i = 0; i < MAX_ELEMENTS; i++)
        {
            m_puzzle[i] = puzzle[i];
        }
    }

    virtual void TearDown()
    {
    }
};

TEST_F(SudokuUtilCheckerTest, ColInRange)
{
   ASSERT_EQ(true, checkCol(m_puzzle, 47, 8));
   ASSERT_EQ(true, checkCol(m_puzzle, 8, 3));
   ASSERT_EQ(true, checkCol(m_puzzle, 80, 3));
}