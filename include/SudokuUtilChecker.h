#pragma once
#include "stdint.h"
#include "SudokuCommonTypes.h"

namespace Sudoku
{
bool checkCol(const PuzzlePtrType puzzle, SudokuIndex index, ValType val);

bool checkRow(const PuzzlePtrType puzzle, SudokuIndex index, ValType val);

bool checkGroup(const PuzzlePtrType puzzle, SudokuIndex index, ValType val);

bool checkAll(const PuzzlePtrType puzzle, SudokuIndex index, ValType val);
}
