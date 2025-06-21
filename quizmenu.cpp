#include <iostream>
#include <windows.h> // Highlight function
#include <conio.h> // getch() function (for key input)

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

//Function definitions
int main();
void White_HL(string text);
void DrawQues(int input);
void DummyOption();
void SelectOption(int option);
void MenuSelection();


// Highlight Function
void White_HL(string text){ 
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 112);
    cout << text;
    SetConsoleTextAttribute(hConsole, 15);
}

// Draws the question on the screen
void DrawQues(int input){
    system("cls");

    // Set quiz function to show text
    cout << "This is a question?" << endl;

    cout << endl;


    // Highlights text based on input
    if (input == 0){
        cout << "--> "; White_HL("Yes"); cout << endl;
    }
    else{
        cout << "--> Yes" << endl;
    }

    if (input == 1){
        cout << "--> "; White_HL("No"); cout << endl;
    }
    else{
        cout << "--> No" << endl;
    }


}

void DummyOption(){
    system("cls");
    cout << "Hello" << endl;
    getch();

    main();
}

// Executes function based on selected option
void SelectOption(int option){

    switch (option){
        case 0:
            DummyOption();
        break;
        case 1:
            DummyOption();
        break;
    }
}


// Key inputs for selecting the question with arrow keys
void MenuSelection(){

    int y = 0;
    DrawQues(y); // Draw question once

    // Range of selection 0 - 2
    while(true){
        switch (getch()){
            case KEY_UP:
            if (y <= 1 && y > 0){
                y--;
                DrawQues(y);
            }
            break; 
            case KEY_DOWN:
            if (y < 1 && y >= 0){
                y++;
                DrawQues(y);
            }
            break;
            case KEY_ENTER:
            SelectOption(y);
            break;
        }
    }
}

int main(){

    MenuSelection();

    return 0;
}