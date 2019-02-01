/** 
 * Matthew Miles
 * Date worked on: 12/6/2016 - 12/13/2016
 * Purpose: simple database to store and retrieve student information
 */

#include <iostream>
#include <fstream>
#include "database.h"
using namespace std;

int main()
{
    char filename[256], Trash[2];
    database object; //create an object
    cout << "Welcome to student information database" << endl;
    cout << "Please enter a file name: ";
    cin.getline(filename, 256); //get a filename from user input
    if(ifstream(filename)) //if the file exists
    {
        int option;
        cout << "File already exists" << endl;
        cout << "1 to add info" << endl << "2 to search" << endl;
        cin >> option;
        cin.getline(Trash, 2);
        if(option == 1) //if user enters 1
            object.add(filename); //add information to file
        if(option == 2)
        {
            string key;
            cout << "Enter a search phrase: ";
            getline(cin, key);
            object.search(filename, key); //search file for the search phrase
        }
    }
    else //if the file doesnt exist
    {
        object.fileCreate(filename); //create a new file
        int option;
        cout << "Would you like to add data? (1 for yes): ";
        cin >> option;
        cin.getline(Trash, 2);
        if(option == 1)
            object.add(filename); //add information to file
    }
    return 0;
}