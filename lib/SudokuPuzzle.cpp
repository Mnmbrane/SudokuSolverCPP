#include "SudokuPuzzle.h"
#include "SudokuUtilChecker.h"
#include "SudokuCoord.h"

#include "string.h"
#include "stdio.h"

using namespace Sudoku;

SudokuPuzzle::SudokuPuzzle() :
   initFlag(false)
{
   resetPuzzle();
}

void SudokuPuzzle::resetPuzzle()
{
   unmarkedCoordList.clear();
   memset(m_puzzle, 0, sizeof(m_puzzle));
}

const std::vector<SudokuCoord> SudokuPuzzle::getUnmarkedCoords() const
{
   return unmarkedCoordList;
}

// getters
ValType SudokuPuzzle::getValAt(SudokuCoord coord)
{
   if(!initFlag)
   {
      return VAL_0;
   }

   return m_puzzle[coord.getIndex()];
}

// setters
bool SudokuPuzzle::setValAt(SudokuCoord coord, ValType val)
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
   for(uint8_t i = 0; i < PUZZLE_MAX_ELEMENTS; i++)
   {
      // If it's a 0 this means it's unmarked
      if(inPuzzle[i] == 0)
      {
         SudokuCoord unmarkedCoord(i);

         // Add to the list
         unmarkedCoordList.push_back(unmarkedCoord);
         m_puzzle[i] = VAL_0;
      }
      else if(checkAll(m_puzzle, i, inPuzzle[i]) == false)
      {
         resetPuzzle();
         return false;
      }
   }

   initFlag = true;

   return true;
}