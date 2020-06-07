#pragma once

#define PUZZLE_MAX_INDEX (80)
#define PUZZLE_MAX_ELEMENTS (PUZZLE_MAX_INDEX+1)

#define ROW_COL_TO_INDEX(row, col) ((row * 9) + col)
#define INDEX_TO_ROW(index) (index / 9)
#define INDEX_TO_COL(index) (index % 9)