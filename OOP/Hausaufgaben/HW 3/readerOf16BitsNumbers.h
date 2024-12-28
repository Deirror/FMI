#pragma once
#include "Pair.hpp"
#include <fstream>

Pair<uint16_t, uint16_t> read16BitsNumbers(std::ifstream& ifs);
