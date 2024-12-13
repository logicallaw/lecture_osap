#include "library_code.h"

#include <algorithm>
#include <iostream>

bool IsPositive(int input) { return input >= 0; }

int CountPositives(std::vector<int> const &input_vector) {
	return std::count_if(input_vector.begin(), input_vector.end(), IsPositive);
}
