#include <stdio.h>
#include <stdint.h>
#include "SudokuUtilChecker.h"

#define MAX_INDEX 80

/*
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

// https://www.websudoku.com/
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

int main()
{
    // printf("Check insert 8 into index 1 = [%s]\n",
    //     checkCol(1, 8) ? "SUCCESS" : "FAILED");

    // printf("Check insert 8 into index 47 = [%s]\n",
    //     checkRow(47, 8) ? "SUCCESS" : "FAILED");

    // printf("Check insert 8 into index 47 = [%s]\n",
    //     checkGroup(puzzle, 47, 7) ? "SUCCESS" : "FAILED");

    return 0;
}