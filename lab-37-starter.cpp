#include <iostream>
using namespace std;

int sumascii (const string&);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    int sum_char = sumascii("helloWORLD"); // for testing total ascii val should be 924
    cout << "the sum is " << sum_char; // for testing
    

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
