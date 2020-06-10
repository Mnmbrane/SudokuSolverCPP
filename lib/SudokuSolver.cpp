#include "SudokuSolver.h"
#include "SudokuCommonTypes.h"
#include "IterativeBacktrack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace Sudoku;

Solver::Solver()
{
   pipeline.begin = nullptr;
   pipeline.end = nullptr;

   constructAlgoPipeline();
}

Solver::~Solver()
{
   // free everything in the pipeline
   resetPipeline();
}

void Solver::resetPipeline()
{
   // Run through piplne
   while(pipeline.begin != pipeline.end)
   {
      // Pointer to next in the list
      AlgoNodeType* temp = ((pipeline.begin)->next);
      if(pipeline.begin != nullptr)
      {
         // Free the algo
         if(pipeline.begin->algo != nullptr)
         {
            free(pipeline.begin->algo);
            pipeline.begin->algo = nullptr;
            pipeline.begin->next = nullptr;
            pipeline.begin->prev = nullptr;
         }
         free(pipeline.begin);
         pipeline.begin = nullptr;
      }
      pipeline.begin = temp;
   }
}

void Solver::constructAlgoPipeline()
{
   resetPipeline();
   
   addToPipeline(new IterativeBacktrack);
}

void Solver::addToPipeline(AlgorithmInterface* algo)
{
   if(pipeline.begin == nullptr)
   {
      pipeline.begin = new AlgoNodeType;
      pipeline.begin->next = nullptr;
      pipeline.begin->prev = nullptr;
      pipeline.begin->algo = algo;

      pipeline.end = pipeline.begin;
   }
   else
   {
      AlgoNodeType* walker = pipeline.begin;
      while(walker != nullptr)
      {
         walker = walker->next;
      }
      
      // make the new node and place algo inside
      walker = new AlgoNodeType;
      walker->algo = algo;
      walker->next = nullptr;
      walker->prev = pipeline.end;

      // The walker is now the ned of the pipeline
      pipeline.end->next = walker;
      pipeline.end = walker;
   }
}

bool Solver::Solve(Sudoku::Puzzle& puzzle)
{
   bool retVal = false;
   AlgoNodeType* walker = pipeline.begin;

   // Walk through the pipeline
   while(walker != nullptr)
   {
      retVal = walker->algo->Solve(puzzle);

      // Don't care about the return value since
      // we are at the end, just return retVal
      if(walker == pipeline.end)
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
         walker = pipeline.begin;
      }
      
   }

   return retVal;
}