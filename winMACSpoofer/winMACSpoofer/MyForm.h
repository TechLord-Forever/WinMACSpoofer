
#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

#define TOTALBYTES 8192
#define BYTEINCREMENT 4096

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <iostream>
#include <string>
#include <Windows.h>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <malloc.h>
#include <ctime>
#include <atlbase.h>
#include "atlstr.h"
#include "comutil.h"
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include <iomanip>
#include <sstream>


#pragma comment(lib,"IPHlpApi.Lib")


using namespace std;
using namespace System;
using namespace System::Windows::Forms;



LPCSTR getNetworkInfo();//Locates the active "Wi-Fi" adapter

void setNewMac(); //Set the "Wi-Fi" adapter's new mac address

void revertToOriginalMac(); //change the mac Address back to the original

string queryKey();//Locates the subkey which holds the active "Wi-Fi" adapter

LPCSTR queryRegValue(string); //Find the subkey where the where the active "Wi-Fi" is located

string returnCurrentMAcAddress();//returns the curernt MAC Address of the active nic

string randomizeMAC();//returns a randomized MAC address


#pragma once

string FINAL_MAC = "";

namespace winMACSpoofer {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Label^  label4;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(27, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Current MAC Address";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(146, 22);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(116, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(252, 168);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Set New MAC";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(144, 62);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(118, 21);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Random MAC Address";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(268, 62);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Randomize\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(15, 209);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Enter New MAC Manually";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(146, 104);
			this->textBox3->MaxLength = 2;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(22, 20);
			this->textBox3->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(174, 104);
			this->textBox4->MaxLength = 2;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(22, 20);
			this->textBox4->TabIndex = 10;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(202, 104);
			this->textBox5->MaxLength = 2;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(22, 20);
			this->textBox5->TabIndex = 11;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(230, 104);
			this->textBox6->MaxLength = 2;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(22, 20);
			this->textBox6->TabIndex = 12;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(258, 104);
			this->textBox7->MaxLength = 2;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(22, 20);
			this->textBox7->TabIndex = 13;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(286, 104);
			this->textBox8->MaxLength = 2;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(22, 20);
			this->textBox8->TabIndex = 14;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(121, 145);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(65, 17);
			this->radioButton1->TabIndex = 15;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Random";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(192, 145);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(60, 17);
			this->radioButton2->TabIndex = 16;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Manual";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Set New MAC With :";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 261);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	string queryKey(){

			TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
			DWORD    cbName;                   // size of name string 
			TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
			DWORD    cchClassName = MAX_PATH;  // size of class string 
			DWORD    cSubKeys = 0;               // number of subkeys 
			DWORD    cbMaxSubKey;              // longest subkey size 
			DWORD    cchMaxClass;              // longest class string 
			DWORD    cValues;              // number of values for key 
			DWORD    cchMaxValue;          // longest value name 
			DWORD    cbMaxValueData;       // longest value data 
			DWORD    cbSecurityDescriptor; // size of security descriptor 
			FILETIME ftLastWriteTime;      // last write time 

			DWORD i, retCode;

			TCHAR  achValue[MAX_VALUE_NAME];
			DWORD cchValue = MAX_VALUE_NAME;

			HKEY hKey;
			LPCWSTR dir = TEXT("SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}");
			LONG checkReg = RegOpenKeyEx(HKEY_LOCAL_MACHINE, dir, 0, KEY_READ, &hKey);
			//cout << checkReg;

			if (checkReg == ERROR_SUCCESS)
			{
				cout << "Success opening key" << endl;
			}
			// Get the class name and the value count. 

			retCode = RegQueryInfoKey(
				hKey,                    // key handle 
				achClass,                // buffer for class name 
				&cchClassName,           // size of class string 
				NULL,                    // reserved 
				&cSubKeys,               // number of subkeys 
				&cbMaxSubKey,            // longest subkey size 
				&cchMaxClass,            // longest class string 
				&cValues,                // number of values for this key 
				&cchMaxValue,            // longest value name 
				&cbMaxValueData,         // longest value data 
				&cbSecurityDescriptor,   // security descriptor 
				&ftLastWriteTime);       // last write time 

			// Enumerate the subkeys, until RegEnumKeyEx fails.

			if (cSubKeys)
			{
				//printf("\nNumber of subkeys: %d\n", cSubKeys);

				for (i = 0; i < cSubKeys; i++)
				{
					cbName = MAX_KEY_LENGTH;
					retCode = RegEnumKeyEx(hKey, i, achKey, &cbName, NULL, NULL, NULL, &ftLastWriteTime);
					//string subKey;

					if (retCode == ERROR_SUCCESS)
					{
						//_tprintf(TEXT("(%d) %s\n"), i + 1, achKey);
						String ^subKey = gcnew String(achKey);
						//subKey += " (System::String)";
						string subKeyStr = msclr::interop::marshal_as<std::string>(subKey);
						//queryRegValue(subkey);

						//string key = "SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}\\" + subKey;
						string key = "SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}\\" + subKeyStr;

						//cout << key;
						//Convert string to windows data type
						LPCSTR findKey = key.c_str();
						cout << findKey;
						return key;
					};
				}
			}
		}

	string randomizeMAC(){
			srand(time(0)); //Seeds the rand() function
			string newMAC;
			char secondNibble[] = { 'A', 'E', '2', '6' };
			char newValArray[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
			for (int i = 0; i < 6; i++){

				newMAC += newValArray[rand() % 16];

				//Windows physical address second nibble is limited to 2, 6, A ,E
				if (i == 0)
					newMAC += secondNibble[rand() % 4];
				else
					newMAC += newValArray[rand() % 16];

				if (i < 5)
					newMAC += '-';

			}

			return newMAC;
		}
	
	void setNewMac(){

		HKEY hKey;
		string key = queryKey();
		LPCSTR sk = key.c_str();

		string newMAC = FINAL_MAC;
		LPCSTR keyData = newMAC.c_str();

		//convert LPCSTR to LPCWSTR
		USES_CONVERSION;
		LPCWSTR skw = A2W(sk);
		LPCWSTR keyDataW = A2W(keyData);
		cout << skw;
		LONG retval = RegOpenKeyEx(HKEY_LOCAL_MACHINE, skw, 0, KEY_ALL_ACCESS, &hKey);

		if (retval == ERROR_SUCCESS) {
			printf("Success opening key.");
			
		}
		else {
			printf("Error opening key.");
			cout << retval;
		}
		retval = (RegSetValueEx(hKey, TEXT("NetworkAddress"), 0, REG_SZ, (BYTE*)keyDataW, lstrlen(keyDataW) + 17));

		if (retval == ERROR_SUCCESS){
			printf("Success setting key. ");
		}
		else {
			printf("Error setting key.");
		}
		retval = RegCloseKey(hKey);


		system("netsh interface set interface ""Wi-Fi"" DISABLED");
		system("netsh interface set interface ""Wi-Fi"" ENABLED");

	}

	string returnCurrentMAcAddress(){
		/* Declare and initialize variables */

		PWCHAR networkAdap = NULL;
		PCHAR driverDesc = NULL;

		DWORD dwSize = 0;
		DWORD dwRetVal = 0;

		unsigned int i = 0;

		string currentMAC;

		// Set the flags to pass to GetAdaptersAddresses
		ULONG flags = GAA_FLAG_INCLUDE_PREFIX;

		// default to unspecified address family (both)
		ULONG family = AF_UNSPEC;

		LPVOID lpMsgBuf = NULL;

		PIP_ADAPTER_ADDRESSES pAddresses = NULL;
		ULONG outBufLen = 0;
		ULONG Iterations = 0;

		PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;

		// Allocate a 15 KB buffer to start with.
		outBufLen = WORKING_BUFFER_SIZE;

		do {

			pAddresses = (IP_ADAPTER_ADDRESSES *)MALLOC(outBufLen);
			if (pAddresses == NULL) {
				printf
					("Memory allocation failed for IP_ADAPTER_ADDRESSES struct\n");
				exit(1);
			}

			dwRetVal = GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);

			if (dwRetVal == ERROR_BUFFER_OVERFLOW) {
				FREE(pAddresses);
				pAddresses = NULL;
			}
			else {
				break;
			}

			Iterations++;

		} while ((dwRetVal == ERROR_BUFFER_OVERFLOW) && (Iterations < MAX_TRIES));

		if (dwRetVal == NO_ERROR) {
			// If successful, output some information from the data we received
			pCurrAddresses = pAddresses;

			//Cycles through the Network Adapters, ouputs name, type and operational status
			while (pCurrAddresses) {

				//check to see if network adapter is "Wi-fi"
				//printf("\tOperStatus: %ld\n", pCurrAddresses->OperStatus);
				networkAdap = pCurrAddresses->FriendlyName;
				if (pCurrAddresses->OperStatus == 1 && *networkAdap == 87){ //87 == "Wi-Fi"

					if (pCurrAddresses->PhysicalAddressLength != 0) {
						printf("\tPhysical address: ");
						for (i = 0; i < (int)pCurrAddresses->PhysicalAddressLength; i++) {
							if (i == (pCurrAddresses->PhysicalAddressLength - 1)){
								printf("%.2X\n", (int)pCurrAddresses->PhysicalAddress[i]);

								//Convert int to hex
								stringstream stream;
								stream << setw(2) << uppercase << hex << std::setfill('0') 
									<< (int)pCurrAddresses->PhysicalAddress[i];
								currentMAC += stream.str();
							}
							else{
								printf("%.2X-", (int)pCurrAddresses->PhysicalAddress[i]);

								//Convert int to hex
								stringstream stream;
								stream << setw(2) << uppercase << hex << std::setfill('0') 
									<< (int)pCurrAddresses->PhysicalAddress[i];
								currentMAC += stream.str();
								currentMAC += "-";
							}
						}
					}
				}
				pCurrAddresses = pCurrAddresses->Next;
			}
			
		}
		else {
			printf("Call to GetAdaptersAddresses failed with error: %d\n",
				dwRetVal);
			if (dwRetVal == ERROR_NO_DATA)
				printf("\tNo addresses were found for the requested parameters\n");
			else {

				if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
					FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
					// Default language
					(LPTSTR)& lpMsgBuf, 0, NULL)) {
					printf("\tError: %s", lpMsgBuf);
					LocalFree(lpMsgBuf);
					if (pAddresses)
						FREE(pAddresses);
					exit(1);
				}
			}
		}

		if (pAddresses) {
			FREE(pAddresses);
		}


		cout << currentMAC;
		return currentMAC;
	}

void revertToOriginalMac(){

		HKEY hKey;
		string activeRegKey = queryKey();
		LPCSTR sk = activeRegKey.c_str();
		USES_CONVERSION;
		LPCWSTR activeRegKeyW = A2W(sk);

		LPWSTR netAddr = TEXT("NetworkAddress");
		LONG retval = RegOpenKeyEx(HKEY_LOCAL_MACHINE, activeRegKeyW, 0, KEY_ALL_ACCESS, &hKey);

		if (retval == ERROR_SUCCESS) {
			printf("Success opening key.");
		}
		else {
			printf("Error opening key.");
		}
		retval = RegDeleteValue(hKey, netAddr);

		retval = RegCloseKey(hKey);


		system("netsh interface set interface ""Wi-Fi"" DISABLED");
		system("netsh interface set interface ""Wi-Fi"" ENABLED");

	}
#pragma endregion

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		string currentMAC = returnCurrentMAcAddress();
		String ^systemstring = gcnew String(currentMAC.c_str());
		this->textBox1->Text = systemstring;
	}
	
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	FINAL_MAC = randomizeMAC();
	String ^systemstringRandom = gcnew String(FINAL_MAC.c_str());
	this->textBox2->Text = systemstringRandom;
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e){

	if (radioButton1->Checked){
		setNewMac();

		Sleep(4000);
		string currentMAC = returnCurrentMAcAddress();
		String ^systemstring = gcnew String(currentMAC.c_str());
		this->textBox1->Text = systemstring;

	}
	else if (radioButton2->Checked){
		String ^manualMAC;
		manualMAC += this->textBox3->Text;
		manualMAC += "-";
		manualMAC += this->textBox4->Text;
		manualMAC += "-";
		manualMAC += this->textBox5->Text;
		manualMAC += "-";
		manualMAC += this->textBox6->Text;
		manualMAC += "-";
		manualMAC += this->textBox7->Text;
		manualMAC += "-";
		manualMAC += this->textBox8->Text;

		FINAL_MAC = msclr::interop::marshal_as<std::string>(manualMAC);
		setNewMac();

		Sleep(4000);
		string currentMAC = returnCurrentMAcAddress();
		String ^systemstring = gcnew String(currentMAC.c_str());
		this->textBox1->Text = systemstring;

	}
	else{

	}
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e){
	revertToOriginalMac();

	Sleep(4000);
	string currentMAC = returnCurrentMAcAddress();
	String ^systemstring = gcnew String(currentMAC.c_str());
	this->textBox1->Text = systemstring;
}


};

}



