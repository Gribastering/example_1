#include <iostream>;
#include <Math.h>;
using namespace std;
#include "Engine.h";
#include "TestSTand.h";

int main() 
{
    setlocale(0, "");

    do
    {
        system("CLS");
        cout << "Здравствуйте."
            << "\nДля начала теста введите температуру воздуха окружающей среды и модельное время тестирования."
            << "\nТемпература воздуха окружающей среды, С° (от -100 до + 100): ";
        double t_outside = 0;
        int t_interval = 0;

            cin >> t_outside;
            cout << "Модельное время, секунд (от 1 до 10): ";
            cin >> t_interval;
            if (t_interval < 1 ||
                t_interval > 10 ||
                t_outside < -100 ||
                t_outside > 100)
            {
                cout << "Параметры заданы неверно, попробуйте еще раз.\n";
                    system("pause");
                continue;
            }
        

        // входные параметры
        double I = 10;
        double T = 110;
        double Hm = 0.01;
        double Hv = 0.0001;
        double C = 0.1;


        TestStand testStand = TestStand();

        double res = testStand.StartTest(Engine(I, T, Hm, Hv, C, t_outside), t_outside, t_interval);
        cout << "Время прошедшее до перегрева ДВС: " << res << "сек\n";
        system("pause");
             

    } while (true);

	return 0;
}