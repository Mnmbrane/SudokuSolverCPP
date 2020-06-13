#include "SudokuCoord.h"
#include "stdio.h"
using namespace Sudoku;

Coord::Coord() :
   m_row(ROW_0),
   m_col(COL_0),
   m_index(0)
{
}

Coord::Coord(RowType inRow, ColType inCol) :
   m_row(inRow),
   m_col(inCol),
   m_index(rowColToIndex(inRow, inCol))
{
   if( inRow < ROW_0 || inRow >= ROW_8 ||
       inCol < COL_0 || inCol >= COL_8 )
   {
      m_row = ROW_0;
      m_col = COL_0;
      m_index = 0;
   }
}
Coord::Coord(Index inIndex) :
   m_row(indexToRow(inIndex)),
   m_col(indexToCol(inIndex)),
   m_index(inIndex)
{
   if(inIndex < 0 || inIndex > PUZZLE_MAX_INDEX)
   {
      m_row = ROW_0;
      m_col = COL_0;
      m_index = 0;
   }
}

Coord::Coord(const Coord& rhs)
{
   m_row    = rhs.m_row;
   m_col    = rhs.m_col;
   m_index  = rhs.m_index;
}

Index Coord::rowColToIndex(RowType inRow, ColType inCol)
{
   return (Index)((inRow * (ROW_8 + 1)) + inCol);
}

RowType Coord::indexToRow(Index inIndex)
{
   return (RowType)(inIndex / (COL_8 + 1));
}
ColType Coord::indexToCol(Index inIndex)
{
   return (ColType)(inIndex % (COL_8 + 1));
}

RowType Coord::getRow() const
{
   return m_row;
}

ColType Coord::getCol() const
{
   return m_col;
}

Index Coord::getIndex() const 
{
   return m_index;
}

bool Coord::operator==(const Sudoku::Coord& rhs) const
{
   return (this->getIndex() == rhs.getIndex());
}
bool Coord::operator!=(const Sudoku::Coord& rhs) const
{
   return (this->getIndex() != rhs.getIndex());
}
bool Coord::operator<(const Sudoku::Coord& rhs) const
{
   return (this->getIndex() < rhs.getIndex());
}