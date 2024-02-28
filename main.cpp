#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

//Write an application that will read in a number of integers from a file and store them in
//a vector. Allow the user to search through the vector and find the position of any user defined number.

//print elements of vector<int> and vector<string>
void printVector(std::vector<int> &intVect) {
    std::cout << "Printing all of vector: " << std::endl;

    std::vector<int>::size_type sizeVectInt = intVect.size();

    for (std::vector<int>::iterator i = intVect.begin(); i != intVect.end(); i++) {
        std::cout << *i << std::endl;
    }
}
void printVector(std::vector<std::string> &stringVect) {
    std::cout << "Printing all of vector: " << std::endl;

    std::vector<std::string>::size_type sizeVectString = stringVect.size();

    for (std::vector<std::string>::iterator i = stringVect.begin(); i != stringVect.end(); i++) {
        std::cout << *i << std::endl;
    }
}

//read ints from a file
void readIntFromFile(std::vector<int> &vector, std::ifstream &inputIntFile) {
    if (inputIntFile.is_open()) {
        int currentNum;

        while (inputIntFile >> currentNum) {
            vector.push_back(currentNum);
        }

        inputIntFile.close();
    }
}
void readIntFromFile(std::list<int> &vector, std::ifstream &inputIntFile) {
    if (inputIntFile.is_open()) {
        int currentNum;

        while (inputIntFile >> currentNum) {
            vector.push_back(currentNum);
        }

        inputIntFile.close();
    }
}

int q01() {

    std::cout << "--- Q01 ---" << std::endl;


    //make vector
    std::vector<int> ints;

    //read in file
    std::ifstream inputIntFile("../ints.txt");

    readIntFromFile(ints, inputIntFile);

    //debug🚩
    //printVector(ints);

    //search variable
    int userSearch;
    int indexOfSearch = -1;

    //user input message
    std::cout << "Enter integer to search for:";
    std::cin >> userSearch;

    for (std::vector<int>::const_iterator itr = ints.cbegin(); itr != ints.cend(); itr++) {

        if (*itr == userSearch) {
            indexOfSearch = std::distance(ints.cbegin(), itr);
            std::cout << "Integer [" << userSearch << "] found at vector index:" << indexOfSearch << std::endl;
            break;
        }

    }

    if (indexOfSearch == -1) {
        std::cout << "Integer not found in vector!" << std::endl;
    }

    return 1;
}

int q02() {

    std::cout << "--- Q02 ---" << std::endl;


    //make list
    std::list<int> ints;

    //read in file
    std::ifstream inputIntFile("../ints.txt");

    readIntFromFile(ints, inputIntFile);

    //debug🚩
    //printVector(ints);

    //search variable
    int userSearch;

    //user input message
    std::cout << "Enter integer to search for:";
    std::cin >> userSearch;

    int indexOfSearch = -1;
    for (std::list<int>::const_iterator itr = ints.cbegin(); itr != ints.cend(); itr++) {

        if (*itr == userSearch) {
            indexOfSearch = std::distance(ints.cbegin(), itr);
            std::cout << "Integer [" << userSearch << "] found at list index:" << indexOfSearch << std::endl;
            break;
        }

    }

    if (indexOfSearch == -1) {
        std::cout << "Integer not found in list!" << std::endl;
    }


    return 2;
}

int q03() {

    std::cout << "--- Q03 ---" << std::endl;


    //make vector
    std::vector<int> ints;

    //read in file
    std::ifstream inputIntFile("../ints.txt");

    readIntFromFile(ints, inputIntFile);

    //debug🚩
    //printVector(ints);

    //search variable
    int userSearch;
    int indexOfSearch = -1;

    //user input message
    std::cout << "Enter integer to search for:";
    std::cin >> userSearch;

    //THIS IS THE SORTING, GIVE NON CONSTANT START AND END ITR FOR SORTING
    //natural int ordering == ascending
    std::sort(ints.begin(), ints.end());

    for (std::vector<int>::const_iterator itr = ints.cbegin(); itr != ints.cend(); itr++) {

        if (*itr == userSearch) {
            indexOfSearch = std::distance(ints.cbegin(), itr);
            std::cout << "Integer [" << userSearch << "] found at vector index:" << indexOfSearch << std::endl;
            break;
        }

    }

    if (indexOfSearch == -1) {
        std::cout << "Integer not found in vector!" << std::endl;
    }

    std::cout << "Showing they're naturally ordered and ascending:" << std::endl;
    printVector(ints);

    return 3;
}

int q04() {

    std::cout << "--- Q04 ---" << std::endl;

    //make vector and populate
    std::vector<std::string> strings;
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");
    strings.push_back("Four");
    strings.push_back("Five");

    //sort using anonymous class comparator
    //ascending, s1 is smaller than s2 == true
    std::sort(strings.begin(), strings.end(), [](std::string s1, std::string s2){return s1.length() < s2.length();});

    //print out
    printVector(strings);

    return 4;
}

int q05() {

    std::cout << "--- Q05 ---" << std::endl;

    //make vector and populate
    std::vector<std::string> strings;
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");
    strings.push_back("Four");
    strings.push_back("Five");

    //sort using anonymous class comparator
    //s1 is bigger than s2
    std::sort(strings.begin(), strings.end(), [](std::string s1, std::string s2){return s1.length() > s2.length();});

    //print out
    printVector(strings);

    return 5;
}

int main() {

    //run each question, comment to ignore
    q01();

    q02();

    q03();

    q04();

    q05();

    return 0;
}

//            https://codeshare.io/2jbpZR
////////////////////////////////////////////////////////

/*
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;



void print(const vector<int> &vec, string s= "") {
    cout << s <<"[";
    for (int i = 0; i < vec.size(); i++)
    {
        if(i!=0)
            cout << ", ";
        cout << vec[i];
    }
    cout << "]\n";
}

void print(const list<int> &lst, string s= "") {
    cout << s <<"[";
    for (auto it = lst.cbegin(); it != lst.cend(); it++)
    {
        if(it!=lst.cbegin())
            cout << ", ";
        cout << *it;
    }
    cout << "]\n";
}

void print(const vector<string> &vec, string s= "") {
    cout << s <<"[";
    for (int i = 0; i < vec.size(); i++)
    {
        if(i!=0)
            cout << ", ";
        cout << vec[i];
    }
    cout << "]\n";
}

void print(const list<string> &lst, string s= "") {
    cout << s <<"[";
    for (auto it = lst.cbegin(); it != lst.cend(); it++)
    {
        if(it!=lst.cbegin())
            cout << ", ";
        cout << *it;
    }
    cout << "]\n";
}
/*
    Question 1.

    Write an application that will read in a number of integers from a file and store them in
    a vector. Allow the user to search through the vector and find the position of any userdefined number.


void question1()
{

    ifstream fin("nums.txt");
    if(fin)
    {
        vector<int> nums;
        while(!fin.eof())
        {
            int num;
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
        int key, pos=-1;
        cout << "Please enter number to find." << endl;
        cin >> key;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] == key)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
            cout << key << " not found in the vector." <<endl;
        else
            cout << key << " found in the vector at position " << pos << "." <<endl;
    }
}
void question2()
{
    ifstream fin("nums.txt");
    if(fin)
    {
        list<int> nums;
        while(!fin.eof())
        {
            int num;
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
        int key, pos=-1;
        cout << "Please enter number to find." << endl;
        cin >> key;
        int i = 0;
        for(auto it = nums.cbegin(); it != nums.cend(); it++)
        {
            if(*it == key)
            {
                pos = i;
                break;
            }
            i++;
        }
        if(pos == -1)
            cout << key << " not found in the vector." <<endl;
        else
            cout << key << " found in the vector at position " << pos << "." <<endl;
    }
}

 void question3()
{
    ifstream fin("nums.txt");
    if(fin)
    {
        vector<int> nums;
        while(!fin.eof())
        {
            int num;
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
        sort(nums.begin(), nums.end());

        print(nums, "After sorting inputted numbers. ");
        int key, pos=-1;
        cout << "Please enter number to find." << endl;
        cin >> key;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] == key)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
            cout << key << " not found in the vector." <<endl;
        else
            cout << key << " found in the vector at position " << pos << "." <<endl;
    }
}

 // https://codeshare.io/2jbpZR


void print(const vector<int> &vec, string s= "") {
    cout << s <<"[";
    for (int i = 0; i < vec.size(); i++)
    {
        if(i!=0)
            cout << ", ";
        cout << vec[i];
    }
    cout << "]\n";
}

/*
 Question 4.
 Investigate the sort() function, used to sort vector (or list) contents, and see if you can
write the code to sort a vector of strings by the length of the strings. Write the code to
sort the strings in ascending order, by length. (Hint: See sort() documentation and write
a compare function).


void question4()
{
    vector<string> words {"this", "is", "a", "random", "collection", "of", "words"};
    print(words, "Original list of words");
    sort(words.begin(), words.end(), [](string s1, string s2){ return s1.length() < s2.length();});
    print(words, "List of words after sorting");
}

sort(words.begin(), words.end(), [](string s1, string s2){ return s1.length() < s2.length();});
print(words, "List of words after sorting");
}.

int main() {
    question1();
    return 0;
}

*/