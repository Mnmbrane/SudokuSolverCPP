#include "SudokuPuzzle.h"
#include "SudokuCoord.h"

#include "string.h"
#include "stdio.h"

using namespace Sudoku;

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

bool SudokuPuzzle::initialCheck(SudokuIndex index, ValType val)
{
    return (index >= 0 && index <= PUZZLE_MAX_INDEX) &&
           (val > VAL_0 && val < VAL_MAX);
}

bool SudokuPuzzle::checkCol(const PuzzlePtrType puzzle, SudokuIndex index, ValType val)
{
    bool retVal = true;
    SudokuIndex saveIndex = index;

    retVal = initialCheck(index, val);

    // Check Above
    // Subtract by 9 to go up
    while( (index - 9) >= 0 && retVal == true )
    {
        index -= 9;
        // If  there is a match
        // value is invalid
        if(val == puzzle[index])
        {
            retVal = false;
        }
    }

    index = saveIndex;
    // Check down
    // Add by 9 to go down
    while( (index + 9) <= PUZZLE_MAX_INDEX && retVal == true )
    {
        index += 9;
        // If  there is a match
        // value is invalid
        if(val == puzzle[index])
        {
            retVal = false;
        }
    }
    return retVal;
}

bool SudokuPuzzle::checkRow(const PuzzlePtrType puzzle, SudokuIndex index, ValType val)
{
    bool retVal = true;
    SudokuIndex saveIndex = index;

    retVal = initialCheck(index, val);


    // Lower check
    // ex. index = 19,
    // 19 - (19 % 9) = 19 - 1 = 18
    SudokuIndex lowerIndex = index - (index % 9);

    // Upper check
    // ex. index = 19
    // ((19 + 9) - (19 % 9)) - 1
    // (28 - 1) - 1 = 26
    SudokuIndex upperIndex = ((index + 9) - (index % 9)) - 1;

    // Check Left
    // Subtract by 1 to left
    while( (index - 1) >= lowerIndex && retVal == true )
    {
        --index;
        // If  there is a match
        // value is invalid
        if(val == puzzle[index])
        {
            retVal = false;
        }
    }

    index = saveIndex;
    // Check down
    // Add by 1 to go right
    while( (index + 1) <= upperIndex && retVal == true )
    {
        ++index;

        // If  there is a match
        // value is invalid
        if(val == puzzle[index])
        {
            retVal = false;
        }
    }
    return retVal;
}

bool SudokuPuzzle::checkGroup(const PuzzlePtrType puzzle, SudokuIndex index, ValType val)
{
    bool retVal = true;

    retVal = initialCheck(index, val);

    // TODO: Move these into description
    // Want to get the top left corner of the 3x3 grouping
    // Get the left most column in group by subtracting
    // index by (index mod 3)
    // Get the very left most column by mod 9
    // Notice that every starting top left number for the
    // 3x3 grouping is away by 27 elements
    // We can get how many spaces needed to get to top
    // left corner of group by modding the "very" left most
    // index by 27
    // and subtract this number from the left column
    // index
    // There may be a better way of doing this using number
    // theory or some other BS, but this is good enough
    // Could also map each index to a 'set', and see if
    // an index is part of that set, refactoring for later 
    // maybe

    // Ex. index = 70, we want 60 as our starting index:
    // (70 - (70 % 3)) - ((70 - ( 70 % 9)) % 27)
    // (70 - 1) - ((70 - 7) % 27)
    // (69) - (63 % 27)
    // 69 - 9 = 60
    // TODO: remove magic numbers
    SudokuIndex startIndex = (index - (index % 3) ) - ( (index - (index % 9)) % 27 );

    for(SudokuIndex i = startIndex; i <= (startIndex + 18) && retVal == true; i+=9)
    {
        for(SudokuIndex j = i; j < i + 3; j++)
        {
            if(j != index && puzzle[j] == val)
            {
                retVal = false;
                break;
            }
        }
    }
    return retVal;
}

bool SudokuPuzzle::checkAll(const PuzzlePtrType puzzle, SudokuIndex index, ValType val)
{
    if(checkCol(puzzle, index, val) &&
       checkRow(puzzle, index, val) &&
       checkGroup(puzzle, index, val))
    {
        return true;
    }
    else
    {
        return false;
    }
}
