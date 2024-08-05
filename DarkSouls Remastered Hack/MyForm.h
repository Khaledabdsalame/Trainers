#pragma once
#include "Header.h"
namespace DarkSoulsRemasteredHack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::CheckBox^ checkBox5;

	private: System::Windows::Forms::CheckBox^ checkBox6;

	private: System::Windows::Forms::CheckBox^ checkBox7;

	private: System::Windows::Forms::CheckBox^ checkBox8;





	private: System::Windows::Forms::CheckBox^ checkBox10;

	private: System::Windows::Forms::CheckBox^ checkBox11;

	private: System::Windows::Forms::CheckBox^ checkBox12;

	private: System::Windows::Forms::CheckBox^ checkBox13;

	private: System::Windows::Forms::CheckBox^ checkBox14;

	private: System::Windows::Forms::PictureBox^ pictureBox1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			resources->ApplyResources(this->checkBox1, L"checkBox1");
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			resources->ApplyResources(this->checkBox2, L"checkBox2");
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			resources->ApplyResources(this->checkBox3, L"checkBox3");
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			// 
			// backgroundWorker3
			// 
			this->backgroundWorker3->WorkerSupportsCancellation = true;
			this->backgroundWorker3->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker3_DoWork);
			// 
			// checkBox4
			// 
			resources->ApplyResources(this->checkBox4, L"checkBox4");
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox4_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox4);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox1);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox14);
			this->groupBox2->Controls->Add(this->checkBox13);
			this->groupBox2->Controls->Add(this->checkBox12);
			this->groupBox2->Controls->Add(this->checkBox11);
			this->groupBox2->Controls->Add(this->checkBox10);
			this->groupBox2->Controls->Add(this->checkBox8);
			this->groupBox2->Controls->Add(this->checkBox7);
			this->groupBox2->Controls->Add(this->checkBox6);
			this->groupBox2->Controls->Add(this->checkBox5);
			resources->ApplyResources(this->groupBox2, L"groupBox2");
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->TabStop = false;
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// checkBox14
			// 
			resources->ApplyResources(this->checkBox14, L"checkBox14");
			this->checkBox14->Name = L"checkBox14";
			this->checkBox14->UseVisualStyleBackColor = true;
			this->checkBox14->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox14_CheckedChanged);
			// 
			// checkBox13
			// 
			resources->ApplyResources(this->checkBox13, L"checkBox13");
			this->checkBox13->Name = L"checkBox13";
			this->checkBox13->UseVisualStyleBackColor = true;
			this->checkBox13->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox13_CheckedChanged);
			// 
			// checkBox12
			// 
			resources->ApplyResources(this->checkBox12, L"checkBox12");
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->UseVisualStyleBackColor = true;
			this->checkBox12->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox12_CheckedChanged);
			// 
			// checkBox11
			// 
			resources->ApplyResources(this->checkBox11, L"checkBox11");
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->UseVisualStyleBackColor = true;
			this->checkBox11->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox11_CheckedChanged);
			// 
			// checkBox10
			// 
			resources->ApplyResources(this->checkBox10, L"checkBox10");
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->UseVisualStyleBackColor = true;
			this->checkBox10->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox10_CheckedChanged);
			// 
			// checkBox8
			// 
			resources->ApplyResources(this->checkBox8, L"checkBox8");
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->UseVisualStyleBackColor = true;
			this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox8_CheckedChanged);
			// 
			// checkBox7
			// 
			resources->ApplyResources(this->checkBox7, L"checkBox7");
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox7_CheckedChanged);
			// 
			// checkBox6
			// 
			resources->ApplyResources(this->checkBox6, L"checkBox6");
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox6_CheckedChanged);
			// 
			// checkBox5
			// 
			resources->ApplyResources(this->checkBox5, L"checkBox5");
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox5_CheckedChanged);
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true && !backgroundWorker1->IsBusy)
		{
			backgroundWorker1->RunWorkerAsync();
		}
		if (checkBox1->Checked == false)
		{
			backgroundWorker1->CancelAsync();
		}

	}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (checkBox2->Checked == true && !backgroundWorker2->IsBusy)
	{
		backgroundWorker2->RunWorkerAsync();
	}
	if (checkBox2->Checked == false)
	{
		backgroundWorker2->CancelAsync();
	}

}
private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (checkBox3->Checked == true && !backgroundWorker3->IsBusy)
	{
		backgroundWorker3->RunWorkerAsync();
	}
	if (checkBox3->Checked == false)
	{
		backgroundWorker3->CancelAsync();
	}


}
	   private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		   if (checkBox4->Checked == true)
		   {
			   injection4();
		   }

	   }
 private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
         while (!backgroundWorker1->CancellationPending)
		   {
			   injection1();
		   }
}
private: System::Void backgroundWorker2_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	while (!backgroundWorker2->CancellationPending)
	{
		injection2();
	}
}
private: System::Void backgroundWorker3_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	while (!backgroundWorker3->CancellationPending)
	{
		injection3();
     }
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("By Khaled Abdsalame\n\nWould you like to visit Our Discord Channel?", "Credit", MessageBoxButtons::YesNo, MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes) {

		System::Diagnostics::Process::Start("https://discord.gg/JEQe2hk9");
	}

}

private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox5->Checked == true)
	{
		injection5();
	}
	

}

private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (checkBox6->Checked == true )
	{
		injection6();
	}
}

private: System::Void checkBox7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox7->Checked == true )
	{
		injection7();
	}

}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void checkBox8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox8->Checked == true)
	{
		injection8();
	}
}


private: System::Void checkBox10_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox10->Checked == true)
	{
		injection10();
	}

}

private: System::Void checkBox11_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox11->Checked == true)
	{
		injection11();
	}
}

private: System::Void checkBox12_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox12->Checked == true)
	{
		injection12();
	}
}

private: System::Void checkBox13_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox13->Checked == true )
	{
		injection13();
	}
}

private: System::Void checkBox14_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox14->Checked == true)
	{
		injection14();
	}

}

};
}
