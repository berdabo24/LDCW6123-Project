#include<iostream>
using namespace std;

int main()
{
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
    
    return 0;
}