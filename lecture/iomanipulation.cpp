#include <iostream>
#include <iomanip>

using namespace std;

class Movies
{
    public:
    string name;
    string id;
    int year;
};

size_t findWidth(Movies[], int, string);

int main(int argc, char* argv[])
{
    Movies movieList[3];
    size_t nameWidth, idWidth;

    movieList[0].name = "Star Wars: IV - A New Hope";
    movieList[0].id = "tt0076759";
    movieList[0].year = 1977;
    movieList[1].name = "My Cousin Vinny";
    movieList[1].id = "tt0104952";
    movieList[1].year = 1992;
    movieList[2].name = "Spider-Man: the Spider-Verse";
    movieList[2].id = "tt9362722";
    movieList[2].year = 2023;

    nameWidth = findWidth(movieList, 3, "name");
    idWidth = findWidth(movieList, 3, "id");

    cout << left << setw(idWidth) << "ID" << " " << setw(nameWidth) << "Name" << " " << setw(5) << "Year" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << setw(idWidth) << movieList[i].id << " " 
             << setw(nameWidth) << movieList[i].name << " " 
             << setw(5) << movieList[i].year <<endl;
    }
    return 0;
}

size_t findWidth(Movies movieList[], int arrSize, string field)
{
    size_t width = 0;
    for(int i = 0; i < arrSize; i++)
    {
        if(field == "name") {
            if(movieList[i].name.length() > width){
                width = movieList[i].name.length()+1;
            }
        }
        if(field == "id") {
            if(movieList[i].id.length() > width){
                width = movieList[i].id.length()+1;
            }
        }
    }
    return width;
}