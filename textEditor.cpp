#include<iostream>
#include"Header.h"

using namespace std;
int main()
{
	TextStructure T;
	//Node *N=createNode('<');
	char *ads=nullptr;
	T.readTextFromFile("input.txt");
	//cout << "Before " << endl;
	//cout << T;
//	N = nullptr;
	//T.cutKCharsFrom(N, 5, ads);
	Node*A, *B = nullptr;
	//T.findText(amr, false, A, B);
	string a = "name";
	string b = "ahmad";
	T.findandReplaceText(a, b, 1);
	cout << "After";
	cout << T;
	return 0;
}