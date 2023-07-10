#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <msclr\marshal_cppstd.h>
#include "Form2.h"


int index = 0;
using namespace std;

namespace Network {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	vector<vector<string>> network;
	vector<vector<string>> capacity;
	vector<vector<string>> calc;

	vector<vector<string>> getDataFromCSV(string fname) {
		vector<vector<string>> values;
		ifstream ifs(fname.c_str());
		if (!ifs)
		{

			return values;
		}
		string line;
		int count = 0;
		while (ifs.good())
		{
			getline(ifs, line);
			vector<string> temp;
			count++;
			string s = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ';')
					s += line[i];
				else
				{
					temp.push_back(s);
					s = "";
				}
			}
			if (s != "")
				temp.push_back(s);
			if (temp.size() != 0)
				values.push_back(temp);
		}
		ifs.close();

		return values;
	}

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::ColumnHeader^ columnHeader5;
	private: System::Windows::Forms::ColumnHeader^ columnHeader6;
	private: System::Windows::Forms::ColumnHeader^ columnHeader7;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ завантажитиДаніToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ зберегтиДанніToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ мережаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ додатиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ видалитиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ аналізуватиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ проПрограмуToolStripMenuItem;



	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::ListView^ listView3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader13;
	private: System::Windows::Forms::ColumnHeader^ columnHeader14;
	private: System::Windows::Forms::ColumnHeader^ columnHeader15;
	private: System::Windows::Forms::ColumnHeader^ columnHeader16;
	private: System::Windows::Forms::ColumnHeader^ columnHeader17;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ListView^ listView2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader8;
	private: System::Windows::Forms::ColumnHeader^ columnHeader9;
	private: System::Windows::Forms::ColumnHeader^ columnHeader10;
	private: System::Windows::Forms::ColumnHeader^ columnHeader11;
	private: System::Windows::Forms::ColumnHeader^ columnHeader12;


	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
private: System::Windows::Forms::TabPage^ tabPage3;
private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
private: System::Windows::Forms::StatusStrip^ statusStrip1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->завантажитиДаніToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->зберегтиДанніToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->мережаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->додатиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->видалитиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->аналізуватиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->проПрограмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->listView3 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader13 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader14 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader15 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader16 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader17 = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader12 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->panel1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox3);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->listView1);
			this->panel1->Location = System::Drawing::Point(6, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(658, 352);
			this->panel1->TabIndex = 6;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Location = System::Drawing::Point(350, 262);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(300, 85);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Удалить все";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(94, 39);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(122, 23);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Удалить все";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Location = System::Drawing::Point(3, 262);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(330, 85);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Удалить по номеру";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(122, 21);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 2;
			this->textBox6->Text = L"2";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(32, 28);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(79, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Удалить по №";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(111, 56);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Удалить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(3, 162);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(647, 94);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Добавить";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(271, 67);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Добавить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(534, 41);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(107, 20);
			this->textBox5->TabIndex = 9;
			this->textBox5->Text = L"A2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(567, 25);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Выход";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(428, 41);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 7;
			this->textBox4->Text = L"A1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(465, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Вход";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(268, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(133, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Максимальная нагрузка";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(259, 41);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(163, 20);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"100";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(138, 41);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(114, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"M34";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(171, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Название";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(123, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"PC";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(53, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Тип";
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(3, 3);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(652, 153);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"";
			this->columnHeader1->Width = 0;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"№";
			this->columnHeader2->Width = 41;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Тип";
			this->columnHeader3->Width = 130;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Название";
			this->columnHeader4->Width = 122;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Максимальная нагрузка";
			this->columnHeader5->Width = 167;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Вход";
			this->columnHeader6->Width = 98;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Выход";
			this->columnHeader7->Width = 86;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->файлToolStripMenuItem,
					this->мережаToolStripMenuItem, this->проПрограмуToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(699, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->завантажитиДаніToolStripMenuItem,
					this->зберегтиДанніToolStripMenuItem, this->вихідToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// завантажитиДаніToolStripMenuItem
			// 
			this->завантажитиДаніToolStripMenuItem->Name = L"завантажитиДаніToolStripMenuItem";
			this->завантажитиДаніToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->завантажитиДаніToolStripMenuItem->Text = L"Загрузить данные";
			this->завантажитиДаніToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::завантажитиДаніToolStripMenuItem_Click);
			// 
			// зберегтиДанніToolStripMenuItem
			// 
			this->зберегтиДанніToolStripMenuItem->Name = L"зберегтиДанніToolStripMenuItem";
			this->зберегтиДанніToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->зберегтиДанніToolStripMenuItem->Text = L"Сохранить данные";
			this->зберегтиДанніToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::зберегтиДанніToolStripMenuItem_Click);
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->вихідToolStripMenuItem->Text = L"Выход";
			this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::вихідToolStripMenuItem_Click);
			// 
			// мережаToolStripMenuItem
			// 
			this->мережаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->додатиToolStripMenuItem,
					this->видалитиToolStripMenuItem, this->аналізуватиToolStripMenuItem
			});
			this->мережаToolStripMenuItem->Name = L"мережаToolStripMenuItem";
			this->мережаToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->мережаToolStripMenuItem->Text = L"Сеть";
			// 
			// додатиToolStripMenuItem
			// 
			this->додатиToolStripMenuItem->Name = L"додатиToolStripMenuItem";
			this->додатиToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->додатиToolStripMenuItem->Text = L"Добавить";
			this->додатиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::додатиToolStripMenuItem_Click);
			// 
			// видалитиToolStripMenuItem
			// 
			this->видалитиToolStripMenuItem->Name = L"видалитиToolStripMenuItem";
			this->видалитиToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->видалитиToolStripMenuItem->Text = L"Удалить";
			this->видалитиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::видалитиToolStripMenuItem_Click);
			// 
			// аналізуватиToolStripMenuItem
			// 
			this->аналізуватиToolStripMenuItem->Name = L"аналізуватиToolStripMenuItem";
			this->аналізуватиToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->аналізуватиToolStripMenuItem->Text = L"Анализировать";
			this->аналізуватиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::аналізуватиToolStripMenuItem_Click);
			// 
			// проПрограмуToolStripMenuItem
			// 
			this->проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
			this->проПрограмуToolStripMenuItem->Size = System::Drawing::Size(108, 20);
			this->проПрограмуToolStripMenuItem->Text = L"Про программу";
			this->проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::проПрограмуToolStripMenuItem_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->textBox13);
			this->panel3->Controls->Add(this->label13);
			this->panel3->Controls->Add(this->label12);
			this->panel3->Controls->Add(this->textBox12);
			this->panel3->Controls->Add(this->textBox11);
			this->panel3->Controls->Add(this->label11);
			this->panel3->Controls->Add(this->button10);
			this->panel3->Controls->Add(this->listView3);
			this->panel3->Location = System::Drawing::Point(6, 6);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(658, 352);
			this->panel3->TabIndex = 11;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(259, 318);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(157, 20);
			this->textBox13->TabIndex = 7;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(135, 321);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(117, 13);
			this->label13->TabIndex = 6;
			this->label13->Text = L"Уязвим к поражению";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(120, 289);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(133, 13);
			this->label12->TabIndex = 5;
			this->label12->Text = L"Максимальная нагрузка";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(259, 286);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(157, 20);
			this->textBox12->TabIndex = 4;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(259, 220);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(375, 53);
			this->textBox11->TabIndex = 3;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 223);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(248, 13);
			this->label11->TabIndex = 2;
			this->label11->Text = L"Оптимальная последовательность соединения";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(254, 162);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(124, 43);
			this->button10->TabIndex = 1;
			this->button10->Text = L"Расчитать";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// listView3
			// 
			this->listView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader13, this->columnHeader14,
					this->columnHeader15, this->columnHeader16, this->columnHeader17
			});
			this->listView3->HideSelection = false;
			this->listView3->Location = System::Drawing::Point(3, 3);
			this->listView3->Name = L"listView3";
			this->listView3->Size = System::Drawing::Size(652, 153);
			this->listView3->TabIndex = 0;
			this->listView3->UseCompatibleStateImageBehavior = false;
			this->listView3->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader13
			// 
			this->columnHeader13->Text = L"";
			this->columnHeader13->Width = 1;
			// 
			// columnHeader14
			// 
			this->columnHeader14->Text = L"Входной порт";
			this->columnHeader14->Width = 121;
			// 
			// columnHeader15
			// 
			this->columnHeader15->Text = L"Выходной порт";
			this->columnHeader15->Width = 118;
			// 
			// columnHeader16
			// 
			this->columnHeader16->Text = L"Максимальная нагрузка";
			this->columnHeader16->Width = 184;
			// 
			// columnHeader17
			// 
			this->columnHeader17->Text = L"Общая нагрузка на систему";
			this->columnHeader17->Width = 219;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->groupBox6);
			this->panel2->Controls->Add(this->groupBox5);
			this->panel2->Controls->Add(this->groupBox4);
			this->panel2->Controls->Add(this->listView2);
			this->panel2->Location = System::Drawing::Point(6, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(658, 352);
			this->panel2->TabIndex = 12;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->button9);
			this->groupBox6->Location = System::Drawing::Point(335, 262);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(320, 85);
			this->groupBox6->TabIndex = 3;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Удалить все";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(89, 39);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(135, 23);
			this->button9->TabIndex = 0;
			this->button9->Text = L"Удалить все";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button8);
			this->groupBox5->Controls->Add(this->textBox10);
			this->groupBox5->Controls->Add(this->label10);
			this->groupBox5->Location = System::Drawing::Point(3, 262);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(326, 85);
			this->groupBox5->TabIndex = 2;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Удалить по номеру";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(112, 53);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 2;
			this->button8->Text = L"Удалить";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(121, 27);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 20);
			this->textBox10->TabIndex = 1;
			this->textBox10->Text = L"2";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(31, 30);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(79, 13);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Удалить по №";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button7);
			this->groupBox4->Controls->Add(this->textBox9);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->textBox8);
			this->groupBox4->Controls->Add(this->textBox7);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Location = System::Drawing::Point(3, 162);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(652, 94);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Добавить";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(251, 67);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Добавить";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(407, 41);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(175, 20);
			this->textBox9->TabIndex = 5;
			this->textBox9->Text = L"500";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(418, 25);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(133, 13);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Максимальная нагрузка";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(249, 25);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(83, 13);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Выходной порт";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(206, 41);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(154, 20);
			this->textBox8->TabIndex = 2;
			this->textBox8->Text = L"A1";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(17, 41);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(151, 20);
			this->textBox7->TabIndex = 1;
			this->textBox7->Text = L"A0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(36, 25);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Входной порт";
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader8, this->columnHeader9,
					this->columnHeader10, this->columnHeader11, this->columnHeader12
			});
			this->listView2->HideSelection = false;
			this->listView2->Location = System::Drawing::Point(3, 5);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(652, 153);
			this->listView2->TabIndex = 0;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"";
			this->columnHeader8->Width = 0;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"№";
			this->columnHeader9->Width = 57;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"Входной порт";
			this->columnHeader10->Width = 179;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"Выходной порт";
			this->columnHeader11->Width = 168;
			// 
			// columnHeader12
			// 
			this->columnHeader12->Text = L"Максимальная нагрузка";
			this->columnHeader12->Width = 177;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 29);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(682, 392);
			this->tabControl1->TabIndex = 14;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(674, 366);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Элементы компьютерной сети";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->panel2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(674, 366);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Нагрузка";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->panel3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(674, 366);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Расчеты";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 426);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(699, 22);
			this->statusStrip1->TabIndex = 13;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 448);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"Form1";
			this->Text = L"Dish Network";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		toolStripStatusLabel1->Text = "";
	}
	
private: System::Void вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Network::Form2^ f2 = gcnew Network::Form2;
	f2->Show();
	toolStripStatusLabel1->Text = "Открыта форма 2";
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	string k1 = msclr::interop::marshal_as<std::string>(textBox1->Text);
	string k2 = msclr::interop::marshal_as<std::string>(textBox2->Text);
	string k3 = msclr::interop::marshal_as<std::string>(textBox3->Text);
	string k4 = msclr::interop::marshal_as<std::string>(textBox4->Text);
	string k5 = msclr::interop::marshal_as<std::string>(textBox5->Text);

	network.push_back({ k1,k2,k3,k4,k5 });

	index = 0;
	this->listView1->Items->Clear();

	// добавляем строки в listView1
	for (int i = 0; i < network.size(); i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView1
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(to_string(index).c_str()));
		for (int j = 0; j < network[i].size(); ++j)
			listViewItem->SubItems->Add(gcnew System::String(network[i][j].c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView1
		listView1->Items->Add(listViewItem);
	}
	toolStripStatusLabel1->Text = "Добавлено";
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<vector<string>> v;
	for (int i = 0; i < network.size(); ++i)
		if (i + 1 != stoi(msclr::interop::marshal_as<std::string>(textBox6->Text)))
			v.push_back(network[i]);
	network =v;

	index = 0;
	this->listView1->Items->Clear();

	// добавляем строки в listView1
	for (int i = 0; i < network.size(); i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView1
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(to_string(index).c_str()));
		for (int j = 0; j < network[i].size(); ++j)
			listViewItem->SubItems->Add(gcnew System::String(network[i][j].c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView1
		listView1->Items->Add(listViewItem);
	}
	toolStripStatusLabel1->Text = "Удалено по номеру " + textBox6->Text;
}
private: System::Void завантажитиДаніToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	network = getDataFromCSV("network.csv");
	index = 0;
	this->listView1->Items->Clear();

	// добавляем строки в listView1
	for (int i = 0; i < network.size(); i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView1
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(to_string(index).c_str()));
		for (int j = 0; j < network[i].size(); ++j)
			listViewItem->SubItems->Add(gcnew System::String(network[i][j].c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView1
		listView1->Items->Add(listViewItem);
	}

	capacity = getDataFromCSV("capacity.csv");
	index = 0;
	this->listView2->Items->Clear();

	// добавляем строки в listView2
	for (int i = 0; i < capacity.size(); i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView2
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(to_string(index).c_str()));
		for (int j = 0; j < capacity[i].size(); ++j)
			listViewItem->SubItems->Add(gcnew System::String(capacity[i][j].c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView2
		listView2->Items->Add(listViewItem);
	}
	toolStripStatusLabel1->Text = "Загружено";
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripStatusLabel1->Text = "Добавлено";
	string k1 = msclr::interop::marshal_as<std::string>(textBox7->Text);
	string k2 = msclr::interop::marshal_as<std::string>(textBox8->Text);
	string k3 = msclr::interop::marshal_as<std::string>(textBox9->Text);
	

	capacity.push_back({ k1,k2,k3 });

	index = 0;
	this->listView2->Items->Clear();

	// добавляем строки в listView2
	for (int i = 0; i < capacity.size(); i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView2
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(to_string(index).c_str()));
		for (int j = 0; j < capacity[i].size(); ++j)
			listViewItem->SubItems->Add(gcnew System::String(capacity[i][j].c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView2
		listView2->Items->Add(listViewItem);
	}
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<vector<string>> v;
	for (int i = 0; i < capacity.size(); ++i)
		if (i + 1 != stoi(msclr::interop::marshal_as<std::string>(textBox10->Text)))
			v.push_back(capacity[i]);
	capacity = v;

	index = 0;
	this->listView2->Items->Clear();

	// добавляем строки в listView2
	for (int i = 0; i < capacity.size(); i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView2
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(to_string(index).c_str()));
		for (int j = 0; j < capacity[i].size(); ++j)
			listViewItem->SubItems->Add(gcnew System::String(capacity[i][j].c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView2
		listView2->Items->Add(listViewItem);
	}
	toolStripStatusLabel1->Text = "Удалено по номеру " + textBox10->Text;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	network.clear();
	this->listView1->Items->Clear();
	toolStripStatusLabel1->Text = "Удалено";
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	capacity.clear();
	this->listView2->Items->Clear();
	toolStripStatusLabel1->Text = "Удалено";
}
private: System::Void зберегтиДанніToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ofstream myFile;
	string str = "network.csv";
	myFile.open(str);
	for (int i = 0; i < network.size(); ++i)
	{
		for (int j = 0; j < network[i].size(); ++j)
			myFile << network[i][j] << ";";
		myFile << endl;
	}


	ofstream myFile2;
	string str2 = "capacity.csv";
	myFile2.open(str2);
	for (int i = 0; i < capacity.size(); ++i)
	{
		for (int j = 0; j < capacity[i].size(); ++j)
			myFile2 << capacity[i][j] << ";";
		myFile2 << endl;
	}
	toolStripStatusLabel1->Text = "Сохранено в файлы network.csv и capacity.csv";
}
private: System::Void додатиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	string k1 = msclr::interop::marshal_as<std::string>(textBox1->Text);
	string k2 = msclr::interop::marshal_as<std::string>(textBox2->Text);
	string k3 = msclr::interop::marshal_as<std::string>(textBox3->Text);
	string k4 = msclr::interop::marshal_as<std::string>(textBox4->Text);
	string k5 = msclr::interop::marshal_as<std::string>(textBox5->Text);

	network.push_back({ k1,k2,k3,k4,k5 });

	index = 0;
	this->listView1->Items->Clear();

	// добавляем строки в listView1
	for (int i = 0; i < network.size(); i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView1
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(to_string(index).c_str()));
		for (int j = 0; j < network[i].size(); ++j)
			listViewItem->SubItems->Add(gcnew System::String(network[i][j].c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView1
		listView1->Items->Add(listViewItem);
	}
	toolStripStatusLabel1->Text = "Добавлено";
}
private: System::Void видалитиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<vector<string>> v;
	for (int i = 0; i < network.size(); ++i)
		if (i + 1 != stoi(msclr::interop::marshal_as<std::string>(textBox6->Text)))
			v.push_back(network[i]);
	network = v;

	index = 0;
	this->listView1->Items->Clear();

	// добавляем строки в listView1
	for (int i = 0; i < network.size(); i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView1
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(to_string(index).c_str()));
		for (int j = 0; j < network[i].size(); ++j)
			listViewItem->SubItems->Add(gcnew System::String(network[i][j].c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView1
		listView1->Items->Add(listViewItem);
	}
	toolStripStatusLabel1->Text = "Удалено";
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<string> Mass;

	for (int i = 0; i < network.size(); ++i)
	{
		int count = 0;
		for (int j = 0; j < Mass.size(); ++j)
			if (Mass[j] == network[i][3])
				count++;
		if (count == 0)
			Mass.push_back(network[i][3]);

		count = 0;
		for (int j = 0; j < Mass.size(); ++j)
			if (Mass[j] == network[i][4])
				count++;
		if (count == 0)
			Mass.push_back(network[i][4]);
	}

	vector<vector<int>> MassCompany;

	for (int i = 0; i < Mass.size(); ++i)
	{
		vector<int> a;
		for (int j = 0; j < Mass.size(); ++j)
			a.push_back(5000);
		MassCompany.push_back(a);
	}


	for (int i = 0; i < MassCompany.size(); ++i)
	{
		for (int j = 0; j < MassCompany.size(); ++j)
			for (int k = 0; k < capacity.size(); ++k)
			{
				bool c1 = capacity[k][0] == Mass[i];
				bool c2 = capacity[k][1] == Mass[j];
				bool c3 = capacity[k][0] == Mass[j];
				bool c4 = capacity[k][1] == Mass[i];

				if (c1 && c2 || c3 && c4)
				{
					int c = stoi(capacity[k][2]);
					MassCompany[i][j] = c;
				}
			}
	}


	vector<int> ANS;
	ANS.push_back(0);
	do
	{
		int max = 9999;
		int j = ANS[ANS.size() - 1];
		for (int i = 0; i < MassCompany.size(); ++i)
		{
			int count = 0;
			for (int k = 0; k < ANS.size(); ++k)
				if (ANS[k] == i)
					count++;

			if (MassCompany[j][i] < max && count==0)
			{
				max = MassCompany[ANS[ANS.size() - 1]][i];
				j = i;
			}
		}
		ANS.push_back(j);
	} while (ANS.size() < Mass.size());

	string str = "";
	for (int i = 0; i < ANS.size() - 1; ++i)
		str += Mass[ANS[i]] + "-";
	if (ANS.size() != 0)
		str += Mass[ANS[ANS.size() - 1]];

	int sum = 0;
	for (int i = 0; i < ANS.size() - 1; ++i)
		sum += MassCompany[ANS[i]][ANS[i + 1]];

	int M = 0;
	vector<int> V;
	for (int i = 0; i < ANS.size() - 1; ++i)
	{
		for (int j = 0; j < network.size(); ++j)
		{
			if (network[j][3] == Mass[ANS[i]])
				M += stoi(network[j][2]);
			if (network[j][4] == Mass[ANS[i]])
				M -= stoi(network[j][2]);
		}
		V.push_back(M);
	}


	index = 0;
	this->listView3->Items->Clear();

	// добавляем строки в listView3
	for (int i = 0; i < ANS.size()-1; i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView3
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(Mass[ANS[i	]].c_str()));
		listViewItem->SubItems->Add(gcnew System::String(Mass[ANS[i + 1]].c_str()));
		listViewItem->SubItems->Add(gcnew System::String(to_string(MassCompany[ANS[i]][ANS[i + 1]]).c_str()));
		listViewItem->SubItems->Add(gcnew System::String(to_string(V[i]).c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView3
		listView3->Items->Add(listViewItem);
	}

	textBox11->Text = gcnew System::String(str.c_str());
	textBox12->Text = gcnew System::String(to_string(sum).c_str());
	textBox13->Text = ANS.size() > 1 ? gcnew System::String(Mass[ANS[1]].c_str()) : "";

	toolStripStatusLabel1->Text = "Расчитано";
}
private: System::Void аналізуватиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<string> Mass;

	for (int i = 0; i < network.size(); ++i)
	{
		int count = 0;
		for (int j = 0; j < Mass.size(); ++j)
			if (Mass[j] == network[i][3])
				count++;
		if (count == 0)
			Mass.push_back(network[i][3]);

		count = 0;
		for (int j = 0; j < Mass.size(); ++j)
			if (Mass[j] == network[i][4])
				count++;
		if (count == 0)
			Mass.push_back(network[i][4]);
	}

	vector<vector<int>> MassCompany;

	for (int i = 0; i < Mass.size(); ++i)
	{
		vector<int> a;
		for (int j = 0; j < Mass.size(); ++j)
			a.push_back(5000);
		MassCompany.push_back(a);
	}


	for (int i = 0; i < MassCompany.size(); ++i)
	{
		for (int j = 0; j < MassCompany.size(); ++j)
			for (int k = 0; k < capacity.size(); ++k)
			{
				bool c1 = capacity[k][0] == Mass[i];
				bool c2 = capacity[k][1] == Mass[j];
				bool c3 = capacity[k][0] == Mass[j];
				bool c4 = capacity[k][1] == Mass[i];

				if (c1 && c2 || c3 && c4)
				{
					int c = stoi(capacity[k][2]);
					MassCompany[i][j] = c;
				}
			}
	}


	vector<int> ANS;
	ANS.push_back(0);
	do
	{
		int max = 9999;
		int j = ANS[ANS.size() - 1];
		for (int i = 0; i < MassCompany.size(); ++i)
		{
			int count = 0;
			for (int k = 0; k < ANS.size(); ++k)
				if (ANS[k] == i)
					count++;

			if (MassCompany[j][i] < max && count == 0)
			{
				max = MassCompany[ANS[ANS.size() - 1]][i];
				j = i;
			}
		}
		ANS.push_back(j);
	} while (ANS.size() < Mass.size());

	string str = "";
	for (int i = 0; i < ANS.size() - 1; ++i)
		str += Mass[ANS[i]] + "-";
	if (ANS.size() != 0)
		str += Mass[ANS[ANS.size() - 1]];

	int sum = 0;
	for (int i = 0; i < ANS.size() - 1; ++i)
		sum += MassCompany[ANS[i]][ANS[i + 1]];

	int M = 0;
	vector<int> V;
	for (int i = 0; i < ANS.size() - 1; ++i)
	{
		for (int j = 0; j < network.size(); ++j)
		{
			if (network[j][3] == Mass[ANS[i]])
				M += stoi(network[j][2]);
			if (network[j][4] == Mass[ANS[i]])
				M -= stoi(network[j][2]);
		}
		V.push_back(M);
	}


	index = 0;
	this->listView3->Items->Clear();

	// добавляем строки в listView3
	for (int i = 0; i < ANS.size() - 1; i++)
	{
		index++;
		// создадим объект ListViewItem (строку) для listView3
		ListViewItem^ listViewItem = gcnew ListViewItem();
		listViewItem->SubItems->Add(gcnew System::String(Mass[ANS[i]].c_str()));
		listViewItem->SubItems->Add(gcnew System::String(Mass[ANS[i + 1]].c_str()));
		listViewItem->SubItems->Add(gcnew System::String(to_string(MassCompany[ANS[i]][ANS[i + 1]]).c_str()));
		listViewItem->SubItems->Add(gcnew System::String(to_string(V[i]).c_str()));
		// добавляем созданный элемент listViewItem (строку) в listView3
		listView3->Items->Add(listViewItem);
	}

	textBox11->Text = gcnew System::String(str.c_str());
	textBox12->Text = gcnew System::String(to_string(sum).c_str());
	textBox13->Text = ANS.size() > 1 ? gcnew System::String(Mass[ANS[1]].c_str()) : "";
	toolStripStatusLabel1->Text = "Расчитано";
}
};
}
