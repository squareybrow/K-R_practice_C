#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Enter at least one name" << endl;
        return 1;
    }
    cout << "Hello, " << argv[1] << endl;
    return 0;
} 