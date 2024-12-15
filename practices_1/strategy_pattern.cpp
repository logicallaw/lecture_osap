#include <iostream>
using namespace std;

class Attack {
public:
	virtual void motion() = 0;
};

class Sing : public Attack {
public:
	void motion() override { cout << "���� ��ų - �뷡�ϱ�: �뷡�� �ҷ� ��븦 �����\n"; }
};

class Flame : public Attack {
public:
	void motion() override { cout << "���� ��ų - �Ҳ�: �߰ſ� �Ҳ��� ��� ����\n"; }
};

class Passive {
public:
	virtual void detail() = 0;
};

class Defensibility : public Passive {
public:
	void detail() override { cout << "�нú� ��ų - ���: �޴� ���� 40% ���ҽ�Ŵ\n"; }
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
	void name() { cout << "�̸�: ���̸�, �Ӽ�: ��\n"; }
};
int main(void) {
	Pokemon *pairi = new Pairi();
	pairi->introduce();
}
