#include <iostream>
#include <fstream>
#include <limits> 

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    int x1, x2;
    int sum;
    int max_, difference;
    ofstream f_out(argv[argc - 1]);
    for (short int i_file = 1; i_file < argc - 1; i_file++) {
        ifstream f_in(argv[i_file]);
        f_in >> n;
        sum = 0;
        max_ = numeric_limits<int>::min();
        for (int i = 0; i < n; i++) {
            f_in >> x1 >> x2;
            if (x1 > x2) {
                sum += x1;
                difference = x2 - x1;
            }
            else {
                sum += x2;
                difference = x1 - x2;
            }
            if ((difference % 3) && (difference > max_))
                    max_ = difference; 
        }
        if (!(sum % 3)) {
            sum += max_;
        }
        f_out << sum << endl; 
        f_in.close();
    }
    f_out.close();
    system("pause");
    return 0;
}