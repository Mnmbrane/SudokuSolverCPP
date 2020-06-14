#include "IterativeBacktrack.h"
#include "SudokuCommonTypes.h"
#include "SudokuPuzzle.h"
#include "SudokuCoord.h"
#include <stdio.h>
#include <map>

#include <chrono>
#include <thread>

using namespace Sudoku;

using namespace std::chrono_literals;

// Solve using recursive backtracking
bool IterativeBacktrack::Solve(Sudoku::Puzzle& puzzle)
{
   UnmarkedCoordMapType unmarkedCoordList = puzzle.getUnmarkedCoords();
   UnmarkedCoordMapType::iterator coordMapIt = unmarkedCoordList.begin();

   // Saves the candidate iterator we are iterating on
   std::map<Coord, CandidateSetType::iterator> saveMap;
   // Iterate through the unmarked coordinates
   while( coordMapIt != unmarkedCoordList.end() )
   {
      saveMap.insert(std::make_pair(coordMapIt->first, coordMapIt->second.begin()));
      ++coordMapIt;
   }

   bool valueSetFlag = true;
   coordMapIt = unmarkedCoordList.begin();
   // Iterate through the unmarked coordinates
   while( coordMapIt != unmarkedCoordList.end() )
   {
      printf("Working on index[%d]\n", coordMapIt->first.getIndex());

      Coord coord = coordMapIt->first;
      CandidateSetType& candidateSet = coordMapIt->second;

      // this mean we went back
      if(valueSetFlag == false)
      {
         ++saveMap[coord];
         if(saveMap[coord] == candidateSet.end())
         {
            saveMap[coord] = candidateSet.begin();
            --coordMapIt;
            continue;
         }
         valueSetFlag = true;
      }

      // Check if we are at the beginning of the coord map and
      // also at the end of the candidate list, then return false
      if(coordMapIt == unmarkedCoordList.begin() && 
         saveMap[coord] == candidateSet.end())
      {
         return false;
      }
      // Set the value using the save candidate
      while(puzzle.setValAt(coord, *(saveMap[coord])) == false)
      {
         //std::this_thread::sleep_for(1s);

         printf("Working on index=[%d] val [%d]\n", coordMapIt->first.getIndex(), *(saveMap[coord]));
         ++saveMap[coord];

         // If we are at the end of the candidate list, but not at the
         // beginning of the coord list, we need to go back to the previous
         // unmarked coordinate
         if(saveMap[coord] == candidateSet.end())
         {
            printf("Save set is at the end\n");
            --coordMapIt;
            saveMap[coord] = candidateSet.begin();
            puzzle.setValAt(coord, VAL_UNMARKED);
            valueSetFlag = false;
            break;
         }
      }
      // Only Move forward if the value has been set for the
      // current coordinate
      if(valueSetFlag == true)
      {
         printf("Setting val =[%d]\n", *(saveMap[coord] ));
         ++coordMapIt;
      }
   }
   return true;
}