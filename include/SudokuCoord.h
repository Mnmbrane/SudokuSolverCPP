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

      void setRow(RowType inRow);
      void setCol(ColType inCol);
      void setIndex(SudokuIndex inIndex);

      RowType getRow() const ;
      ColType getCol() const ;
      SudokuIndex getIndex() const ;

   private:
      SudokuIndex rowColToIndex(RowType inRow, ColType inCol);
      RowType indexToRow(SudokuIndex inIndex);

      ColType indexToCol(SudokuIndex inIndex);

      RowType     m_row;
      ColType     m_col;
      SudokuIndex m_index;

   };

}