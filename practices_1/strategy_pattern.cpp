#include <iostream>
using namespace std;

class Attack {
public:
	virtual void motion() = 0;
};

class Sing : public Attack {
public:
	void motion() override { cout << "공격 스킬 - 노래하기: 노래를 불러 상대를 잠재움\n"; }
};

class Flame : public Attack {
public:
	void motion() override { cout << "공격 스킬 - 불꽃: 뜨거운 불꽃을 쏘아 공격\n"; }
};

class Passive {
public:
	virtual void detail() = 0;
};

class Defensibility : public Passive {
public:
	void detail() override { cout << "패시브 스킬 - 방어: 받는 피해 40% 감소시킴\n"; }
};

class Pokemon {
public:
	Attack *attack;
	Passive *passive;
	Pokemon() {}

	void introduce() {
		name();
		attack->motion();
		passive->detail();
	}

	virtual void name() {}
	void setAttack(Attack *attack) { this->attack = attack; }
};

class Pairi : public Pokemon {
public:
	Pairi() {
		attack = new Flame();
		passive = new Defensibility();
	}
	void name() { cout << "이름: 파이리, 속성: 불\n"; }
};
int main(void) {
	Pokemon *pairi = new Pairi();
	pairi->introduce();
}
