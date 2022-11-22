
/******************************************************************* ** 
** Program: assignment1.cpp
** Author: Kaushik Dontula
** Date: 10/07/2022
** Description: This program simulates a bowling game and outputs a scoreboard for the user to see how much they bowled. 
** Input: integers. 
** Output: scoreboard that shows the runningtotal of the users rolls.  
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;


/******************************************************************* 
** Function: get_name
** Description: This function gets the name of the user
** Parameters: string name 
** Pre-conditions: the string name has to be made in int main or wherever it is being called
** Post-conditions: passes back the name by reference
*******************************************************************/
void get_name(string &n){
    cout <<  endl << "Enter your name: ";
    cin >> n;
    
}




/******************************************************************* 
** Function: getinput
** Description: This function  greets the user and gets the input of the user of whether they want want to roll or not. 
** Parameters: string input and string n 
** Pre-conditions: the string name has to be made in int main or wherever it is being called and the input string also has to be made in int main
** Post-conditions: passes back the input string by reference
*******************************************************************/
void getinput(string &input, string n){
    cin.ignore();
    cout << endl << "Hello, " << n << endl << "Press 1 to bowl ";
    getline(cin, input);
    return;
}





/******************************************************************* 
** Function: check_input
** Description: This function checks the input of the user and error handles it 
** Parameters: string input 
** Pre-conditions: the string name has to be made in int main
** Post-conditions: passes back the input string by reference and repeats the invalid input screen until the user inputs something valid
*******************************************************************/
void check_input(string &input){
    while (!(input[0] == '1' && input.length() ==1)){
        cout << "That was an invalid input, please try again: ";
        getline(cin, input);
    }
    while (input[0] == '1' && input.length() ==1){
        return;
    }
}





/*******************************************************************
** Function: print_display
** Description: This function  prints the display board whenever it is called with the updated scores and totals 
** Parameters: int bowl1[], int bowl2[], int score[], int total[], int i, int runningtotal
** Pre-conditions: arrays have to be initialized and the integers as well
** Post-conditions: nothign is passed by reference other than the arrays, no changes are being made in this function. Simply printing out the score board. 
*******************************************************************/

void print_display(int bowl1[], int bowl2[], int score[], int total[], int i, int runningtotal){
    cout << endl << endl << "Player 1" << endl;
    cout << "   1     2      3      4       5      6     7      8      9     10 " << endl;
    cout << "________________________________________________________________________________________" << endl;
    for(int i=1; i<11; i++){
        if (( bowl1[i] != 10) && (bowl1[i] + bowl2[i] == 10)){
             cout << setw(2) << "| " << bowl1[i] << " " << "/" << " |";
         }
            else if (bowl1[i] == 10){
                cout << setw(2) << "|  X  |";
            }

        if (bowl1[i] == -1 && bowl2[i] == -1){
            cout << "|     |";
        }
        if((bowl1[i] < 10 && bowl1[i]>0) && (bowl2[i] < 10 && bowl2[i]>0) && (bowl1[i]+bowl2[i] != 10)){
            cout << setw(2) << "| " << bowl1[i] << " " << bowl2[i] << " |";
        }
            else if ((bowl1[i] == 0) && (bowl2[i]>0 && bowl2[i] < 10) && (bowl1[i]+bowl2[i] != 10)){
                cout << setw(2) << "| -" << " " << bowl2[i] << " |";
            }
            else if ((bowl2[i] == 0) && (bowl1[i]>0 && bowl1[i] < 10) && (bowl1[i]+bowl2[i] != 10)){
                cout << setw(2) << "| "  << bowl1[i]<< " " << "- |";
            }
            else if((bowl1[i] == 0 && bowl2[i] == 0)){
                cout << setw(2) << "|  " << "-" << "  |";
            }
        if((i == 10 && bowl1[i] == 10)){
            cout << " " << bowl1[i+1] << " " << bowl2[i+1] << " ";
        }
            else if (((i == 10) && (bowl1[i] + bowl2[i] == 10) && (bowl1[i] != 10))){
                cout << " " << bowl1[i+1] << "   ";
            }
        
        
    }

    cout << "Total: " << endl;
    for (int i=1; i<11;i++){
        if (bowl1[i] == -1 && bowl2[i] == -1){
            cout << "|     |";
        }
            else{
                 cout << setw(2) << "|  " << score[i] << " |";
             }
        
        
    }
    cout << "  " << runningtotal;
    cout << endl << "_________________________________________________________________________________________" << endl;
}




/******************************************************************* 
** Function: check_spare
** Description: This function checks if the frame of the users two rolls are a spare or not 
** Parameters: all variables declared in the int main
** Pre-conditions: arrays have to be initialized and the integers as well
** Post-conditions: runningtotal, pins1, and pins2 are passed by reference as well as all the arrays. But no changes are being made to the arrays.  
*******************************************************************/

void check_spare1(int &pins1, int &pins2, string bowlinput, int bowl1[], int bowl2[], int score[], int total[], int i,int &runningtotal){
    if (bowl1[i-1] +bowl2[i-1] == 10 && i>1 && bowl1[i-1] != 10){
        pins1 = pins1*2;
    }
};





/******************************************************************* 
** Function: check_strike
** Description: This function checks if the frame of the users first roll is a strike or not 
** Parameters: all variables declared in the int main
** Pre-conditions: arrays have to be initialized and the integers as well
** Post-conditions: runningtotal, pins1, and pins2 are passed by reference as well as all the arrays. But no changes are being made to the arrays.  
*******************************************************************/
void check_strike1(int &pins1, int &pins2, string bowlinput, int bowl1[], int bowl2[], int score[], int total[], int i,int &runningtotal){
    if((bowl1[i-1] == 10 && i>1) && (bowl1[i-2] == 10 && i>1)){
        // int temp;
        // temp = bowl1[i-2];
        pins1 += 10 + bowl1[i] + bowl2[i];

    }
        else if (bowl1[i-1] == 10 && i>1){
            pins1 = pins1*2;
            pins2 = pins2*2;
        }
}




/******************************************************************* 
** Function: bowl
** Description: This function allows the user to bowl. It has the random function and assigns it to integers and arrays to keep track of scores and rolls 
** Parameters: int score[], int bowl1[], int bowl2[], int runningtotal
** Pre-conditions: arrays have to be initialized and the integers as well
** Post-conditions: arrays are passed by reference but runningtotal is not. This function calls the print display function which outputs a scoreboard.   
*******************************************************************/
void error_playagain(int &p){
    while (p != 0 && p != 1){
        cin.clear();
        cin.ignore(123, '\n');
        cout << "That was an invalid play again value, please try again: ";
        cin >> p;
    }
}





/******************************************************************* 
** Function: tenth_frame_strike
** Description: This function checks if the frame is the tenth frame, and if so and if the user rolls a strike on the tenth frame it will allow two more rolls. 
** Parameters: all variables declared in the int main
** Pre-conditions: arrays have to be initialized and the integers as well
** Post-conditions: runningtotal, pins1, and pins2 are passed by reference as well as all the arrays. But no changes are being made to the arrays.  
*******************************************************************/
void tenth_frame_strike(int &i, int pins1, int pins2, int &runningtotal, int bowl1[], int bowl2[], int total[], int score[], string bowlinput){
    if (i == 10 && bowl1[i] == 10){
            pins1 = 0;
            pins2 = 0;
            i = i+1;
            cout << endl << endl << "You rolled a strike on the tenth frame! You get two extra rolls "  << endl;
            pins1 = rand() % 11;
            cout << "You bowled: " << pins1 << " pins " << endl;

            cout << "enter 1 to roll again ";
            getline(cin,bowlinput);
            check_input(bowlinput);

            pins2 = rand() % (10+1 - pins1);
            cout << endl << "Your second roll was: " << pins2 << " pins " << endl;

            bowl1[i] = pins1;
            bowl2[i] = pins2;
            total[i] = pins1+pins2;
            runningtotal += total[i];
            score[i] = runningtotal;
            print_display(bowl1, bowl2, score, total,i, runningtotal);
        }
}





/******************************************************************* 
** Function: tenth_frame_spare
** Description: This function checks if the frame is the tenth frame, and if so and if the user rolls a spare on the tenth frame it will allow one more roll. 
** Parameters: all variables declared in the int main
** Pre-conditions: arrays have to be initialized and the integers as well
** Post-conditions: runningtotal, pins1, and pins2 are passed by reference as well as all the arrays. But no changes are being made to the arrays.  
*******************************************************************/
void tenth_frame_spare(int &i, int pins1, int pins2, int &runningtotal, int bowl1[], int bowl2[], int total[], int score[], string bowlinput){
    if ((i == 10) && (bowl1[i] + bowl2[i] == 10)){
            pins1 = 0;
            i = i+1;
            cout << endl << endl << "You rolled a spare on the tenth frame! You get one extra roll" << endl;
            cout << "enter 1 to roll again ";
                getline(cin,bowlinput);
                check_input(bowlinput);
            
            pins1 = rand() % 11;
            cout << "You bowled: " << pins1 << " pins " << endl;

            bowl1[i] = pins1;
            //bowl2[i] = pins2;
            total[i] = pins1;
            runningtotal += total[i];
            score[i] = runningtotal;
            print_display(bowl1, bowl2, score, total,i, runningtotal);
    }
}





/******************************************************************* 
** Function: bowl
** Description: This function allows the user to bowl. It has the random function and assigns it to integers and arrays to keep track of scores and rolls 
** Parameters: int score[], int bowl1[], int bowl2[], int runningtotal
** Pre-conditions: arrays have to be initialized and the integers as well
** Post-conditions: arrays are passed by reference but runningtotal is not. This function calls the print display function which outputs a scoreboard.   
*******************************************************************/
void bowl(int score[], int bowl1[], int bowl2[], int runningtotal){
    for (int i=1;i<11;i++){
        int pins1 = 0;
        int pins2 = 0;
        string bowlinput;
        int total[11];

        cout << endl << endl << "Frame " << i << endl;
        pins1 = rand() % 11;
        cout << "You bowled: " << pins1 << " pins " << endl;

        if(pins1 != 10){
            cout << "enter 1 to roll again ";
            getline(cin,bowlinput);
            check_input(bowlinput);

            pins2 = rand() % (10+1 - pins1);
            cout << "Your second roll was: " << pins2 << " pins " << endl;
        }

        bowl1[i] = pins1;
        bowl2[i] = pins2; 
        if((i < 11) && (bowl1[10] != 10) || (bowl1[10] + bowl2[10] != 10)){
            check_strike1(pins1, pins2, bowlinput, bowl1, bowl2, score, total, i, runningtotal);
            check_spare1(pins1, pins2, bowlinput, bowl1, bowl2, score, total, i, runningtotal);
        }
        total[i] = pins1+pins2;
        runningtotal += total[i];
        score[i] = runningtotal;
        print_display(bowl1, bowl2, score, total,i, runningtotal);

        cout << "enter 1 to go to next frame and roll again ";
        getline(cin,bowlinput);
        check_input(bowlinput);
        
        if(i == 10 && ((bowl1[10] == 10) || (bowl1[10] + bowl2[10] == 10))){
            check_strike1(pins1, pins2, bowlinput, bowl1, bowl2, score, total, i, runningtotal);
            check_spare1(pins1, pins2, bowlinput, bowl1, bowl2, score, total, i, runningtotal);
            tenth_frame_strike(i, pins1, pins2, runningtotal, bowl1, bowl2, total, score, bowlinput);
            tenth_frame_spare(i, pins1, pins2, runningtotal, bowl1, bowl2, total, score, bowlinput);
        }
    }
}




int main(){
int play;
do{
    int runningtotal=0;
    string name;
    get_name(name);

    
    string bowlinput;
    getinput(bowlinput, name);

    check_input(bowlinput);

    srand(time(NULL));

    int score[12];
    int bowl1[12];
    int bowl2[12];

    for(int i = 0; i <= 10; i++){
        score[i] = -1;
    }

    for(int j = 0; j <= 11; j++){
        bowl1[j] = -1;
    }

    for(int k = 0; k <= 11; k++){
        bowl2[k] = -1;
    }
    

    bowl(score,bowl1,bowl2,runningtotal);
    cout << "Do you want to play again (0-no 1-yes): ";
    cin >> play;
    error_playagain(play);

}while(play == 1);
return 0;
}