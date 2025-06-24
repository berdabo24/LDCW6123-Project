#include <iostream>
#include <windows.h> // Highlight function
#include <conio.h> // getch() function (for key input)
#include <limits> // For numeric_limits

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
void startQuiz();
void DrawQues(int input);
void QuizSelectOption(int option);
void DisplayAns(string answer);
void CreateQuestion();
void dialogue(bool answer);
void SetQuiz(int i);
void border();
int StartQuiz();

//Screen Time Tracker functions
void startTracker();
void ErrorCheck(float &input, string prompt);
int ScreenTimeTracker();

//---------------------------------------------------MENU FUNCTIONS---------------------------------------------------//

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

    cout << "+======================================================================================================================+" << endl;
    cout << "|                               ______   ___   _______  ___   _______  _______  ___                                    |" << endl;
    cout << "|                              |      | |   | |       ||   | |       ||   _   ||   |                                   |" << endl;
    cout << "|                              |  _    ||   | |    ___||   | |_     _||  |_|  ||   |                                   |" << endl;
    cout << "|                              | | |   ||   | |   | __ |   |   |   |  |       ||   |                                   |" << endl;
    cout << "|                              | |_|   ||   | |   ||  ||   |   |   |  |       ||   |___                                |" << endl;
    cout << "|                              |       ||   | |   |_| ||   |   |   |  |   _   ||       |                               |" << endl;
    cout << "|                              |______| |___| |_______||___|   |___|  |__| |__||_______|                               |" << endl;
    cout << "| ______    _______  _______  _______  _______  __    _  _______  ___   _______  ___   ___      ___   _______  __   __ |" << endl;
    cout << "||    _ |  |       ||       ||       ||       ||  |  | ||       ||   | |  _    ||   | |   |    |   | |       ||  | |  ||" << endl;
    cout << "||   | ||  |    ___||  _____||    _  ||   _   ||   |_| ||  _____||   | | |_|   ||   | |   |    |   | |_     _||  |_|  ||" << endl;
    cout << "||   |_||_ |   |___ | |_____ |   |_| ||  | |  ||       || |_____ |   | |       ||   | |   |    |   |   |   |  |       ||" << endl;
    cout << "||    __  ||    ___||_____  ||    ___||  |_|  ||  _    ||_____  ||   | |  _   | |   | |   |___ |   |   |   |  |_     _||" << endl;
    cout << "||   |  | ||   |___  _____| ||   |    |       || | |   | _____| ||   | | |_|   ||   | |       ||   |   |   |    |   |  |" << endl;
    cout << "||___|  |_||_______||_______||___|    |_______||_|  |__||_______||___| |_______||___| |_______||___|   |___|    |___|  |" << endl;
    cout << "|                             _______  __   __  _______  _______  ___   _  _______  ______                             |" << endl;
    cout << "|                            |       ||  | |  ||       ||       ||   | | ||       ||    _ |                            |" << endl;
    cout << "|                            |       ||  |_|  ||    ___||       ||   |_| ||    ___||   | ||                            |" << endl;
    cout << "|                            |       ||       ||   |___ |       ||      _||   |___ |   |_||_                           |" << endl;
    cout << "|                            |      _||       ||    ___||      _||     |_ |    ___||    __  |                          |" << endl;
    cout << "|                            |     |_ |   _   ||   |___ |     |_ |    _  ||   |___ |   |  | |                          |" << endl;
    cout << "|                            |_______||__| |__||_______||_______||___| |_||_______||___|  |_|                          |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << endl;
    cout << "Use the UP, DOWN arrow keys and ENTER key to select:" << endl;

    // Highlights text based on input
    if (input == 0){
        cout << "-> "; White_HL("{Daily Digital Time Tracker}"); cout << endl;
    }
    else{
        cout << "    Daily Digital Time Tracker" << endl;
    }

    if (input == 1){
        cout << "-> "; White_HL("{Digital Sharing Quiz}"); cout << endl;
    }
    else{
        cout << "    Digital Sharing Quiz" << endl;
    }

    if (input == 2){
        cout << "-> "; White_HL("{Exit}"); cout << endl;
    }
    else{
        cout << "    Exit" << endl;
    }

}

// Function for quiz start page
void startQuiz() {
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
        cout << "-> "; White_HL("{Yes}"); cout << endl;
    }
    else{
        cout << "    Yes" << endl;
    }

    if (input == 1){
        cout << "-> "; White_HL("{No}"); cout << endl;
    }
    else{
        cout << "    No" << endl;
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
    startQuiz();

    // Main quiz loop
    marks = 0; // Reset marks
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
    cout << "Your total marks: " << marks << "/7 !" << endl << endl;
    cout << "Thank you for taking this quiz! Let's make the Internet a safe space for everyone! BD" << endl;

    AnyKey();
    return 0;
}

// Function for quiz start page
void startTracker() {
    system("cls");
    cout << "\t\t\t*+ Welcome to the +*" << endl;
    cout << " _____          _____ _  __     __  _____ _____ _____ _____ _______       _      \n";
    cout << "|  __ \\   /\\   |_   _| | \\ \\   / / |  __ \\_   _/ ____|_   _|__   __|/\\   | |     \n";
    cout << "| |  | | /  \\    | | | |  \\ \\_/ /  | |  | || || |  __  | |    | |  /  \\  | |     \n";
    cout << "| |  | |/ /\\ \\   | | | |   \\   /   | |  | || || | |_ | | |    | | / /\\ \\ | |     \n";
    cout << "| |__| / ____ \\ _| |_| |____| |    | |__| || || |__| |_| |_   | |/ ____ \\| |____ \n";
    cout << "|_____/_/____\\_\\_____|______|_|____|_____/_____\\_____|_____|_ |_/_/____\\_\\______|\n";
    cout << "|__   __|_   _|  \\/  |  ____| |__   __|  __ \\     /\\   / ____| |/ /  ____|  __ \\ \n";
    cout << "   | |    | | | \\  / | |__       | |  | |__) |   /  \\ | |    | ' /| |__  | |__) |\n";
    cout << "   | |    | | | |\\/| |  __|      | |  |  _  /   / /\\ \\| |    |  < |  __| |  _  / \n";
    cout << "   | |   _| |_| |  | | |____     | |  | | \\ \\  / ____ \\ |____| . \\| |____| | \\ \\ \n";
    cout << "   |_|  |_____|_|  |_|______|    |_|  |_|  \\_\\/_/    \\_\\_____|_|\\_\\______|_|  \\_\\\n";
    cout << endl << endl;
    cout << "*+ Press any key to start! +*" << endl;
    getch();
}

// Function to check for valid input
void ErrorCheck(float &input, string prompt) { 
    do{
        cout << prompt; // Prompt user for input
        cin >> input; // Get user input
        if (cin.fail() || input < 0 || input > 24) { // Check if input is valid
            cout << "Invalid input! Please enter a positive number between 0 and 24." << endl;
            cout << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            input = -1; // Set to -1 to ensure the loop continues
        }
    } while (input < 0 || input > 24); // Ensure positive number
}


int ScreenTimeTracker(){
    startTracker();
    system("cls");

    float StudyHour, EntHour, SocialHour; // Study hours, Entertainment hours, Social Media hours
    
    cout << "How many hours do you spend on digital studying in a day? \n";
    
    ErrorCheck(StudyHour, "Hour(s) spent on study: "); 

    cout << endl;
    border();
    cout << endl;
    
    
    cout << "How many hours do you spend on digital entertainment in a day? \n";
    
    ErrorCheck(EntHour, "Hour(s) spent on entertainment: "); 

    cout << endl;
    border();
    cout << endl;
    

    cout << "How many hours do you spend on social media in a day? \n";

    ErrorCheck(SocialHour, "Hour(s) spent on social media: "); 

    cout << endl;
    border();
    cout << endl;
    
    float TotalScreenTime = StudyHour + EntHour + SocialHour;
    
    cout << "Total screen time: " << TotalScreenTime << " hours" << endl;
    
    if (TotalScreenTime > 3){
        cout << "High screen time! Consider reducing your digital use." << endl;
    }
    else{
        cout << "Your screen time is healthy." << endl;
    }
    
    cout << "\n";
    
    if (StudyHour >= EntHour && StudyHour >= SocialHour){
        cout << "Good balance: You have productive screen time" << endl;
    }
    else if (SocialHour > StudyHour || SocialHour > EntHour){
        cout << "Warning: You are spending too much time on social media! This may lead to an addiction." << endl;
    }
    else if (EntHour > StudyHour || EntHour > SocialHour){
        cout << "Consider balancing entertainment with more productive tasks!" << endl;
    }

    AnyKey();
    return 0;
}



int main(){

    while(true){
        MenuSelection();
    }


    return 0;
}