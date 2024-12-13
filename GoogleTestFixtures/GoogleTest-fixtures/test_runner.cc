#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include "library_code.h"

TEST(AccountTest, TestEmptyAccount) {
	Account account;

	double balance = account.balance();
	ASSERT_EQ(0, balance);
}

class AccountTestFixture : public testing::Test {
public:
	AccountTestFixture();
	virtual ~AccountTestFixture();
	void SetUp() override;
	void TearDown() override;
	static void SetUpTestCase();
	static void TearDownTestCase();

protected:
	Account account_;
};

AccountTestFixture::AccountTestFixture() { std::cout << "Constructor called\n"; }

AccountTestFixture::~AccountTestFixture() { std::cout << "Destructor called\n"; }

void AccountTestFixture::SetUpTestCase() { std::cout << "SetUpTestCase called\n"; }

void AccountTestFixture::TearDownTestCase() { std::cout << "TearDownTestCase called\n"; }

void AccountTestFixture::SetUp() {
	std::cout << "SetUp called\n";
	account_.Deposit(10.5);
}

void AccountTestFixture::TearDown() { std::cout << "TearDown called\n"; }

TEST_F(AccountTestFixture, TestDeposit) {
	std::cout << "Test body\n";
	ASSERT_EQ(10.5, account_.balance());
}
TEST_F(AccountTestFixture, TestWithdrawOK) {
	account_.Withdraw(3);
	ASSERT_EQ(7.5, account_.balance());
}

TEST_F(AccountTestFixture, TestWithdrawInsufficientFunds) { ASSERT_THROW(account_.Withdraw(300), std::runtime_error); }

TEST_F(AccountTestFixture, TestTransferOK) {
	Account to;

	account_.Transfer(to, 2);

	ASSERT_EQ(8.5, account_.balance());
	ASSERT_EQ(2, to.balance());
}

TEST_F(AccountTestFixture, TestTransferInsufficientFunds) {
	Account to;

	ASSERT_THROW(account_.Transfer(to, 200), std::runtime_error);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
