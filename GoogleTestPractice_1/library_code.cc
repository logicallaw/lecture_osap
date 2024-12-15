#include "library_code.h"

#include <stdexcept>
#include <vector>

std::vector<int> GenerateNumbers(int n, int limit) {
	std::vector<int> result;
	if (limit <= 0) {
		throw std::runtime_error("Argument must be >= 0");
	}
	for (int i = 0; i < n; i++) {
		result.push_back(i % limit);
	}
	return result;
}
