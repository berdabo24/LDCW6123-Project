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
void DisplayAns(string answer);
void SelectOption(int option);
void CreateQuestion();
void SetQuiz(int i);
void border();

// Declare variables
int QUIZ_SIZE=7, i=0, marks = 0;
string question[7], comment[7], correctAnswers[7], reason[7];

int CurrentQues = 0;


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
    cout << question[CurrentQues] << endl << endl;
    border();

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

void DisplayAns(string answer){
    cout << endl;
    border();
    cout << endl;


    if (answer == correctAnswers[CurrentQues]){
        cout << comment[CurrentQues] << endl;
        cout << reason[CurrentQues] << endl;
        marks++;
    }
    else{
        cout << correctAnswers[CurrentQues] << endl;
        cout << reason[CurrentQues] << endl;
    }


    
}

// Executes function based on selected option
void SelectOption(int option){

    switch (option){
        case 0:
            DisplayAns("Yes");
        break;
        case 1:
            DisplayAns("No");
        break;
    }
}


// Creates the question with menu selection
void CreateQuestion(){

    int y = 0;
    DrawQues(y); // Draw question once

    // Range of selection 0 - 2
    bool loop = true;
    while(loop){
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
            getch();
            loop = false;
            break;
        }
    }
}


void border() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

// Function to display the quiz questions
void SetQuiz(int i) {

    CurrentQues = i;

    if (i == 0) {
        question[i] = "Should personal details like full names, addresses, or contact info be shared online publicly?";
        comment[i] = "Yeahh!";
        correctAnswers[i] = "No";
        reason[i] = "Sharing such information can put individuals at risk of identity theft, cyberstalking, or other safety concerns.";
    }
    else if (i == 1) {
        question[i] = "Is it okay to share someone else's photo on social media without their permission?";
        comment[i] = "Yeahh!";
        correctAnswers[i] = "No";
        reason[i] = "Sharing someone's image without consent is a violation of their privacy and can be considered unethical, even if it was taken in a public place.";
    }
    else if (i == 2) {
        question[i] = "Is it appropriate to use someone else's work in your presentation without giving credit?";
        comment[i] = "Yeahh!";
        correctAnswers[i] = "No";
        reason[i] = "This is plagiarism. Proper attribution respects intellectual property and promotes academic and ethical integrity.";
    }
    else if (i == 3) {
        question[i] = "Is it ethical to download copyrighted music or movies from unofficial websites?";
        comment[i] = "Yeahh!";
        correctAnswers[i] = "No";
        reason[i] = "It's a form of digital piracy, which infringes on creators' intellectual property rights and is illegal in many countries.";
    }
    else if (i == 4) {
        question[i] = "Should you check the credibility of a news source before reposting an article?";
        comment[i] = "Yeahh!";
        correctAnswers[i] = "Yes";
        reason[i] = "Verifying sources helps prevent the spread of misinformation, which is a major ethical responsibility in digital spaces.";
    }
    else if (i == 5) {
        question[i] = "Is it ethical to share viral content if it contains misinformation or unverified facts?";
        comment[i] = "Yeahh!";
        correctAnswers[i] = "No";
        reason[i] = "Spreading unverified content contributes to digital misinformation and can have real-world consequences, especially in crisis situations.";
    }
    else if (i == 6) {
        question[i] = "Can sharing fake profiles or impersonations online lead to legal consequences?";
        comment[i] = "Yeahh!";
        correctAnswers[i] = "Yes";
        reason[i] = "Impersonating someone or spreading fake identities can result in legal action under fraud, harassment, or cybercrime laws.";
    }

    CreateQuestion();
}

int main() {

    // Main quiz loop
    for (i = 0; i <= 6; i++){
        SetQuiz(i);
    }

    cout << endl;

    cout << marks << "/6" << endl;

    // Set calculations and final statements here

    cout << "endofline" << endl;

    return 0;
}