#pragma once
#include "clsScreen.h"

class clsTransferScreen : public clsScreen
{
private:

	static void _PrintClient(clsBankClient& Client)
	{

		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc.Number  : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:
	static void ShowTransferScreen()
	{
		// Check access rights in the next lesson


		clsScreen::_DrawScreenHeader("Transfer Screen");

		// Read account number and validate it's existance 
		string AccountNumber1 = clsInputValidate::ReadString("Please enter account number to transfer from: ");
		while (!clsBankClient::IsClientExist(AccountNumber1))
		{
			cout << "Account number you entered doesn't exist, please try again.\n\n";
			AccountNumber1 = clsInputValidate::ReadString("Please enter account number to transfer from: ");

		}


		// find client and print his card
		clsBankClient TransferFrom = clsBankClient::Find(AccountNumber1);
		_PrintClient(TransferFrom);


		// Read the account number that we want to transfer to 
		string AccountNumber2 = clsInputValidate::ReadString("\nPlease enter account number to transfer to: ");
		while (!clsBankClient::IsClientExist(AccountNumber2) || AccountNumber2 == AccountNumber1)
		{
			if (AccountNumber1 == AccountNumber2)
				cout << "Can't transfer to the same account number, please enter another account number.\n\n";
			else
				cout << "Account number you entered doesn't exist, please try again.\n\n";

			AccountNumber2 = clsInputValidate::ReadString("Please enter account number to transfer to: ");
		}


		// find client and print his card
		clsBankClient TransferTo = clsBankClient::Find(AccountNumber2);
		_PrintClient(TransferTo);


		// Read valid transfer amount
		float TransferAmount = clsInputValidate::ReadPositiveFloat(false, "\nEnter transfer amount: ", "Amount must be greater than Zero, please try again\n\n");
		while (TransferAmount > TransferFrom.AccountBalance)
		{
			cout << "Amount exceeds the avalible balance, please enter a valid amount.\n\n" << endl;
			TransferAmount = clsInputValidate::ReadPositiveFloat(false, "Enter transfer amount: ", "Amount must be greater than Zero, please try again\n\n");

		}


		// if sure do transfering
		char sure = 'n';
		cout << "Are you sure, do you want to perform this operation? [Y|N]: ";
		cin >> sure;
		if (sure == 'y' || sure == 'Y')
		{
			TransferFrom.AccountBalance -= TransferAmount;
			TransferFrom.Save();

			TransferTo.AccountBalance += TransferAmount;
			TransferTo.Save();
		}


		cout << "Sender card after transfering:" << endl;
		_PrintClient(TransferFrom);

		cout << "Receiver card after transfering:" << endl;
		_PrintClient(TransferTo);

		// Transfering is Done :-)
	}
};

