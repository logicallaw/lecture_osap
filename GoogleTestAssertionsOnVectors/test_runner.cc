#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "library_code.h"
// 0, 1, 2, 0, 1
TEST(VectorMatchers, Example) {
	std::vector<int> v = {0, 1, 2, 0, 1};

	// 1. ��� ��Ұ� -1���� ũ�� 3���� ������ Ȯ��
	EXPECT_THAT(v, testing::Each(testing::AllOf(testing::Gt(-1), testing::Lt(3)))); // Each ���

	// 2. ���Ͱ� Ư�� ��Ҹ� �����ϴ��� Ȯ��
	EXPECT_THAT(v, testing::Contains(2));

	// 3. ������ ��� ��Ұ� Ư�� ������� �ִ��� Ȯ��
	EXPECT_THAT(v, testing::ElementsAre(0, 1, 2, 0, 1));
}

TEST(ContainerMatchers, CheckSize) {
	std::vector<std::string> words = {"hello", "world", "test"};
	EXPECT_THAT(words, testing::SizeIs(3));
	EXPECT_THAT(words, testing::Not(testing::IsEmpty()));
}

TEST(ContainerMatchers, CheckOrder) {
	std::vector<int> numbers = {5, 3, 1, 4, 2};

	// 1. ������ ���ҵ��� [1, 2, 3, 4, 5]�� ��Ȯ�� ���� �������� Ȯ���ϼ���.
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
