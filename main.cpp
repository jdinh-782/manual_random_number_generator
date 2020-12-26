#include <iostream>
#include <vector>
#include "Timer.h"

using namespace std;


//recursive function for the fibonacci sequence
int fibonacci (int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}


//manual for loop for the fibonacci sequence
void fibonacciLoop (int n)
{
    int a = 0;
    int b = 1;
    int c;

    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    cout << a << " ";
    //1, 1, 2, 3, 5, 8, 13, 21...
}


int main()
{
    int maxNum;

    cout << "Enter a number: ";
    cin >> maxNum;

    int maxTemp = maxNum;
    int minNum = 0;
    int randomNumber = maxTemp / 2;
    int numArray[25]; //fills up array with numbers (size = 25)
    vector<int> numVector; //used to compare time spent on program

    //if the number inputted is 0, simply give 0's (no calculations)
    if (maxNum == 0)
    {
        for (int & i : numArray)
        {
            i = maxNum;
        }
    }

    else
    {
        for (int i = 0; i < 25; i++)
        {
            if (maxNum == 1)
            {
                maxTemp = 1;
            }
            maxTemp = i + 1 * (randomNumber % maxTemp) + i;
            minNum = minNum + 1 * minNum + 2;
            minNum++;
            randomNumber = minNum + maxTemp;

            //keep decrementing numbers until the number is less than or equal to the number inputted
            do
            {
                if (randomNumber <= maxNum)
                {
                    break;
                }
                randomNumber -= 5;
            } while(randomNumber > maxNum);

            //checks if the number is now negative so keep incrementing until its not negative
            do
            {
                if (randomNumber >= 0)
                {
                    break;
                }
                randomNumber += 5;
            } while(randomNumber < 0);

            //now check if the random number is greater than the number inputted
            if (randomNumber > maxNum)
            {
                randomNumber = randomNumber / 2;
            }

            //only check if the number inputted is 1 because
            if (maxNum == 1)
            {
                if (randomNumber < 0)
                {
                    randomNumber = 1;
                }
                else if (randomNumber > 1)
                {
                    randomNumber = 0;
                }
            }

            //finally store the new random number in the array
            numArray[i] = randomNumber;

            //finally store the new random number in the vector
            numVector.push_back(randomNumber);

            //cout << randomNumber << " ";
        }
    }

    //display the random numbers in array/vector
    for (int i : numArray)
    {
        cout << i << " ";
    }

    cout << endl << endl;

    Timer t;
    t.start();

    //around the 40th term, the fibonacci function begins to slow down/crash
    for (int i = 1; i <= 40; i++)
    {
        fibonacciLoop(i);
        //cout << fibonacci(i) << " ";
    }
    t.end();

    cout << "\n\nThis function took " << t.getDuration() << " seconds.";

    return 0;
}
