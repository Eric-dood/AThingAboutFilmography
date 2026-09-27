//COMSC-210 | Lab 15 | Eric-Giulio Hedes
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
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
        void print()
        {
            cout << "Movie: " << getName() << endl;
            cout << "Year released: " << getYear() << endl;
            cout << "Screenwriter: " << getScreenWriter() << endl << endl;
        }
};

int main()
{
    ifstream movies;
    movies.open("input.txt");
    vector<Movie> movList;

    string s, n; //Stores name and screenwriter
    int y; //Stores year
    if (movies.good())
    {
        while (getline(movies, s))
        {
            movies >> y;
            movies.ignore(1000, 10);
            getline(movies, n);

            Movie temp;
            temp.setScreenWriter(s);
            temp.setYear(y);
            temp.setName(n);
            movList.push_back(temp);
        }

        movies.close();
    }
    else
        cout << "Invalid text file. Try again next time!" << endl;
    
    //Print the movie list
    for (int i = 0; i < movList.size(); i++)
        movList[i].print();
}