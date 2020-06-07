#pragma once
#include <stdint.h>
#include "common.h"

enum e_Puzzle
{
   PUZZLE_UNSOLVED,
   PUZZLE_SOLVED,
   PUZZLE_INVALID,
   PUZZLE_INVALID_AT_INDEX_80,

   MAX_NUM_PUZZLE
};
uint8_t* getPuzzle(e_Puzzle puzzleIndex);