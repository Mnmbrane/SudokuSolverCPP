#pragma once
#include "SudokuCommonTypes.h"

class Sudoku::Cell
{
public:
   Cell();
   Cell(RowType inRow, ColType inCol);
   Cell(Index inIndex);
   Cell(const Cell&); // Copy Constructor

   ~Cell(){}

   RowType getRow() const ;
   ColType getCol() const ;
   Index getIndex() const ;

   bool operator==(const Cell& rhs) const;
   bool operator!=(const Cell& rhs) const;
   bool operator<(const Cell& rhs) const;

private:

   Index rowColToIndex(RowType inRow, ColType inCol);
   RowType indexToRow(Index inIndex);

   ColType indexToCol(Index inIndex);

   RowType     m_row;
   ColType     m_col;
   Index m_index;

};