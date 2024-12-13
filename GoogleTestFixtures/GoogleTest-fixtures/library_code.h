#ifndef LIBRARY_CODE_H_
#define LIBRARY_CODE_H_

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

#endif // LIBRARY_CODE_H_