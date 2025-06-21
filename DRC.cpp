#include <iostream>
#include <windows.h> // Highlight function
#include <conio.h> // getch() function (for key input)

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

//Function definitions

//Menu functions
int main();
void White_HL(string text);
void DrawMenu(int input);
void MenuSelectOption(int option);
void MenuSelection();

//Quiz funtions
void startPage();
void DrawQues(int input);
void QuizSelectOption(int option);
void DisplayAns(string answer);
void CreateQuestion();
void dialogue(bool answer);
void SetQuiz(int i);
void border();
int StartQuiz();

//Screen Time Tracker functions
int ScreenTimeTracker();

// Declare variables
int QUIZ_SIZE = 7, CurrentQues = 0, marks = 0, random;
string question[7], correctAnswers[7], reason[7], commentText;

// Highlight Function
void White_HL(string text){ 
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 112);
    cout << text;
    SetConsoleTextAttribute(hConsole, 15);
}

void AnyKey(){
    cout << endl;
    cout << endl;

    cout << "Press any key to continue..." << endl;
    getch();
}

// Draws the menu on the screen
void DrawMenu(int input){
    system("cls");

    cout << "-==+{ Digital Responsibility Checker }+==-" << endl;
    cout << endl;
    cout << "Use the UP, DOWN arrow keys and ENTER key to select:" << endl;

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

}

// Function for start page
void startPage() {
    system("cls");
    cout << "\t\t*+ Welcome to the +*" << endl;
    cout << "    _____ _____ _____ _____ _______       _\n";
    cout << "   |  __ \\_   _/ ____|_   _|__   __|/\\   | |\n";
    cout << "   | |  | || || |  __  | |    | |  /  \\  | |\n";
    cout << "   | |  | || || | |_ | | |    | | / /\\ \\ | |\n";
    cout << "   | |__| || || |__| |_| |_   | |/ ____ \\| |____\n";
    cout << "  _|_____/_____\\_____|_____|__|_/_/____\\_\\______|_\n";
    cout << " / ____| |  | |   /\\   |  __ \\|_   _| \\ | |/ ____|\n";
    cout << "| (___ | |__| |  /  \\  | |__) | | | |  \\| | |  __ \n";
    cout << " \\___ \\|  __  | / /\\ \\ |  _  /  | | | . ` | | |_ |\n";
    cout << " ____) | |  | |/ ____ \\| | \\ \\ _| |_| |\\  | |__| |\n";
    cout << "|_____/|_|  |_/_/___ \\_\\_|_ \\_\\_____|_| \\_|\\_____|\n";
    cout << "            / __ \\| |  | |_   _|___  /\n";
    cout << "           | |  | | |  | | | |    / /\n";
    cout << "           | |  | | |  | | | |   / /\n";
    cout << "           | |__| | |__| |_| |_ / /__\n";
    cout << "            \\___\\_\\\\____/|_____/_____|  \n";
    cout << endl << endl;
    cout << "*+ Press any key to start the quiz! +*" << endl;
    getch();
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
        cout << "*+ "; White_HL("Yes"); cout << endl;
    }
    else{
        cout << "*+ Yes" << endl;
    }

    if (input == 1){
        cout << "*+ "; White_HL("No"); cout << endl;
    }
    else{
        cout << "*+ No" << endl;
    }

}

// Determines if the user chooses the right option and displays the answer
void DisplayAns(string answer){
    cout << endl;
    border();
    cout << endl;


    if (answer == correctAnswers[CurrentQues]){
        dialogue(true);
        cout << endl;
        cout << reason[CurrentQues] << endl;
        marks++;
    }
    else{
        dialogue(false);
        cout << endl << "The correct answer is: " << correctAnswers[CurrentQues] << endl;
        cout << reason[CurrentQues] << endl;
    }
}

// Executes function based on selected option
void MenuSelectOption(int option){

    switch (option){
        case 0:
            ScreenTimeTracker();
        break;
        case 1:
            StartQuiz();
        break;
        case 2:
            system("cls");
            cout << "Program exited" << endl;
            exit(0);
        break;
    }
}

// Executes function based on selected option
void QuizSelectOption(int option){

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
            QuizSelectOption(y);
            AnyKey();
            loop = false;
            break;
        }
    }
}

// Key inputs for selecting the menu with arrow keys
void MenuSelection(){

    int y = 0;
    DrawMenu(y); // Draw menu once

    // Range of selection 0 - 2

    bool loop = true;
    while(loop){
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
            MenuSelectOption(y);
            loop = false;
            break;
        }
    }
}

// Border for decoration
void border() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

//Displays a dialogue when user answers the quiz
void dialogue(bool answer) {
    random = rand() % 5;
    if (answer) {
        if (random == 0) {
            commentText = "WUOW! You got it right! :D";
        }
        if (random == 1) {
            commentText = "HUZZAH! Your answer is CORRECT! XD";
        }
        if (random == 2) {
            commentText = "CORRECTAMUNDO! That's slang for 'correct'. OvO";
        }
        if (random == 3) {
            commentText = "You must be really smart! You got it right! OvO";
        }
        if (random == 4) {
            commentText = "UH-HYUK! You picked the right answer! XD";
        }
    } else {
        if (random == 0) {
            commentText = "Uh-oh! That's wrong. ;-;";
        }
        if (random == 1) {
            commentText = "Awww. Thats not right. (._. ;)";
        }
        if (random == 2) {
            commentText = "Oopsies! You got it wrong. (=v= ;)";
        }
        if (random == 3) {
            commentText = "Oof. Not the right answer. (T_T)";
        }
        if (random == 4) {
            commentText = "YEOUCH! That isn't the right one! ;-;";
        }
    }
    cout << commentText << endl;
}

int ScreenTimeTracker(){
    system("cls");

    float StudyHour, EntHour, SocialHour; // Study hours, Entertainment hours, Social Media hours
    cout << "--==++{ Daily digital time tracker }++==-- \n\n";
    
    cout << "How many hours have you studied for? \n";
    cout << "Hour(s) studying: "; cin >> StudyHour; cout << "\n";
    
    cout << "How many hours have you spent on entertainment? \n";
    cout << "Hour(s) spent on entertainment: "; cin >> EntHour; cout << "\n";
    
    cout << "How many hours have you spent on social media? \n";
    cout << "Hour(s) spent on social media: "; cin >> SocialHour; cout << "\n";
    
    float TotalScreenTime = StudyHour + EntHour + SocialHour;
    
    cout << "Total screen time: " << TotalScreenTime << " hours" << endl;
    
    if (TotalScreenTime > 10){
        cout << "High screen time! Consider reducing your digital use." << endl;
    }
    else{
        cout << "Your screen time is healthy." << endl;
    }
    
    cout << "\n";
    
    if (StudyHour >= EntHour && StudyHour >= SocialHour){
        cout << "Good balance: You have productive screen time" << endl;
    }
    else if (SocialHour >= StudyHour || SocialHour >= EntHour){
        cout << "Warning: You are spending too much time on social media! This may lead to an addiction." << endl;
    }
    else if (EntHour >= StudyHour || EntHour >= SocialHour){
        cout << "Consider balancing entertainment with more productive tasks!" << endl;
    }

    AnyKey();
    return 0;
}

// Function to display the quiz questions
void SetQuiz(int i) {

    CurrentQues = i;

    if (i == 0) {
        question[i] = "1. Should personal details like full names, addresses, or contact info be shared online publicly?";
        correctAnswers[i] = "No";
        reason[i] = "Sharing such information can put individuals at risk of identity theft, cyberstalking, or other safety concerns.";
    }
    else if (i == 1) {
        question[i] = "2. Is it okay to share someone else's photo on social media without their permission?";
        correctAnswers[i] = "No";
        reason[i] = "Sharing someone's image without consent is a violation of their privacy and can be considered unethical, even if it was taken in a public place.";
    }
    else if (i == 2) {
        question[i] = "3. Is it appropriate to use someone else's work in your presentation without giving credit?";
        correctAnswers[i] = "No";
        reason[i] = "This is plagiarism. Proper attribution respects intellectual property and promotes academic and ethical integrity.";
    }
    else if (i == 3) {
        question[i] = "4. Is it ethical to download copyrighted music or movies from unofficial websites?";
        correctAnswers[i] = "No";
        reason[i] = "It's a form of digital piracy, which infringes on creators' intellectual property rights and is illegal in many countries.";
    }
    else if (i == 4) {
        question[i] = "5. Should you check the credibility of a news source before reposting an article?";
        correctAnswers[i] = "Yes";
        reason[i] = "Verifying sources helps prevent the spread of misinformation, which is a major ethical responsibility in digital spaces.";
    }
    else if (i == 5) {
        question[i] = "6. Is it ethical to share viral content if it contains misinformation or unverified facts?";
        correctAnswers[i] = "No";
        reason[i] = "Spreading unverified content contributes to digital misinformation and can have real-world consequences, especially in crisis situations.";
    }
    else if (i == 6) {
        question[i] = "7. Can sharing fake profiles or impersonations online lead to legal consequences?";
        correctAnswers[i] = "Yes";
        reason[i] = "Impersonating someone or spreading fake identities can result in legal action under fraud, harassment, or cybercrime laws.";
    }

    CreateQuestion();
}

int StartQuiz() {

    // Display quiz start page
    startPage();

    // Main quiz loop
    for (int i = 0; i <= 6; i++){
        SetQuiz(i);
    }

   
    // Set calculations and final statements here
    system("cls");
    cout << "    ___________   ___________ __  ____\n";
    cout << "   / ____/  _/ | / /  _/ ___// / / / /\n";
    cout << "  / /_   / //  |/ // / \\__ \\/ /_/ / / \n";
    cout << " / __/ _/ // /|  // / ___/ / __  /_/  \n";
    cout << "/_/   /___/_/ |_/___//____/_/ /_(_)   " << endl << endl;
    cout << "*+ WOOOOO!!! You have completed the quiz! +*" << endl << endl;
    cout << "Your total marks: " << marks << "/6 !" << endl << endl;
    cout << "Thank you for taking this quiz! Let's make the Internet a safe space for everyone! BD" << endl;

    AnyKey();
    return 0;
}

int main(){

    while(true){
        MenuSelection();
    }


    return 0;
}