/* Author: Evelyn Pan
 * Assignment Title: Project 11
 * Assignment Description: GPS
 *
 * Due Date: 2/23/22
 * Date Created: 2/22/22
 * Date Last Modified: 2/23/22
*/

/* Data Abstraction: Output file stream is opened.
 * Program sets fileName, distToStart, currx,
 * curry, startx, starty,
 *
 // Input: The program reads input as the precursor.
 * The program uses loop function to check and
 * make sure the fileName is right and opens.
 *
 // Process:
 * Program checks
 *
 //Output:
 * Outputs the final location, total distance
 * traveled, distances to starting point,
 * and average distance to starting point.
 *
 // Assumptions:
 * It is assumed that:
 * If the user puts in a suitable double commands,
 * the program will run efficiently.
 *
*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    
    //data abstraction
    ifstream inputFile;
    string fileName, command, junk;
    double distToStart, currx, curry, startx, starty,
    prevx, prevy, avg, stopx, stopy, d1, d2;
    double totalDist = 0.0, totalDistStart = 0.0;
    int count = 0;
    bool tripStarted = false, tripStopped = false;
    
    //input
    do {
        cout << "Please Enter The Name Of The Data File: ";
        cin >> fileName;
        cout << fileName << endl;
        inputFile.open(fileName);
        if (!inputFile) {
            cout << "Error: File failed to open. " << endl;
        }
    } while (!inputFile);
    cout << endl;
    
    
    
    //process
    getline(inputFile, junk);
    getline(inputFile, junk);
    

    while (!tripStarted) {
        inputFile >> command >> currx >> curry;
        if (command == "START") {
            tripStarted = true;
            startx = currx;
            starty = curry;
        }
    }
    
    do {
        prevx = currx;
        prevy = curry;
        inputFile >> command >> currx >> curry;
        if (command == "STOP") {
            tripStopped = true;
        }
        else {
            d1 = sqrt(pow(currx - prevx, 2) + pow(curry - prevy, 2));
            d2 = sqrt(pow(startx - currx, 2) + pow(starty - curry, 2));
            totalDist = totalDist + d1;
            totalDistStart = totalDistStart + d2;
            count++;
        }
    } while (!tripStopped);
    
    stopx = currx;
    stopy = curry;
        
    distToStart = sqrt(pow(startx - stopx, 2) + pow(starty - stopy, 2));
    avg = totalDistStart / count;
    
    
    //output
    cout << fixed << setprecision(1) << endl;
    cout << "Final Location: (" << currx << ", " << curry << ")" << endl;
    cout << "Total distance traveled " << totalDist << endl;
    cout << "Distance to starting point " << distToStart << endl;
    cout << "Average distance to start point = " << avg << endl;
    
    inputFile.close();
    
    return 0;
    
}
    

        




