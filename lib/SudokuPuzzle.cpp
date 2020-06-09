#include "SudokuPuzzle.h"
#include "SudokuCoord.h"

#include "string.h"
#include "stdio.h"

using namespace Sudoku;

Puzzle::Puzzle() :
   initFlag(false)
{
   resetPuzzle();
}

Puzzle::~Puzzle()
{
   resetPuzzle();
   initFlag = false;
}

void Puzzle::resetPuzzle()
{
   unmarkedCoordList.clear();
   memset(m_puzzle, 0, sizeof(m_puzzle));
}

// Getters
const std::vector<Coord> Puzzle::getUnmarkedCoords() const
{
   return unmarkedCoordList;
}


ValType Puzzle::getValAt(const Coord& coord) const
{
   if(!initFlag)
   {
      return VAL_UNMARKED;
   }

   return m_puzzle[coord.getIndex()];
}

bool Puzzle::isPuzzleInit()
{
   return initFlag;
}

// setters
bool Puzzle::setValAt(const Coord& coord, ValType val)
{
   if(!initFlag)
   {
      return false;
   }
   Index index = coord.getIndex();
   if(checkAll(m_puzzle, index, val) == false)
   {
      m_puzzle[index] = VAL_UNMARKED;
      return false;
   }
   else
   {
       m_puzzle[index] = val;
       return true;
   }
}

bool Puzzle::initPuzzle(PuzzlePtrType inPuzzle)
{
   // Check Validity of the puzzle
   for(Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
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
   for(Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
    {
        // If it's a 0 this means it's unmarked
        if(inPuzzle[i] == 0)
        {
            Coord unmarkedCoord(i);

            // Add to the list
            unmarkedCoordList.push_back(unmarkedCoord);
            m_puzzle[i] = VAL_UNMARKED;
        }

        m_puzzle[i] = inPuzzle[i];
   }


   initFlag = true;

   return true;
}

// Private functions //

bool Puzzle::initialCheck(Index index, ValType val)
{
    return (index >= 0 && index <= PUZZLE_MAX_INDEX) &&
           (val > VAL_UNMARKED && val < VAL_MAX);
}

bool Puzzle::checkCol(const PuzzlePtrType puzzle, Index index, ValType val)
{
    bool retVal = true;
    Index saveIndex = index;

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

bool Puzzle::checkRow(const PuzzlePtrType puzzle, Index index, ValType val)
{
    bool retVal = true;
    Index saveIndex = index;

    retVal = initialCheck(index, val);


    // Lower check
    // ex. index = 19,
    // 19 - (19 % 9) = 19 - 1 = 18
    Index lowerIndex = index - (index % 9);

    // Upper check
    // ex. index = 19
    // ((19 + 9) - (19 % 9)) - 1
    // (28 - 1) - 1 = 26
    Index upperIndex = ((index + 9) - (index % 9)) - 1;

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

bool Puzzle::checkGroup(const PuzzlePtrType puzzle, Index index, ValType val)
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
    Index startIndex = (index - (index % 3) ) - ( (index - (index % 9)) % 27 );

    for(Index i = startIndex; i <= (startIndex + 18) && retVal == true; i+=9)
    {
        for(Index j = i; j < i + 3; j++)
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

bool Puzzle::checkAll(const PuzzlePtrType puzzle, Index index, ValType val)
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

bool operator==(const Sudoku::Puzzle& lhs, const Sudoku::Puzzle& rhs)
{
    bool retBool = true;
    for(Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX && retBool==true; i++)
    {
        retBool = lhs.getValAt(i) == rhs.getValAt(i);
    }
    return retBool;
}