#include "SudokuPuzzle.h"
#include "SudokuCoord.h"

#include "string.h"
#include <stdio.h>

using namespace Sudoku;

Puzzle::Puzzle() : initFlag(false)
{
   resetPuzzle();
}

Puzzle::Puzzle(const Puzzle &puzzle)
{
   resetPuzzle();
   for (Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      m_puzzle[i].setVal(puzzle.getValAt(i));
   }
}

Puzzle::~Puzzle()
{
   resetPuzzle();
}

void Puzzle::resetPuzzle()
{
   for (Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      m_puzzle[i].setVal(VAL_UNMARKED);
   }
   initFlag = false;
}

bool Puzzle::checkPuzzleValidity(Cell *inPuzzle)
{
   // Check Validity of the puzzle
   for (Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      bool checkInPuzzle = checkAll(inPuzzle, i, inPuzzle[i].getVal());

      //printf("%d %d\n", inPuzzle[i], checkInPuzzle);
      // Ignore 0's since we are init, check the rest
      if (checkInPuzzle == false)
      {
         // If we are initializing and the value is 0 then return true
         if (initFlag == false && inPuzzle[i].getVal() == VAL_UNMARKED)
         {
            return true;
         }
         else
         {
            // Don't do anything just return false
            // Still used the puzzle from before
            return false;
         }
      }
   }
   return true;
}

void Puzzle::setPuzzle(Cell *inPuzzle)
{
   // Clear everything out
   resetPuzzle();
   // Passes the validity test, set everything up
   for (Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      m_puzzle[i] = inPuzzle[i];
   }
}

bool Puzzle::initPuzzle(Cell *inPuzzle)
{
   if (checkPuzzleValidity(inPuzzle) == true)
   {
      // Set the puzzle to in Puzzle
      setPuzzle(inPuzzle);
      initFlag = true;
      return true;
   }
   else
   {
      return false;
   }
}

ValType Puzzle::getValAt(const Coord &coord) const
{
   return m_puzzle[coord.getIndex()].getVal();
}

CandidateSetType Puzzle::getCandidateAt(const Coord &coord) const
{
   return m_puzzle[coord.getIndex()].getCandidates();
}

bool Puzzle::isPuzzleInit()
{
   return initFlag;
}

bool Puzzle::isMarkedAt(const Coord &coord)
{
   return m_puzzle[coord.getIndex()].isMarked();
}

// setters
bool Puzzle::setValAt(const Coord &coord, ValType val)
{
   if (!initFlag)
   {
      return false;
   }
   else if (val == VAL_UNMARKED)
   {
      m_puzzle[coord.getIndex()] = val;
      return true;
   }
   else if (checkAll(m_puzzle, coord.getIndex(), val) == false)
   {
      return false;
   }
   else
   {
      m_puzzle[coord.getIndex()] = val;
      return true;
   }
}

void Puzzle::deleteCandidateAt(const Coord &coord, ValType val)
{
   m_puzzle[coord.getIndex()].deleteCandidate(val);
}

void Puzzle::printPuzzle() const
{
   for (Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX; i++)
   {
      Coord coord(i);

      if (coord.getCol() == COL_0)
      {
         printf("\n");
         if (coord.getRow() == ROW_3 || coord.getRow() == ROW_6)
         {
            printf("\n");
         }
      }
      else if (coord.getCol() == COL_3 || coord.getCol() == COL_6)
      {
         printf("|");
      }

      printf("%d ", m_puzzle[i].getVal());
   }
   printf("\n\n");
}

// Private functions //

bool Puzzle::initialCheck(Index index, ValType val)
{
   return (index >= 0 && index <= PUZZLE_MAX_INDEX) &&
          (val >= VAL_1 && val <= VAL_9);
}

bool Puzzle::checkCol(Cell *inPuzzle, Index index, ValType val)
{
   bool retVal = true;
   Index saveIndex = index;

   retVal = initialCheck(index, val);

   // Check Above
   // Subtract by 9 to go up
   while ((index - 9) >= 0 && retVal == true)
   {
      index -= 9;
      // If  there is a match
      // value is invalid
      if (val == inPuzzle[index].getVal())
      {
         retVal = false;
      }
   }

   index = saveIndex;
   // Check down
   // Add by 9 to go down
   while ((index + 9) <= PUZZLE_MAX_INDEX && retVal == true)
   {
      index += 9;
      // If  there is a match
      // value is invalid
      if (val == inPuzzle[index].getVal())
      {
         retVal = false;
      }
   }

   return retVal;
}

bool Puzzle::checkRow(Cell *inPuzzle, Index index, ValType val)
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
   while ((index - 1) >= lowerIndex && retVal == true)
   {
      --index;
      // If  there is a match
      // value is invalid
      if (val == inPuzzle[index].getVal())
      {
         retVal = false;
      }
   }

   index = saveIndex;
   // Check down
   // Add by 1 to go right
   while ((index + 1) <= upperIndex && retVal == true)
   {
      ++index;

      // If  there is a match
      // value is invalid
      if (val == inPuzzle[index].getVal())
      {
         retVal = false;
      }
   }
   return retVal;
}

bool Puzzle::checkGroup(Cell *inPuzzle, Index index, ValType val)
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
   Index startIndex = (index - (index % 3)) - ((index - (index % 9)) % 27);

   for (Index i = startIndex; i <= (startIndex + 18) && retVal == true; i += 9)
   {
      for (Index j = i; j < i + 3; j++)
      {
         if (j != index && inPuzzle[j].getVal() == val)
         {
            retVal = false;
            break;
         }
      }
   }
   return retVal;
}

bool Puzzle::checkAll(Cell *inPuzzle, Index index, ValType val)
{
   if (checkCol(inPuzzle, index, val) &&
       checkRow(inPuzzle, index, val) &&
       checkGroup(inPuzzle, index, val))
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Puzzle::operator==(const Sudoku::Puzzle &rhs)
{
   bool retBool = true;
   for (Sudoku::Index i = 0; i <= PUZZLE_MAX_INDEX && retBool == true; i++)
   {
      retBool = this->getValAt(i) == rhs.getValAt(i);
   }
   return retBool;
}
