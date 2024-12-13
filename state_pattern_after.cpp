#include <iostream>
using namespace std;

class ElectricFan;

class State {
public:
    virtual void on_button(ElectricFan* EF) = 0;
    virtual void off_button(ElectricFan* EF) = 0;
};

class Stop : public State {
public:
    Stop() {
        cout << "\n<<���� ����: ����>>\n";
    }
    void on_button(ElectricFan* EF) override;
    void off_button(ElectricFan* EF) override;
};

class Wind : public State {
public:
    Wind() {
        cout << "\n<<���� ����: ��ǳ>>\n";
    }
    void on_button(ElectricFan* EF) override;
    void off_button(ElectricFan* EF) override;
};

class Sleep : public State {
public:
    Sleep() {
        cout << "\n<<���� ����: ����>>\n";
    }
    void on_button(ElectricFan* EF) override;
    void off_button(ElectricFan* EF) override;
};

class ElectricFan {
public:
    ElectricFan() {
        state = new Stop();
    }
    ~ElectricFan() {
        delete state;
    }
    void setState(State* newState) {
        delete state;
        state = newState;
    }
    void on_push() {
        state->on_button(this);
    }
    void off_push() {
        state->off_button(this);
    }
    void operation() {
        off_push();
        on_push();
        on_push();
        on_push();
        off_push();
    }

private:
    State* state;
};

void Stop::on_button(ElectricFan* EF) {
    cout << "\n***on ��ư ����***\n" << "�������� ��ǳ ���·� �ٲ�\n";
    EF->setState(new Wind());
}

void Stop::off_button(ElectricFan* EF) {
    cout << "\n***off ��ư ����***\n" << "���� ��ȭ ����\n";
}

void Wind::on_button(ElectricFan* EF) {
    cout << "\n***on ��ư ����***\n" << "��ǳ���� ���� ���·� �ٲ�\n";
    EF->setState(new Sleep());
}

void Wind::off_button(ElectricFan* EF) {
    cout << "\n***off ��ư ����***\n" << "��ǳ���� ���� ���·� �ٲ�\n";
    EF->setState(new Stop());
}

void Sleep::on_button(ElectricFan* EF) {
    cout << "\n***on ��ư ����***\n" << "���鿡�� ��ǳ ���·� �ٲ�\n";
    EF->setState(new Wind());
}

void Sleep::off_button(ElectricFan* EF) {
    cout << "\n***off ��ư ����***\n" << "���鿡�� ���� ���·� �ٲ�\n";
    EF->setState(new Stop());
}

int main() {
    ElectricFan* EF = new ElectricFan();
    EF->operation();
    delete EF;
    return 0;
}