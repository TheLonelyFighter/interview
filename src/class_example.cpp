#include<iostream>


class Cars {
    //std::string brand = "None";
    int speed;
    int gears;


    public:

    std::string brand;

    //constructor
    Cars(std::string brand_arg = "None", int speed_arg = 0, int gears_arg = 0) {
        speed = speed_arg;
        brand = brand_arg;
    }

   

    void outside_method();

    void set_speed(int max_speed) {
        speed = max_speed;
    }

    int get_speed() {
        return speed;
    }
};

void Cars::outside_method()
{
    std::cout << "This is a method defined outside the class" << std::endl;
}

int main() {
    Cars car_one("BMW", 300, 6);
    std::cout << car_one.get_speed() << std::endl;
    int max_speed = 200;
    car_one.set_speed(max_speed);
    std::cout << car_one.brand << " " << car_one.get_speed() << std::endl;
    car_one.outside_method();
}