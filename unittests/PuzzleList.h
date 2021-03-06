#pragma once
#include <stdint.h>
#include "SudokuCell.h"

enum e_Puzzle
{
   PUZZLE_UNSOLVED,
   PUZZLE_SOLVED,
   PUZZLE_INVALID,
   PUZZLE_INVALID_AT_INDEX_80,
   PUZZLE_UNSOLVABLE,
   PUZZLE_ALL_ZEROES,
   PUZZLE_ALL_ZEROES_SOLVED,

   MAX_NUM_PUZZLE
};
Sudoku::Cell* getPuzzle(e_Puzzle puzzleIndex);