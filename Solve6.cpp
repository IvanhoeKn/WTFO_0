#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void increase(int first, int second, vector<int>& array_of_el, vector<int>& length, int* index) {
    length[0] = 0;
    for (int i = first; i < second; ++i) {
        length[i] = 1;
        index[i] = -1;
        for (int j = 0; j < i; ++j) 
            if (array_of_el[j] < array_of_el[i])
                if (1 + length[j] > length[i]) {
                    length[i] = 1 + length[j];
                    index[i] = j;
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream f_in(argv[1]);
    ofstream f_out(argv[2]);
    int n, x;
    //ввод 
    f_in >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        f_in >> x;
        numbers.push_back(x);
    }
    //поиск возрасатющей последовательности
    std::vector<int> length_1(n);
    int* index_1 = new int[n];
    increase(0, n, numbers, length_1, index_1);
    //поиск убывающей последовательности
    reverse (numbers.begin(), numbers.end());
    std::vector<int> length_2(n);
    int* index_2 = new int[n];
    increase(0, n, numbers, length_2, index_2);
    //поиск последовательности максимальной длины
    int max_length = 0;
    int pos_1, pos_2;
    for (int i = 0; i < n; ++i)
        if (length_1[i] + length_2[n - 1 - i] > max_length) {
            max_length = length_1[i] + length_2[n - 1 - i];
            pos_2 = n - 1 - i;
            pos_1 = i;
        }
    f_out << max_length - 1 << endl;
    //вывод пути
    //для возрастающей последовательности
    reverse (numbers.begin(), numbers.end());
    vector<int> path_1;
    while (pos_1 != -1) {
        path_1.push_back(pos_1);
        pos_1 = index_1[pos_1];
    }
    reverse (path_1.begin(), path_1.end());
    for (int i = 0; i < (int)path_1.size(); ++i)
        f_out << numbers[path_1[i]] << ' ';
    length_1.clear();
    delete[] index_1;
    path_1.clear();
    //для убывающей последовательности
    vector<int> path_2;
    pos_2 = index_2[pos_2];
    while (pos_2 != -1) {
        path_2.push_back (pos_2);
        pos_2 = index_2[pos_2];
    }
    for (int i = 0; i < (int)path_2.size(); ++i)
        f_out << numbers[n - 1 - path_2[i]] << ' ';
    //---------------------------------------------
    numbers.clear();
    f_in.close();
    f_out.close();
    system("pause");
    return 0;
}