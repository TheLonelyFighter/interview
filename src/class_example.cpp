#include<iostream>
#include<vector>
#include<algorithm>


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

int main() 
{
    //static declaration
    Cars bmw("BMW", 300, 6);
    Cars nissan("Nissan", 250, 7);
    Cars dacia("Dacia", 160, 5);
    std::vector<Cars> car_list = {bmw, nissan, dacia};
    std::cout << bmw.get_speed() << std::endl;
    int max_speed = 200;
    bmw.set_speed(max_speed);
    std::cout << bmw.brand << " " << bmw.get_speed() << std::endl;
    bmw.outside_method();

    //sort example using lambda function
    std::sort(car_list.begin(), car_list.end(), [](Cars a, Cars b) {return a.get_speed() > b.get_speed();});

    for(auto i : car_list) {
        std::cout << i.brand << " " << i.get_speed() << std::endl;
    }

    Cars("Ferarri", 400, 8);
    car_list.push_back(Cars("Ferarri", 400, 8));
    std::sort(car_list.begin(), car_list.end(), [](Cars a, Cars b) {return a.get_speed() < b.get_speed();});
    for(auto i : car_list) {
        std::cout << i.brand << " " << i.get_speed() << std::endl;
    }

    //dynamic declaration
    Cars *audi = new Cars("Audi", 280, 6);
    Cars *skoda = new Cars("Skoda", 200, 6);

    std::vector<Cars> car_list_dyn = {*audi, *skoda};


    std::cout << "\nDynamic declaration" << std::endl;
    Cars *mercedes = new Cars("Mercedes", 320, 7);
    car_list_dyn.push_back(*mercedes);
    std::sort(car_list_dyn.begin(), car_list_dyn.end(), [](Cars a, Cars b) {return a.get_speed() > b.get_speed();});

    for(auto i : car_list_dyn) {
        std::cout << i.brand << " " << i.get_speed() << std::endl;
    }

    //car_list_dyn.erase(car_list_dyn.begin());

    for(auto& i : car_list_dyn) {
        std::cout << i.brand << " " << i.get_speed() << std::endl;
    }
    int index = 0;
    for (auto& i : car_list_dyn) {
        
        if (i.brand == "Mercedes") {
            std::cout << "Mercedes is in the list, will be deleted" << std::endl;
            car_list_dyn.erase(car_list_dyn.begin() + index);
        }
        index++;
    }

    for(auto& i : car_list_dyn) {
        std::cout << i.brand << " " << i.get_speed() << std::endl;
    }
    return 0;
}