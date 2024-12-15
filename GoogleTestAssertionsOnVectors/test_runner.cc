#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "library_code.h"
// 0, 1, 2, 0, 1
TEST(VectorMatchers, Example) {
	std::vector<int> v = {0, 1, 2, 0, 1};

	// 1. 모든 요소가 -1보다 크고 3보다 작은지 확인
	EXPECT_THAT(v, testing::Each(testing::AllOf(testing::Gt(-1), testing::Lt(3)))); // Each 사용

	// 2. 벡터가 특정 요소를 포함하는지 확인
	EXPECT_THAT(v, testing::Contains(2));

	// 3. 벡터의 모든 요소가 특정 순서대로 있는지 확인
	EXPECT_THAT(v, testing::ElementsAre(0, 1, 2, 0, 1));
}

TEST(ContainerMatchers, CheckSize) {
	std::vector<std::string> words = {"hello", "world", "test"};
	EXPECT_THAT(words, testing::SizeIs(3));
	EXPECT_THAT(words, testing::Not(testing::IsEmpty()));
}

TEST(ContainerMatchers, CheckOrder) {
	std::vector<int> numbers = {5, 3, 1, 4, 2};

	// 1. 벡터의 원소들이 [1, 2, 3, 4, 5]와 정확히 같은 순서인지 확인하세요.
	EXPECT_THAT(numbers, testing::ElementsAre(5, 3, 1, 4, 2));

	EXPECT_THAT(numbers, testing::WhenSorted(testing::ElementsAre(1, 2, 3, 4, 5)));
}
TEST(ContainerMatchers, CheckContents) {
	std::vector<int> numbers = {5, 3, 3, 3, 5, 7};
	EXPECT_THAT(numbers, testing::Contains(3));
	EXPECT_THAT(numbers, testing::Contains(3).Times(3));
	EXPECT_THAT(numbers, testing::Not(testing::Each(5)));
}

TEST(ValueMatchers, CheckConditions) {
	int value = 42;
	EXPECT_THAT(value, testing::AllOf(testing::Ge(0), testing::Le(100)));
}


int main(int argc, char **argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
