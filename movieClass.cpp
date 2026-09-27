//COMSC-210 | Lab 15 | Eric-Giulio Hedes
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

//Set up the Movie class
class Movie
{
    private:
        string name, screenwriter;
        int year;
    public:
        //Getter funcitons
        string getScreenWriter() { return screenwriter; }
        string getName() { return name; }
        int getYear() { return year; }
        //Setter functions
        void setScreenWriter(string msg) { screenwriter = msg; }
        void setName(string msg) { name = msg; }
        void setYear(int val) { year = val; }
        //Set up the print function
        void print();
};