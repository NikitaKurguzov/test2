// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//метод блочной перестановки 

string Decrypt(string text, vector<int> key)
{
    //if not enough characters append some spaces
    text.append(key.size() - text.size() % key.size(), ' ');
    string result;
    for (int i = 0; i < text.size(); i += key.size())
    {
        for (int j = 0; j < key.size(); j++)
        {
            result.push_back(text[key[j] - 1 + i]);//positions are stored as user friendly keys i guess?
        }
    }
    return result;
}

string DecryptSimple(string text)
{
    string result;
    int key[] = { 2,5,1,3,4,6 };
    int additional_spaces_count = 6 - text.size() % 6;
    if (additional_spaces_count != 6)
    {
        text.append(additional_spaces_count, ' ');
    }
    int size = ceil(text.size() / 6.f);
    for (int i = 0; i < text.size(); i += 6)
    {
        for (int j = 0; j < 6; j++)
        {
            result.push_back(text[key[j] - 1 + i]);
        }
    }
    return result;
}

string Encrypt(string text, vector<int> key)
{
    int key_size = key.size();
    int size = ceil(text.size() / (float)key_size);//bad. Fix this this
    //create empty string with size of the encrypted string
    string result = string(size * key.size(), ' ');
    for (int i = 0; i < size; i++)
    {
        string t = text.substr(i * key_size, key_size);
        if (t.size() < key_size)
        {
            t.append(string(key_size - t.size(), ' '));
        }
        for (int j = 0; j < key_size; j++)
        {
            result[(key[j] - 1 ) + (i * key_size)] = t[j];
        }
    }
    return result;
}

int main()
{
    string test_text = "abcdf";
    vector<int> key = { 2,5,1,3,4,6 };
    //vector<int> key = { 3,4,1,5,2 };
    getline(cin, test_text);
    cout << DecryptSimple(test_text) << endl;
    cout << Decrypt(test_text,key);
    //cout << "Encrypted " <<  Encrypt(test_text, key) << endl;
    //cout << "Decrypted " << DecryptSimple(Encrypt(test_text, key));
}