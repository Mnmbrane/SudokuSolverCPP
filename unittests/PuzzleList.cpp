#include "PuzzleList.h"

using namespace Sudoku;

ValType VAL_0 = VAL_UNMARKED; 

// 1
Cell puzzleUnsolved[] =
{
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_9,  VAL_0, VAL_0, VAL_0,
   VAL_2, VAL_8, VAL_0,  VAL_3, VAL_0, VAL_0,  VAL_1, VAL_0, VAL_5,
   VAL_3, VAL_0, VAL_5,  VAL_0, VAL_8, VAL_0,  VAL_7, VAL_4, VAL_6,

   VAL_7, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_6, VAL_0,
   VAL_0, VAL_3, VAL_0,  VAL_4, VAL_2, VAL_7,  VAL_0, VAL_8, VAL_0,
   VAL_0, VAL_2, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_7,

   VAL_8, VAL_1, VAL_3,  VAL_0, VAL_5, VAL_0,  VAL_6, VAL_0, VAL_2,
   VAL_5, VAL_0, VAL_9,  VAL_0, VAL_0, VAL_2,  VAL_0, VAL_1, VAL_8,
   VAL_0, VAL_0, VAL_0,  VAL_8, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0
};


Cell puzzleSolved[] =
{
   VAL_4, VAL_6, VAL_1,  VAL_5, VAL_7, VAL_9,  VAL_8, VAL_2, VAL_3,
   VAL_2, VAL_8, VAL_7,  VAL_3, VAL_4, VAL_6,  VAL_1, VAL_9, VAL_5,
   VAL_3, VAL_9, VAL_5,  VAL_2, VAL_8, VAL_1,  VAL_7, VAL_4, VAL_6,
   
   VAL_7, VAL_5, VAL_4,  VAL_1, VAL_3, VAL_8,  VAL_2, VAL_6, VAL_9,
   VAL_9, VAL_3, VAL_6,  VAL_4, VAL_2, VAL_7,  VAL_5, VAL_8, VAL_1,
   VAL_1, VAL_2, VAL_8,  VAL_6, VAL_9, VAL_5,  VAL_4, VAL_3, VAL_7,
   
   VAL_8, VAL_1, VAL_3,  VAL_9, VAL_5, VAL_4,  VAL_6, VAL_7, VAL_2,
   VAL_5, VAL_4, VAL_9,  VAL_7, VAL_6, VAL_2,  VAL_3, VAL_1, VAL_8,
   VAL_6, VAL_7, VAL_2,  VAL_8, VAL_1, VAL_3,  VAL_9, VAL_5, VAL_4
};

Cell puzzleUnsolvable[] =
{
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_9,  VAL_0, VAL_0, VAL_0,
   VAL_2, VAL_8, VAL_0,  VAL_3, VAL_0, VAL_0,  VAL_1, VAL_0, VAL_5,
   VAL_3, VAL_0, VAL_5,  VAL_0, VAL_8, VAL_0,  VAL_7, VAL_4, VAL_6,

   VAL_7, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_6, VAL_0,
   VAL_0, VAL_3, VAL_0,  VAL_4, VAL_2, VAL_7,  VAL_0, VAL_8, VAL_0,
   VAL_0, VAL_2, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_7,

   VAL_8, VAL_1, VAL_3,  VAL_0, VAL_5, VAL_0,  VAL_6, VAL_0, VAL_2,
   VAL_5, VAL_0, VAL_9,  VAL_0, VAL_0, VAL_2,  VAL_0, VAL_1, VAL_8,
   VAL_0, VAL_0, VAL_0,  VAL_8, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_3
};

ValType VAL_10 = (ValType)10; 
Cell puzzleInvalid[] =
{
   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,
   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,
   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,

   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,
   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,
   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,

   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,
   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,
   VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10,  VAL_10, VAL_10, VAL_10
};

Cell puzzleInvalidAtIndex80[] =
{
   VAL_8, VAL_2, VAL_7,  VAL_1, VAL_5, VAL_4,  VAL_3, VAL_9, VAL_6,
   VAL_9, VAL_6, VAL_5,  VAL_3, VAL_2, VAL_7,  VAL_1, VAL_4, VAL_8,
   VAL_3, VAL_4, VAL_1,  VAL_6, VAL_8, VAL_9,  VAL_7, VAL_5, VAL_2,

   VAL_5, VAL_9, VAL_3,  VAL_4, VAL_6, VAL_8,  VAL_2, VAL_7, VAL_1,
   VAL_4, VAL_7, VAL_2,  VAL_5, VAL_1, VAL_3,  VAL_6, VAL_8, VAL_9,
   VAL_6, VAL_1, VAL_8,  VAL_9, VAL_7, VAL_2,  VAL_4, VAL_3, VAL_5,

   VAL_7, VAL_8, VAL_6,  VAL_2, VAL_3, VAL_5,  VAL_9, VAL_1, VAL_4,
   VAL_1, VAL_5, VAL_4,  VAL_7, VAL_9, VAL_6,  VAL_8, VAL_2, VAL_3,
   VAL_2, VAL_3, VAL_9,  VAL_8, VAL_4, VAL_1,  VAL_5, VAL_6, VAL_8
};

Cell puzzleAllZeroes[] =
{
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,

   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,

   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,
   VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0,  VAL_0, VAL_0, VAL_0
};

Cell puzzleAllZeroesSolved[] =
{
   VAL_1, VAL_2, VAL_3,  VAL_4, VAL_5, VAL_6,  VAL_7, VAL_8, VAL_9,
   VAL_4, VAL_5, VAL_6,  VAL_7, VAL_8, VAL_9,  VAL_1, VAL_2, VAL_3,
   VAL_7, VAL_8, VAL_9,  VAL_1, VAL_2, VAL_3,  VAL_4, VAL_5, VAL_6,
  
   VAL_2, VAL_1, VAL_4,  VAL_3, VAL_6, VAL_5,  VAL_8, VAL_9, VAL_7,
   VAL_3, VAL_6, VAL_5,  VAL_8, VAL_9, VAL_7,  VAL_2, VAL_1, VAL_4,
   VAL_8, VAL_9, VAL_7,  VAL_2, VAL_1, VAL_4,  VAL_3, VAL_6, VAL_5,
  
   VAL_5, VAL_3, VAL_1,  VAL_6, VAL_4, VAL_2,  VAL_9, VAL_7, VAL_8,
   VAL_6, VAL_4, VAL_2,  VAL_9, VAL_7, VAL_8,  VAL_5, VAL_3, VAL_1,
   VAL_9, VAL_7, VAL_8,  VAL_5, VAL_3, VAL_1,  VAL_6, VAL_4, VAL_2
};

Cell* puzzles[MAX_NUM_PUZZLE] =
{
   puzzleUnsolved,
   puzzleSolved,
   puzzleInvalid,
   puzzleInvalidAtIndex80,
   puzzleUnsolvable,
   puzzleAllZeroes,
   puzzleAllZeroesSolved
};

Cell* getPuzzle(e_Puzzle puzzleIndex)
{
   return puzzles[puzzleIndex];
}