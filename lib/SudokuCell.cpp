#include "SudokuCell.h"
#include "stdio.h"
using namespace Sudoku;

Cell::Cell() :
   m_row(ROW_0),
   m_col(COL_0),
   m_index(0)
{
}

Cell::Cell(RowType inRow, ColType inCol) :
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
Cell::Cell(Index inIndex) :
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

Cell::Cell(const Cell& rhs)
{
   m_row    = rhs.m_row;
   m_col    = rhs.m_col;
   m_index  = rhs.m_index;
}

Index Cell::rowColToIndex(RowType inRow, ColType inCol)
{
   return (Index)((inRow * (ROW_8 + 1)) + inCol);
}

RowType Cell::indexToRow(Index inIndex)
{
   return (RowType)(inIndex / (COL_8 + 1));
}
ColType Cell::indexToCol(Index inIndex)
{
   return (ColType)(inIndex % (COL_8 + 1));
}

RowType Cell::getRow() const
{
   return m_row;
}

ColType Cell::getCol() const
{
   return m_col;
}

Index Cell::getIndex() const 
{
   return m_index;
}

bool Cell::operator==(const Sudoku::Cell& rhs) const
{
   return (this->getIndex() == rhs.getIndex());
}
bool Cell::operator!=(const Sudoku::Cell& rhs) const
{
   return (this->getIndex() != rhs.getIndex());
}
bool Cell::operator<(const Sudoku::Cell& rhs) const
{
   return (this->getIndex() < rhs.getIndex());
}