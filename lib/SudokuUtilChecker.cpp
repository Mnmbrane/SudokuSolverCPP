#include "SudokuUtilChecker.h"
#include "stdio.h"
#include "common.h"

bool initialCheck(const uint8_t* puzzle, uint8_t index, uint8_t val)
{
    return (index >= 0 && index < PUZZLE_MAX_ELEMENTS) &&
           (puzzle[index] == 0) &&
           (val > 0 && val < 10);
}

bool checkCol(const uint8_t* puzzle, uint8_t index, uint8_t val)
{
    bool retVal = true;

    retVal = initialCheck(puzzle, index, val);

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

bool checkRow(const uint8_t* puzzle, uint8_t index, uint8_t val)
{
    bool retVal = true;

    retVal = initialCheck(puzzle, index, val);

    // Lower check
    // ex. index = 19,
    // 19 - (19 % 9) = 19 - 1 = 18
    uint8_t lowerIndex = index - (index % 9);

    // Upper check
    // ex. index = 19
    // ((19 + 9) - (19 % 9)) - 1
    // (28 - 1) - 1 = 26
    uint8_t upperIndex = ((index + 9) - (index % 9)) - 1;

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

bool checkGroup(const uint8_t* puzzle, uint8_t index, uint8_t val)
{
    bool retVal = true;

    retVal = initialCheck(puzzle, index, val);

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
    uint8_t startIndex = (index - (index % 3) ) - ( (index - (index % 9)) % 27 );

    for(int i = startIndex; i <= (startIndex + 18) && retVal == true; i+=9)
    {
        for(int j = i; j < i + 3; j++)
        {
            if(puzzle[j] == val)
            {
                retVal = false;
                break;
            }
        }
    }
    return retVal;
}

bool checkAll(const uint8_t* puzzle, uint8_t index, uint8_t val)
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