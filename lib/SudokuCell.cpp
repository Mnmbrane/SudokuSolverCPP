#include "SudokuCell.h"

using namespace Sudoku;

Cell::Cell()
{
   insertAllValues();
}

Cell::Cell(ValType val)
{
   if(val == VAL_UNMARKED)
   {
      insertAllValues();
   }
   else
   {
      m_candidates.insert(val);
   }

}

Cell::Cell(CandidateSetType candidates)
{
   if(candidates.size() == 1 &&
      *(candidates.begin()) == VAL_UNMARKED)
   {
      insertAllValues();
   }
   else
   {
      m_candidates = candidates;
   }
   
}

Cell::Cell(const Cell& cell)
{
   setVal(cell.getVal());
}

ValType Cell::getVal() const
{
   if(m_candidates.size() > 1)
   {
      return VAL_UNMARKED;
   }
   else
   {
      return *(m_candidates.begin());
   }
}

void Cell::setVal(ValType val)
{
   if(val >= VAL_UNMARKED && val <= VAL_9)
   {
      if(val != VAL_UNMARKED)
      {
         m_candidates.clear();
         m_candidates.insert(val);
      }
      else
      {
         insertAllValues();
      }
   }

}

std::set<ValType> Cell::getCandidates() const
{
   return m_candidates;
}

void Cell::insertAllValues()
{
   m_candidates.clear();
   for(ValType val = VAL_1; val < VAL_MAX; ++val)
   {
      m_candidates.insert(val);
   }
}

// Is marked if we only have 1 candidate remaning
bool Cell::isMarked()
{
   return (m_candidates.size() == 1);
}

void Cell::operator=(const ValType& rhs)
{
   setVal(rhs);
}

bool Cell::operator==(const Cell& rhs) const
{
   return (m_candidates == rhs.getCandidates());
}

bool Cell::operator==(int rhs) const
{
   return (getVal() == rhs);
}

bool Cell::operator!=(const Cell& rhs) const
{
   return (m_candidates != rhs.getCandidates());
}