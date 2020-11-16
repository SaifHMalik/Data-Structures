/*
IDE: Visual Code 1.51.1
Compiler: g++ (MinGW.org GCC Build-20200227-1) 9.2.0g++ (MinGW.org GCC Build-20200227-1) 9.2.0
cppStandard: c++17
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> neighbours; // checking neighbors
int rows, columns;
vector<vector<int>> track{{0, 0}}; //track for valid row and columns
vector<string> tracks;             // saves the track in the form required for output
char maze[50][50];                 // char array declared here(50 max column and rows)

// Checks Cell of Tracks so no cell is revisited
bool checkTrack(int i, int j)
{
    for (int k = 0; k < track.size(); k++)
    {
        if (track[k][0] == i && track[k][1] == j)
        {
            return true;
        }
    }
    return false;
}

// Prints Track Vector
void printTrack()
{
    for (int i = 0; i < track.size(); i++)
    {
        for (int j = 0; j < track[i].size(); j++)
        {
            cout << track[i][j] << ", ";
        }
        cout << "\t";
    }
    cout << endl;
}

// Print Neighbours Vector for error checking
void printNeighbours()
{
    for (int i = 0; i < neighbours.size(); i++)
    {
        cout << neighbours[i] << ",";
    }
    cout << endl;
}

// compare Lengths for sorting in ascending order
bool compareLen(string &a, string &b)
{
    return (a.size() < b.size());
}

// Formats a Path as required by output then stores in string vector tracks
void saveTrack()
{
    stringstream track_;
    track_ << "={(" << track[0][1] << "," << track[0][0] << ")";
    for (int i = 1; i < track.size(); i++)
    {
        track_ << ",(" << track[i][1] << "," << track[i][0] << ")";
    }
    track_ << "} Cost=" << track.size();
    tracks.push_back(track_.str());
}

// Write in Output FIle
void saveTracks()
{
    int count = 0;
    ofstream outputFile("OutputFile.txt");
    if (tracks.size() > 1)
    {
        sort(tracks.begin(), tracks.end(), compareLen); // sorts function from algorithm library
    }
    while (count < tracks.size())
    {
        outputFile << "Path#" << count + 1 << tracks[count] << endl;
        count++;
    }
}

// Recursive Function to search for valid paths in the Maze
void searchMaze(vector<int> index, int nextNeighbour)
{
    int k;
    int i = index[0];
    int j = index[1];
    if (neighbours.size() >= track.size())
    {
        neighbours.pop_back();
    }
    for (k = nextNeighbour + 1; k < 4; k++)
    {
        if (k == 0 && i > 0)
        {
            i--;
            neighbours.push_back(k);
            break;
        }
        else if (k == 1 && j > 0)
        {
            j--;
            neighbours.push_back(k);
            break;
        }
        else if (k == 2 && j < columns - 1)
        {
            j++;
            neighbours.push_back(k);
            break;
        }
        else if (k == 3 && i < rows - 1)
        {

            i++;
            neighbours.push_back(k);
            break;
        }
        else
        {
            continue;
        }
    }
    if (maze[i][j] == 'e')
    {
        track.push_back({i, j});
        saveTrack();
        track.pop_back();
        searchMaze(track.back(), neighbours.back());
    }
    else if (maze[i][j] == '0' && checkTrack(i, j) == false)
    {
        track.push_back({i, j});
        searchMaze(track.back(), -1);
    }
    else
    {
        if (track.size() <= 1)
        {
            return;
        }
        else
        {
            if (k == 4)
            {
                track.pop_back();
            }
            searchMaze(track.back(), neighbours.back());
        }
    }
}

int main()
{
    string inputString;
    int row = 0;
    ifstream inputFile("InputFile.txt");

    getline(inputFile, inputString);
    stringstream inputStream(inputString);
    getline(inputStream, inputString, ' ');
    rows = stoi(inputString);
    getline(inputStream, inputString, ' ');
    columns = stoi(inputString);
    char newMaze[rows][columns];
    while (row < rows)
    {
        getline(inputFile, inputString);
        inputStream.clear();
        inputStream.str(inputString);
        for (int i = 0; i < columns; i++)
        {
            getline(inputStream, inputString, ' ');
            newMaze[row][i] = inputString[0];
        }
        row++;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            maze[i][j] = newMaze[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (tolower(maze[i][j]) == 's')
            {
                track[0][0] = i;
                track[0][1] = j;
            }
        }
    }
    searchMaze(track.back(), -1);
    saveTracks();
}