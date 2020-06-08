#include "PuzzleList.h"

ValType puzzleUnsolved[] =
{
   (ValType)0, (ValType)0, (ValType)0,  (ValType)0, (ValType)0, (ValType)9,  (ValType)0, (ValType)0, (ValType)0,
   (ValType)2, (ValType)8, (ValType)0,  (ValType)3, (ValType)0, (ValType)0,  (ValType)1, (ValType)0, (ValType)5,
   (ValType)3, (ValType)0, (ValType)5,  (ValType)0, (ValType)8, (ValType)0,  (ValType)7, (ValType)4, (ValType)6,

   (ValType)7, (ValType)0, (ValType)0,  (ValType)0, (ValType)0, (ValType)0,  (ValType)0, (ValType)6, (ValType)0,
   (ValType)0, (ValType)3, (ValType)0,  (ValType)4, (ValType)2, (ValType)7,  (ValType)0, (ValType)8, (ValType)0,
   (ValType)0, (ValType)2, (ValType)0,  (ValType)0, (ValType)0, (ValType)0,  (ValType)0, (ValType)0, (ValType)7,

   (ValType)8, (ValType)1, (ValType)3,  (ValType)0, (ValType)5, (ValType)0,  (ValType)6, (ValType)0, (ValType)2,
   (ValType)5, (ValType)0, (ValType)9,  (ValType)0, (ValType)0, (ValType)2,  (ValType)0, (ValType)1, (ValType)8,
   (ValType)0, (ValType)0, (ValType)0,  (ValType)8, (ValType)0, (ValType)0,  (ValType)0, (ValType)0, (ValType)0
};

ValType puzzleSolved[] =
{
   (ValType)8, (ValType)2, (ValType)7,  (ValType)1, (ValType)5, (ValType)4,  (ValType)3, (ValType)9, (ValType)6,
   (ValType)9, (ValType)6, (ValType)5,  (ValType)3, (ValType)2, (ValType)7,  (ValType)1, (ValType)4, (ValType)8,
   (ValType)3, (ValType)4, (ValType)1,  (ValType)6, (ValType)8, (ValType)9,  (ValType)7, (ValType)5, (ValType)2,

   (ValType)5, (ValType)9, (ValType)3,  (ValType)4, (ValType)6, (ValType)8,  (ValType)2, (ValType)7, (ValType)1,
   (ValType)4, (ValType)7, (ValType)2,  (ValType)5, (ValType)1, (ValType)3,  (ValType)6, (ValType)8, (ValType)9,
   (ValType)6, (ValType)1, (ValType)8,  (ValType)9, (ValType)7, (ValType)2,  (ValType)4, (ValType)3, (ValType)5,

   (ValType)7, (ValType)8, (ValType)6,  (ValType)2, (ValType)3, (ValType)5,  (ValType)9, (ValType)1, (ValType)4,
   (ValType)1, (ValType)5, (ValType)4,  (ValType)7, (ValType)9, (ValType)6,  (ValType)8, (ValType)2, (ValType)3,
   (ValType)2, (ValType)3, (ValType)9,  (ValType)8, (ValType)4, (ValType)1,  (ValType)5, (ValType)6, (ValType)7
};

ValType puzzleInvalid[] =
{
   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,
   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,
   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,

   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,
   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,
   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,

   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,
   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,
   (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10,  (ValType)10, (ValType)10, (ValType)10
};

ValType puzzleInvalidAtIndex80[] =
{
   (ValType)8, (ValType)2, (ValType)7,  (ValType)1, (ValType)5, (ValType)4,  (ValType)3, (ValType)9, (ValType)6,
   (ValType)9, (ValType)6, (ValType)5,  (ValType)3, (ValType)2, (ValType)7,  (ValType)1, (ValType)4, (ValType)8,
   (ValType)3, (ValType)4, (ValType)1,  (ValType)6, (ValType)8, (ValType)9,  (ValType)7, (ValType)5, (ValType)2,

   (ValType)5, (ValType)9, (ValType)3,  (ValType)4, (ValType)6, (ValType)8,  (ValType)2, (ValType)7, (ValType)1,
   (ValType)4, (ValType)7, (ValType)2,  (ValType)5, (ValType)1, (ValType)3,  (ValType)6, (ValType)8, (ValType)9,
   (ValType)6, (ValType)1, (ValType)8,  (ValType)9, (ValType)7, (ValType)2,  (ValType)4, (ValType)3, (ValType)5,

   (ValType)7, (ValType)8, (ValType)6,  (ValType)2, (ValType)3, (ValType)5,  (ValType)9, (ValType)1, (ValType)4,
   (ValType)1, (ValType)5, (ValType)4,  (ValType)7, (ValType)9, (ValType)6,  (ValType)8, (ValType)2, (ValType)3,
   (ValType)2, (ValType)3, (ValType)9,  (ValType)8, (ValType)4, (ValType)1,  (ValType)5, (ValType)6, (ValType)8
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