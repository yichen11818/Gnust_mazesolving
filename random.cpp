#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int size = 10;
    const int threshold = 3; 
    ofstream outFile("output.txt");

    if (!outFile) {
        cerr << "无法打开文件output.txt进行写入" << endl;
        return 1;
    }

    srand(time(0)); 

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            outFile << (rand() % 4 < threshold ? 0 : 1) << " ";
        }
        outFile << "\n"; 
    }


    outFile.close();

    cout << "数组已成功写入文件output.txt" << endl;

    return 0;
}
