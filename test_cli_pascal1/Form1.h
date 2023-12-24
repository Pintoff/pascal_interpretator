#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "lexan.h"
#include "sall.h"
#include <vcclr.h>


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::Button^ lexical;
	private: System::Windows::Forms::Button^ syntax;

	private: System::Windows::Forms::RichTextBox^ sourceFile;


	private:
		
	bool isRichTextBoxEmpty = true;
	bool isFileSelected = false;
	System::String^ selectedFileName = nullptr;
	private: System::Windows::Forms::RichTextBox^ infoBox;
	

	private: System::Windows::Forms::TextBox^ errBoxHeader;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ clearSourceField;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lexical = (gcnew System::Windows::Forms::Button());
			this->syntax = (gcnew System::Windows::Forms::Button());
			this->sourceFile = (gcnew System::Windows::Forms::RichTextBox());
			this->infoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->errBoxHeader = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->clearSourceField = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����ToolStripMenuItem,
					this->������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1283, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->��������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(57, 24);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��������ToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->������ToolStripMenuItem->Text = L"������";
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����ToolStripMenuItem_Click);
			// 
			// lexical
			// 
			this->lexical->Enabled = false;
			this->lexical->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lexical->Location = System::Drawing::Point(12, 46);
			this->lexical->Name = L"lexical";
			this->lexical->Size = System::Drawing::Size(143, 86);
			this->lexical->TabIndex = 3;
			this->lexical->Text = L"����������� ������";
			this->lexical->UseVisualStyleBackColor = true;
			this->lexical->Click += gcnew System::EventHandler(this, &Form1::lexical_Click);
			// 
			// syntax
			// 
			this->syntax->Enabled = false;
			this->syntax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->syntax->Location = System::Drawing::Point(12, 145);
			this->syntax->Name = L"syntax";
			this->syntax->Size = System::Drawing::Size(143, 86);
			this->syntax->TabIndex = 4;
			this->syntax->Text = L"�������������� ������";
			this->syntax->UseVisualStyleBackColor = true;
			this->syntax->Click += gcnew System::EventHandler(this, &Form1::syntax_Click);
			// 
			// sourceFile
			// 
			this->sourceFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->sourceFile->Location = System::Drawing::Point(734, 87);
			this->sourceFile->Name = L"sourceFile";
			this->sourceFile->Size = System::Drawing::Size(535, 477);
			this->sourceFile->TabIndex = 6;
			this->sourceFile->Text = L"";
			this->sourceFile->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// infoBox
			// 
			this->infoBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->infoBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infoBox->Location = System::Drawing::Point(219, 87);
			this->infoBox->Name = L"infoBox";
			this->infoBox->ReadOnly = true;
			this->infoBox->Size = System::Drawing::Size(473, 477);
			this->infoBox->TabIndex = 7;
			this->infoBox->Text = L"";
			this->infoBox->TextChanged += gcnew System::EventHandler(this, &Form1::infoBox_TextChanged);
			// 
			// errBoxHeader
			// 
			this->errBoxHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->errBoxHeader->Location = System::Drawing::Point(219, 46);
			this->errBoxHeader->Name = L"errBoxHeader";
			this->errBoxHeader->ReadOnly = true;
			this->errBoxHeader->Size = System::Drawing::Size(196, 29);
			this->errBoxHeader->TabIndex = 8;
			this->errBoxHeader->Text = L"��������� ������";
			this->errBoxHeader->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(942, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 24);
			this->label1->TabIndex = 9;
			this->label1->Text = L"�������� ����";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(454, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(203, 29);
			this->button1->TabIndex = 10;
			this->button1->Text = L"�������� ��������� ������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// clearSourceField
			// 
			this->clearSourceField->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->clearSourceField->Location = System::Drawing::Point(1099, 46);
			this->clearSourceField->Name = L"clearSourceField";
			this->clearSourceField->Size = System::Drawing::Size(127, 28);
			this->clearSourceField->TabIndex = 11;
			this->clearSourceField->Text = L"�������� ���� �����";
			this->clearSourceField->UseVisualStyleBackColor = true;
			this->clearSourceField->Click += gcnew System::EventHandler(this, &Form1::clearSourceField_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1283, 612);
			this->Controls->Add(this->clearSourceField);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->errBoxHeader);
			this->Controls->Add(this->infoBox);
			this->Controls->Add(this->sourceFile);
			this->Controls->Add(this->syntax);
			this->Controls->Add(this->lexical);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"������������� ����� �������";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::OpenFileDialog^ openFileDialog1 = gcnew System::Windows::Forms::OpenFileDialog();

		openFileDialog1->Filter = "��������� ����� (*.txt)|*.txt|��� ����� (*.*)|*.*";
		openFileDialog1->FilterIndex = 1;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			selectedFileName = openFileDialog1->FileName;
			
			isFileSelected = true;
			UpdateButtonAvailability();
			System::Windows::Forms::MessageBox::Show("������ ����: " + selectedFileName, "����������");
		}
	}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	System::String^ text = sourceFile->Text;
	isRichTextBoxEmpty = System::String::IsNullOrWhiteSpace(text);
	UpdateButtonAvailability();
}
private: System::Void lexical_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isFileSelected) {
		if (initialize(1) == 1) {
			syntax->Enabled = true;
		}
		pin_ptr<const wchar_t> wname = PtrToStringChars(selectedFileName);
		FILE* input = _wfopen(wname, L"rt");
		if (!input) {
			// �������� � ������� ������
			showErrorMsg("Exception raised - main: error while open input file");
		}
		else {
			fseek(input, 0, SEEK_END);
			long fileSize = ftell(input);
			fseek(input, 0, SEEK_SET);
			char* buffer = new char[fileSize + 1];
			fread(buffer, sizeof(char), fileSize, input);
			fclose(input);
			buffer[fileSize] = '\0';
			String^ fileContent = gcnew String(buffer, 0, fileSize, System::Text::Encoding::UTF8);
			sourceFile->Text = fileContent;
			delete[] buffer;
			return;
		}
	} 
	
}
private: void UpdateButtonAvailability() {
		   bool isButtonEnabled = !isRichTextBoxEmpty || isFileSelected;

		   lexical->Enabled = isButtonEnabled;
}

private: int initialize(int state) {
	// ��������� ������� �����
	pin_ptr<const wchar_t> wname = PtrToStringChars(selectedFileName);
	FILE* input = _wfopen(wname, L"rt");
	// ��������� �������� ����� (������)
	FILE* output = fopen("..\\output.txt", "w");
	// ��������� �������� ����� (���������)
	FILE* result = fopen("..\\result.txt", "w");
	setlocale(LC_ALL, ".1251");
	if (!input) {
		// �������� � ������� ������
		showErrorMsg("Exception raised - main : error while open input file");
		fprintf(result, "\nException raised - main: error while open input file\n\n");
	}
	// ����������: 1 - �����, 0 - �������
	int i = interpretate(input, output, result, state);
	fclose(input);
	fclose(output);
	fclose(result);
	ReadOutputFile();
	return i;
}

private: int initialize(int state, FILE* input) {
	// ��������� �������� ����� (������)
	FILE* output = fopen("..\\output.txt", "w");
	// ��������� �������� ����� (���������)
	FILE* result = fopen("..\\result.txt", "w");
	setlocale(LC_ALL, ".1251");
	if (!input) {
		// �������� � ������� ������
		showErrorMsg("Exception raised - main : error while open input file");
		fprintf(result, "\nException raised - main: error while open input file\n\n");
	}
	// ����������: 1 - �����, 0 - �������
	int i = interpretate(input, output, result, state);
	fclose(input);
	fclose(output);
	fclose(result);
	ReadOutputFile();
	return i;
}

private: // ������������� �����
	int interpretate(FILE* input, FILE* output, FILE* result, int state) {
		// ����������� ������
		if (state == 1) {
			// ����������� ����������
			try {
				// �������������� ������
				return (new lexan(input, output))->parse();
			}
			catch (texception* e) {
				printf("\nException raised - ");
				fprintf(result, "\nException raised - ");
				e->get_info(result);
				return -1;
			}
			catch (...) {
				printf("\nUnexpected exception raised\n\n");
				fprintf(result, "\nUnexpected exception raised\n\n");
				return -2;
			}
			return 1;
		}
		// �������������� ������
		if (state == 2) {
			// ����������� ����������
			try {
				// �������������� ������
				return (new syntaxan(new lexan(input, output), output, result))->parse();
			}
			catch (texception* e) {
				printf("\nException raised - ");
				fprintf(result, "\nException raised - ");
				e->get_info(result);
			}
			catch (...) {
				printf("\nUnexpected exception raised\n\n");
				fprintf(result, "\nUnexpected exception raised\n\n");
			}
			return 0; // �������
		}

		if (state == 3) {

		}
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void infoBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}

private: System::Void ReadOutputFile()
{
	FILE* output = fopen("..\\output.txt", "rt");
	if (output != nullptr)
	{
		std::string content;
		char buffer[256];
		while (fgets(buffer, sizeof(buffer), output) != nullptr)
		{
			content += buffer;
		}
		fclose(output);
		String^ contentString = gcnew String(content.c_str());
		infoBox->Text = contentString;
	} else {
		showErrorMsg("������ �������� ����� output.txt");
	}
}
private: System::Void syntax_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isFileSelected) {
		if (initialize(2) == 1) {
			// ������
			
		}
		readResultFile();
		return;
	} 
}

private:void readResultFile() {
	FILE* output = fopen("..\\result.txt", "rt");
	if (output != nullptr)
	{
		std::string content;
		char buffer[256];
		while (fgets(buffer, sizeof(buffer), output) != nullptr)
		{
			content += buffer;
		}
		fclose(output);
		String^ contentString = gcnew String(content.c_str());
		infoBox->Text += contentString;
	} else {
		showErrorMsg("������ �������� ����� result.txt");
	}
}
private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ message = "1. ������� �������� ���� ��� �������� �������� ���� � �������� ����.\n"
		"2. ������� �� ������ ����������� ������.\n"
		"3. ����� ��������� ������������ ������� ������� �� ������ �������������� ������.";

	MessageBox::Show(message, "������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	selectedFileName = nullptr;
	isFileSelected = false;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	infoBox->Clear();
}

private: void showErrorMsg(String^ errorMessage) {
	MessageBox::Show(errorMessage, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
private: System::Void clearSourceField_Click(System::Object^ sender, System::EventArgs^ e) {
	sourceFile->Clear();
}
private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	this->~Form1();
}

};
}
