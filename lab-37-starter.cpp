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

    int sum_char = sumascii("A");
    cout << "the sum is " << sum_char;
    

    return 0;
}


int sumascii (const string &input)
{
    int sum = 0;
    for (char c : input){
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
