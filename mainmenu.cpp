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
void DrawMenu(int input);
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

// Draws the menu on the screen
void DrawMenu(int input){
    system("cls");

    cout << "Digital Responsibility Checker" << endl;
    cout << endl;

    // Highlights text based on input
    if (input == 0){
        cout << "1. "; White_HL("Daily Digital Time Tracker"); cout << endl;
    }
    else{
        cout << "1. Daily Digital Time Tracker" << endl;
    }

    if (input == 1){
        cout << "2. "; White_HL("Digital Sharing Quiz"); cout << endl;
    }
    else{
        cout << "2. Digital Sharing Quiz" << endl;
    }

    if (input == 2){
        cout << "3. "; White_HL("Exit"); cout << endl;
    }
    else{
        cout << "3. Exit" << endl;
    }


    cout << input << endl;

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
        case 2:
            system("cls");
            exit(0);
        break;
    }
}


// Key inputs for selecting the menu with arrow keys
void MenuSelection(){

    int y = 0;
    DrawMenu(y); // Draw menu once

    // Range of selection 0 - 2
    while(true){
        switch (getch()){
            case KEY_UP:
            if (y <= 2 && y > 0){
                y--;
                DrawMenu(y);
            }
            break; 
            case KEY_DOWN:
            if (y < 2 && y >= 0){
                y++;
                DrawMenu(y);
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