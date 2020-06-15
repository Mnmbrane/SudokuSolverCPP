#pragma once
#include "SudokuCommonTypes.h"

class Sudoku::Coord
{
public:
   Coord();
   Coord(RowType inRow, ColType inCol);
   Coord(Index inIndex);
   Coord(const Coord&); // Copy Constructor

   ~Coord(){}

   RowType getRow() const ;
   ColType getCol() const ;
   GroupType getGroup() const;
   Index getIndex() const ;
   Index getIndexFromGroup() const;

   bool operator==(const Coord& rhs) const;
   bool operator!=(const Coord& rhs) const;
   bool operator<(const Coord& rhs) const;

private:

   Index rowColToIndex(RowType inRow, ColType inCol);
   RowType indexToRow(Index inIndex);
   ColType indexToCol(Index inIndex);
   GroupType indexToGroup(Index inIndex);
   Index indexToGroupIndex(Index inIndex) const;

   RowType     m_row;
   ColType     m_col;
   GroupType   m_group;
   Index m_index;

};