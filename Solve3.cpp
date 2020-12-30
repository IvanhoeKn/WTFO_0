#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    unsigned int n;
    ifstream f_in(argv[1]);
    ofstream f_out(argv[2]);
    f_in >> n;
    //n = (~n & 255) - n;
    n = (255 - n) / 2;
    f_out << n;
    f_in.close();
    f_out.close();
    system("pause");
    return 0;
}