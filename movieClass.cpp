//COMSC-210 | Lab 15 | Eric-Giulio Hedes
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Set up the Movie class
class Movie
{
    //Private is used for variables
    private:
        string name, screenwriter;
        int year;
    //Public is used for external-use functions
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
            cout << "Movie: " << getName() << endl; //Print the movie name
            cout << "Year released: " << getYear() << endl; //Print the year released
            cout << "Screenwriter: " << getScreenWriter() << endl << endl; //Print the screenwriter
        }
};

//Start of main()
int main()
{
    //Declare the movies file, which opens "input.txt"
    ifstream movies;
    movies.open("input.txt");
    //Also declare the movList vector, which will be used for storing & printing
    vector<Movie> movList;
    //The failed bool is used if the input file doesn't exist
    bool failed = false;

    string s, n; //Stores name and screenwriter
    int y; //Stores year
    
    //Check if the movie text file is valid
    if (movies.good())
    {
        //Do a while loop & scan the lines
        while (getline(movies, s))
        {
            //Store the values to temporary values
            movies >> y;
            movies.ignore(1000, 10);
            getline(movies, n);
            //Create a temporary Movie object
            Movie temp;
            //Store the variables into the temporary ovject
            temp.setScreenWriter(s);
            temp.setYear(y);
            temp.setName(n);
            //Finally, use push_back to store all object variables into the movList vector
            movList.push_back(temp);
        }

        //Close the text file
        movies.close();
    }
    else //If there is no input file, generate an error message
    {
        cout << "Invalid text file. Try again next time!" << endl;
        failed = true; //Also set failed to true if there is no input file
    }
    
    //Print the movie list
    if (!failed) //Only print it out if the failed boolean is false
    {
        for (int i = 0; i < movList.size(); i++)
            movList[i].print();
    }
}
//End of main()