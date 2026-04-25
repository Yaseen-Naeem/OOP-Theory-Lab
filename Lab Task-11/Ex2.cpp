#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("numbers.txt");
    int num;

    while (file >> num) {
        if (num % 2 == 0) {
            cout << num << " ";
        }
    }

    file.close();
    return 0;
}