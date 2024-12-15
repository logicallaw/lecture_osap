#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include "library_code.h"

TEST(ValueMatchers, CheckConditions) {
	int value = 42;
	EXPECT_THAT(value, testing::AllOf(testing::Ge(0), testing::Le(100)));
}
int main(int argc, char **argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
