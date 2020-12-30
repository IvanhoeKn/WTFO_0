#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int n, max_weight;
    int max_el, sum = 0;
    int index;
    bool flag = true;
    ifstream f_in(argv[1]);
    ofstream f_out(argv[2]);
    f_in >> max_weight >> n;
    int* array_of_el = new int[n];
    for (int i = 0; i < n; i++)
        f_in >> array_of_el[i];
    sort(array_of_el, array_of_el + n);
    int i = -1;
    while (flag && (i < n)) {
        i++;
        if (sum + array_of_el[i] <= max_weight) 
            sum += array_of_el[i];
        else
            flag = false;
    }
    index = i;
    max_el = array_of_el[i - 1];
    sum -= max_el;
    while (!flag && (i < n)) {
        if (sum + array_of_el[i] <= max_weight)
            max_el = array_of_el[i];
        else
            flag = true; 
        i++;       
    }
    f_out << index << " " << max_el;
    delete[] array_of_el;
    f_in.close();
    f_out.close();
    system("pause");
    return 0;
}