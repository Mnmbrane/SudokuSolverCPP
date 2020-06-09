#pragma once
#include <stdint.h>
#include "SudokuCommonTypes.h"

using namespace Sudoku;

enum e_Puzzle
{
   PUZZLE_UNSOLVED,
   PUZZLE_SOLVED,
   PUZZLE_INVALID,
   PUZZLE_INVALID_AT_INDEX_80,

   MAX_NUM_PUZZLE
};
PuzzlePtrType getPuzzle(e_Puzzle puzzleIndex);