#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "library_code.h"

TEST(VectorTests, ElementsAreTest) {
	std::vector<int> v = GenerateNumbers(5, 3);

	ASSERT_THAT(v, testing::ElementsAre(0, 1, 2, 0, 1));
}

TEST(VectorTests, RangeTest) {
	using namespace testing;
	std::vector<int> v = GenerateNumbers(5, 3);

	ASSERT_THAT(v, Each(AllOf(Ge(0), Lt(3))));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
