#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <time.h>

using namespace std; //not wanting to type std in my program 50 times.


int getNumber() 
{
    string queryStr;
    while (true)
    {
        try
        {
            cout << "What is the number you want the algorithim to find: ";
            cin >> queryStr;
            int queryNum = stoi(queryStr);
            return queryNum;
        }
        catch(invalid_argument)
        {
            cout << "\nPlease input a number.\n";
        }
        
        
    }

    return 404;
}

int checkAnswer(int input, int answer) //return 2 if it's correct. 1 if it's more than. 0 if it's less than.
{
    if(input == answer) {
        //cout << "The algorithim has completed. The answer is: " << input;
        return 2;
    } else if(input < answer) {
        return 0;
    }else if(input > answer) {
        return 1;
    }

    return 50;//something went wrong if this function returns 50;
}

void useSortAlgorithim() 
{
    int min, max;
    string minStr, maxStr;
    while(true) 
    {
        try
        {
            cout << "\nWhat is the min number for this group: ";
            cin >> minStr;
            min = stoi(minStr);
            break;
        }
        catch(invalid_argument)
        {
            cout << "\nYou did not input valid data. Try again \n";
        }
    }

    while (true)
    {
        try
        {
            cout << "\nWhat is the max number in the group: ";
            cin >> maxStr;
            max = stoi(maxStr);
            if(min >= max) {
                cout << "\nYou cannot make max and min equal. You cannot make min greater than max.\n";
            }else {
                break;
            }
        }
        catch(const std::exception& e)
        {
            cout << "\nYou did not input valid data. Try again \n";
        }
    }
    

   int answer = getNumber();
   if(answer > max || answer < min) {
       cout << "\nYou did not input a number within your preset range. Please input your numbers again. \n";
       useSortAlgorithim();
   }
   int steps = 0;
    cout << "\n\n\n\n\nUsing split sort algorithim to find: " << answer << " between " << min << " and " << max << "\n\n\n";
    vector <int> numberList = {};

    for(int i = min; i <= max; i++) {
        //cout << i << "\t";
        numberList.push_back(i);
    }
    cout << "\n\nListing the group...\n\n";
    for(int i = 0; i < numberList.size(); i++) {
        cout << numberList[i] << "\t";
    }

    
    int activeIndex = 0;//start with #1
    vector <int> usedNumbers= {};
    
    cout << "\n\n\n\n\n\n\nStarting search with algorithim...\n\n\n";
    if(checkAnswer(numberList[activeIndex],answer) == 2) {
            cout << "the answer was right";
            return;
    } else if(checkAnswer(numberList[activeIndex],answer) == 0) {
            steps++;
            cout <<"\ntesting: " << numberList[activeIndex] << "\ntoo low\n";
            numberList.erase(numberList.begin()+activeIndex);
            activeIndex = numberList.size()-1;//move to #15
    }
    //first check lowest number. Then check highest number.
    while (checkAnswer(numberList[activeIndex],answer) != 2){
        cout << "testing: " << numberList[activeIndex] << "\n";
         if(checkAnswer(numberList[activeIndex],answer) == 1) {//too high case
            cout << "too high\n";
            numberList.erase(numberList.begin()+activeIndex, numberList.begin() + numberList.size());
            activeIndex = (((numberList.size()-1) / 2));
            steps++;
        } else if(checkAnswer(numberList[activeIndex],answer) == 0) {
            cout << "too low\n";
            numberList.erase(numberList.begin()-1, numberList.begin() + activeIndex); 
            activeIndex = ((numberList.size()-1)/2);
            steps++;
        } 
    }
   
    cout << "The algorithim returned: " << numberList[activeIndex] << ". \n\nFound in " << steps+1 << " steps from: " << abs(min)+abs(max) << " results." "\n\n\nMade by Luke Fisher";
}

int main() 
{ 
    useSortAlgorithim();
    return 0;
}
