#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;
using std::string;

class Car{
    protected:
    string m_DriveMode;
    private:
    int m_MaxSeating;
    int m_price;
    void m_UpdataPrice(int base = 50000){
    }
    public:
    string m_brand;
    string m_model;
    int m_year;

    Car(string x, string y, int z, int s){
        m_brand = x;
        m_model = y;
        m_year = z;
        m_MaxSeating = s;
    }
    int get_MaxSeating(){
        return m_MaxSeating;
    }
    int get_Price(){
        return m_price;
    }
    string det_DriveMode(){
        return m_DriveMode;
    }
};

class BMW_Car : public Car{
    public:
    BMW_Car(string y, int z, int s) : Car("BMW", y, z, s){
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheal";
    }

    string get_DriveMode(){
        return m_DriveMode;
    }
};
class AUDI_Car : public Car{
    public:
    AUDI_Car(string y, int z, int s) : Car("Audi", y, z, s){
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheal";
    }

    string get_DriveMode(){
        return m_DriveMode;
    }
};
class BENZ_Car : public Car{
    public:
    BENZ_Car(string y, int z, int s) : Car("Benz", y, z, s){
        cout << "Constructing BENZ_Car\n";
        m_DriveMode = "Front-wheal";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

int main(){

    BMW_Car car_1("32",2023,5);
    cout<<car_1.m_brand;
    cout<<" : Drive Mode = " << car_1.get_DriveMode() <<endl;

    AUDI_Car car_2("32",2023,5);
    cout<<car_2.m_brand;
    cout<<" : Drive Mode = " << car_2.get_DriveMode() <<endl;

    BENZ_Car car_3("32",2023,5);
    cout<<car_3.m_brand;
    cout<<" : Drive Mode = " << car_3.get_DriveMode() <<endl;
}
