#include <iostream>
#include <iomanip>      // for setw()
#include <string>       // for string
#include <cmath>        // for sqrt()
using namespace std; 

// This function computes the distance between two villages 
// with coordinates (x1, y1) and (x2, y2).
double distance(double x1, double y1, double x2, double y2);

int main()
{
    const int NUM_VILLAGES = 5;
    const int PRINT_WIDTH = 10; 

    // village names and coordinates
    string villages[NUM_VILLAGES] = {"Gezer",   "Tapuach",  "Shezif",   "Petel",    "Gefen"};
    double xPos[NUM_VILLAGES] =     {100,       -100,       100,        -100,       0};
    double yPos[NUM_VILLAGES] =     {100,       100,        -100,       -100,       0};

    // distance matrix - a two-dimensional array
    double dist[NUM_VILLAGES][NUM_VILLAGES];
    
    // compute the distances between all villages
    // and store them in the distance matrix
    for(int i = 0; i < NUM_VILLAGES; i++)
    {
        for(int j=0; j<NUM_VILLAGES; j++)
        {
            dist[i][j] = distance(xPos[i], yPos[i], xPos[j], yPos[j]);
        }
    }

    // find the two farthest villages
    int vill1, vill2;      // indexes of the two farthest villages in the villages array
    double maxDist = 0;    // the distance between the two farthest villages
    for(int i = 0; i < NUM_VILLAGES; i++)
    {
        for(int j=0; j < NUM_VILLAGES; j++)
        {
            if(maxDist < dist[i][j]) 
            {
                maxDist = dist[i][j];
                vill1 = i;
                vill2 = j;
            }
        }
    }
    
    // print the distance matrix and the farthest villages
    // print the  header (the names of the villages)
    cout << setw(PRINT_WIDTH) <<" ";
    for(int i = 0; i < NUM_VILLAGES; i++)
    {
        cout << setw(PRINT_WIDTH) << villages[i];
    }
    cout << endl;

    // print the distance matrix
    for(int i = 0; i < NUM_VILLAGES; i++)
    {
        cout << setw(PRINT_WIDTH) << villages[i];
        for(int j=0; j<NUM_VILLAGES; j++)
        {
            cout << setw(PRINT_WIDTH) << dist[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    // print the two farthest villages
    cout << "The farthest villages: " << villages[vill1] << " and " << villages[vill2] << endl;
    cout << "The distance :        " << maxDist << endl;
    cout << endl;
     
    system("pause");
    return 0;
}

double distance(double x1, double y1, double x2, double y2)
{
    return(sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)));
}

