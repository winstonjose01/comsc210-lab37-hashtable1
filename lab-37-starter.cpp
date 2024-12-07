// COMSC210 | Lab 37 | Winston Jose
// IDE Used: Visual Studio Code
// Github link: https://github.com/winstonjose01/comsc210-lab37-hashtable1 

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <thread>
using namespace std;

const int ENTRIES = 100;

// Function Prototypes
int sumascii (const string&);
int gen_hash_index(const string&);
void display_menu();
bool find_key (map<int,list<string>> &, int);
void delete_key (map<int,list<string>> &, int);
void add_key (map<int,list<string>> &, int );
bool modify_key(map<int,list<string>> &, int, int);
void print_hashtable(map<int,list<string>> &, const int);

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

    // Add interactive menu
    int choice;
    int search_key;
    int new_key;
    while (true){
        display_menu();
        cin >> choice;
        switch (choice)
        {
        case 1: // Search for a key
            cout << endl;
            cout << "Enter the key you want to find: ";
            cin >> search_key;
            if (find_key(hash_table,search_key))
            {
                cout << "Key: " << search_key << " was found";
                cout << "\nValues: ";
                for (const auto& val: hash_table[search_key]){
                    cout << val << "  ";
                }
                
            }
            else
                cout << "\nKey: " << search_key << " was NOT found";
            cout << endl;
            break;

        case 2: // Add a key
            cout << "\nEnter the key you want to add: ";
            cin >> search_key;
            if (find_key(hash_table, search_key))
            {
                cout << "Key " << search_key << " already exists and cannot be added";
                break;
            }
            else
                add_key (hash_table, search_key);

            // Check if the key exists after it was added
            if (find_key(hash_table,search_key)){
                cout << "Key: " << search_key << " has been added";
            }
            else
                cout << "\nError occurred, unable to add";
            cout << endl;
            break;

        case 3: // Delete a key
            cout << "\nEnter the key you want to delete: ";
            cin >> search_key;
            if (find_key(hash_table,search_key))
                delete_key(hash_table, search_key);
            else
                cout << "Key: " << search_key << " was NOT found. Unable to delete";

            // Chech if the key exists after it was deleted
            if (!find_key(hash_table,search_key)){
                cout << "Key: " << search_key << " has been deleted";
            }
            else
                cout << "\nError occurred when trying to delete. Unable to proceed.";
            cout << endl;
            break;
    
        case 4: // Modify a key
            cout << "Enter the key you want to modify: ";
            cin >> search_key;
            cout << "Enter the new key :";
            cin >> new_key;
            if (find_key(hash_table,search_key)){
                if (modify_key(hash_table,search_key,new_key)){
                    cout << "Key: " << search_key << "has been modified to" << new_key;  
                    cout << "Here is the new key's data: ";
                    for (const auto &val : hash_table[new_key])
                        cout << val << " ";
                } 
                else
                {
                    cout << "\nError occurred, Unable to modify the old key.";
                }
            }
            else
            {
                cout << "\nError occurred, key not found. Unable to modify";
            }
            cout << endl;
            break;

        case 5: // Print the first 100 entries
            cout << "This the first " << ENTRIES << "of the hash table" << endl;
            print_hashtable(hash_table,ENTRIES);
            break;

        case 6: // Exit
            return 0;
            break;
        
        default: 
            cout << "\nInvalid input. Enter a correct choice number!";
            cout << endl;
            break;
        }
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

void display_menu(){
    cout << endl;
    cout << "---------- HASH TABLE MENU OPTION ----------" << endl;
    cout << "[1] Search for a key " << endl;
    cout << "[2] Add a key " << endl;
    cout << "[3] Remove a key " << endl;
    cout << "[4] Modify a key " << endl;
    cout << "[5] Print the first 100 entries of the hashtable " << endl;
    cout << "[6] Exit " << endl;
    cout << "Choose an option --> ";
}

bool find_key (map<int,list<string>> &hash_table, const int search_key){
    auto it =  hash_table.find(search_key);
    if (it != hash_table.end()) 
        return true;
    else
        return false;
}

void delete_key (map<int,list<string>> &hash_table, int remove_key){
    cout << "Deleting key " << remove_key << " with values: ";
    for (const auto& val: hash_table[remove_key]) 
        cout << val << " ";
    cout << "....\n";
    this_thread::sleep_for(chrono::seconds(3));
    hash_table.erase(remove_key);
}

void add_key (map<int,list<string>> &hash_table, int add_key){
    hash_table[add_key] = {};
}

bool modify_key(map<int,list<string>> &hash_table, int search_key, int new_key){
    auto it = hash_table.find(search_key);

    if (it != hash_table.end()){
        list <string> temp = it->second;
        hash_table.erase(it);
        hash_table[new_key] = temp;
        return true;
    } 
    else
        return false;
}

void print_hashtable (map<int,list<string>> &hash_table, const int entries){
    int i = 0;  // Start from index 0
    for (const auto& pair: hash_table){
        if (i >= entries) break;     // Stop after 100 entries
        cout << "["<< i+1 << "] Key: " << pair.first << ":" << endl;
        
        for (const auto& val: pair.second){
                cout << val << "  ";
        }
        cout << endl;
        i++;
        
    }
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
