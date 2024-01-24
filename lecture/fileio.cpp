#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    fstream fs;
    size_t fileSize;
    fs.open("input.txt", ios_base::in|ios_base::out|ios_base::binary|ios_base::ate);
    
    fileSize = fs.tellg();

    char buffer[fileSize] = {};

    fs.seekg(ios_base::beg);

    fs.read(buffer, fileSize);

    // char buffer[5] = {};
    // fstream fs;
    // fs.open("input.txt", ios_base::in|ios_base::out|ios_base::binary);

    // fs.seekg(5);

    // fs.read(buffer, 5);

    // for(int i = 0; i < 5; i++) {
    //     cout << "DEBUG: buffer[" << i << "]: "
    //          << buffer[i] << endl;
    // }

    // buffer[1] = 'a';

    // fs.seekg(-5);

    // fs.write(buffer, 5);

    // int number[5];
    // ifstream fin;
    // fin.open("input.txt");
    // ofstream fout;
    // fout.open("output.txt");

    // // for(int i = 0; i < 5; i++)
    // // {
    // //     fin >> number;

    // //     cout << "number" << i << ": " 
    // //          << number << endl;
    // // }
    // int counter = 0;
    // // while(fin >> number)
    // while(!fin.eof())
    // {
    //     fin >> number[counter];
    //     cout << "number" << counter << ": " 
    //          << number[counter] << endl;

    //     counter++;
    // }

    // for(int i = 0; i < counter; i++) {
    //     fout << number[i] << endl;
    // }
    // // fout << endl;

    // fin.close();
    // fout.close();
    fs.close();
    return 0;
}