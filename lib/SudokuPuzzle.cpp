#include "SudokuPuzzle.h"
#include "SudokuUtilChecker.h"
#include "SudokuCoord.h"

#include "string.h"
#include "stdio.h"

namespace Sudoku
{
SudokuPuzzle::SudokuPuzzle() :
   initFlag(false)
{
   resetPuzzle();
}

SudokuPuzzle::~SudokuPuzzle()
{
   resetPuzzle();
   initFlag = false;
}

void SudokuPuzzle::resetPuzzle()
{
   unmarkedCoordList.clear();
   memset(m_puzzle, 0, sizeof(m_puzzle));
}

// Getters
const std::vector<SudokuCoord> SudokuPuzzle::getUnmarkedCoords() const
{
   return unmarkedCoordList;
}


ValType SudokuPuzzle::getValAt(const SudokuCoord& coord)
{
   if(!initFlag)
   {
      return VAL_0;
   }

   return m_puzzle[coord.getIndex()];
}

bool SudokuPuzzle::isPuzzleInit()
{
   return initFlag;
}

// setters
bool SudokuPuzzle::setValAt(const SudokuCoord& coord, ValType val)
{
   if(!initFlag)
   {
      return false;
   }
   SudokuIndex index = coord.getIndex();
   if(checkAll(m_puzzle, index, val) == false)
   {
      m_puzzle[index] = VAL_0;
      return false;
   }
   else
   {
       m_puzzle[index] = val;
       return true;
   }
}

bool SudokuPuzzle::initPuzzle(PuzzlePtrType inPuzzle)
{
   // Check Validity of the puzzle
   for(Sudoku::SudokuIndex i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      bool checkInPuzzle = checkAll(inPuzzle, i, inPuzzle[i]);

      //printf("%d %d\n", inPuzzle[i], checkInPuzzle);
      // Ignore 0's since we are init, check the rest
      if(inPuzzle[i] != 0 && checkInPuzzle == false)
      {
         // Don't do anything just return false
         // Still used the puzzle from before
         return false;
      }
   }

   // Clear everything out
   resetPuzzle();
   // Passes the validity test, set everything up
   for(Sudoku::SudokuIndex i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      // If it's a 0 this means it's unmarked
      if(inPuzzle[i] == 0)
      {
         SudokuCoord unmarkedCoord(i);

         // Add to the list
         unmarkedCoordList.push_back(unmarkedCoord);
         m_puzzle[i] = VAL_0;
      }

      m_puzzle[i] = inPuzzle[i];
   }


   initFlag = true;

   return true;
}
}

