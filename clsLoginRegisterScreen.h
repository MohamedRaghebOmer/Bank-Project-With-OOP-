#pragma once
#include "clsScreen.h"
class clsLoginRegisterScreen : public clsScreen
{
private:
	static void _PrintOneRegister(const string& RegisterLine)
	{
		vector <string> CurrentLineSplited = clsString::Split(RegisterLine, "#//#");
		
		cout << setw(20) << left << "" << "| " << left << setw(33) << CurrentLineSplited[0];
		cout << "| " << left << setw(17) << CurrentLineSplited[1];
		cout << "| " << left << setw(15) << CurrentLineSplited[2];
		cout << "| " << left << setw(8) << CurrentLineSplited[3];
	}

public:
	static void ShowLoginRegisterScreen()
	{
		// Check acess first

		_DrawScreenHeader("Login Register Screen", "", true);

		cout << setw(20) << left << "" << "\n\t________________________________________________________________________________________________________\n\n";
		cout << setw(20) << left << "" << "| " << left << setw(33) << "Date & Time";
		cout << "| " << left << setw(17) << "User Name";
		cout << "| " << left << setw(15) << "Password";
		cout << "| " << left << setw(8) << "Permissions";
		cout << setw(20) << left << "" << "\n\t________________________________________________________________________________________________________\n\n";

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string CurrentLine = "";

			while (getline(MyFile, CurrentLine))
			{
				_PrintOneRegister(CurrentLine);
				cout << endl;
			}
			cout << setw(20) << left << "" << "\n\t________________________________________________________________________________________________________\n\n";

			MyFile.close();
		}
	}

};

