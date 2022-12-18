#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


void appendToFile(const string& userInput){ //takes in user input
    ofstream file;
    file.open("CSC450_CT5_mod5.txt", ios::app); //open the file in append mode
    file << "\n" << userInput; //add new line then add userInput
    file.close(); //close file
}

string readFile(){
    ifstream read("CSC450_CT5_mod5.txt"); //generate input file stream object for the file
    ostringstream output;
    output << read.rdbuf();
    return output.str();
}

string reverseString(){
    string s = readFile(); //store what is returned from readFile() into s
    int length = s.length(); //set length to s.length()

    for (int i = 0; i < length/2; i++){ //iterate as long as i < half of the length
        swap(s[i], s[length - i  - 1]); //swap s @ i with s at the opposite end
    }
    return s; //return s
}

int main() {
    string input; //create new string called input
    cout << "Enter what you want to append to the file:"; //ask user for input
    getline(cin, input); //call getline function using cin for user input and input for storage

    appendToFile(input); //call appendToFile on userInput

    appendToFile( reverseString()); //call append to file on reverseString() return value
    return 0;

}
