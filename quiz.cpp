#include <iostream>
#include <windows.h> // Highlight function
#include <conio.h> // getch() function (for key input)

using namespace std;\

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

// Declare variables
int QUIZ_SIZE=7, i=0, sum = 0;
string question[7], answer[7], correctAnswers[7], reason[7];

void border() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

// Function to display the quiz questions
void setQuiz(int i) {
    if (i == 0) {
        question[i] = "Should personal details like full names, addresses, or contact info be shared online publicly?";
        correctAnswers[i] = "No";
        reason[i] = "Sharing such information can put individuals at risk of identity theft, cyberstalking, or other safety concerns.";
    }
    else if (i == 1) {
        question[i] = "Is it okay to share someone else’s photo on social media without their permission?";
        correctAnswers[i] = "No";
        reason[i] = "Sharing someone’s image without consent is a violation of their privacy and can be considered unethical—even if it was taken in a public place.";
    }
    else if (i == 2) {
        question[i] = "- Is it appropriate to use someone else’s work in your presentation without giving credit?";
        correctAnswers[i] = "No";
        reason[i] = "This is plagiarism. Proper attribution respects intellectual property and promotes academic and ethical integrity.";
    }
    else if (i == 3) {
        question[i] = "- Is it ethical to download copyrighted music or movies from unofficial websites?";
        correctAnswers[i] = "No";
        reason[i] = "It’s a form of digital piracy, which infringes on creators’ intellectual property rights and is illegal in many countries.";
    }
    else if (i == 4) {
        question[i] = "Should you check the credibility of a news source before reposting an article?";
        correctAnswers[i] = "Yes";
        reason[i] = "Verifying sources helps prevent the spread of misinformation, which is a major ethical responsibility in digital spaces.";
    }
    else if (i == 5) {
        question[i] = "- Is it ethical to share viral content if it contains misinformation or unverified facts?";
        correctAnswers[i] = "No";
        reason[i] = "Spreading unverified content contributes to digital misinformation and can have real-world consequences, especially in crisis situations.";
    }
    else if (i == 6) {
        question[i] = "- Can sharing fake profiles or impersonations online lead to legal consequences?";
        correctAnswers[i] = "Yes";
        reason[i] = "Impersonating someone or spreading fake identities can result in legal action under fraud, harassment, or cybercrime laws.";
    }
}

int main() {

    // Display questions
    do {
        system("cls");
        setQuiz(i);

        cout << question[i] << endl << endl;
        border();
        cout << "\t+ Yes" << endl;
        cout << "\t+ No" << endl;
        
        cin >> answer[i];
        cout << "Press any button to continue...";
        getch();

    } while (i < QUIZ_SIZE);

    // Calculate the total number of questions answered orrect
    // Output the result
    system("cls");
    cout << "The sum of " << sum << " and " << sum << " is " << sum << "." << endl;

    return 0;
}