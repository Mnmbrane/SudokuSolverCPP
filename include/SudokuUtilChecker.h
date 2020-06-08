#pragma once
#include "stdint.h"
#include "SudokuCommonTypes.h"

bool checkCol(const Sudoku::PuzzlePtrType puzzle, Sudoku::SudokuIndex index, Sudoku::ValType val);

bool checkRow(const Sudoku::PuzzlePtrType puzzle, Sudoku::SudokuIndex index, Sudoku::ValType val);

bool checkGroup(const Sudoku::PuzzlePtrType puzzle, Sudoku::SudokuIndex index, Sudoku::ValType val);

bool checkAll(const Sudoku::PuzzlePtrType puzzle, Sudoku::SudokuIndex index, Sudoku::ValType val);