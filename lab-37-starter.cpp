// COMSC210 | Lab 37 | Winston Jose
// IDE Used: Visual Studio Code
// Github link: https://github.com/winstonjose01/comsc210-lab37-hashtable1 

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// Function Prototypes
int sumascii (const string&);
int gen_hash_index(const string&);

int main() {
    // ------------------ PART TWO / THREE --------------------------
    string line;
    int total = 0;
    int sum_str = 0;
    ifstream fin("lab-37-data.txt");
    map<int,list<string>> hash_table;  // Map container to hold hashtable

    // Check if file opened correctly
    if (!fin.is_open()){
        cout << "Error opening file. Aborting" << endl;
        return(1);
    }

    while (getline(fin, line)){
        int key = gen_hash_index(line); // PART THREE: Generate hash index
        hash_table[key].push_front(line);   // Insert line into the hash table

        // PART TWO: Calculate total ASCII sum
        sum_str = sumascii(line); 
        total += sum_str; 
    }
    fin.clear();
    fin.seekg(0);

    // PART THREE
    // Display the first 100 entries of the hash table
    int i = 0;  // Start from index 0
    for (const auto& pair: hash_table){
        if (i >= 100) break;     // Stop after 100 entries
        cout << "["<< i+1 << "] Key: " << pair.first << ":" << endl;
        cout << "\tValues: ";
        for (const auto& val: pair.second){
                cout << val << "  ";
        }
        cout << endl;
        i++;
        
    }

    // PART TWO - Total ASCII sum
    cout <<"\nTotal ASCII values in the entire file = " << total << endl;
 
    // Testing PART ONE functionality
    int part_one = sumascii("helloWORLD"); // PART ONE - Testing total ascii val should be 924
    cout << "\nThe ascii sum of helloWORLD = " << part_one; // PART ONE - for testing
    
    return 0;
}

// PART ONE - This function calculates the ascii value of a string input
// arguments: a string input
// returns : an integer, the total ascii value of the string
int sumascii (const string &input)
{
    int sum = 0;
    for (char c : input){
        sum += int(c);  // Calculate the sum of ASCII values
    }
    return sum;
}

// PART THREE: This function calculates the hash index based on the ASCII sum
// arguments: a string input
// returns : an integer, the total ascii value of the string
int gen_hash_index(const string &input)
{
    int sum = 0;
    for (char c : input){
        sum += int(c);  // Calculate the sum of ASCII values
    }
    return sum; // Return the sum as the hash index
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
