#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "LetterGrade.h"

using namespace std;

int main()
{
	int v;
	double enter;
	vector<string> names;
	string n;
	string fileName; 
	vector<double> grades;
	vector<vector<double>> base;
	ofstream myfile; 
	cout << "My Gradebook" << endl; 
	cout << "+++++++++++++++++++++++++" << endl << endl; 

	cout << "Enter the name of your csv file: ";
	getline(cin, fileName);

	cout << "Enter the number of students: "; 
	int numStud; 
	cin >> numStud;
	cout << "Enter the number of graded assingments: ";
	int gradeStud; 
	cin >> gradeStud; 

	cout << endl; 

	for (int i = 0; i < numStud; i++)
	{
		cout << "Enter student #" << (i + 1) << "'s name ==> ";
		cin >> n;
		names.push_back(n);

		for (int p = 0; p < gradeStud; p++)
		{
			cout << n << "'s grade #" << (p + 1) << "==> ";
			cin >> enter;
			grades.push_back(enter);
		}
		base.push_back(grades);
		grades.clear();
		cout << endl;
		cout << endl;

	}

	LetterGrade final;

	double accum = 0;
	cout << "GRADE BOOK CREATED \n";
	cout << "============================" << endl << endl;

	vector<string> header = { "Grade" , "Average", "Letter Grade"};
	
	//creates a header line for grade #
	for (int h = 0; h < gradeStud; h++)
	{
		cout << "\t" << header[0] << " #" << (h + 1);
	}

	//Creates header line for Average and Letter Grade
	cout << "\t" << header[1];
	cout << "\t" << header[2];

	cout << endl;
	for (int o = 0; o < numStud; o++)
	{
		cout << names[o];
		for (int n = 0; n < gradeStud; n++)
		{
			cout << "\t\t" << base[o][n];
			accum = base[n][o] + accum;

		}
		accum = accum / gradeStud;
		cout << "\t" << accum;
		cout <<"\t" << final.getLetterGrade(accum);
		accum = 0;
		cout << endl;
	}
 
	final.createfile(fileName, names, base);


	cout << endl << fileName << " has been created! \n \n";
}