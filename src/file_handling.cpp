#include<fstream>

int main()
{
    std::ofstream file("../assets/test.txt");
    file << "Hello World" << std::endl;
    file.close();
}