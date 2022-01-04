#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

void EmailC();
void EmailAdd();

int main()
{
	cout << "----- Please Enter Your Credentials -----\n" << endl;
	EmailC();
	return 0;
}

bool operator == (string name, string username)
{
	if (name.length() - 1 == username.length() || name.length() == username.length())
	{
		for (int i = 0; i < name.length() - 1; i++)
		{
			if (name[i] != username[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

void EmailC()
{
	string name, username, passD, passU;
	char ans;
	int atc = 0, matchE = 0, matchP = 0, lineT = 0, lineN;
	bool valid = true;

	cout << "Username / Email: ";
	cin >> username;

	for (int i = 0; i < username.length(); i++)
	{
		if (username[i] == '@')
		{
			atc += 1;
		}
	}
	if (atc > 1)
	{
		cout << "Email / Username is not valid\n" << endl;
		cout << endl;
		cout << "Try again: " << endl;
		EmailC();
	}

	fstream dataB;
	dataB.open("ValidNames.txt");
	if (!dataB.is_open())
	{
		cout << "1-File could not be opened...\n" << endl;
	}

	fstream dataP;
	dataP.open("ValidPass.txt");
	if (!dataP.is_open())
	{
		cout << "2-File could not be opened...\n" << endl;
	}
	
	while (getline(dataB, name))
	{
		lineT++;
		if (name == username)
		{
			matchE += 1;
			lineN = lineT;
		}
	}
	
	if (matchE != 1)
	{
		cout << "\n---------------------------------------\nEmail / Username is not in the database\n---------------------------------------\n" << endl;

		cout << " + Would you like to sign up? + \n\nYes or No [Y/N]: ";
		cin >> ans;

		if (ans == 'y' || ans == 'Y')
		{
			EmailAdd();
			EmailC();
		}
		else if (ans == 'n' || ans == 'N')
		{
			EmailC();
		}
	}
	else if (matchE == 1)
	{
		int count = 0;
		cout << "Password: ";
		cin >> passU;
		while (getline(dataP, passD))
		{
			count++;
			if (count == lineN)
			{
				if (passD.length() - 1 == passU.length() || passD.length() == passU.length())
				{
					for (int i = 0; i < passD.length() - 1; i++)
					{
						if (passD[i] != passU[i])
						{
							valid = false;
						}
					}
				}
				else
				{
					valid = false;
				}
			}
		}
	}
	
	if (valid == false)
	{
		cout << "Incorrect Email / Password. Try again: \n" << endl;
		EmailC();
	}
	else 
	{
		char letter;
		cout << "\n *** Valid. You have gained access to nothing. *** " << endl;
		cout << "\nDo you want to see a picture of a dog instead? [Y/N]: ";
		cin >> letter;
		if (letter == 'y' || letter == 'Y')
		{
			cout << "\nJust kidding I cannot show you due to an 'unknown escape sequence: '040'"<< endl;
		}
	}
	dataB.close();
	dataP.close();
}

void EmailAdd()
{
	string Estr, newP, newPt, Eline, Pline;
	int atcount = 0;

	fstream dataB;
	dataB.open("ValidNames.txt", ios_base::app);
	if (!dataB.is_open())
	{
		cout << "1-File could not be opened...\n" << endl;
	}

	fstream dataP;
	dataP.open("ValidPass.txt", ios_base::app);
	if (!dataP.is_open())
	{
		cout << "2-File could not be opened...\n" << endl;
	}

	cout << "\n--------\nSign up!\n--------\n" << endl;
	cout << "Email: ";
	cin >> Estr;
	for (int i = 0; i < Estr.length(); i++)
	{
		if (Estr[i] == '@')
		{
			atcount += 1;
		}
	}
	if (atcount > 1 || atcount == 0)
	{
		cout << "Email / Username is not valid\n" << endl;
		cout << endl;
		cout << "Try again: " << endl;
		EmailAdd();
	}
	else 
	{
		int tNum = 0, num = 0;

		dataB << Estr << endl;
		cout << "Valid.\n\nEnter a new Password: ";
		cin >> newPt;
		cout << "\nConfirm new Password: ";
		cin >> newP;
		if (newPt != newP)
		{
			cout << "\nError: Passwords do not match.\n Try Again:\n" << endl;
		}
		else
		{
			cout << "-------------------------" << endl;
			dataP << newP << endl;
		}
	}

}