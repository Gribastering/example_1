#pragma once
#include "Windows.h";
class TestStand
{
public:
    double StartTest(Engine testing_engine, double t_outside, double t_interval)
    {

        double Time_to_overheat = 0;
        
        while (testing_engine.GetT_engine() < testing_engine.GetT())
        { 
            testing_engine.SetM(testing_engine.Comp_M(testing_engine.GetV()));
            double Vh = testing_engine.Heats(testing_engine.GetM());
            double Vc = testing_engine.Cools(t_outside);
            double Vtotal = Vh + Vc;      
            testing_engine.SetT_engine(testing_engine.GetT_engine() + (Vtotal * t_interval));
            testing_engine.SetV(testing_engine.GetV() + (testing_engine.Comp_Acceliration(testing_engine.GetM()) * t_interval));
            // �.�. ����������� ��������� ������� ��� �������� �������� ��������� ����� 300 �����/��� �� �������
            // ������������ ������������ �������� �� 300 ������/���. 
            // ���� ���������������� ��� �������, �� ��� ��������� ��������� ����������� ���������� ����� (����� 20), 
            // ���� ����� �������� ����������, �.�. �������� ������ ����� ����� 0 � ������ ����� ���������������� �����������. �������� � ����������� �������� ��������.
            // ��� �������������, ����� ����������������� ������ �������.
            /*if (testing_engine.GetV() > 300)
            {
                testing_engine.SetV(300);
            }*/
            Time_to_overheat += t_interval;
            system("CLS");
            cout << "������� ����������� ���: " << testing_engine.GetT_engine();
            cout << "\n������� �������� �������� ����������� ����: " << testing_engine.GetV();
            Sleep(1000);

        }
        system("CLS");
        return Time_to_overheat;
    }
};

