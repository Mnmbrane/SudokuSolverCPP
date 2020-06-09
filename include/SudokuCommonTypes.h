#pragma once
namespace Sudoku
{
   class SudokuCoord;
   class SudokuPuzzle;

   static const int PUZZLE_MAX_INDEX = 80;
   static const int PUZZLE_MAX_ELEMENTS = (PUZZLE_MAX_INDEX + 1);

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
      VAL_UNMARKED, VAL_1, VAL_2, VAL_3, VAL_4, VAL_5, VAL_6, VAL_7, VAL_8, VAL_9, VAL_MAX
   } ValType;

   inline ValType operator++(ValType& val)
   {
      val = static_cast<ValType>((static_cast<int>(val) + 1) % (VAL_MAX+1));
      return val;
   }

   inline ValType operator++(ValType& val, int)
   {
      ValType temp = val;
      val = static_cast<ValType>((static_cast<int>(val) + 1) % (VAL_MAX+1));
      return temp;
   }

   inline ValType operator--(ValType& val)
   {
      val==0 ? val = VAL_MAX : val = static_cast<ValType>((static_cast<int>(val) - 1));
      return val;
   }

   inline ValType operator--(ValType& val, int)
   {
      ValType temp = val;
      val==0 ? val = VAL_MAX : val = static_cast<ValType>((static_cast<int>(val) - 1));
      return temp;
   }

   typedef ValType* PuzzlePtrType;
   typedef int SudokuIndex;
}