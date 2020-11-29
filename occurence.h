#ifndef OCCURENCE_H
#define OCCURENCE_H
#include <vector>
#include <iostream>
using namespace std;

class Occurence
{
public:
    vector<int>frequence;
    vector<char> arr;


    Occurence(string a);

    void print_occurence();
};

#endif // OCCURENCE_H
