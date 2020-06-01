#pragma once
#include "stdint.h"


bool checkCol(const uint8_t* puzzle, uint8_t index, uint8_t val);
bool checkRow(const uint8_t* puzzle, uint8_t index, uint8_t val);
bool checkGroup(const uint8_t* puzzle, uint8_t index, uint8_t val);
