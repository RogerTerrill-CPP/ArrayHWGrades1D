#include <iostream>
#include <iomanip>
using namespace std;

//Constants for number of students and number of homeworks
const int NUMBER_OF_STUDENTS = 6, NUMBER_OF_HOMEWORKS = 5;

//Prototype declarations
void input_grade(int a[][NUMBER_OF_HOMEWORKS], int lastStudent, int lastHW);
void calculateStudentAvg(const int grade[][NUMBER_OF_HOMEWORKS], double studentAvg[]);
void calculateHomeworkAvg(const int grade[][NUMBER_OF_HOMEWORKS], double homeworkAvg[]);
void display(const int grade[][NUMBER_OF_HOMEWORKS], const double studentAvg[], const double homeworkAvg[]);

int main()
{
	//Declare and initialize an array
	int grade[NUMBER_OF_STUDENTS][NUMBER_OF_HOMEWORKS];
	double studentAvg[NUMBER_OF_STUDENTS];
	double homeworkAvg[NUMBER_OF_HOMEWORKS];


	//Function to ask user to enter data
	input_grade(grade, NUMBER_OF_STUDENTS, NUMBER_OF_HOMEWORKS);

	//Function to calculate student average
	calculateStudentAvg(grade, studentAvg);

	//Function to calculate homework assignment average
	calculateHomeworkAvg(grade, homeworkAvg);

	//Display the final results
	display(grade, studentAvg, homeworkAvg);

	return 0;
}

/*******************************************************
Name            :   input_grade(int a[][NUMBER_OF_HOMEWORKS], int lastStudent, int lastHW
Arguments       :   int lastStudent, lastHW, a[][NUMBER_OF_HOMEWORKS]
Returns         :   None
Precondition    :   Global constant NUMBER_OF_STUDENTS, NUMBER_OF_HOMEWORKS
Postcondition   :   Each a[studentNum - 1][homeworkNum - 1] will have the homework for each student
*******************************************************/
void input_grade(int a[][NUMBER_OF_HOMEWORKS], int lastStudent, int lastHW)
{
	//Loop through each student
	for (int studentNum = 1; studentNum <= lastStudent; studentNum++)
	{
		cout << "Enter 5 homework grades for student number separated by spaces: " << studentNum << endl;
		//Loop through each homework
		for (int homeworkNum = 1; homeworkNum <= lastHW; homeworkNum++)
		{
			//Enter the grade for homework assignment
			cin >> a[studentNum - 1][homeworkNum - 1];
		}
	}

}

/*******************************************************
Name            :   calculateStudentAvg(const int grade[][NUMBER_OF_HOMEWORKS], double studentAvg[])
Arguments       :   const int grade[][NUMBER_OF_HOMEWORKS], double studentAvg[]
Returns         :   None
Precondition    :   Global constant NUMBER_OF_STUDENTS, NUMBER_OF_HOMEWORKS
Postcondition   :   Each studentAvg[studentNumber - 1] constains the average for student number studentNumber
*******************************************************/
void calculateStudentAvg(const int grade[][NUMBER_OF_HOMEWORKS], double studentAvg[])
{
	//Loop through each student
	for (int studentNumber = 1; studentNumber <= NUMBER_OF_STUDENTS; studentNumber++)
	{
		//Declare and initialize sum variable
		double sum = 0;

		//Loop thorugh each homework
		for (int homeworkNum = 1; homeworkNum <= NUMBER_OF_HOMEWORKS; homeworkNum++)
		{
			//Sum the scores of each homework assignment
			sum += grade[studentNumber - 1][homeworkNum - 1];

			//Calculate the average of each student
			studentAvg[studentNumber - 1] = sum / NUMBER_OF_HOMEWORKS;
		}

	}
}

/*******************************************************
Name            :   calculateHomeworkAvg(const int grade[][NUMBER_OF_HOMEWORKS], double homeworkAvg[])
Arguments       :   const int grade[][NUMBER_OF_HOMEWORKS], double homeworkAvg[], double sum
Returns         :   None
Precondition    :   Global constant NUMBER_OF_STUDENTS, NUMBER_OF_HOMEWORKS
Postcondition   :   Each homeworkAvg[homeworkNum - 1] constains the average for homework number homeworkNum
*******************************************************/
void calculateHomeworkAvg(const int grade[][NUMBER_OF_HOMEWORKS], double homeworkAvg[])
{
	//Loop through each homework
	for (int homeworkNum = 1; homeworkNum <= NUMBER_OF_HOMEWORKS; homeworkNum++)
	{
		//Initialize and declare the sum variable
		double sum = 0;

		//Loop through each student
		for (int studentNum = 1; studentNum <= NUMBER_OF_STUDENTS; studentNum++)
		{
			//Sum the grades for homework
			sum += grade[studentNum - 1][homeworkNum - 1];

			//Calculate the homework average
			homeworkAvg[homeworkNum - 1] = sum / NUMBER_OF_STUDENTS;
		}
	}
}

/*******************************************************
Name            :   display(const int grade[][NUMBER_OF_HOMEWORKS], const double studentAvg[], const double homeworkAvg[])
Arguments       :   const int grade[][NUMBER_OF_HOMEWORKS], const double studentAvg[], const double homeworkAvg[]
Returns         :   None
Precondition    :   Global constant NUMBER_OF_STUDENTS, NUMBER_OF_HOMEWORKS, studentAvg[] and homeworkAvg[] values
Postcondition   :   Display the results of all the students and homeworks
*******************************************************/
void display(const int grade[][NUMBER_OF_HOMEWORKS], const double studentAvg[], const double homeworkAvg[])

{
	//Set precision for displaying a table of data
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	cout << setw(10) << "Student"
		<< setw(5) << "Ave"
		<< setw(15) << "Homeworks\n";

	//Loop through each student
	for (int studentNum = 1; studentNum <= NUMBER_OF_STUDENTS; studentNum++)
	{
		//Using spacing the create columns for data
		cout << setw(10) << studentNum
			<< setw(5) << studentAvg[studentNum - 1] << " ";

		//Loop through each homework assignment
		for (int homeworkNum = 1; homeworkNum <= NUMBER_OF_HOMEWORKS; homeworkNum++)
		{
			//Show each students homework assignment grade
			cout << setw(5) << grade[studentNum - 1][homeworkNum - 1];
		}
		cout << endl;
	}

	//Display averages of each homework assignment
	cout << "Homework Averages = ";
	for (int homeworkNum = 1; homeworkNum <= NUMBER_OF_HOMEWORKS; homeworkNum++)
	{
		cout << setw(5) << homeworkAvg[homeworkNum - 1];
	}
	cout << endl;
}
