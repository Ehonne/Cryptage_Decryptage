#include "occurence.h"
#define SIZE 256

Occurence::Occurence(string str)
{
    // 'freq[]' implemented as hash table
    int freq[SIZE];
    // initialize all elements of freq[] to 0
    for(int i =0; i < SIZE; i++)
        freq[i] = 0;
    //Calculating frequency of each character.
    for(int i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]]++;
    }
    for(int i = 0; i < SIZE; i++)
    {
        if(freq[i] != 0)
        {
            arr.push_back(char(i));
            frequence.push_back(freq[i]);
        }
    }
}


void Occurence::print_occurence()
{
    for (int i = 0; i < (int)this->arr.size(); i++)
    {
        cout << this->arr[i] << this->frequence[i] << " || ";
    }
    cout << endl;
}
