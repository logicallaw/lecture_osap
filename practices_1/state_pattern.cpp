#include <iostream>
using namespace std;

class EletricFan;

class State {
public:
	virtual void on_button(EletricFan *EF) = 0;
	virtual void off_button(EletricFan *EF) = 0;
};

class Stop : public State {
public:
	Stop() { cout << "\n현재상태:정지\n"; }
	void on_button(EletricFan *EF) override;
	void off_button(EletricFan *EF) override;
};
