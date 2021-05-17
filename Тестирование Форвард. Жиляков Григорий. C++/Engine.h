#pragma once
class Engine
{
private:
    double m_array[6] = { 20, 75, 100, 105, 75, 0 };
    double v_array[6] = { 0, 75, 150, 200, 250, 300 };
    double I;
    double T;
    double Hm;
    double Hv;
    double C;
    // текущее значение температуры охлаждающей жидкости ДВС
    double T_engine;
    // текущее значение скорости вращения коленчатого вала ДВС
    double V;
    // текущее значение крутящего момента ДВС
    double M;

public:
    Engine(double I, double T, double Hm, double Hv, double C, double T_outside)
    {
        this->I = I;
        this->T = T;
        this->Hm = Hm;
        this->Hv = Hv;
        this->C = C;
        T_engine = T_outside;
        V = 0;
    }
    ~Engine() 
    {
    }

    double Comp_M(double V_current)
    {
        int index = -1;

        for (int i = 0; i < 6; i++)
        {
            if (v_array[i] == V_current)
            {
                return m_array[i];
            }
            else if (v_array[i] > V_current)
            {
                index = i;
                // вычисляем текущее значение крутящего момента ДВС
                return m_array[index - 1] + (m_array[index] - m_array[index - 1])
                    * (V_current - v_array[index - 1]) / (v_array[index] - v_array[index - 1]);
            }
        }

        return 1;
    }

    double Heats(double M)
    {
        return (M * Hm) + ((V*V) * Hv);
    }

    double Cools(double T_outside)
    {
        return C * (T_outside - T_engine);
    }

    double Comp_Acceliration(double M_current)
    {
        return M_current / I;
    }

    double GetV() 
    {
        return V;
    }
    void SetV(double v) 
    {
        V = v;
    }
    double GetT_engine() 
    {
        return T_engine;
    }
    void SetT_engine(double t_engine) 
    {
        T_engine = t_engine;
    }
    double GetM() 
    {
        return M;
    }
    void SetM(double m) 
    {
        M = m;
    }
    double GetT() 
    {
        return T;
    }

};

