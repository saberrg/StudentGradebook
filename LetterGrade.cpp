#include "LetterGrade.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void LetterGrade::createfile(string fileName, vector<string> name, vector<vector<double>> grades)
{
	ofstream create; 
	double accum = 0; 
	create.open(fileName + ".csv");
	vector<string> header = {"Student Name",  "Grade" , "Average", "Letter Grade" };

	//creates a header line for grade #
	create << header[0] << ",";

	for (int h = 0; h < grades.size(); h++)
	{
		create << header[1] << " #" << (h + 1) << ",";
	}

	//Creates header line for Average and Letter Grade
	create << header[2];
	create << "," << header[3] << endl;

	for (int o = 0; o < name.size(); o++)
	{
		create << name[o];
		for (int n = 0; n < grades.size(); n++)
		{
			create << "," << grades[o][n];
			accum = grades[n][o] + accum;

		}
		accum = accum / grades.size();
		create << "," << accum;
		LetterGrade final;
		create << "," << final.getLetterGrade(accum);
		accum = 0;
		create << endl;
	}


}


string LetterGrade::getLetterGrade(double f)
{

	if (f >= 100)
	{
		return "A+";

	}

	else if (f >= 93 && f <= 99.99)
	{
		return "A";
	}
	else if (f <= 92.99 && f >= 90)
	{
		return "A-";
	}
	else if (f >= 87.99 && f <= 89.99)
	{
		return "B+";
	}
	else if (f >= 83 && f <= 86.99)
	{
		return "B";
	}
	else if (f >= 80 && f <= 82.99)
	{
		return "B-";
	}
	else if (f >= 77 && f <= 79.99)
	{
		return "C+";
	}
	else if (f >= 73 && f <= 76.99)
	{
		return "C";
	}
	else if (f >= 70 && f <= 72.99)
	{
		return "C-";
	}

	else {
		return "F";
	}
}