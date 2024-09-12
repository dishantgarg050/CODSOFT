#include <iostream>
#include <cstdlib>  // For rand() and srand() from this dictionary
#include <ctime>    // For time() from this dictionary

using namespace std;

int main() 
{
    // Seed the random no generator with the current time
    srand(time(0));

    // Generate a random no between int min and int max
    int randomNo = rand();

    // Generate a random no between 1 and 100
      //int randomNo = rand() % 100 + 1;

    cout<<"random no:"<<randomNo<<endl;
    
    int guess = 0;
  bool iscorrectguess = false;

    
  // cout << "Guess the no between 1 and 100: ";
      cout<<"Guess the no:";
     while(guess!= randomNo)
     {
  
        cin >> guess;//  user to guess the no until the correct no is found

        if (guess > randomNo) 
        {
            cout << "Guess is too high! again guess it: ";
            
        } 
        else if (guess < randomNo) 
        {
            cout << "Guess is too low! again guess it: ";
            
        } 
    
        else
        {
            cout << "Congratulations! You guessed the correct no: " << randomNo << endl;
           iscorrectguess = true;
            break; //break for out of  loop
        }

     if(iscorrectguess ==true)
     {
       break;
     }
     }

    return 0;
}

