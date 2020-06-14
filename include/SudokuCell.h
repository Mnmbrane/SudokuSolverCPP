#pragma once
#include "SudokuCommonTypes.h"
#include <set>
class Sudoku::Cell
{
public:
   // Default to all candidate values 1-9
   Cell();

   // Insert value into the candidate list
   // this makes it marked
   Cell(ValType val);

   Cell(std::set<ValType> candidates);

   Cell(const Cell&);
   ~Cell(){}

   // gets the first value in the candidate list
   // may not be the number you are looking for if
   // the cell is unmarked
   ValType getVal() const;

   CandidateSetType getCandidates() const;

   void printCandidates();

   void setVal(ValType val);

   void deleteCandidate(ValType val);

   // Is marked if we only have 1 candidate remaning
   bool isMarked() const;

   void insertAllValues();

   void operator=(const ValType& rhs);
   bool operator==(const Cell& rhs) const;
   bool operator==(int rhs) const;
   bool operator!=(const Cell& rhs) const;

private:

   CandidateSetType m_candidates;

};