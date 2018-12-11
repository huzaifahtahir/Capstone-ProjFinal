#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

////////////////////////////////////////////////
//				Function Prototypes
////////////////////////////////////////////////
void displayMenu();
void inputGrades();
void getExamGrades(double &examGrade1, double &examGrade2, double &examGrade3);
void displayGrades();
void displayStudentExamStats();
void displayAnExamStats();

////////////////////////////////////////////////
//				Global Constants
////////////////////////////////////////////////
const int CHOICE_INPUT_GRADE = 1;
const int CHOICE_DISPLAY_ALL_GRADES = 2;
const int CHOICE_DISPLAY_STUDENT_EXAM = 3;
const int CHOICE_DISPLAY_EXAM_STATS = 4;
const int CHOICE_QUIT = 5;


////////////////////////////////////////////////
//				Main Function
////////////////////////////////////////////////
int main() 
{
	system("title Capstone Project");

	int choice;

	do {
		displayMenu();
		cin >> choice;

		switch (choice)
		{
		case CHOICE_INPUT_GRADE:
			inputGrades();
			break;

		case CHOICE_DISPLAY_ALL_GRADES:
			displayGrades();
			break;

		case CHOICE_DISPLAY_STUDENT_EXAM:
			displayStudentExamStats();
			break;
		
		case CHOICE_DISPLAY_EXAM_STATS:
			/*cout << "This task is not complete yet..\n\n";*/
			displayAnExamStats();
			break;

		case CHOICE_QUIT:	 cout << "\nThanks for using the program. Bye!\n";
			break;

		default: cout << "You may only enter 1, 2, 3, 4, and 5 as your choice! Try again...\n\n";
		
		}

	} while (choice != 5);
		
	return 0;
}

////////////////////////////////////////////////
//			Function Definitions
////////////////////////////////////////////////

void displayMenu()
{
	cout << "1. Input A Student Grade\n";
	cout << "2. Display All Grades\n";
	cout << "3. Display A Student's Exam Statistics\n";
	cout << "4. Display An Exam's Statistics\n";
	cout << "5. Exit\n";
	cout << "Enter your choice (1-5): ";
}


////////////////////////////////////////////////
//				CHOICE 1
////////////////////////////////////////////////
void inputGrades() {
	
	//				Variables
	//==============================================
	bool doAgain;
	double examGrade1 = 0;
	double examGrade2 = 0;
	double examGrade3 = 0;
	int stdId;


	do {
		doAgain = true;
		cout << "Enter your Student ID: ";
		cin >> stdId;

		if (stdId < 1 || stdId > 9999) {
			cout << "Your student ID must be in between 0 and 9999! Try again...\n";
			doAgain = false;
		}

	} while (doAgain != true);

	getExamGrades(examGrade1, examGrade2, examGrade3);

	ofstream writeGrades;
	writeGrades.open("grades.txt", ios::app);

	if (writeGrades)
	{

		writeGrades << stdId << "\t"
			<< examGrade1 << "\t"
			<< examGrade2 << "\t"
			<< examGrade3 << endl;
	}
	else 
	{
			cout << "\nError writing to file!" << endl;	
	}
	
	writeGrades.close();

}

void getExamGrades(double &examGrade1, double &examGrade2, double &examGrade3) 
{	
	do 
	{
		cout << "Enter the first exam grade: ";
		cin >> examGrade1;

		if (examGrade1 < 0)
			cout << "Exam grade must be higher than 0!\n";
	} while (examGrade1 < 0);

	do 
	{
		cout << "Enter the second exam grade: ";
		cin >> examGrade2;

		if (examGrade2 < 0)
			cout << "Exam grade must be higher than 0!\n";
	} while (examGrade2 < 0);
	
	do
	{
		cout << "Enter the third exam grade: ";
		cin >> examGrade3;
		cout << endl;

		if (examGrade3 < 0)
			cout << "Exam grade must be higher than 0!\n";
	} while (examGrade3 < 0);

}


////////////////////////////////////////////////
//				CHOICE 2
////////////////////////////////////////////////
void displayGrades()
{
	ifstream readGrades;
	int studentId;
	double examGrade1, examGrade2, examGrade3;


	readGrades.open("grades.txt");


	if (readGrades)
	{
		system("cls");
		cout << left 
			 << "Student ID\t" << "Exam 1\t" << "Exam 2\t" << "Exam 3\t" << endl;
		cout << "======================================" << endl;
		while (readGrades >> studentId >> examGrade1 >> examGrade2 >> examGrade3)
		{
			cout << left << setw(4) << studentId << "\t\t" 
				<< fixed << setprecision(2) 
				<< right << setw(6) << examGrade1 << "\t" 
				<< right << setw(6) << examGrade2 << "\t"
				<< right << setw(6) << examGrade3 << endl;
		}
		cout << endl;
		system("pause");
	}

	else
	{
		cout << "\nError opening file!\n";
	}

	cout << endl;
}

////////////////////////////////////////////////
//				CHOICE 3
////////////////////////////////////////////////
void displayStudentExamStats() {
	
	int studentId;
	int searchId;
	double examGrade1, examGrade2, examGrade3;
	ifstream readGrades;

	do
	{
		cout << "Enter the student ID: ";
		cin >> searchId;

		if (searchId < 0 || searchId > 9999) {
			cout << "Your student ID must be in between 0 and 9999! Try again...\n";
		}

	} while (searchId < 0 || searchId > 9999);

		readGrades.open("grades.txt");
		
		if (readGrades)
		{
			system("cls");
			
			bool wordFound = false;
			while (readGrades >> studentId >> examGrade1 >> examGrade2 >> examGrade3)
			{
				if (searchId == studentId)
				{
					cout << left
						<< "Student ID\t" << "Exam 1\t" << "Exam 2\t" << "Exam 3\t" << "  Average" << endl;
					cout << "=================================================" << endl;
					cout << left << setw(4) << studentId << "\t\t"
						<< fixed << setprecision(2)
						<< right << setw(6) << examGrade1 << "\t"
						<< right << setw(6) << examGrade2 << "\t"
						<< right << setw(6) << examGrade3 << "\t"
						<< right << setw(9) << (examGrade1 + examGrade2 + examGrade3) / 3 << endl;
					/*cout << "\t\tAverage: " << (examGrade1 + examGrade2 + examGrade3) / 3 << endl << endl;*/
					wordFound = true;
					system("pause");
					break;
				}
			}	
			if (!wordFound) {
				cout << "The student ID and record cannot be found!\n";
			}
		}
		else
		{
			cout << "\nError opening file!\n";
		}
	cout << endl;
}

////////////////////////////////////////////////
//				CHOICE 4
////////////////////////////////////////////////

void displayAnExamStats() {
	
	int examNumber;
	int studentId;
	int studentCounter = 0;
	double minGrade = 0;
	double maxGrade = 0;
	double examGrade1, examGrade2, examGrade3;
	double examAverage = 0;
	double stndrdDev = 0;
	ifstream readGrades;
	
	do {

		cout << "Enter exam number: ";
		cin >> examNumber;

		if (examNumber < 1 || examNumber > 3) {
			cout << "Error! You can only enter 1, 2, and 3 as exam number!\n";

		}

	} while (examNumber < 1 || examNumber > 3);

	readGrades.open("grades.txt");

	if (readGrades) {

		bool found = false;
		system("cls");

		while (readGrades >> studentId >> examGrade1 >> examGrade2 >> examGrade3)
		{
			if (examNumber == 1)
			{
				if (examGrade1 > maxGrade) {
				maxGrade = examGrade1;
				minGrade = maxGrade;
				}


				if (examGrade1 < minGrade) {
					minGrade = examGrade1;
				}


				studentCounter++;
				examAverage += examGrade1;
				cout << examGrade1 << "\t\n";
				found = true;
			}


			if (examNumber == 2)
			{
				if (examGrade2 > maxGrade) {
					maxGrade = examGrade2;
					minGrade = maxGrade;
				}


				if (examGrade2 < minGrade) {
					minGrade = examGrade2;
				}


				studentCounter++;
				examAverage += examGrade2;
				cout << examGrade2 << "\t\n";
				found = true;
			}

			if (examNumber == 3)
			{

				if (examGrade3 > maxGrade) {
					maxGrade = examGrade3;
					minGrade = maxGrade;
				}


				if (examGrade3 < minGrade) {
					minGrade = examGrade3;
				}

				studentCounter++;
				examAverage += examGrade3;
				cout << examGrade3 << "\t\n";
				found = true;
			}
		}

		if (!found) {
			cout << "No grades were found for this exam.";
		}

	
		////////////////////////////////////////////////
		//				Standard Dev
		////////////////////////////////////////////////
		/*while (readGrades >> examGrade1 >> examGrade2 >> examGrade3)
		{
			stndrdDev = examGrade1 - examAverage;
			cout << "Standard Dev: ";
		}*/


		
		cout << "Number of students who took the exam: " << studentCounter << endl;
		cout << "Average of exam: " << examAverage / studentCounter << endl;
		cout << "Max grade: " << maxGrade << endl;
		cout << "Min grade: " << minGrade << endl << endl;

	}

	else
	{
		cout << "\nError opening file!\n";
	}

}