#include <iostream>
#include <string>
using namespace std;
/*
Pure virtual function이 하나라도 있으면
그 클래스는 인스턴스화 불가능한 Abstract class이다.
*/

class ToppingDecorator {
public:
	virtual string Name() const = 0;
	virtual int Kcal() const = 0;
};

class Toast {
public:
	string name;
	int kcal;

	Toast() : name(""), kcal(0) {}

	virtual void serve() {
		getName();
		getKcal();
	}

	void getName() const { cout << "주문한 토스트:" << name << endl; }

	void getKcal() const { cout << "칼로리:" << kcal << "Kcal\n" << endl; }

	void addTopping(ToppingDecorator *td) {
		addName(td->Name());
		addKcal(td->Kcal());
	}

	void addName(const string &n) { name = n + name; }

	void addKcal(int k) { kcal += k; }
};

class NormalBread : public Toast {
public:
	NormalBread() {
		name = "식빵 토스트";
		addKcal(300);
	}
};

class WheatBread : public Toast {
public:
	WheatBread() {
		name = "호밀식빵 토스트";
		addKcal(250);
	}
};

class ButterBread : public Toast {
public:
	ButterBread() {
		name = "버터식빵 토스트";
		addKcal(400);
	}
};

class MilkBread : public Toast {
public:
	MilkBread() {
		name = "우유식빵 토스트";
		addKcal(350);
	}
};

class Ham : public ToppingDecorator {
public:
	string Name() const override { return "햄"; }

	int Kcal() const override { return 200; }
};

class Vegetable : public ToppingDecorator {
public:
	string Name() const override { return "야채"; }

	int Kcal() const override { return 10; }
};

class Cheese : public ToppingDecorator {
public:
	string Name() const override { return "치즈"; }

	int Kcal() const override { return 50; }
};

class Egg : public ToppingDecorator {
public:
	string Name() const override { return "달걀"; }

	int Kcal() const override { return 100; }
};

int main(void) {
	Toast *toast1 = new NormalBread();
	toast1->addTopping(new Cheese());
	toast1->addTopping(new Ham());
	toast1->serve();
	delete toast1;

	Toast *toast2 = new WheatBread();
	toast2->addTopping(new Vegetable());
	toast2->addTopping(new Egg());
	toast2->serve();
	delete toast2;

	Toast *toast3 = new ButterBread();
	toast3->addTopping(new Ham());
	toast3->addTopping(new Ham());
	toast3->addTopping(new Ham());
	toast3->serve();
	delete toast3;

	return 0;
}
