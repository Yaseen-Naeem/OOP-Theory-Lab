#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("data.txt");
    string line;
    int count = 0;

    while (getline(file, line)) {
        count++;
    }

    file.close();

    cout << "Number of lines: " << count << endl;

    return 0;
}