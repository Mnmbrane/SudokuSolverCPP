#pragma once

// Forward Declare
class SudokuPuzzle;

class AlgorithmInterface
{
protected:
   virtual bool Solve(SudokuPuzzle& puzzle) = 0;
};