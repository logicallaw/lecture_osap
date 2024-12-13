#include <iostream>
using namespace std;

class Attack {
public:
    virtual void motion() = 0;
};

class Sing : public Attack {
public:
    void motion() override {
        cout << "���� ��ų - �뷡�ϱ�: �뷡�� �ҷ� ��븦 �����\n";
    }
};

class Flame : public Attack {
public:
    void motion() override {
        cout << "���� ��ų - �Ҳ�: �߰ſ� �Ҳ��� ��� ����\n";
    }
};

class millionVolt : public Attack {
public:
    void motion() override {
        cout << "���� ��ų - �鸸 ��Ʈ: �鸸 ��Ʈ�� ������ �������� ����\n";
    }
};

class Passive {
public:
    virtual void detail() = 0;
};

class Defensibility : public Passive {
public:
    void detail() override {
        cout << "�нú� ��ų - ���: �޴� ���� 40% ���ҽ�Ŵ\n\n";
    }
};

class Avoidability : public Passive {
public:
    void detail() override {
        cout << "�нú� ��ų - ȸ��: 30% Ȯ���� ���� ȸ��\n\n";
    }
};

class Speedability : public Passive {
public:
    void detail() override {
        cout << "�нú� ��ų - ���ǵ�: �� ���� �� �� ����\n\n";
    }
};

class Pokemon {
public:
    Attack* attack;
    Passive* passive;
    Pokemon() {}

    void introduce() {
        name();
        attack->motion();
        passive->detail();
    }
    virtual void name() {}
    void setAttack(Attack* attack) {
        this->attack = attack;
    }
    void setPassive(Passive* passive) {
        this->passive = passive;
    }
};

class Pairi : public Pokemon {
public:
    Pairi() {
        attack = new Flame();
        passive = new Defensibility();
    }
    void name() {
        cout << "�̸�: ���̸�, �Ӽ�: ��\n";
    }
};

class Purin : public Pokemon {
public:
    Purin() {
        attack = new Sing();
        passive = new Avoidability();
    }
    void name() {
        cout << "�̸�: Ǫ��, �Ӽ�: ���\n";
    }
};

class Pikachu : public Pokemon {
public:
    Pikachu() {
        attack = new millionVolt();
        passive = new Speedability();
    }
    void name() {
        cout << "�̸�: ��ī��, �Ӽ�: ����\n";
    }
};

int main() {
    Pokemon* pikachu = new Pikachu();
    pikachu->introduce();

    Pokemon* pairi = new Pairi();
    pairi->introduce();

    Pokemon* purin = new Purin();
    purin->introduce();

    purin->setAttack(new millionVolt());
    purin->setPassive(new Defensibility());
    purin->introduce();
    return 0;
}