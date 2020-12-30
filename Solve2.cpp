#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream f_in(argv[1]);
    ofstream f_out(argv[2]);
    int n, d, count = 0;
    f_in >> n >> d;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            if (i > d)
                count++;
            if (n / i > d)
                count++;
        }
    f_out << count;
    f_in.close();
    f_out.close();
    system("pause");
    return 0;
}