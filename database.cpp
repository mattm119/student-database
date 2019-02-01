#include <iostream>
#include <string>
#include <fstream>
#include "database.h"
using namespace std;

database::database() //constructor does nothing
{
    
}

database::~database() //destructor sets all double values to 0
{
    midterm = 0;
    finalgrade = 0;
    examAVG = 0;
    hw1 = 0;
    hw2 = 0;
    hw3 = 0;
    hwAVG = 0;
    attendance = 0;
    project = 0;
    overallGrade = 0;
}

void database::fileCreate(char fileName[]) //creates a file
{
    ofstream myFile(fileName); //creates an output stream
    if(myFile.is_open())
        cout << "File created: " << fileName << endl;
    else
        cout << "File could not be created" << endl;
}

void database::add(char fileName[]) //allows the user to add information
{
    ofstream fileAppend(fileName, ios::app); //prepares the file 
    
    cout << "Enter student name: ";
    cin.getline(studentName, 256);
    fileAppend << "Name: " << studentName << "\t";
    
    cout << "Student ID: ";
    cin.getline(studentID, 256);
    fileAppend << "ID: " << studentID << "\t";
    
    cout << "Current Year: ";
    cin.getline(year, 256);
    fileAppend << "Year: " << year << "\t";
    
    cout << "Department: ";
    cin.getline(department, 256);
    fileAppend << "Department: " << department << "\t";
    
    cout << "Mid-term Grade: ";
    cin >> midterm;
    fileAppend << "Midterm: " << midterm << "\t";
    
    cout << "Final exam grade: ";
    cin >> finalgrade;
    fileAppend << "Final Exam: " << finalgrade << "\t";
    
    examAVG = averageExam(midterm, finalgrade);
    fileAppend << "Exam Average: " << examAVG << "\t";
    
    cout << "HW 1 Grade: ";
    cin >> hw1;
    fileAppend << "HW1 Grade: " << hw1 << "\t";
    
    cout << "HW 2 Grade: ";
    cin >> hw2;
    fileAppend << "HW2 Grade: " << hw2 << "\t";
    
    cout << "HW 3 Grade: ";
    cin >> hw3;
    fileAppend << "HW3 Grade: " << hw3 << "\t";
    
    hwAVG = averageHW(hw1, hw2, hw3);
    fileAppend << "HW Average: " << hwAVG << "\t";
    
    cout << "Attendance: ";
    cin >> attendance;
    fileAppend << "Attendance: " << attendance << "\t";
    
    cout << "Project grade: ";
    cin >> project;
    fileAppend << "Project: " << project << "\t";
    
    overallGrade = overall(examAVG, hwAVG, project, attendance);
    fileAppend << "Overall Grade: " << overallGrade << "\t";
    
    letterGrade = lettergrade(overallGrade);
    fileAppend << "Letter Grade: " << letterGrade << endl;
    
    //allows the user to add more data, search the file, or end the program
    int option;
    char Trash[2];
    cout << "What would you like to do now?" << endl;
    cout << "1. Add more data" << endl << "2. Search the database" << endl;
    cout << "Press anything else to terminate" << endl;
    cin >> option;
    cin.getline(Trash, 2);
    if(option == 1)
    {
        add(fileName);
    }
    if(option == 2)
    {
        string key;
        cout << "Enter a search phrase: ";
        getline(cin, key);
        search(fileName, key);
    }
}

//allows the user to enter a search term to search for in the file
void database::search(char filename[], string key) 
{
    ifstream inFile; //input stream to operate on files
    string line;
    //cout << "you want to search for the phrase: " << key << endl;
    
    inFile.open(filename);
    
    size_t position; //unsigned int for use in comparing with string::npos
    while(inFile.good()) //while none of the streams flags (end of file for example) are set
    {
        getline(inFile, line);
        position = line.find(key);
        if(position!=string::npos)
        {
            cout << "Returning line where search key was found." << endl;
            cout << line << endl;
        }
    }
    
    //allows the user to add more data, search the file, or end the program
    int option;
    char Trash[2];
    cout << "What would you like to do now?" << endl;
    cout << "1. Add more data" << endl << "2. Search again" << endl;
    cout << "Press anything else to terminate" << endl;
    cin >> option;
    cin.getline(Trash, 2);
    if(option == 1)
    {
        add(filename);
    }
    if(option == 2)
    {
        string key;
        cout << "Enter a search phrase: ";
        getline(cin, key);
        search(filename, key);
    }
}

double database::averageExam(double x, double y) //returns exam grade average
{
    return (x+y)/2;
}

double database::averageHW(double x, double y, double z) //returns homework grade average
{
    return (x+y+z)/3;
}

double database::overall(double a, double b, double c, double d) //returns overall grade
{
    return (0.5*a)+(0.2*b)+(0.2*c)+(0.1*d);
}

string database::lettergrade(double myoverallgrade) //returns the overall grade as a letter using string
{
    if (myoverallgrade < 60.0)
        return "F";
    else if(myoverallgrade < 63.0)
        return "D-";
    else if(myoverallgrade < 66.0)
        return "D";
    else if(myoverallgrade < 70.0)
        return "D+";
    else if(myoverallgrade < 73.0)
        return "C-";
    else if(myoverallgrade < 76.0)
        return "C";
    else if(myoverallgrade < 80.0)
        return "C+";
    else if(myoverallgrade < 83.0)
        return "B-";
    else if(myoverallgrade < 86.0)
        return "B";
    else if(myoverallgrade < 90.0)
        return "B+";
    else if(myoverallgrade < 93.0)
        return "A-";
    else
        return "A";
}