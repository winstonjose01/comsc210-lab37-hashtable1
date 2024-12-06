#include <iostream>
#include <fstream>
using namespace std;

int sumascii (const string&);


int main() {
    // char a = 'A';
    // cout << a << endl;
    // cout << (int) a << endl;
    // int b = 66;
    // cout << b << endl;
    // cout << (char) b << endl;

    // ------------------ PART TWO --------------------------
    string line;
    int total = 0;
    int sum_str = 0;
    ifstream fin("lab-37-data.txt");

    if (!fin.is_open()){
        cout << "Error opening file. Aborting" << endl;
        return(1);
    }

    while (getline(fin, line)){
        sum_str = sumascii(line);
        total += sum_str;
    }
    fin.clear();
    fin.seekg(0);
    cout <<"Total ASCII values in the entire file = " << total << endl;

    // ----------------- END OF PART TWO ------------------

    int part_one = sumascii("helloWORLD"); // for testing total ascii val should be 924
    cout << "the ascii sum of helloWORLD = " << part_one; // for testing
    
    return 0;
}

// PART ONE - This function calculates the ascii value of a string input
// arguments: a string input
// returns : an integer, the total ascii value of the string
int sumascii (const string &input)
{
    int sum = 0;
    for (char c : input){
        //cout << c << "=" << int(c) << endl;
        sum += int(c);
    }
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
