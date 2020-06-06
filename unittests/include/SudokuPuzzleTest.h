#pragma once

#include "googletest/include/gtest/gtest.h"
#include "SudokuUtilChecker.h"

class PhraseTest : public ::testing::Test
{
protected:
    phraseClass * myPhrase1;
    phraseClass * myPhrase2;
    virtual void SetUp()
    {      
        myPhrase1 = new createPhrase("1234567890");
        myPhrase2 = new createPhrase("1234567890");  
    }

    virtual void TearDown()
    {
        delete myPhrase1;
        delete myPhrase2;  
    }
};