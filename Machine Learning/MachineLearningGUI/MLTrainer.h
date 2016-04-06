#include "KRRTrainer.h"
#include "SVRTrainer.h"
#pragma once

namespace MachineLearningGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace MachineLearningTraining;

	/// <summary>
	/// Summary for MLTrainer
	/// </summary>
	public ref class MLTrainer : public System::Windows::Forms::Form
	{
	public:
		MLTrainer(void)
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
		~MLTrainer()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^  select_folder_btn;
	private: System::Windows::Forms::Label^  select_file_label;

	private: System::Windows::Forms::ProgressBar^  training_progress_bar;
	private: System::Windows::Forms::Button^  train_model_btn;

	private: System::Windows::Forms::CheckBox^  train_aug_check;

	private: System::Windows::Forms::CheckBox^  train_non_aug_check;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  select_folder_text;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


	protected:

	protected:

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
			this->select_folder_btn = (gcnew System::Windows::Forms::Button());
			this->select_file_label = (gcnew System::Windows::Forms::Label());
			this->training_progress_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->train_model_btn = (gcnew System::Windows::Forms::Button());
			this->train_aug_check = (gcnew System::Windows::Forms::CheckBox());
			this->train_non_aug_check = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->select_folder_text = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// select_folder_btn
			// 
			this->select_folder_btn->BackColor = System::Drawing::Color::SteelBlue;
			this->select_folder_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->select_folder_btn->FlatAppearance->BorderSize = 0;
			this->select_folder_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->select_folder_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->select_folder_btn->ForeColor = System::Drawing::Color::Transparent;
			this->select_folder_btn->Location = System::Drawing::Point(239, 70);
			this->select_folder_btn->Margin = System::Windows::Forms::Padding(4);
			this->select_folder_btn->Name = L"select_folder_btn";
			this->select_folder_btn->Size = System::Drawing::Size(168, 30);
			this->select_folder_btn->TabIndex = 1;
			this->select_folder_btn->Text = L"Select Folder";
			this->select_folder_btn->UseVisualStyleBackColor = false;
			this->select_folder_btn->Click += gcnew System::EventHandler(this, &MLTrainer::select_file_btn_Click);
			// 
			// select_file_label
			// 
			this->select_file_label->AutoSize = true;
			this->select_file_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->select_file_label->ForeColor = System::Drawing::Color::SteelBlue;
			this->select_file_label->Location = System::Drawing::Point(221, 22);
			this->select_file_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->select_file_label->Name = L"select_file_label";
			this->select_file_label->Size = System::Drawing::Size(335, 24);
			this->select_file_label->TabIndex = 2;
			this->select_file_label->Text = L"Select XML File for Model Training";
			// 
			// training_progress_bar
			// 
			this->training_progress_bar->Location = System::Drawing::Point(459, 168);
			this->training_progress_bar->Margin = System::Windows::Forms::Padding(4);
			this->training_progress_bar->Name = L"training_progress_bar";
			this->training_progress_bar->Size = System::Drawing::Size(292, 28);
			this->training_progress_bar->TabIndex = 3;
			// 
			// train_model_btn
			// 
			this->train_model_btn->BackColor = System::Drawing::Color::ForestGreen;
			this->train_model_btn->Enabled = false;
			this->train_model_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->train_model_btn->FlatAppearance->BorderSize = 0;
			this->train_model_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->train_model_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->train_model_btn->ForeColor = System::Drawing::Color::Transparent;
			this->train_model_btn->Location = System::Drawing::Point(239, 152);
			this->train_model_btn->Margin = System::Windows::Forms::Padding(4);
			this->train_model_btn->Name = L"train_model_btn";
			this->train_model_btn->Size = System::Drawing::Size(168, 30);
			this->train_model_btn->TabIndex = 4;
			this->train_model_btn->Text = L"Train Model";
			this->train_model_btn->UseVisualStyleBackColor = false;
			this->train_model_btn->Click += gcnew System::EventHandler(this, &MLTrainer::train_model_btn_Click);
			// 
			// train_aug_check
			// 
			this->train_aug_check->AutoSize = true;
			this->train_aug_check->Checked = true;
			this->train_aug_check->CheckState = System::Windows::Forms::CheckState::Checked;
			this->train_aug_check->Enabled = false;
			this->train_aug_check->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->train_aug_check->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->train_aug_check->Location = System::Drawing::Point(17, 135);
			this->train_aug_check->Margin = System::Windows::Forms::Padding(4);
			this->train_aug_check->Name = L"train_aug_check";
			this->train_aug_check->Size = System::Drawing::Size(156, 21);
			this->train_aug_check->TabIndex = 5;
			this->train_aug_check->Text = L"Augmented Model";
			this->train_aug_check->UseVisualStyleBackColor = true;
			this->train_aug_check->CheckedChanged += gcnew System::EventHandler(this, &MLTrainer::train_aug_check_CheckedChanged);
			// 
			// train_non_aug_check
			// 
			this->train_non_aug_check->AutoSize = true;
			this->train_non_aug_check->Checked = true;
			this->train_non_aug_check->CheckState = System::Windows::Forms::CheckState::Checked;
			this->train_non_aug_check->Enabled = false;
			this->train_non_aug_check->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->train_non_aug_check->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->train_non_aug_check->Location = System::Drawing::Point(17, 161);
			this->train_non_aug_check->Margin = System::Windows::Forms::Padding(4);
			this->train_non_aug_check->Name = L"train_non_aug_check";
			this->train_non_aug_check->Size = System::Drawing::Size(191, 21);
			this->train_non_aug_check->TabIndex = 6;
			this->train_non_aug_check->Text = L"Non-Augmented Model";
			this->train_non_aug_check->UseVisualStyleBackColor = true;
			this->train_non_aug_check->CheckedChanged += gcnew System::EventHandler(this, &MLTrainer::train_non_aug_check_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->train_model_btn);
			this->groupBox1->Controls->Add(this->train_non_aug_check);
			this->groupBox1->Controls->Add(this->train_aug_check);
			this->groupBox1->Controls->Add(this->select_folder_btn);
			this->groupBox1->Controls->Add(this->select_folder_text);
			this->groupBox1->Location = System::Drawing::Point(-4, 69);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(445, 238);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			// 
			// select_folder_text
			// 
			this->select_folder_text->BackColor = System::Drawing::Color::White;
			this->select_folder_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->select_folder_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->select_folder_text->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->select_folder_text->Location = System::Drawing::Point(17, 34);
			this->select_folder_text->Margin = System::Windows::Forms::Padding(4);
			this->select_folder_text->Name = L"select_folder_text";
			this->select_folder_text->ReadOnly = true;
			this->select_folder_text->Size = System::Drawing::Size(390, 17);
			this->select_folder_text->TabIndex = 0;
			this->select_folder_text->TextChanged += gcnew System::EventHandler(this, &MLTrainer::select_file_text_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(487, 140);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 24);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Model Training Progress";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MLTrainer::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MLTrainer::backgroundWorker1_ProgressChanged);
			// 
			// MLTrainer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(764, 298);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->select_file_label);
			this->Controls->Add(this->training_progress_bar);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MLTrainer";
			this->Text = L"Machine Learning Model Trainer";
			this->Load += gcnew System::EventHandler(this, &MLTrainer::MLTrainer_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MLTrainer_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void select_file_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			select_folder_text->Text = folderBrowserDialog1->SelectedPath;
		}
	}
private: System::Void train_aug_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (!train_aug_check->Checked && !train_non_aug_check->Checked)
		train_model_btn->Enabled = false;
	else
		train_model_btn->Enabled = true;
}
private: System::Void train_non_aug_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (!train_aug_check->Checked && !train_non_aug_check->Checked)
		train_model_btn->Enabled = false;
	else
		train_model_btn->Enabled = true;
}
private: System::Void select_file_text_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (select_folder_text->Text != ""){
		train_aug_check->Enabled = true;
		train_non_aug_check->Enabled = true;
		train_model_btn->Enabled = true;
	}
	else {
		train_aug_check->Enabled = false;
		train_non_aug_check->Enabled = false;
		train_model_btn->Enabled = false;
	}
}
private: System::Void train_model_btn_Click(System::Object^  sender, System::EventArgs^  e) {
	train_model_btn->Enabled = false;
	backgroundWorker1->RunWorkerAsync(select_folder_text->Text);
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(e->Argument->ToString());
	char* folder_path;
	try{
		folder_path = static_cast<char*>(ptrToNativeString.ToPointer());
		KRRTrainer krr;
		SVRTrainer svr;
		krr.setDataFolder(folder_path);
		backgroundWorker1->ReportProgress(1);
		krr.findDataFiles();
		backgroundWorker1->ReportProgress(5);
		krr.loadData();
		backgroundWorker1->ReportProgress(10);
		svr.setDataFolder(folder_path);
		backgroundWorker1->ReportProgress(11);
		svr.findDataFiles();
		backgroundWorker1->ReportProgress(15);
		svr.loadData();
		backgroundWorker1->ReportProgress(20);
		if (train_aug_check->Checked){
			krr.trainAugmentedModel();
			backgroundWorker1->ReportProgress(40);
			svr.trainAugmentedModel();
			backgroundWorker1->ReportProgress(60);
		}
		if (train_non_aug_check->Checked){
			krr.trainNonAugmentedModel();
			backgroundWorker1->ReportProgress(80);
			svr.trainNonAugmentedModel();
			
		}
	}
	catch (...){
		Marshal::FreeHGlobal(ptrToNativeString);
		throw;
	}
	backgroundWorker1->ReportProgress(100);
}
private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
	training_progress_bar->Value = e->ProgressPercentage;
	if (training_progress_bar->Value == 100){
		MessageBox::Show("Training has completed!", "Notification", MessageBoxButtons::OK, MessageBoxIcon::Information);
		train_model_btn->Enabled = true;
	}
}
};
}
