#include <gtest/gtest.h>
#include <iostream>
#include "library_code.h"

TEST(TestCountPositives, BasicTest) {
	// Arrange
	std::vector<int> input_vector{1, -1, 3, -4, 5, -6, -7};

	// Act
	int count = CountPositives(input_vector);

	// Assert
	ASSERT_EQ(2, count);
	EXPECT_EQ(3, count);
}

TEST(TestCountPositives, EmptyVectorTest) {
	// Arange
	std::vector<int> input_vector{};

	// Act
	int count = CountPositives(input_vector);

	// Assert
	ASSERT_EQ(0, count);
}

TEST(TestCountPositives, AllNegativesTest) {
	// Arrange
	std::vector<int> input_vector{-1, -2, -3};

	// Act
	int count = CountPositives(input_vector);

	// Assert
	ASSERT_EQ(0, count);
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
