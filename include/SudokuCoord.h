#pragma once
#include "SudokuCommonTypes.h"

namespace Sudoku
{
   class SudokuCoord
   {
   public:
      SudokuCoord(RowType inRow, ColType inCol);
      SudokuCoord(SudokuIndex inIndex);
      SudokuCoord(const SudokuCoord&); // Copy Constructor

      // Used to initialize
      SudokuCoord& operator++();    //  Prefix ++
      SudokuCoord operator++(int);  //  Postfix ++


      void setRow(RowType inRow);
      void setCol(ColType inCol);
      void setIndex(SudokuIndex inIndex);

      RowType getRow();
      ColType getCol();
      SudokuIndex getIndex();

   private:
      SudokuIndex rowColToIndex(RowType inRow, ColType inCol);
      RowType indexToRow(SudokuIndex inIndex);

      ColType indexToCol(SudokuIndex inIndex);

      RowType     m_row;
      ColType     m_col;
      SudokuIndex m_index;

   };

}