#include <iostream>

using namespace std;

const int NUM_GRADES = 14;
const int NUM_GRADE_VARIATIONS = 3;
const int MAX_CLASSES = 10;
float points[NUM_GRADES];
string letterGrades[MAX_CLASSES];
float credits[MAX_CLASSES];
float numCredits;
float baseCredits;
float GPA;
int numClasses;

void introWords();
void gradeValues();
void numClassesTaken();
void gradesPerClass();
int totalCredits();
void numCreditsPerClass();
void calculateGPA();
void getGPA();
void findBaseCredits();

int main() {
	introWords();
	gradeValues();
	numClassesTaken();
	gradesPerClass();
	numCreditsPerClass();
	totalCredits();
	findBaseCredits();
	calculateGPA();
	getGPA();
	return 0;
}


/*REQUIRES: nothing
MODIFIES: nothing
EFFECTS: Introduces program
*/
void introWords() {
	cout << "Welcome to the GPA Calculator!" << endl;
}

/*REQUIRES: cin must be number
* MODIFIES: points[i]
* EFFECTS: adds grade point values to an array
*/
void gradeValues() {
	char letterGrade = 'A';

	cout << "What is the grade point value of a(n):" << endl;
	for (int i = 0; i < NUM_GRADES; i++) {
		for (int j = 0; j < NUM_GRADE_VARIATIONS; j++) {
			if (j == 0) {
				cout << letterGrade << "+: ";
				cin >> points[i];
				i++;
			}
			else if (j == 1) {
				cout << letterGrade << ": ";
				cin >> points[i];
				i++;
			}
			else if (j == 2) {
				cout << letterGrade << "-: ";
				cin >> points[i];
				i++;
			}
		}
		letterGrade++;
	}
}

/*REQUIRES: cin must be number
MODIFIES: numClasses
EFFECTS: gives value to numClasses
*/
void numClassesTaken() {
	cout << "How many classes did you take this semester excluding pass/fail courses? ";
	cin >> numClasses;
}

void gradesPerClass() {

	cout << "What was your letter grade in each class? " << endl;
	for (int i = 1; i <= numClasses; i++) {
		cout << "Class " << i << ") ";
		cin >> letterGrades[i];
	}
}

void numCreditsPerClass() {
	cout << "How many credits were your classes worth? " << endl;
	for (int i = 1; i <= numClasses; i++) {
		cout << "Class " << i << ") ";
		cin >> credits[i];
	}
}

int totalCredits() {
	for (int i = 0; i <= numClasses; i++) {
		if (letterGrades[i] == "A+") {
			numCredits += (points[0] * credits[i]);
		}
		else if (letterGrades[i] == "A") {
			numCredits += (points[1] * credits[i]);
		}
		else if (letterGrades[i] == "A-") {
			numCredits += (points[2] * credits[i]);
		}
		else if (letterGrades[i] == "B+") {
			numCredits += (points[3] * credits[i]);
		}
		else if (letterGrades[i] == "B") {
			numCredits += (points[4] * credits[i]);
		}
		else if (letterGrades[i] == "B-") {
			numCredits += (points[5] * credits[i]);
		}
		else if (letterGrades[i] == "C+") {
			numCredits += (points[6] * credits[i]);
		}
		else if (letterGrades[i] == "C") {
			numCredits += (points[7] * credits[i]);
		}
		else if (letterGrades[i] == "C-") {
			numCredits += (points[8] * credits[i]);
		}
		else if (letterGrades[i] == "D") {
			numCredits += (points[9] * credits[i]);
		}
		else if (letterGrades[i] == "F") {
			numCredits += (points[10] * credits[i]);
		}
	}
	return numCredits;
}

void findBaseCredits() {
	for (int i = 1; i <= numClasses; i++) {
		baseCredits += credits[i];
	}
}

void calculateGPA() {
	GPA = numCredits / baseCredits;
}

void getGPA() {
	cout << "Your GPA is " << GPA << endl;
}