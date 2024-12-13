#include "library_code.h"

Validator::Validator(int low, int high) : low_{low}, high_{high} {}

bool Validator::InRange(int value_to_test) const { return low_ <= value_to_test && value_to_test <= high_; }
