// Author - Nathaniel Rupsis

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// User class
class User{
    private:
        int numOfCoins; // number of coins the user currently has
        string userId; // the users ID

    public:
        User(string id){
            this->numOfCoins = 0; // set the default number of coins to zero
            this->userId = id;   // set the user id
        }
        // getter for users coins
        int getNumOfCoins(){
            return this->numOfCoins; 
        }
        string getUserId(){
            return this->userId; 
        }
        void addCoin(){
            this->numOfCoins++; // increment the coin count by one
        }
};

vector<User> players;
// function prototypes
bool handleGuess(string, int);
int getCoins(string);
void startGuessing(User);



int main(){
    

    // generate a random seed
    srand((int) time(0));
    User nate = User("1");
    players.push_back(nate);
    // a sample set of objects 

    startGuessing(nate);




    return 0;
}

void startGuessing(User player){
     int userGuess;
     string userAnswer;

        // run the program once
    do{
        cout << "Players coins: " << player.getNumOfCoins() << endl;
        
        // prompt user for guess    
        cout << "Enter Guess: " << endl;

        // check to see if guess is correct
        cin >> userGuess;
        // pass the user's id and guess to the handle guess function which returns a boolean value
        if(handleGuess(player.getUserId(), userGuess)){
            cout << "Correct!" << endl;
            player.addCoin();// if correct, add a coin to count
        }
        
        // else prompt the user if they would like to play again
        cout << "would you like to play again (Y/N)?" << endl;

        cin >> userAnswer;
        
       

    }while(userAnswer == "Y"); // continue the loop till the player doesn't enter yes
}


// returns the coins for the specified user ID
int getCoins(string userId){
    for(int i = 0; i < players.size(); i++){
        if(userId == players[i].getUserId()){
            return players[i].getNumOfCoins(); 
            // of the user ID matched the passed argument, return the objects coin count
        }
    }
    cout << "User ID not found" << endl;
    return -1; // if the idea isn't found, return negative one as error
}

// function to handle user's guess
bool handleGuess(string userId, int userGuess){
    int randomNum = ((rand() % 10) + 1); // generates a random int

    if(userGuess == randomNum){
        return true;
    }else{
        cout << "Sorry, the answer was: " << randomNum << endl;
        return false;
    }

}