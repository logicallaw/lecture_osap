#include <iostream>
using namespace std;

class Pokemon {
public:
    void introduce() {
        name();
        attack();
        passive();
    }
    virtual void name() {};
    virtual void attack() {};
    virtual void passive() {};
};

class Purin : public Pokemon {
public:
    void passive() override {
        cout << "�нú� ��ų: ȸ��\n\n";
        // ȸ��: 30% Ȯ���� ���� ȸ�� 
    }
    void attack() override {
        cout << "���� ��ų: �뷡�ϱ�\n";
        // �뷡�ϱ�: �뷡�� �ҷ� ��븦 �����
    }
    void name() override {
        cout << "�̸�: Ǫ��, �Ӽ�: ���\n";
    }
};

class Pairi : public Pokemon {
public:
    void passive() override {
        cout << "�нú� ��ų: ���\n\n";
        // ���: �޴� ���ظ� 40% ���ҽ�Ŵ 
    }
    void attack() override {
        cout << "���� ��ų: �Ҳ�\n";
        // �Ҳ�: �߰ſ� �Ҳ��� ������� ��
    }
    void name() override {
        cout << "�̸�: ���̸�, �Ӽ�: ��\n";
    }
};

class Pikachu : public Pokemon {
public:
    void passive() override {
        cout << "�нú� ��ų: ���ǵ�\n\n";
        // ���ǵ�: �� ���� �� �� ������ 
    }
    void attack() override {
        cout << "���� ��ų: �鸸 ��Ʈ\n";
        // �鸸 ��Ʈ: �鸸 ��Ʈ�� ������ �������� ������
    }
    void name() override {
        cout << "�̸�: ��ī��, �Ӽ�: ����\n";
    }
};

int main() {
    Pokemon* pikachu = new Pikachu();
    pikachu->introduce();

    Pokemon* purin = new Purin();
    purin->introduce();

    Pokemon* pairi = new Pairi();
    pairi->introduce();
    return 0;
}