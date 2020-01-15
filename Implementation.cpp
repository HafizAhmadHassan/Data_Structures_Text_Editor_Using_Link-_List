#include"Header.h"

TextStructure::TextStructure()
{
	head = tail = nullptr;
	textSize = 0;
}
TextStructure::TextStructure(const TextStructure& copy)
{
	head = nullptr;
	copyList(copy);
}

TextStructure& TextStructure:: operator=(const TextStructure & right)
{
	if (this != &right)
	{
		copyList(right);
	}
	return *this;
}
void TextStructure::addCharAtFront(char obj)
{
	if (textSize == 0)
	{
		head = tail = new Node;
		head->ch = obj;
		head->next = nullptr;
		head->prev = nullptr;

		textSize++;
	}
	else
	{
		Node *temp = new Node;
		temp->next = head;
		temp->ch = obj;
		temp->prev = nullptr;

		head = temp;
		temp = nullptr;
		textSize++;
	}
}
void TextStructure::addCharAtEnd(char obj)
{
	if (textSize == 0)
	{
		head = tail = new Node;
		head->ch = obj;
		head->next = nullptr;
		head->prev = nullptr;

		textSize++;
	}
	else
	{
		Node *newNode = createNode(obj);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		newNode = nullptr;
		textSize++;
	}

}

void TextStructure::addCharAfter(char obj, Node* &ptr)
{
	if (ptr == nullptr)
	{
		addCharAtEnd(obj);
	}
	else
	{
		Node *temp = head;
		while (temp != nullptr&&temp->ch != ptr->ch)
		{
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			addCharAtEnd(obj);
		}
		else
		{
			Node *newNode = createNode(obj);
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;
			temp = newNode;
			newNode = nullptr;
			textSize++;
		}

	}
}
void TextStructure::cutKCharsFrom(Node*ptr, int k, char *& subText)
{
	Node *temp = head;
	while (temp != nullptr&&temp->ch != ptr->ch)
	{
		temp = temp->next;
	}
	if (subText != nullptr)
	{
		delete subText;
		subText = nullptr;
	}
	if (temp == nullptr)
	{
		cout << "The Given Character does not exist in The list to cut from " << endl;
	}
	else
	{
		int count = 1;
		Node *startCut = temp;
		while (temp != nullptr)
		{
			temp = temp->next;
			count++;
		}
		//cout << "Count " << count << endl;

		if (k < count)
		{
			temp = startCut;
			if (startCut != head){

				startCut = startCut->prev;
			}
			subText = new char[k + 1];
			int i = 0;
			Node *del;
			/*tail = startCut->prev;
			tail->next = nullptr;*/
			while (i < k)
			{
				del = temp;
				subText[i] = temp->ch;
				temp = temp->next;
				i++;
				delete del;
				textSize--;
			}
			if (startCut != head){
				startCut->next = temp;
				temp->prev = startCut;
			}
			else
			{
				head = temp;
				temp->prev = head;

			}
			subText[i] = '\0';

		}
		else
		{
			cout << "Cut cannot be successful bcz there are Less node exist than k " << endl;
		}

	}

}
bool TextStructure::findText(const string& str, bool direction, Node*& start, Node*&end)
{
	int len = str.length();
	bool found = false;
	if (direction)
	{
		
		Node* temp = head;
		while (temp != nullptr)
		{
			int count = 0, i = 0;
			if (temp->ch == str[i])
			{
				start = temp;
				count++;
				while (temp != nullptr &&i < len && str[i] != '\0')
				{
					i++;
					temp = temp->next;
					if (temp == nullptr)
					{
						break;
					}
					if (temp != nullptr&&temp->ch == str[i])
						count++;
				}
				if (temp == nullptr)
				{
					break;
				}
				if (count == len)
				{
					end = temp;
					found = true;
					break;
				}
				else
				{
					start = end = nullptr;
					int x = (len - 1);
					while (x > 1)
					{
						temp = temp->prev;
						x--;
					}
				}
			}
			temp = temp->next;
		}

	}
	else if (!direction)
	{
		{
			Node* temp = tail;
			while (temp != nullptr)
			{
				int count = 0, i = 0;
				if (temp->ch == str[i])
				{
					start = temp;
					count++;
					while (temp != nullptr &&i < len && str[i] != '\0')
					{
						i++;
						temp = temp->prev;
						if (temp == nullptr)
						{
							break;
						}
						if (temp != nullptr&&temp->ch == str[i])
							count++;
					}
					if (temp == nullptr)
					{
						break;
					}
					if (count == len)
					{
						end = temp;
						found = true;
						break;
					}
					else
					{
						start = end = nullptr;
						int x = (len - 1);
						while (x > 1)
						{
							temp = temp->next;
							x--;
						}
					}
				}
				temp = temp->prev;
			}

		}


	}
	return found;
}

void TextStructure::findandReplaceText(const string & str1, const string & str2, bool direction)
{
	Node *st, *end;
	/*this->findText(str1,direction, st, end);
	int len=str1.length();
	Node* temp1 = st;
	if (direction)
	{
		int i = 0;
		while (i < len)
		{
			temp1 = st;
			st = st->next;
			delete temp1;
		}
		
	}*/
	Node*toPut = nullptr;
	int len = str1.length();
	bool found = false;
	if (direction)
	{
		Node* temp = head;
		
		while (temp != nullptr)
		{
			int count = 0, i = 0;
			if (temp->ch == str1[i])
			{
				st = temp;
				toPut = temp;
				toPut = toPut->prev;
				count++;
				while (temp != nullptr &&i < len && str1[i] != '\0')
				{
					i++;
					temp = temp->next;
					if (temp == nullptr)
					{
						break;
					}
					if (temp != nullptr&&temp->ch == str1[i])
						count++;
				}
				if (temp == nullptr)
				{
					break;
				}
				if (count == len)
				{
					end = temp;
					found = true;
					break;
				}
				else
				{
					st = end = nullptr;
					int x = (len - 1);
					while (x > 1)
					{
						temp = temp->prev;
						x--;
					}
				}
			}
			temp = temp->next;
		}
	}
	
	if (found == true)
	{
		Node* temp2;
		int i = 0;
		while (i < len)
		{
			temp2 = st;
			st = st->next;
			delete temp2;
			i++;
		}
		toPut->next = createNode(str2[0]);

		toPut = toPut->next;
		for (int i = 1; str2[i] != '\0'; i++)
		{
			
			Node* newNode = createNode(str2[i]);
			toPut->next = newNode;
			newNode->prev = toPut;
			toPut = toPut->next;
		}
		toPut->next = end->next;
		end->prev = toPut;
	}
	/*else if (!direction)
	{
		{
			Node* temp = tail;
			while (temp != nullptr)
			{
				int count = 0, i = 0;
				if (temp->ch == str1[i])
				{
					st = temp;
					count++;
					while (temp != nullptr &&i < len && str1[i] != '\0')
					{
						i++;
						temp = temp->prev;
						if (temp == nullptr)
						{
							break;
						}
						if (temp != nullptr&&temp->ch == str1[i])
							count++;
					}
					if (temp == nullptr)
					{
						break;
					}
					if (count == len)
					{
						end = temp;
						found = true;
						break;
					}
					else
					{
						st = end = nullptr;
						int x = (len - 1);
						while (x > 1)
						{
							temp = temp->next;
							x--;
						}
					}
				}
				temp = temp->prev;
			}

		}


	}*/

}
ostream& operator << (ostream& out, TextStructure t)      // Friend Function to Output TextStructure
{
	Node* temp = t.head;
	out << "The Characters inside the List are " << endl;
	while (temp != nullptr)
	{
		out << temp->ch << "  ";
		temp = temp->next;
	}
	out << endl;
	return out;
}
void TextStructure::readTextFromFile(const string & filename)
{
	ifstream fin;
	char *arr = nullptr;
	fin.open(filename, ios::in);
	if (fin.fail())
	{
		cout << "Unable to open file " << endl;
		exit(1);
	}
	else
	{

		arr = new char[100];
		fin.getline(arr, 100, '\n');
		textSize = strlen(arr);
		if (textSize > 0)
		{
			head = createNode(arr[0]);
			Node *temp;
			temp = head;


			for (int i = 1; arr[i] != '\0'; i++)
			{
				Node* newNode = createNode(arr[i]);
				temp->next = newNode;
				newNode->prev = temp;
				temp = temp->next;
			}
			tail = temp;
		}
		else
		{
			cout << "The File is empty " << endl;
		}
		delete arr;
	}
}


TextStructure::~TextStructure()
{
	destroyList();
}
void TextStructure::copyList(const TextStructure& otherList)
{
	Node *newNode;       //pointer to create a node
	Node *current;       //pointer to traverse the list
	if (head != nullptr) //if the list is nonempty, make it empty
		destroyList();
	if (otherList.head == nullptr) //otherList is empty
	{
		head = nullptr;
		tail = nullptr;
		textSize = 0;
	}
	else
	{
		current = otherList.head; //current points to the
		//list to be copied
		textSize = otherList.textSize;
		//copy the first node
		head = new Node; //create the node
		head->ch = current->ch; //copy the info
		head->next = nullptr; //set the link field of
		head->prev = nullptr;

		tail = head; //make last point to the
		//first node
		current = current->next; //make current point to
		//the next node
		//copy the remaining list
		while (current != nullptr)
		{
			newNode = new Node; //create a node
			newNode->ch = current->ch; //copy the info
			newNode->next = nullptr; //set the link of
			//newNode to NULL
			newNode->prev = tail;
			tail->next = newNode; //attach newNode after last
			tail = newNode; //make last point to
			//the actual last node
			current = current->next; //make current point
			//to the next node
		}//end while
	}//end else
}//end copyList
void TextStructure::destroyList()
{
	Node *temp; //pointer to deallocate the memory
	//occupied by the node

	while (head != nullptr) //while there are nodes in the list
	{
		temp = head; //set temp to the current node
		head = head->next; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
	}
	tail = nullptr; //initialize last to NULL; first has already
	//been set to NULL by the while loop
	textSize = 0;
}
Node *createNode(const char& obj)
{
	Node *temp = new Node;
	temp->ch = obj;
	temp->next = nullptr;
	temp->prev = nullptr;

	return temp;
}