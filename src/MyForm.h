#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <tisudshl.h>
#include "Listener.h"
#include "Algorithm.h"
#include <Windows.h>

#include <iostream>
#include <string>
#include <ctime>



namespace FARELCLRv02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace alg;
	using namespace _DSHOWLIB_NAMESPACE; // The Imaging Source camera library with DSHOW API

	Mat raw;
	Mat frame;
	DShowLib::Grabber* m_pGrabber;
	Listener* listener;
	tFrameNotificationSinkPtr pSink;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			m_pGrabber = new DShowLib::Grabber();
			listener = new Listener();
			pSink = FrameNotificationSink::create(*listener, MEDIASUBTYPE_Y800);
			this->SetStyle(static_cast<ControlStyles>(ControlStyles::AllPaintingInWmPaint | ControlStyles::OptimizedDoubleBuffer | ControlStyles::DoubleBuffer | ControlStyles::UserPaint), true);
			this->UpdateStyles();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete m_pGrabber;
				delete components;
				delete listener;
			}
		}

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnSetCam;
	private: System::Windows::Forms::Button^ btnSetProp;
	private: System::Windows::Forms::Button^ btnTest;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::PictureBox^ btnBlue;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::PictureBox^ pageBar;
	private: System::Windows::Forms::TextBox^ textFilter;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::PictureBox^ picCam;
	private: System::Windows::Forms::PictureBox^ picGear;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TrackBar^ trackBarw;
	private: System::Windows::Forms::TrackBar^ trackBary;
	private: System::Windows::Forms::TrackBar^ trackBarh;



	private: System::Windows::Forms::TrackBar^ trackBarx;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textThresh;
	private: System::Windows::Forms::Label^ textScore;
	private: System::Windows::Forms::PictureBox^ picLive;
	private: System::Windows::Forms::PictureBox^ picLiveG;
	private: System::Windows::Forms::Button^ button4;









	private: System::Windows::Forms::Button^ button3;








	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnSetCam = (gcnew System::Windows::Forms::Button());
			this->btnSetProp = (gcnew System::Windows::Forms::Button());
			this->btnTest = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pageBar = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textScore = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textThresh = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textFilter = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBary = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarh = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarx = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarw = (gcnew System::Windows::Forms::TrackBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnBlue = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->picLiveG = (gcnew System::Windows::Forms::PictureBox());
			this->picLive = (gcnew System::Windows::Forms::PictureBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->picCam = (gcnew System::Windows::Forms::PictureBox());
			this->picGear = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pageBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBary))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarh))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarx))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarw))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnBlue))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLiveG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLive))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGear))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// btnSetCam
			// 
			this->btnSetCam->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnSetCam->FlatAppearance->BorderSize = 0;
			this->btnSetCam->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSetCam->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20));
			this->btnSetCam->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSetCam->Location = System::Drawing::Point(3, 129);
			this->btnSetCam->Name = L"btnSetCam";
			this->btnSetCam->Size = System::Drawing::Size(82, 55);
			this->btnSetCam->TabIndex = 3;
			this->btnSetCam->Text = L"Aç";
			this->btnSetCam->UseVisualStyleBackColor = false;
			this->btnSetCam->Click += gcnew System::EventHandler(this, &MyForm::btnSetCam_Click);
			// 
			// btnSetProp
			// 
			this->btnSetProp->BackColor = System::Drawing::Color::Transparent;
			this->btnSetProp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSetProp->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20));
			this->btnSetProp->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnSetProp->Location = System::Drawing::Point(91, 129);
			this->btnSetProp->Name = L"btnSetProp";
			this->btnSetProp->Size = System::Drawing::Size(162, 55);
			this->btnSetProp->TabIndex = 2;
			this->btnSetProp->Text = L"Özellikler";
			this->btnSetProp->UseVisualStyleBackColor = false;
			this->btnSetProp->Click += gcnew System::EventHandler(this, &MyForm::btnSetProp_Click);
			// 
			// btnTest
			// 
			this->btnTest->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnTest->FlatAppearance->BorderSize = 0;
			this->btnTest->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTest->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20));
			this->btnTest->ForeColor = System::Drawing::Color::White;
			this->btnTest->Location = System::Drawing::Point(3, 190);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(82, 124);
			this->btnTest->TabIndex = 2;
			this->btnTest->Text = L"Test";
			this->btnTest->UseVisualStyleBackColor = false;
			this->btnTest->Click += gcnew System::EventHandler(this, &MyForm::btnTest_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->pageBar);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(340, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(940, 707);
			this->panel1->TabIndex = 3;
			// 
			// pageBar
			// 
			this->pageBar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pageBar.Image")));
			this->pageBar->Location = System::Drawing::Point(826, 0);
			this->pageBar->Name = L"pageBar";
			this->pageBar->Size = System::Drawing::Size(114, 26);
			this->pageBar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pageBar->TabIndex = 10;
			this->pageBar->TabStop = false;
			this->pageBar->Visible = false;
			this->pageBar->Click += gcnew System::EventHandler(this, &MyForm::pageBar_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(940, 707);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::pictureBox1_DoubleClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::bar_mouse);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel4->AutoSize = true;
			this->panel4->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->Controls->Add(this->textScore);
			this->panel4->Controls->Add(this->label7);
			this->panel4->Controls->Add(this->textThresh);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Controls->Add(this->textFilter);
			this->panel4->Controls->Add(this->label6);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->button3);
			this->panel4->Controls->Add(this->label3);
			this->panel4->Controls->Add(this->trackBary);
			this->panel4->Controls->Add(this->trackBarh);
			this->panel4->Controls->Add(this->trackBarx);
			this->panel4->Controls->Add(this->trackBarw);
			this->panel4->Controls->Add(this->button2);
			this->panel4->Controls->Add(this->button1);
			this->panel4->Location = System::Drawing::Point(302, 139);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(259, 436);
			this->panel4->TabIndex = 14;
			this->panel4->DoubleClick += gcnew System::EventHandler(this, &MyForm::panel4_DoubleClick);
			// 
			// textScore
			// 
			this->textScore->AutoSize = true;
			this->textScore->BackColor = System::Drawing::Color::Red;
			this->textScore->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20));
			this->textScore->ForeColor = System::Drawing::Color::White;
			this->textScore->Location = System::Drawing::Point(133, 401);
			this->textScore->Name = L"textScore";
			this->textScore->Size = System::Drawing::Size(27, 35);
			this->textScore->TabIndex = 28;
			this->textScore->Text = L"-";
			this->textScore->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12));
			this->label7->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label7->Location = System::Drawing::Point(6, 396);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 21);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Eþik : ";
			// 
			// textThresh
			// 
			this->textThresh->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->textThresh->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textThresh->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12));
			this->textThresh->ForeColor = System::Drawing::SystemColors::Info;
			this->textThresh->Location = System::Drawing::Point(60, 398);
			this->textThresh->MaxLength = 5;
			this->textThresh->Name = L"textThresh";
			this->textThresh->Size = System::Drawing::Size(50, 21);
			this->textThresh->TabIndex = 25;
			this->textThresh->Text = L"99999";
			this->textThresh->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textThresh->TextChanged += gcnew System::EventHandler(this, &MyForm::textThresh_TextChanged);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12));
			this->label1->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label1->Location = System::Drawing::Point(-3, 374);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 21);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Filtre : ";
			// 
			// textFilter
			// 
			this->textFilter->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->textFilter->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textFilter->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12));
			this->textFilter->ForeColor = System::Drawing::SystemColors::Info;
			this->textFilter->Location = System::Drawing::Point(60, 376);
			this->textFilter->MaxLength = 3;
			this->textFilter->Name = L"textFilter";
			this->textFilter->Size = System::Drawing::Size(50, 21);
			this->textFilter->TabIndex = 12;
			this->textFilter->Text = L"999";
			this->textFilter->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textFilter->TextChanged += gcnew System::EventHandler(this, &MyForm::textFilter_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label6->Location = System::Drawing::Point(84, 267);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 36);
			this->label6->TabIndex = 23;
			this->label6->Text = L"- W +";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20, System::Drawing::FontStyle::Bold));
			this->label5->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label5->Location = System::Drawing::Point(170, 144);
			this->label5->Name = L"label5";
			this->label5->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label5->Size = System::Drawing::Size(37, 108);
			this->label5->TabIndex = 22;
			this->label5->Text = L"-\r\nH\r\n+";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label4->Location = System::Drawing::Point(49, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 108);
			this->label4->TabIndex = 21;
			this->label4->Text = L"-\r\nY\r\n+";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DodgerBlue;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(132, 357);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(124, 38);
			this->button3->TabIndex = 24;
			this->button3->Text = L"Kalibrasyon";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label3->Location = System::Drawing::Point(91, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 36);
			this->label3->TabIndex = 20;
			this->label3->Text = L"- X +";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBary
			// 
			this->trackBary->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->trackBary->LargeChange = 100;
			this->trackBary->Location = System::Drawing::Point(0, 100);
			this->trackBary->Maximum = 2544;
			this->trackBary->Name = L"trackBary";
			this->trackBary->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBary->Size = System::Drawing::Size(45, 205);
			this->trackBary->SmallChange = 10;
			this->trackBary->TabIndex = 19;
			this->trackBary->TickFrequency = 200;
			this->trackBary->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBary->Scroll += gcnew System::EventHandler(this, &MyForm::trackBary_Scroll);
			// 
			// trackBarh
			// 
			this->trackBarh->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->trackBarh->LargeChange = 100;
			this->trackBarh->Location = System::Drawing::Point(211, 100);
			this->trackBarh->Maximum = 2544;
			this->trackBarh->Name = L"trackBarh";
			this->trackBarh->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarh->Size = System::Drawing::Size(45, 205);
			this->trackBarh->SmallChange = 10;
			this->trackBarh->TabIndex = 18;
			this->trackBarh->TickFrequency = 200;
			this->trackBarh->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBarh->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarh_Scroll);
			// 
			// trackBarx
			// 
			this->trackBarx->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->trackBarx->LargeChange = 100;
			this->trackBarx->Location = System::Drawing::Point(0, 53);
			this->trackBarx->Maximum = 2544;
			this->trackBarx->Name = L"trackBarx";
			this->trackBarx->Size = System::Drawing::Size(256, 45);
			this->trackBarx->SmallChange = 10;
			this->trackBarx->TabIndex = 17;
			this->trackBarx->TickFrequency = 200;
			this->trackBarx->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBarx->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarx_Scroll);
			// 
			// trackBarw
			// 
			this->trackBarw->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->trackBarw->LargeChange = 100;
			this->trackBarw->Location = System::Drawing::Point(0, 306);
			this->trackBarw->Maximum = 2544;
			this->trackBarw->Name = L"trackBarw";
			this->trackBarw->Size = System::Drawing::Size(256, 45);
			this->trackBarw->SmallChange = 10;
			this->trackBarw->TabIndex = 16;
			this->trackBarw->TickFrequency = 200;
			this->trackBarw->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBarw->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarw_Scroll);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Silver;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(132, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 37);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Kusur 2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(124, 37);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Kusur 1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btnBlue
			// 
			this->btnBlue->BackColor = System::Drawing::Color::Transparent;
			this->btnBlue->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnBlue.Image")));
			this->btnBlue->Location = System::Drawing::Point(8, 20);
			this->btnBlue->Name = L"btnBlue";
			this->btnBlue->Size = System::Drawing::Size(142, 68);
			this->btnBlue->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->btnBlue->TabIndex = 10;
			this->btnBlue->TabStop = false;
			this->btnBlue->Click += gcnew System::EventHandler(this, &MyForm::btnBlue_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(46, 584);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(282, 72);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Çizik Tespit Programý v1.0";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->picLiveG);
			this->panel2->Controls->Add(this->picLive);
			this->panel2->Controls->Add(this->checkBox2);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->btnSetCam);
			this->panel2->Controls->Add(this->btnSetProp);
			this->panel2->Controls->Add(this->btnTest);
			this->panel2->Location = System::Drawing::Point(28, 139);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(256, 420);
			this->panel2->TabIndex = 13;
			this->panel2->DoubleClick += gcnew System::EventHandler(this, &MyForm::panel2_DoubleClick);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20));
			this->button4->ForeColor = System::Drawing::Color::Red;
			this->button4->Location = System::Drawing::Point(3, 320);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(82, 47);
			this->button4->TabIndex = 6;
			this->button4->Text = L"SS";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// picLiveG
			// 
			this->picLiveG->BackColor = System::Drawing::Color::DodgerBlue;
			this->picLiveG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picLiveG.Image")));
			this->picLiveG->Location = System::Drawing::Point(5, 102);
			this->picLiveG->Name = L"picLiveG";
			this->picLiveG->Size = System::Drawing::Size(10, 10);
			this->picLiveG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picLiveG->TabIndex = 5;
			this->picLiveG->TabStop = false;
			// 
			// picLive
			// 
			this->picLive->BackColor = System::Drawing::Color::DodgerBlue;
			this->picLive->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picLive.Image")));
			this->picLive->Location = System::Drawing::Point(5, 132);
			this->picLive->Name = L"picLive";
			this->picLive->Size = System::Drawing::Size(10, 10);
			this->picLive->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picLive->TabIndex = 4;
			this->picLive->TabStop = false;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15));
			this->checkBox2->ForeColor = System::Drawing::Color::DodgerBlue;
			this->checkBox2->Location = System::Drawing::Point(115, 258);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(103, 31);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->Text = L"Kusur 2";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15));
			this->checkBox1->ForeColor = System::Drawing::Color::DodgerBlue;
			this->checkBox1->Location = System::Drawing::Point(115, 221);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(103, 31);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Kusur 1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// picCam
			// 
			this->picCam->BackColor = System::Drawing::Color::Transparent;
			this->picCam->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCam.Image")));
			this->picCam->Location = System::Drawing::Point(48, 43);
			this->picCam->Name = L"picCam";
			this->picCam->Size = System::Drawing::Size(50, 20);
			this->picCam->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picCam->TabIndex = 14;
			this->picCam->TabStop = false;
			this->picCam->Click += gcnew System::EventHandler(this, &MyForm::picCam_Click);
			// 
			// picGear
			// 
			this->picGear->BackColor = System::Drawing::Color::Transparent;
			this->picGear->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picGear.Image")));
			this->picGear->Location = System::Drawing::Point(180, 41);
			this->picGear->Name = L"picGear";
			this->picGear->Size = System::Drawing::Size(25, 25);
			this->picGear->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picGear->TabIndex = 15;
			this->picGear->TabStop = false;
			this->picGear->Click += gcnew System::EventHandler(this, &MyForm::picGear_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->picGear);
			this->Controls->Add(this->picCam);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->btnBlue);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(3, 3);
			this->MinimumSize = System::Drawing::Size(600, 500);
			this->Name = L"MyForm";
			this->Text = L"FAREL - ODTÜ Otomasyon";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::formClick);
			this->DoubleClick += gcnew System::EventHandler(this, &MyForm::MyForm_DoubleClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pageBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBary))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarh))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarx))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarw))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnBlue))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLiveG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLive))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGear))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: int max_frame_w, max_frame_h;
			 int x_a, y_a, w_a, h_a;
			 int x_b, y_b, w_b, h_b;
			 int data_filter_a = 30;
			 int data_filter_b = 30;
			 int data_thresh_a = 400;
			 int data_thresh_b = 400;
			 bool dragging;
			 int mouseX = 0, mouseY = 0;
			 bool TEST_FLAG = false;
			 bool CAM_FLAG = true;
			 bool blue_click = false;
			 Drawing::Size btnBlueLoc_norm;
			 int calib_num = 1;			
			 alg::resultStr defect_a;
			 alg::resultStr defect_b;
			 int liveTimer;
			 int idx = 0;
			 bool MAXI_FLAG = false;
			 Drawing::Size window_size;
			 Drawing::Size window_size_norm;
			 double wc_s, hc_s; // Multiplied with current values to scale
			 double wc, hc; // Multiplied with constant norm values

	private: 
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			max_frame_w = this->panel1->Size.Width;
			max_frame_h = this->panel1->Size.Height;
			this->Controls->Add(this->panel4);
			this->panel4->Location = panel2->Location;
			this->panel4->Visible = false;
			btnBlueLoc_norm = cli::safe_cast<Drawing::Size>(btnBlue->Location);
			this->btnBlue->Controls->Add(this->picCam);
			picCam->Location = picCam->Location - btnBlueLoc_norm;
			trackBarx->Enabled = false;
			trackBary->Enabled = false;
			trackBarw->Enabled = false;
			trackBarh->Enabled = false;
			picLiveG->Location = picLive->Location;
			picLive->Visible = false;
			picLiveG->Visible = true;
			liveTimer = 0;
			MAXI_FLAG = false;
			window_size = Drawing::Size(this->Width, this->Height);
			window_size_norm = Drawing::Size(this->Width, this->Height);
			wc = 1.0;
			hc = 1.0;
			wc_s = 0.0;
			hc_s = 0.0;
			if (!DShowLib::InitLibrary())
			{
				return;
			}		
		}

		void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage, Boolean GrayScale) {
				if (!GrayScale) {
					System::Drawing::Graphics^ graphics = control->CreateGraphics();
					System::IntPtr ptr(colorImage.ptr());
					System::Drawing::Bitmap^ b;
					switch (colorImage.type())
					{
					case CV_8UC3: //non-grayscale images are correctly displayed here
						b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
							System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
						break;
					case CV_8UC1: //grayscale images are incorrectly displayed here
						b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
							System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
						break;
					default:
						//error message				
						break;
					}
					System::Drawing::RectangleF rect(0, 0, (float)control->Width, (float)control->Height);
					graphics->DrawImage(b, rect);
				}
				else {
					System::Drawing::Graphics^ graphics = control->CreateGraphics();
					System::IntPtr ptr(colorImage.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
						System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, (float)control->Width, (float)control->Height);
					graphics->DrawImage(b, rect);
				}
		}
	
		void str2console(std::string& str) {
			System::String^ str2 = gcnew System::String(str.c_str());
			System::Diagnostics::Debug::WriteLine(str2);
		}

		System::Void btnTest_Click(System::Object^ sender, System::EventArgs^ e) {
			str2console("TIS FPS: " + std::to_string(m_pGrabber->getFPS()));
			if (m_pGrabber->isDevOpen()) {
				if (checkBox1->Checked) defect_a = alg::alg_sobel(raw, x_a, y_a, x_a + w_a, y_a + h_a, data_filter_a, data_thresh_a, false, 1);
				if (checkBox2->Checked) defect_b = alg::alg_sobel(raw, x_b, y_b, x_b + w_b, y_b + h_b, data_filter_b, data_thresh_b, false, 2);
				TEST_FLAG = true;
			}
		}

		System::Void btnSetCam_Click(System::Object^ sender, System::EventArgs^ e) {
			m_pGrabber->stopLive();
			m_pGrabber->showDevicePage();
			if (m_pGrabber->isDevOpen()) {
				SIZE dim;
				VideoFormatItem vidForm = m_pGrabber->getVideoFormat();
				dim = vidForm.getSize();
				max_frame_w = (int)dim.cx;
				max_frame_h = (int)dim.cy;
				trackBary->Enabled = true;
				trackBarx->Enabled = true;
				trackBarw->Enabled = true;
				trackBarh->Enabled = true;
				trackBarx->Maximum = max_frame_w;
				trackBary->Maximum = max_frame_h;
				trackBarh->Maximum = max_frame_h;
				trackBarw->Maximum = max_frame_w;
				x_a = max_frame_w / 8;
				w_a = max_frame_w / 4;
				y_a = max_frame_h / 2;
				h_a = max_frame_h / 8;
				x_b = 5 * max_frame_w / 8;
				w_b = max_frame_w / 4;
				y_b = max_frame_h / 2;
				h_b = max_frame_h / 8;

				float panel_ratio = (float)this->panel1->Size.Height / (float)this->panel1->Size.Width;
				float frame_ratio = (float)max_frame_h / (float)max_frame_w;
				if (panel_ratio > frame_ratio) {
					this->pictureBox1->Size = Drawing::Size(this->panel1->Size.Width - 3, (this->panel1->Size.Width - 3) * frame_ratio);
				}
				else {
					this->pictureBox1->Size = Drawing::Size((this->panel1->Size.Height - 3) / frame_ratio, this->panel1->Size.Height - 3);
				}

				m_pGrabber->setOverlayBitmapPathPosition(DShowLib::ePP_NONE);
				m_pGrabber->setSinkType(pSink);

				// Start the camera
				m_pGrabber->startLive(false);

				str2console((std::string)"Cam ready !");
				this->timer1->Start();
			}
			return;
		}

		System::Void btnSetProp_Click(System::Object^ sender, System::EventArgs^ e) {
			m_pGrabber->showVCDPropertyPage();
		}

		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (listener->flag) {
				raw = listener->giveFrame();
				frame = gray1to3ch(raw);
				char idle_color[2] = { 'k','w' };
				if (CAM_FLAG)
				{
					if (checkBox1->Checked) {
						if (TEST_FLAG && defect_a.detection_flag) alg::draw_roi(frame, 'g', x_a, y_a, x_a + w_a, y_a + h_a);
						else if (TEST_FLAG && !defect_a.detection_flag) alg::draw_roi(frame, 'r', x_a, y_a, x_a + w_a, y_a + h_a);
						else alg::draw_roi(frame, idle_color[idx], x_a, y_a, x_a + w_a, y_a + h_a);
					}
					if (checkBox2->Checked) {
						if (TEST_FLAG && defect_b.detection_flag) alg::draw_roi(frame, 'g', x_b, y_b, x_b + w_b, y_b + h_b);
						else if (TEST_FLAG && !defect_b.detection_flag) alg::draw_roi(frame, 'r', x_b, y_b, x_b + w_b, y_b + h_b);
						else alg::draw_roi(frame, idle_color[idx], x_b, y_b, x_b + w_b, y_b + h_b);
					}
				}
				else
				{
					if (calib_num == 1) alg::draw_roi(frame, 'b', x_a, y_a, x_a + w_a, y_a + h_a);
					else if (calib_num == 2) alg::draw_roi(frame, 'b', x_b, y_b, x_b + w_b, y_b + h_b);
					else {}

				}
				
				DrawCVImage(this->pictureBox1, frame, false);
				listener->flag = false;
				if (liveTimer % 10 == 0) {
					picLive->Visible = !picLive->Visible;
					picLiveG->Visible = !picLiveG->Visible;
					idx = ++idx % 2;
				}
				liveTimer += 1;
			}
			
			if (blue_click) {
				Drawing::Point pt;
				if (CAM_FLAG) {
					if (btnBlue->Location.X >= (117 * wc)) {
						CAM_FLAG = false;
						this->calibrationMode();
						blue_click = false;
					}
					else
					{
						pt = Drawing::Point(btnBlue->Location.X + 22 * wc, btnBlue->Location.Y);
						btnBlue->Location = pt;
					}
				}
				else {
					if (btnBlue->Location.X <= (10 * wc)) {
						CAM_FLAG = true;
						this->camMode();
						blue_click = false;
					}
					else
					{
						pt = Drawing::Point(btnBlue->Location.X - 22 * wc, btnBlue->Location.Y);
						btnBlue->Location = pt;
					}
				}
			}
		}	

		Mat gray1to3ch(Mat& m1)
		{
			Mat m3;
			Mat channels[3] = { m1, m1, m1 };
			merge(channels, 3, m3);
			return m3;
		}

		System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
			
			return;
		}

		System::Void rsrsCtrl(Windows::Forms::Control^ obj) {
			int dumx, dumy;

			if (obj != this) {	
				obj->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", obj->Font->Size * hc_s, obj->Font->Style));

				dumx = (int)((double)obj->Location.X * wc_s);
				dumy = (int)((double)obj->Location.Y * hc_s);
				obj->Location = Drawing::Point(dumx, dumy);

				dumx = (int)((double)obj->Size.Width * wc_s);
				dumy = (int)((double)obj->Size.Height * hc_s);
				obj->Size = Drawing::Size(dumx, dumy);

			}

			if(obj->HasChildren){
				for each (Windows::Forms::Control^ child in obj->Controls) {
					rsrsCtrl(child);
				}
			}
		}

		System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = true;
			mouseX = e->X;
			mouseY = e->Y;
		}

		System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = false;
		}

		System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			int x = this->Location.X;
			int y = this->Location.Y;
			if (dragging) {
				this->Location = Drawing::Point(x + e->X - mouseX, y + e->Y - mouseY);
			}
		}

		System::Void bar_mouse(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (dragging) {
				int x = this->Location.X;
				int y = this->Location.Y;
				this->Location = Drawing::Point(x + e->X - mouseX, y + e->Y - mouseY);
			}
			else {
				int x = this->MousePosition.X - this->Location.X;
				int y = this->MousePosition.Y - this->Location.Y;
				if ((this->Size.Width - 100 * wc < x) && (x < this->Size.Width) && (0 < y) && (y < 30 * hc)) {
					pageBar->Visible = true;
				}
				else {
					pageBar->Visible = false;
				}
			}
		}

		System::Void pageBar_Click(System::Object^ sender, System::EventArgs^ e) {
			int x = this->MousePosition.X - this->Location.X;

			if ((this->Size.Width - 25 * wc < x) && (x < this->Size.Width)) {
				Application::Exit();
			}
			else if((this->Size.Width - 60 * wc < x) && (x < this->Size.Width - 40 * wc)) {
				page_resize();
			}
			else if ((this->Size.Width - 114 * wc < x) && (x < this->Size.Width - 80 * wc)) {
				this->WindowState = Windows::Forms::FormWindowState::Minimized;
			}
		}

		System::Void page_resize() {
			if (MAXI_FLAG) {
				this->WindowState = Windows::Forms::FormWindowState::Normal;
				hc_s = (double)window_size_norm.Height / (double)window_size.Height;
				wc_s = (double)window_size_norm.Width / (double)window_size.Width;
				hc = 1.0;
				wc = 1.0;
				rsrsCtrl(this);
				MAXI_FLAG = false;
			}
			else {
				this->WindowState = Windows::Forms::FormWindowState::Maximized;
				hc_s = (double)this->Size.Height / (double)window_size.Height;
				wc_s = (double)this->Size.Width / (double)window_size.Width;
				hc = hc_s;
				wc = wc_s;
				rsrsCtrl(this);
				MAXI_FLAG = true;
			}
			window_size = Drawing::Size(this->Size);
		}

		System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = true;
			mouseX = e->X;
			mouseY = e->Y;
		}

		System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = false;
		}

		System::Void calibrationMode(){
			this->panel2->Visible = false;
			this->panel4->Visible = true;
			if (calib_num == 1) button1->PerformClick();
			else if (calib_num == 2) button2->PerformClick();
		}

		System::Void camMode() {
			cv::destroyAllWindows(); // Close calibration windows
			this->panel2->Visible = true;
			this->panel4->Visible = false;
			picLive->Visible = false;
			picLiveG->Visible = true;

		}

		System::Void swicthMode() {
			Resources::ResourceManager^ resources = gcnew Resources::ResourceManager(L"FARELCLRv02.MyForm_switch", this->GetType()->Assembly);
			Drawing::Size btnBlueLoc;
			btnBlueLoc.Height = btnBlueLoc_norm.Height * hc;
			btnBlueLoc.Width = btnBlueLoc_norm.Width * wc;

			if (CAM_FLAG) {
				picCam->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCam2.Image")));
				this->Controls->Add(this->picCam);
				picCam->Location = picCam->Location + btnBlueLoc;
				picGear->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picGear2.Image")));
				this->btnBlue->Controls->Add(this->picGear);
				picGear->Location = picGear->Location - (btnBlueLoc + Drawing::Size(110 * wc,0));
			}
			else {
				picCam->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCam.Image")));
				this->btnBlue->Controls->Add(this->picCam);
				picCam->Location = picCam->Location - btnBlueLoc;
				picGear->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picGear.Image")));
				this->Controls->Add(this->picGear);
				picGear->Location = picGear->Location + (btnBlueLoc + Drawing::Size(110 * wc, 0));
			}
			blue_click = true;
			timer1->Start();
		}

		System::Void btnBlue_Click(System::Object^ sender, System::EventArgs^ e) {
			this->swicthMode();
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button2->BackColor = System::Drawing::Color::Silver;
			calib_num = 1;
			trackBarx->Value = x_a;
			trackBary->Value = max_frame_h - y_a;
			trackBarw->Value = w_a;
			trackBarh->Value = max_frame_h - h_a;
			textFilter->Text = Convert::ToString(data_filter_a);
			textThresh->Text = Convert::ToString(data_thresh_a);


		}
	
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			this->button1->BackColor = System::Drawing::Color::Silver;
			this->button2->BackColor = System::Drawing::Color::Red;
			calib_num = 2;
			trackBarx->Value = x_b;
			trackBary->Value = max_frame_h - y_b;
			trackBarw->Value = w_b;
			trackBarh->Value = max_frame_h - h_b;
			textFilter->Text = Convert::ToString(data_filter_b);
			textThresh->Text = Convert::ToString(data_thresh_b);
		}

		System::Void formClick(System::Object^ sender, System::EventArgs^ e) {
			int x = this->MousePosition.X - this->Location.X;
			int y = this->MousePosition.Y - this->Location.Y;
			if ((10 * wc < x) && (x < 250 * wc) && (10 * hc < y) && (y < 90 * hc)) {
				this->swicthMode();
			}
		}

		System::Void picCam_Click(System::Object^ sender, System::EventArgs^ e) {
			this->swicthMode();
		}
	
		System::Void picGear_Click(System::Object^ sender, System::EventArgs^ e) {
			this->swicthMode();
		}

		System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			TEST_FLAG = false;
		}

		System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			TEST_FLAG = false;
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			if (m_pGrabber->isDevOpen()) {
				if (calib_num == 1) {
					defect_a = alg::alg_sobel(raw, x_a, y_a, x_a + w_a, y_a + h_a, data_filter_a, data_thresh_a, true, 1);
					textScore->Text = Convert::ToString(defect_a.result_score);
				}
				else if (calib_num == 2) {
					defect_b = alg::alg_sobel(raw, x_b, y_b, x_b + w_b, y_b + h_b, data_filter_b, data_thresh_b, true, 2);
					textScore->Text = Convert::ToString(defect_b.result_score);
				}
			}
		}

		System::Void textFilter_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			if (calib_num == 1) {
				if (!System::String::IsNullOrEmpty(textFilter->Text))
					data_filter_a = Convert::ToInt32(textFilter->Text);
			}
			else if (calib_num == 2) {
				if (!System::String::IsNullOrEmpty(textFilter->Text))
					data_filter_b = Convert::ToInt32(textFilter->Text);
			}
			
		}

		System::Void textThresh_TextChanged(System::Object^ sender, System::EventArgs^ e) {			
			if (calib_num == 1) {
				if (!System::String::IsNullOrEmpty(textThresh->Text))
					data_thresh_a = Convert::ToInt32(textThresh->Text);
			}
			else if (calib_num == 2) {
				if (!System::String::IsNullOrEmpty(textThresh->Text))
					data_thresh_b = Convert::ToInt32(textThresh->Text);
			}
		}

		System::Void trackBarx_Scroll(System::Object^ sender, System::EventArgs^ e) {
			textScore->Text = Convert::ToString(trackBarx->Value);
			if (calib_num == 1) {
				x_a = trackBarx->Value;
				if (x_a + w_a > max_frame_w) {
					w_a = max_frame_w - x_a;
					trackBarw->Value = w_a;
				}
			}
			else if (calib_num == 2) {
				x_b = trackBarx->Value;
				if (x_b + w_b > max_frame_w) {
					w_b = max_frame_w - x_b;
					trackBarw->Value = w_b;
				}
			}
		}

		System::Void trackBary_Scroll(System::Object^ sender, System::EventArgs^ e) {
			textScore->Text = Convert::ToString(max_frame_h - trackBary->Value);
			if (calib_num == 1) {
				y_a = max_frame_h - trackBary->Value;
				if (y_a + h_a > max_frame_h) {
					h_a = max_frame_h - y_a;
					trackBarh->Value = y_a;
				}
			}
			else if (calib_num == 2) {
				y_b = max_frame_h - trackBary->Value;
				if (y_b + h_b > max_frame_h) {
					h_b = max_frame_h - y_b;
					trackBarh->Value = y_b;
				}
			}
		}

		System::Void trackBarw_Scroll(System::Object^ sender, System::EventArgs^ e) {
			if (calib_num == 1) {
				if (x_a + trackBarw->Value > max_frame_w) {
					trackBarw->Value = max_frame_w - x_a;
					w_a = max_frame_w - x_a;
				}
				else w_a = trackBarw->Value;
			}
			else if (calib_num == 2) {
				if (x_b + trackBarw->Value > max_frame_w) {
					trackBarw->Value = max_frame_w - x_b;
					w_b = max_frame_w - x_b;
				}
				else w_b = trackBarw->Value;
			}
			textScore->Text = Convert::ToString(trackBarw->Value);
		}	

		System::Void trackBarh_Scroll(System::Object^ sender, System::EventArgs^ e) {
			if (calib_num == 1) {
				if (y_a > trackBarh->Value) {
					trackBarh->Value = y_a;
					h_a = max_frame_h - y_a;
				}
				else h_a = max_frame_h - trackBarh->Value;
			}
			else if (calib_num == 2) {
				if (y_b > trackBarh->Value) {
					trackBarh->Value = y_b;
					h_b = max_frame_h - y_b;
				}
				else h_b = max_frame_h - trackBarh->Value;
			}
			textScore->Text = Convert::ToString(max_frame_h - trackBarh->Value);
		}

		System::Void MyForm_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
			page_resize();
		}
		
		System::Void pictureBox1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
			page_resize();
		}

		System::Void panel2_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
			page_resize();
		}

		System::Void panel4_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
			page_resize();
		}
		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {			// Screenshot
			char buffer[MAX_PATH] = { 0 };
			GetCurrentDirectoryA(MAX_PATH, buffer);
			std::string cwd = std::string(buffer);
			std:size_t pos = cwd.find(" - ");
			if( pos != cwd.npos) cwd.replace(pos, 3, "-");
			if (m_pGrabber->isDevOpen()) {			
				std::time_t timestamp = std::time(0);
				std::string time_str = std::string(ctime(&timestamp));
				time_str.pop_back(); // Delete Enter char 
				std::replace(time_str.begin(), time_str.end(), ' ', '_');
				std::replace(time_str.begin(), time_str.end(), ':', '_');
				std::string path = cwd + std::string("\\ss\\raw_") + time_str + std::string(".bmp");
				cv::imwrite(path, raw);
				path = cwd + std::string("\\ss\\frame_") + time_str + std::string(".bmp");
				cv::imwrite(path, frame);
			}
		}
};
}

// JUNK
/*

std::string str_test = "test";
str2console(str_test);

namedWindow("Display Window", WINDOW_KEEPRATIO);
imshow("Display Window", img);
int key_test = waitKey(0);

DrawCVImage(this->pictureBox1, img, false);

m_pGrabber->showDevicePage();
if (m_pGrabber->isDevValid())
{
	System::IntPtr ptr = this->panel1->Handle;
	m_pGrabber->setHWND((HWND) ptr.ToPointer());
	m_pGrabber->startLive();
}

Application::DoEvents();

IMAGE FLIP
Image^ tmpImg = shpTri->Image;
tmpImg->RotateFlip(RotateFlipType::RotateNoneFlipX);
shpTri->Image = tmpImg;



*/

/*str2console("CV Grabber: " + cap.getBackendName());
str2console("CV FPS: " + std::to_string(cap.get(cv::CAP_PROP_FPS)));
str2console("CV Frame Count: " + std::to_string(cap.get(cv::CAP_PROP_FRAME_COUNT)));
str2console("CV Frame Width: " + std::to_string(cap.get(cv::CAP_PROP_FRAME_WIDTH)));*/

/* KAMERA SECME
// Grabber::tVidCapDevListPtr ptr = m_pGrabber->getAvailableVideoCaptureDevices();
int deviceID = 0;             // 0 = open default camera
int apiID = cv::CAP_ANY;      // 0 = autodetect default API
// open selected camera using selected API
cap.open(deviceID, apiID);
// check if we succeeded
if (!cap.isOpened()) {
	std::cerr << "ERROR! Unable to open camera\n";
	return;
}*/