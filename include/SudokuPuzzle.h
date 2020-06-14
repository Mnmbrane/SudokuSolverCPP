#pragma once

#include <stdint.h>
#include "SudokuCommonTypes.h"
#include "SudokuCell.h"

class Sudoku::Puzzle
{
public:

   Puzzle();
   Puzzle(const Puzzle& puzzle);
   ~Puzzle();

   void resetPuzzle();

   // getters
   ValType getValAt(const Coord& coord) const;

   CandidateSetType getCandidateAt(const Coord& coord) const;

   bool isPuzzleInit();
   bool isMarkedAt(const Coord& coord) const;

   // setters
   bool setValAt(const Coord& coord, ValType val);

   void deleteCandidateAt(const Coord& coord, ValType vals);

   bool initPuzzle(Cell* inPuzzle);

   void printPuzzle() const;

   bool checkAll(Cell* puzzle, Index index, ValType val);

   bool checkPuzzleValidity(Cell* inPuzzle = nullptr);

   bool operator==(const Puzzle& rhs);

private:

   void setPuzzle(Cell* inPuzzle);
   // Checker
   bool initialCheck(Index index, ValType val);
   bool checkCol(Cell* puzzle, Index index, ValType val);
   bool checkRow(Cell* puzzle, Index index, ValType val);
   bool checkGroup(Cell* puzzle, Index index, ValType val);
   
   bool initFlag;
   
   // The puzzle in array format
   Cell m_puzzle[PUZZLE_MAX_ELEMENTS];
};