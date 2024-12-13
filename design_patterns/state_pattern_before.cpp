#include <iostream>
using namespace std;

class ElecFan {
public:
    ElecFan() {
        State = "Stop";
        cout << "<<���� ����: " << State << " >>\n";
    }
    void setState(string state) {
        this->State = state;
    }
    void on_button() {
        if (State == "Stop")
        {
            State = "Wind";
            cout << "\n***on ��ư ����***\n" << "�������� ��ǳ ���·� �ٲ�\n";
            cout << "\n<<���� ����: " << State << ">>\n";
        }
        else if (State == "Wind") {
            cout << "\n***on ��ư ����***\n" << "���� ��ȭ ����\n";
            cout << "\n<<���� ����: " << State << ">>\n";
        }
    }
    void off_button() {
        if (State == "Stop") {
            cout << "\n***off ��ư ����***\n" << "���� ��ȭ ����\n";
            cout << "\n<<���� ����: " << State << ">>\n";
        }
        else if (State == "Wind") {
            State = "Stop";
            cout << "\n***off ��ư ����***\n" << "��ǳ���� ���� ���·� �ٲ�\n";
            cout << "\n<<���� ����: " << State << ">>\n";
        }
    }
private:
    string State;
};

int main()
{
    ElecFan* electricfan = new ElecFan();
    electricfan->on_button();
    electricfan->off_button();
    return 0;
}