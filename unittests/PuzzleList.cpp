#include "PuzzleList.h"

using namespace Sudoku;

ValType VAL_0 = VAL_UNMARKED; 

// 1
ValType puzzleUnsolved[] =
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


ValType puzzleSolved[] =
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

ValType VAL_10 = (ValType)10; 
ValType puzzleInvalid[] =
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

ValType puzzleInvalidAtIndex80[] =
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

PuzzlePtrType puzzles[MAX_NUM_PUZZLE] =
{
   puzzleUnsolved,
   puzzleSolved,
   puzzleInvalid,
   puzzleInvalidAtIndex80
};

PuzzlePtrType getPuzzle(e_Puzzle puzzleIndex)
{
   return puzzles[puzzleIndex];
}