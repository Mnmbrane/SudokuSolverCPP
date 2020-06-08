#pragma once
namespace Sudoku
{
   typedef unsigned char uint8_t;

   static const uint8_t PUZZLE_MAX_INDEX = 80;
   static const uint8_t PUZZLE_MAX_ELEMENTS = (PUZZLE_MAX_INDEX + 1);

   typedef enum
   {
      ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8, ROW_MAX
   } RowType;

   typedef enum
   {
      COL_0, COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8, COL_MAX
   } ColType;

   typedef enum
   {
      VAL_0, VAL_1, VAL_2, VAL_3, VAL_4, VAL_5, VAL_6, VAL_7, VAL_8, VAL_MAX
   } ValType;

   typedef ValType* PuzzlePtrType;
   typedef uint8_t SudokuIndex;

}