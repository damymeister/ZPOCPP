#include <iostream>
#include <vector>
#include <memory>
#include "buffer_arr.h"
#include "buffer_file.h"
using namespace std;
int main () {
    vector<unique_ptr<BufferArr>> ba;
    vector<unique_ptr<BufferFile>> bf;
    for (int i = 0; i < 6; i++)
    {
        unique_ptr<BufferArr> b(new BufferArr(3));
        ba.push_back(move(b));
        unique_ptr<BufferFile> c(new BufferFile("bufor.txt"));
        bf.push_back(move(c));
    }
    for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ba[i]->add(i * j);
            }
            ba[0]->add(10); // Blad!
            ba[i]->write();
            bf[i]->add(i);
        }
    bf[0]->write();
    for (int i = 0; i < 6; i++)
    {
        ba[i].reset();
        bf[i].reset();
    }
    return 0;
}
