#include "NakedOnes.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuCoord.h"
#include <stdio.h>
#include <set>

using namespace Sudoku;

// Solve using recursive backtracking
bool NakedOnes::Solve(Sudoku::Puzzle& puzzle, CandidateSetMapType& unmarkedCoordList)
{
   //  bool candidatesHaveChanged = true;
   //  while(candidatesHaveChanged == true)
   //  {
   //      candidatesHaveChanged = false;
   //      for(Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
   //      {
   //          CandidateSetType candidateSet = puzzle.getCandidates();
   //          for(CandidateSetType::iterator it = candidateSet.begin(); it != candidateSet.end(); ++it)
   //          {
   //              // Check if everything to make sure it's
   //              // actually a good candidate
   //              if(checkAll(m_puzzle, i, *it) == false)
   //              {
   //                  m_puzzle[i].deleteCandidate(*it);
   //                  candidatesHaveChanged = true;
   //              }
   //          }

   //          if(!m_puzzle[i].isMarked() && candidatesHaveChanged == false)
   //          {
   //              // Insert all of the candidates that were found
   //              // into the map of unmarked coords
   //              Coord coord(i);
   //              unmarkedCoords.insert(std::make_pair(coord, m_puzzle[i].getCandidates()));
   //          }
   //      }
   //  }
   return false;
}