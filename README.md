# SudokuSolverCPP

Need GNU make to make use of make files.

This Solver uses a pipelining system to pass on the Sudoku puzzle to various Sudoku Algorithms. Solve Algorithms will need to be placed under /lib/SolveAlgorithm and added to the Makefile SRC list. Add the instantiation into the constructAlgoPipeline() methon in the Solver class.

My goal is to implement various Solve Algorithms(Naked 1s, Hidden 1s, Naked twins...) to add into the pipeline. If all else fails the very last algorithm in the pipeline is the complete search Iterative Backtrack algorithm.

The data structure used for this is a Linked List. Once the List has been made, start with the first algorithm(ex. Naked 1s), if it found unmarked places it could solve, then restart the entire list again. Our place in the pipeline will only move forward if and only if, no solves were made in the current algorithm.
 
The Iterative Backtrack will be the last algorithm as it is the complete search of the entire puzzle. This algorithm will be last because it's a very slow algorithm, but 100% reliable
 
 Example:
    START->Naked 1s->Hidden 1s->Iterative Backtrack->SOLVED

This pipeline will grow as more and more algorithms are implemented.