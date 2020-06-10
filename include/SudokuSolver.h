#pragma once
#include "SudokuCommonTypes.h"
#include "AlgorithmInterface.h"
#include "SudokuPuzzle.h"

/* This is the main Solver manager, it's job
 * is to create a pipeline of algorithm to run
 * the Puzzle through.
 * 
 * The data structure used for this is a Linked
 * List. Once the List has been made, start with
 * the first algorithm(Naked 1s), if it found
 * unmarked places it could solve, then restart
 * the entire list again. Our place in the
 * pipeline will only move forward if and only
 * if, no solves were made in the current algorithm
 * 
 * The Iterative Backtrack will be the last algorithm
 * as it is the complete search of the entire puzzle.
 * This algorithm will be last because it's a
 * very slow algorithm, but 100% reliable
 * 
 * Example:
 *    START->Naked 1s->Hidden 1s->
 *    Iterative Backtrack->SOLVED
 * 
 */
class Sudoku::Solver
{
public:
   Solver();
   ~Solver();

   bool Solve(Sudoku::Puzzle& puzzle);

   // Adds algo to the end of the pipeline
   void addToPipeline(AlgorithmInterface* algo);

private:
   void constructAlgoPipeline();

   void resetPipeline();

   typedef struct AlgoNode
   {
      struct AlgoNode* next;
      struct AlgoNode* prev;
      AlgorithmInterface* algo;
   } AlgoNodeType;

   typedef struct AlgoLinkedList
   {
      AlgoNodeType* begin;
      AlgoNodeType* end;
   } AlgoLinkedList;

   AlgoLinkedList pipeline;
};