#include "library_code.h"
#include <iostream>

Account::Account() : balance_{0} {}

void Account::Deposit(double sum) { balance_ += sum; }

void Account::Withdraw(double sum) {
	if (balance_ < sum) {
		throw std::runtime_error("Insufficient funds");
	}
	balance_ -= sum;
}

double Account::balance() const { return balance_; }

void Account::Transfer(Account &to, double sum) {
	Withdraw(sum);
	to.Deposit(sum);
}
