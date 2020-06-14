#include "NakedOnes.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuCoord.h"
#include <stdio.h>
#include <set>

using namespace Sudoku;


// Try to get all of the naked ones first before going to the next algorithm
bool NakedOnes::Solve(Sudoku::Puzzle &puzzle, CandidateSetMapType &unmarkedCoordList)
{
   bool retVal = false;
   CandidateSetMapType prunedSetMap;

   // Go through the candidate map and set each candidate for each cell
   for (CandidateSetMapType::iterator candidateSetMapIt = unmarkedCoordList.begin();
        candidateSetMapIt != unmarkedCoordList.end();
        ++candidateSetMapIt)
   {
      Coord coord = candidateSetMapIt->first;
      CandidateSetType candidateSet = unmarkedCoordList[coord];
      // Go through the candidate list for the cell
      for (ValType const& candidate : candidateSet)
      {
         // Check if everything to make sure it's
         // actually a good candidate
         if (puzzle.checkAll(nullptr, coord.getIndex(), candidate) == false)
         {
            puzzle.deleteCandidateAt(coord.getIndex(), candidate);

            // Something got deleted we want to go through this again
            retVal = true;
         }
      }

      if (!puzzle.isMarkedAt(coord.getIndex()))
      {
         // Insert all of the candidates that were found
         // into the map of unmarked coords
         prunedSetMap.insert(std::make_pair(coord, puzzle.getCandidateAt(coord)));
      }
   }

   if(retVal == true)
   {
      unmarkedCoordList.clear();
      for(auto const& [coord, prunedSet] : prunedSetMap)
      {
         unmarkedCoordList.insert(std::make_pair(coord, prunedSet));
      }
   }
   return retVal;
}