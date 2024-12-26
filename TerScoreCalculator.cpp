#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    float GAA; // Average score in best 10 out of 11 weekly assignments
    int quiz1, quiz2, finalExam;

    // Input GAA
    cout << "Enter the GAA (average score of best 10 out of 11 weekly graded assignments): ";
    cin >> GAA;

    // Input quiz scores
    cout << "Enter the score for Quiz 1 (enter 0 if not attempted): ";
    cin >> quiz1;
    cout << "Enter the score for Quiz 2 (enter 0 if not attempted): ";
    cin >> quiz2;

    // Input final exam score
    cout << "Enter the score for the final exam: ";
    cin >> finalExam;

    // Check eligibility to write the final exam
    if (GAA < 40) {
        cout << "You are not eligible to write the final exam due to low weekly assignment scores." << endl;
        return 0;
    }

    if (quiz1 == 0 && quiz2 == 0) {
        cout << "You are not eligible to write the final exam due to non-attendance in quizzes." << endl;
        return 0;
    }

    // Check eligibility to obtain the final course grade
    if (finalExam == 0) {
        cout << "You are not eligible to obtain the final course grade due to non-attendance in the final exam." << endl;
        return 0;
    }

    // Calculate T (Final Course Score)
    float maxQuizScore = max(quiz1, quiz2);
    float option1 = 0.6 * finalExam + 0.2 * maxQuizScore;
    float option2 = 0.4 * finalExam + 0.2 * quiz1 + 0.3 * quiz2;
    float T = 0.1 * GAA + max(option1, option2);

    // Output final course score
    cout << "The Final Course Score (T) is: " << T << endl;

    return 0;
}
