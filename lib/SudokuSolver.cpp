#include "SudokuSolver.h"
#include "SudokuCoord.h"
#include "SudokuCommonTypes.h"
#include "IterativeBacktrack.h"
#include "NakedOnes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace Sudoku;

Solver::Solver()
{
   m_pipeline.begin = nullptr;
   m_pipeline.end = nullptr;

   constructAlgoPipeline();
}

Solver::~Solver()
{
   // free everything in the m_pipeline
   resetPipeline();
}

void Solver::resetPipeline()
{
   // Run through piplne
   while(m_pipeline.begin != m_pipeline.end)
   {
      // Pointer to next in the list
      AlgoNodeType* temp = ((m_pipeline.begin)->next);
      if(m_pipeline.begin != nullptr)
      {
         // Free the algo
         if(m_pipeline.begin->algo != nullptr)
         {
            free(m_pipeline.begin->algo);
            m_pipeline.begin->algo = nullptr;
            m_pipeline.begin->next = nullptr;
            m_pipeline.begin->prev = nullptr;
         }
         free(m_pipeline.begin);
         m_pipeline.begin = nullptr;
      }
      m_pipeline.begin = temp;
   }
}

void Solver::constructAlgoPipeline()
{
   resetPipeline();

   addToPipeline(new NakedOnes);
   
   addToPipeline(new IterativeBacktrack);
}

CandidateSetMapType Solver::getCandidateSetMap(const Sudoku::Puzzle& puzzle)
{
   CandidateSetMapType retSetMap;
   for(Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      Coord coord(i);
      if(!puzzle.isMarkedAt(coord))
      {
         retSetMap[coord] = puzzle.getCandidateAt(coord);
      }
   }
   return retSetMap;
}

void Solver::addToPipeline(AlgorithmInterface* algo)
{
   if(m_pipeline.begin == nullptr)
   {
      m_pipeline.begin = new AlgoNodeType;
      m_pipeline.begin->next = nullptr;
      m_pipeline.begin->prev = nullptr;
      m_pipeline.begin->algo = algo;

      m_pipeline.end = m_pipeline.begin;
   }
   else
   {
      AlgoNodeType* walker = m_pipeline.begin;
      while(walker != nullptr)
      {
         walker = walker->next;
      }
      
      // make the new node and place algo inside
      walker = new AlgoNodeType;
      walker->algo = algo;
      walker->next = nullptr;
      walker->prev = m_pipeline.end;

      // The walker is now the ned of the m_pipeline
      m_pipeline.end->next = walker;
      m_pipeline.end = walker;
   }
}

bool Solver::Solve(Sudoku::Puzzle& puzzle)
{
   bool retVal = false;
   AlgoNodeType* walker = m_pipeline.begin;
   CandidateSetMapType candidateSetMap = getCandidateSetMap(puzzle);
   // Walk through the m_pipeline
   while(walker != nullptr)
   {
      retVal = walker->algo->Solve(puzzle, candidateSetMap);

      // If the puzzle became invalid we 
      // need to return false
      if(puzzle.checkPuzzleValidity() == false)
      {
         return false;
      }
      // Don't care about the return value since
      // we are at the end, just return retVal
      else if(walker == m_pipeline.end)
      {
         return retVal;
      }
      // Walk forward if nothing was solved
      else if(retVal == false)
      {
         walker = walker->next;
      }
      // We solved something great, go back to
      // the beginning
      else
      {
         walker = m_pipeline.begin;
      }
      
   }

   return retVal;
}