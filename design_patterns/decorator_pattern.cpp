#include <iostream>
#include <string>
using namespace std;

class Toast {
public:
  virtual string getName() const = 0;
  virtual int getKcal() const = 0;
};

class NormalBread : public Toast {
public:
  string getName() const override { return " 식빵 토스트"; }

  int getKcal() const override { return 300; }
};

class WheatBread : public Toast {
public:
  string getName() const override { return " 호밀식빵 토스트"; }

  int getKcal() const override { return 250; }
};

class ButterBread : public Toast {
public:
  string getName() const override { return " 버터식빵 토스트"; }

  int getKcal() const override { return 400; }
};

class MilkBread : public Toast {
public:
  string getName() const override { return " 우유식빵 토스트"; }

  int getKcal() const override { return 350; }
};

class ToppingDecorator : public Toast {
public:
  ToppingDecorator(Toast *toast) : toast_(toast) {}

  string getName() const override { // 생략 가능
    return toast_->getName();
  }

  int getKcal() const override { // 생략 가능
    return toast_->getKcal();
  }

protected:
  Toast *toast_;
};

class Ham : public ToppingDecorator {
public:
  Ham(Toast *toast) : ToppingDecorator(toast) {}

  string getName() const override { return "햄" + toast_->getName(); }

  int getKcal() const override { return toast_->getKcal() + 200; }
};

class Vegetable : public ToppingDecorator {
public:
  Vegetable(Toast *toast) : ToppingDecorator(toast) {}

  string getName() const override { return "야채" + toast_->getName(); }

  int getKcal() const override { return toast_->getKcal() + 10; }
};

class Cheese : public ToppingDecorator {
public:
  Cheese(Toast *toast) : ToppingDecorator(toast) {}

  string getName() const override { return "치즈" + toast_->getName(); }

  int getKcal() const override { return toast_->getKcal() + 50; }
};

class Egg : public ToppingDecorator {
public:
  Egg(Toast *toast) : ToppingDecorator(toast) {}

  string getName() const override { return "달걀" + toast_->getName(); }

  int getKcal() const override { return toast_->getKcal() + 100; }
};

int main() {
  Toast *toast1 = new NormalBread();
  toast1 = new Cheese(toast1);
  toast1 = new Ham(toast1);
  cout << "주문한 토스트: " << toast1->getName() << endl;
  cout << "칼로리: " << toast1->getKcal() << " Kcal\n" << endl;
  delete toast1;

  Toast *toast2 = new WheatBread();
  toast2 = new Vegetable(toast2);
  toast2 = new Egg(toast2);
  cout << "주문한 토스트: " << toast2->getName() << endl;
  cout << "칼로리: " << toast2->getKcal() << " Kcal\n" << endl;
  delete toast2;

  Toast *toast3 = new ButterBread();
  toast3 = new Ham(toast3);
  toast3 = new Ham(toast3);
  toast3 = new Ham(toast3);
  cout << "주문한 토스트: " << toast3->getName() << endl;
  cout << "칼로리: " << toast3->getKcal() << " Kcal\n" << endl;
  delete toast3;

  return 0;
}