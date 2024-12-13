#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include "library_code.h"

TEST(AccountTest, TestEmptyAccount) {
	Account account;
	double balance = account.balance();

	ASSERT_EQ(0, balance);
	ASSERT_LE(0, balance);
}

TEST(AccountTest, TestDeposit) {
	Account account;

	account.Deposit(10.5);

	ASSERT_EQ(10.5, account.balance());
}

TEST(AccountTest, TestWithdrawOK) {
	Account account;
	account.Deposit(10.5);
	account.Withdraw(3);

	ASSERT_EQ(7.5, account.balance());
}

TEST(AccountTest, TestWithInsufficientFunds) {
	Account account;
	account.Deposit(10.5);

	ASSERT_THROW(account.Withdraw(300), std::runtime_error);
}

TEST(AccountTest, TestTransferOK) {
	Account account;
	account.Deposit(10.5);

	Account to;
	account.Transfer(to, 2);

	ASSERT_EQ(8.5, account.balance());
	ASSERT_EQ(2, to.balance());
}

TEST(AccountTest, TestTransferInsufficientFunds) {
	Account account;
	account.Deposit(10.5);

	Account to;

	ASSERT_THROW(account.Transfer(to, 200), std::runtime_error);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
