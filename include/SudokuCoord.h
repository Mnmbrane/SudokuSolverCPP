#pragma once
#include "SudokuCommonTypes.h"

namespace Sudoku
{
   class SudokuCoord
   {
   public:
      SudokuCoord();
      SudokuCoord(RowType inRow, ColType inCol);
      SudokuCoord(SudokuIndex inIndex);
      SudokuCoord(const SudokuCoord&); // Copy Constructor

      void setRow(RowType inRow);
      void setCol(ColType inCol);
      void setIndex(SudokuIndex inIndex);

      RowType getRow() const ;
      ColType getCol() const ;
      SudokuIndex getIndex() const ;

   friend bool operator==(const SudokuCoord& lhs, const SudokuCoord& rhs);
   friend bool operator!=(const SudokuCoord& lhs, const SudokuCoord& rhs);

   private:
      SudokuIndex rowColToIndex(RowType inRow, ColType inCol);
      RowType indexToRow(SudokuIndex inIndex);

      ColType indexToCol(SudokuIndex inIndex);

      RowType     m_row;
      ColType     m_col;
      SudokuIndex m_index;

   };
}