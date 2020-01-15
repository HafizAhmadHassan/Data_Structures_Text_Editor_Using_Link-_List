#include<iostream>
#include<fstream>
using namespace std;
struct Node
{
	char ch;
	Node * next, *prev;
};

class TextStructure
{
	Node * head, *tail;
	int textSize;//num of characters in text
public:
	TextStructure();
	
	TextStructure(const TextStructure &);
	TextStructure& operator=(const TextStructure &);

	void addCharAtFront(char obj);
	void addCharAtEnd(char obj);
	void addCharAfter(char, Node*&);
	void cutKCharsFrom(Node*ptr, int k, char *& subText);
	bool findText(const string& str, bool direction, Node*& start, Node*&end);
	void findandReplaceText(const string & str1, const string & str2, bool direction);

	friend ostream& operator<<(ostream&,TextStructure);   // Friend Function to Output TextStructure
	void readTextFromFile(const string & filename);
	~TextStructure();
	void copyList(const TextStructure &);// This function is Both used in Copy Constructor as well as in Assignment operator
	void destroyList();
};
Node *createNode(const char& obj);