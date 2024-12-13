class Account {
public:
	Account();
	void Deposit(double sum);
	void Withdraw(double sum);
	double balance() const;
	void Transfer(Account &to, double sum);

private:
	double balance_;
};
