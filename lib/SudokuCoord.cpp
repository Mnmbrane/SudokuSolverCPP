#include "SudokuCoord.h"

namespace Sudoku
{
SudokuCoord::SudokuCoord(RowType inRow, ColType inCol) :
   m_row(inRow),
   m_col(inCol),
   m_index(rowColToIndex(inRow, inCol))
{
   if(inRow >= ROW_MAX || inCol >= COL_MAX)
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
   if(inIndex >= PUZZLE_MAX_INDEX)
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

SudokuCoord& SudokuCoord::operator++ ()
{
   setIndex(m_index+1);
   return *this;
}
SudokuCoord SudokuCoord::operator++(int)
{
   SudokuCoord coord(m_index);
   setIndex(m_index+1);
   return coord;
}

SudokuIndex SudokuCoord::rowColToIndex(RowType inRow, ColType inCol)
{
   return ((inRow * 9) + inCol);
}

RowType SudokuCoord::indexToRow(SudokuIndex inIndex)
{
   return (RowType)(inIndex / 9);
}
ColType SudokuCoord::indexToCol(SudokuIndex inIndex)
{
   return (ColType)(inIndex % 9);
}


void SudokuCoord::setRow(RowType inRow)
{
   if(inRow < ROW_MAX && inRow >= ROW_0)
   {
      m_row = inRow;

      // Recalculate index
      m_index = rowColToIndex(inRow, m_col);
   }
   // else do nothing
}
void SudokuCoord::setCol(ColType inCol)
{
   if(inCol < COL_MAX && inCol >= COL_0)
   {
      m_col = inCol;

      // Recalculate index
      m_index = rowColToIndex(m_row, inCol);
   }
   // else do nothing
}
void SudokuCoord::setIndex(SudokuIndex inIndex)
{
   if(inIndex <= PUZZLE_MAX_INDEX && inIndex >= 0)
   {
      m_index = inIndex;

      // Recalculate row and col
      m_row = indexToRow(inIndex);
      m_col = indexToCol(inIndex);
   }
}

RowType SudokuCoord::getRow()
{
   return m_row;
}

ColType SudokuCoord::getCol()
{
   return m_col;
}

SudokuIndex SudokuCoord::getIndex()
{
   return m_index;
}

}