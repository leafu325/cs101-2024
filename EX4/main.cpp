#include <iostream>
#include <string>

using namespace std;

class Fueltank {
private:
    int m_FueltankCapacity;
    int m_Gas_grade;

public:
    Fueltank(int FueltankCapacity = 3000, int Gas = 98) : m_FueltankCapacity(FueltankCapacity), m_Gas_grade(Gas) {}

    void fuel_up(int v, int gas) {
        m_FueltankCapacity += v;
        m_Gas_grade = gas;
        cout << "fuel_up: " << v << " Gas_grade: " << m_Gas_grade << endl;
    }

    void set_Gas_grade(int Gas_grade) {
        cout << "Set Gas_grade: " << Gas_grade << endl;
        m_Gas_grade = Gas_grade;
    }

    int get_Gas_grade() {
        return m_Gas_grade;
    }
};


class Car {
protected:
    string m_DriveMode;

private:
    int m_MaxSeating;
    int m_price;

public:
    string m_brand;
    string m_model;
    int m_year;

    Car(string x, string y, int z, int s) : m_brand(x), m_model(y), m_year(z), m_MaxSeating(s) {}

    int get_MaxSeating() {
        return m_MaxSeating;
    }

    int get_Price() {
        return m_price;
    }

    string get_brand() {
        return m_brand;
    }

    string det_DriveMode() {
        return m_DriveMode;
    }
};

class AUDI_Car : public Car, public Fueltank {
public:
    AUDI_Car(string y, int z, int s) : Car("Audi", y, z, s), Fueltank() {
        cout << "Constructing AUDI_Car" << endl;
        cout << m_brand << ": Gas_grade = " << get_Gas_grade() << endl;
    }
};

int main() {
    AUDI_Car car_2("A1", 2021, 2);
    car_2.set_Gas_grade(95);
    cout << car_2.get_brand() << ": Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.fuel_up(300, 95);
    return 0;
}
