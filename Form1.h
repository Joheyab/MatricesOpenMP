#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#include "omp.h"
#include <stdexcept>
#include <sstream> 


namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;


  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  private: 
      int nThreads; 
      String^ message;
      int rows;
      int cols;
      float** matrixA;
      float** matrixB;
      float** matrixR;
      char operation;
  private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
  private: System::Windows::Forms::Label^ label2;
  private: System::Windows::Forms::ComboBox^ comboBox2;
  private: System::Windows::Forms::TextBox^ Amatrix;
  private: System::Windows::Forms::TextBox^ Rmatrix;


  private: System::Windows::Forms::TextBox^ Bmatrix;

  private: System::Windows::Forms::Label^ label3;
  private: System::Windows::Forms::Label^ label4;
  private: System::Windows::Forms::Label^ label5;
  private: System::Windows::Forms::Button^ button2;
  private: System::Windows::Forms::ComboBox^ comboBox3;
  private: System::Windows::Forms::Label^ label6;




  private: System::Windows::Forms::Button^ button1;


  public:
    Form1(void)
    {
      InitializeComponent();
      nThreads = 1;
      rows = 4;
      operation = 'M';
      //
      //TODO: Add the constructor code here
      //

      // uncomment to execute the rk1-utils:
      //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

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
  private: System::Windows::Forms::Label^ label1;
  protected:
  private: System::Windows::Forms::TextBox^ textBox1;
  private: System::Windows::Forms::ComboBox^ comboBox1;
  private: System::ComponentModel::IContainer^ components;
  private: System::Windows::Forms::Button^ button3;

  
      /// <summary>
      /// Erforderliche Designervariable.




  protected:

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
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
        this->Amatrix = (gcnew System::Windows::Forms::TextBox());
        this->Rmatrix = (gcnew System::Windows::Forms::TextBox());
        this->Bmatrix = (gcnew System::Windows::Forms::TextBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->button2 = (gcnew System::Windows::Forms::Button());
        this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->SuspendLayout();
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Location = System::Drawing::Point(31, 80);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(61, 13);
        this->label1->TabIndex = 0;
        this->label1->Text = L"Set threads";
        this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
        // 
        // textBox1
        // 
        this->textBox1->Location = System::Drawing::Point(34, 176);
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(257, 20);
        this->textBox1->TabIndex = 1;
        // 
        // comboBox1
        // 
        this->comboBox1->FormattingEnabled = true;
        this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
        this->comboBox1->Location = System::Drawing::Point(98, 77);
        this->comboBox1->Name = L"comboBox1";
        this->comboBox1->Size = System::Drawing::Size(35, 21);
        this->comboBox1->TabIndex = 2;
        this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
        // 
        // button1
        // 
        this->button1->Location = System::Drawing::Point(184, 214);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(107, 23);
        this->button1->TabIndex = 3;
        this->button1->Text = L"Make operation";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
        // 
        // backgroundWorker1
        // 
        this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Location = System::Drawing::Point(31, 107);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(27, 13);
        this->label2->TabIndex = 4;
        this->label2->Text = L"Size";
        // 
        // comboBox2
        // 
        this->comboBox2->FormattingEnabled = true;
        this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"5", L"6", L"7", L"8" });
        this->comboBox2->Location = System::Drawing::Point(98, 104);
        this->comboBox2->Name = L"comboBox2";
        this->comboBox2->Size = System::Drawing::Size(80, 21);
        this->comboBox2->TabIndex = 5;
        this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
        // 
        // Amatrix
        // 
        this->Amatrix->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->Amatrix->Enabled = false;
        this->Amatrix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->Amatrix->Location = System::Drawing::Point(315, 25);
        this->Amatrix->MaxLength = 1632767;
        this->Amatrix->Multiline = true;
        this->Amatrix->Name = L"Amatrix";
        this->Amatrix->ReadOnly = true;
        this->Amatrix->Size = System::Drawing::Size(151, 138);
        this->Amatrix->TabIndex = 6;
        this->Amatrix->TextChanged += gcnew System::EventHandler(this, &Form1::Amatrix_TextChanged);
        // 
        // Rmatrix
        // 
        this->Rmatrix->BackColor = System::Drawing::SystemColors::Info;
        this->Rmatrix->Enabled = false;
        this->Rmatrix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->Rmatrix->ForeColor = System::Drawing::SystemColors::WindowText;
        this->Rmatrix->Location = System::Drawing::Point(354, 192);
        this->Rmatrix->Multiline = true;
        this->Rmatrix->Name = L"Rmatrix";
        this->Rmatrix->ReadOnly = true;
        this->Rmatrix->Size = System::Drawing::Size(287, 158);
        this->Rmatrix->TabIndex = 7;
        // 
        // Bmatrix
        // 
        this->Bmatrix->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->Bmatrix->Enabled = false;
        this->Bmatrix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->Bmatrix->Location = System::Drawing::Point(503, 25);
        this->Bmatrix->Multiline = true;
        this->Bmatrix->Name = L"Bmatrix";
        this->Bmatrix->ReadOnly = true;
        this->Bmatrix->Size = System::Drawing::Size(162, 138);
        this->Bmatrix->TabIndex = 8;
        // 
        // label3
        // 
        this->label3->AutoSize = true;
        this->label3->Location = System::Drawing::Point(559, 9);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(45, 13);
        this->label3->TabIndex = 9;
        this->label3->Text = L"Matrix B";
        // 
        // label4
        // 
        this->label4->AutoSize = true;
        this->label4->Location = System::Drawing::Point(372, 9);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(45, 13);
        this->label4->TabIndex = 10;
        this->label4->Text = L"Matrix A";
        // 
        // label5
        // 
        this->label5->AutoSize = true;
        this->label5->Location = System::Drawing::Point(458, 176);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(57, 13);
        this->label5->TabIndex = 11;
        this->label5->Text = L"Matrix Res";
        this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
        // 
        // button2
        // 
        this->button2->Location = System::Drawing::Point(103, 214);
        this->button2->Name = L"button2";
        this->button2->Size = System::Drawing::Size(75, 23);
        this->button2->TabIndex = 12;
        this->button2->Text = L"Initialize";
        this->button2->UseVisualStyleBackColor = true;
        this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
        // 
        // comboBox3
        // 
        this->comboBox3->FormattingEnabled = true;
        this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Multiplication",L"Division", L"Addition" });
        this->comboBox3->Location = System::Drawing::Point(136, 131);
        this->comboBox3->Name = L"comboBox3";
        this->comboBox3->Size = System::Drawing::Size(80, 21);
        this->comboBox3->TabIndex = 13;
        this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox3_SelectedIndexChanged);
        // 
        // label6
        // 
        this->label6->AutoSize = true;
        this->label6->Location = System::Drawing::Point(31, 134);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(90, 13);
        this->label6->TabIndex = 14;
        this->label6->Text = L"Type of operation";
        this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::IndianRed;
        this->ClientSize = System::Drawing::Size(677, 360);
        this->Controls->Add(this->label6);
        this->Controls->Add(this->comboBox3);
        this->Controls->Add(this->button2);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->Bmatrix);
        this->Controls->Add(this->Rmatrix);
        this->Controls->Add(this->Amatrix);
        this->Controls->Add(this->comboBox2);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->comboBox1);
        this->Controls->Add(this->textBox1);
        this->Controls->Add(this->label1);
        this->Name = L"Form1";
        this->Text = L"Form1";
        this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.




protected: delegate void SetTextDelegate(String^ text);
  private: System::Void SetText(String^ text) {
    if (this->textBox1->InvokeRequired) {
		SetTextDelegate^ d = gcnew SetTextDelegate(this, &Form1::SetText);
		this->Invoke(d, gcnew array<Object^> { text });
	}
	else {
		this->textBox1->Text = text;
	}
  }
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    backgroundWorker1->RunWorkerAsync();
    if (rows < 50) {
        Rmatrix->ResetText();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                Rmatrix->AppendText(String::Concat(Convert::ToString(matrixR[i][j]), " "));
            }
            Rmatrix->AppendText("\r\n");
        }
    }
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    matrixA = new float* [rows];
    matrixB = new float* [rows];
    matrixR = new float* [rows];

    for (int i = 0; i < rows; i++)
        matrixA[i] = new float[rows];
    for (int i = 0; i < rows; i++)
        matrixB[i] = new float[rows];
    for (int i = 0; i < rows; i++)
        matrixR[i] = new float[rows];

    Random^ rand = gcnew Random(); 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            matrixA[i][j] = rand->Next(1, 100); 
            matrixB[i][j] = rand->Next(1, 100); 
            matrixR[i][j] = 0;
        }
    }

    Amatrix->ResetText();
    Bmatrix->ResetText();
    Rmatrix->ResetText();

    if (rows < 50) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                Amatrix->AppendText(String::Concat(Convert::ToString(matrixA[i][j]), " "));
                Bmatrix->AppendText(String::Concat(Convert::ToString(matrixB[i][j]), " "));
                Rmatrix->AppendText(String::Concat(Convert::ToString(matrixR[i][j]), " "));
            }
            Amatrix->AppendText("\r\n");
            Bmatrix->AppendText("\r\n");
            Rmatrix->AppendText("\r\n");
        }
    }
}




private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    nThreads = int::Parse(comboBox1->Text);
}

private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}

       private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
           double stime = omp_get_wtime();
#pragma omp parallel num_threads(nThreads)
           for (int i = 0; i < rows; i++)
               for (int j = 0; j < rows; j++)
                   for (int k = 0; k < rows; k++) {
                       if (operation == 'A') {
                           matrixR[i][j] = matrixA[i][j] + matrixB[i][j];
                       }
                       else if (operation == 'M') {
                           matrixR[i][j] = matrixA[i][k] * matrixB[k][j];
                       }
                       else if (operation == 'D') {
                           DivideMatrices(matrixA, matrixB, matrixR, rows);
                       }
                   }
           stime = omp_get_wtime() - stime;
           message = String::Concat("Elapsed time: ", Convert::ToString(stime), " seconds");
           SetText(message);
       }
              void DivideMatrices(float** matrixA, float** matrixB, float** matrixR, int rows) {
                  float** inverseB = new float* [rows];
                  for (int i = 0; i < rows; i++) {
                      inverseB[i] = new float[rows];  // Inicializa cada fila de inverseB
                      for (int j = 0; j < rows; j++) {
                          matrixR[i][j] = 0;
                          if (matrixB[i][j] == 0) {
                              throw gcnew System::Exception("Division by zero error.");
                          }
                          inverseB[i][j] = 1.0f / matrixB[i][j];
                      }
                  }

                  for (int i = 0; i < rows; i++) {
                      for (int j = 0; j < rows; j++) {
                          for (int k = 0; k < rows; k++) {
                              matrixR[i][j] += matrixA[i][k] * inverseB[k][j];
                          }
                      }
                  }
              }

   
       private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    	rows = int::Parse(comboBox2->Text);
  }
  private: System::Void Amatrix_TextChanged(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void Bmatrix_TextChanged(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void Rmatrix_TextChanged(System::Object^ sender, System::EventArgs^ e) {
  }
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
  private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
      ComboBox^ comboBox = dynamic_cast<ComboBox^>(sender);
      if (comboBox != nullptr) {
          String^ selectedOperation = comboBox->SelectedItem->ToString();
          if (selectedOperation == "Multiplication") {
              operation = 'M';
          }
          else if (selectedOperation == "Addition") {
              operation = 'A';
          }
          else if (selectedOperation == "Division") {
              operation = 'D';
          }
      }
}
};


}





