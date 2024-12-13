#include <iostream>
using namespace std;

class ElecFan {
public:
    ElecFan() {
        State = "Stop";
        cout << "<<현재 상태: " << State << " >>\n";
    }
    void setState(string state) {
        this->State = state;
    }
    void on_button() {
        if (State == "Stop")
        {
            State = "Wind";
            cout << "\n***on 버튼 눌림***\n" << "정지에서 송풍 상태로 바뀜\n";
            cout << "\n<<현재 상태: " << State << ">>\n";
        }
        else if (State == "Wind") {
            cout << "\n***on 버튼 눌림***\n" << "상태 변화 없음\n";
            cout << "\n<<현재 상태: " << State << ">>\n";
        }
    }
    void off_button() {
        if (State == "Stop") {
            cout << "\n***off 버튼 눌림***\n" << "상태 변화 없음\n";
            cout << "\n<<현재 상태: " << State << ">>\n";
        }
        else if (State == "Wind") {
            State = "Stop";
            cout << "\n***off 버튼 눌림***\n" << "송풍에서 정지 상태로 바뀜\n";
            cout << "\n<<현재 상태: " << State << ">>\n";
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