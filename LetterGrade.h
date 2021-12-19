#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class LetterGrade
{
public:
	double AverageGrade = 0;
	vector<string> names; 
	vector<double> grades; 
	vector<vector<double>> base; 
 
	void createfile(string, vector<string>, vector<vector<double>>);
	string getLetterGrade(double); 


};

