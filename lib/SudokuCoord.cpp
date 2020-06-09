#include "SudokuCoord.h"
#include "stdio.h"
using namespace Sudoku;

SudokuCoord::SudokuCoord() :
   m_row(ROW_0),
   m_col(COL_0),
   m_index(0)
{
}

SudokuCoord::SudokuCoord(RowType inRow, ColType inCol) :
   m_row(inRow),
   m_col(inCol),
   m_index(rowColToIndex(inRow, inCol))
{
   if( inRow < ROW_0 || inRow >= ROW_MAX ||
       inCol < COL_0 || inCol >= COL_MAX )
   {
      m_row = ROW_0;
      m_col = COL_0;
      m_index = 0;
   }
}
SudokuCoord::SudokuCoord(SudokuIndex inIndex) :
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

SudokuCoord::SudokuCoord(const SudokuCoord& rhs)
{
   m_row    = rhs.m_row;
   m_col    = rhs.m_col;
   m_index  = rhs.m_index;
}

SudokuIndex SudokuCoord::rowColToIndex(RowType inRow, ColType inCol)
{
   return (SudokuIndex)((inRow * 9) + inCol);
}

RowType SudokuCoord::indexToRow(SudokuIndex inIndex)
{
   return (RowType)(inIndex / 9);
}
ColType SudokuCoord::indexToCol(SudokuIndex inIndex)
{
   return (ColType)(inIndex % 9);
}

RowType SudokuCoord::getRow() const
{
   return m_row;
}

ColType SudokuCoord::getCol() const
{
   return m_col;
}

SudokuIndex SudokuCoord::getIndex() const 
{
   return m_index;
}