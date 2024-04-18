#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#include "omp.h"



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
  private: int nThreads; String^ message;
  private: System::Windows::Forms::Button^ button1;


  public:
    Form1(void)
    {
      InitializeComponent();
      nThreads = 1;
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


  
      /// <summary>
      /// Erforderliche Designervariable.




  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

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
        this->SuspendLayout();
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Location = System::Drawing::Point(31, 86);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(61, 13);
        this->label1->TabIndex = 0;
        this->label1->Text = L"Set threads";
        this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
        // 
        // textBox1
        // 
        this->textBox1->Location = System::Drawing::Point(34, 174);
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(185, 20);
        this->textBox1->TabIndex = 1;
        // 
        // comboBox1
        // 
        this->comboBox1->FormattingEnabled = true;
        this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
        this->comboBox1->Location = System::Drawing::Point(98, 83);
        this->comboBox1->Name = L"comboBox1";
        this->comboBox1->Size = System::Drawing::Size(121, 21);
        this->comboBox1->TabIndex = 2;
        this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
        // 
        // button1
        // 
        this->button1->Location = System::Drawing::Point(34, 128);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(75, 23);
        this->button1->TabIndex = 3;
        this->button1->Text = L"Go";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(284, 261);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->comboBox1);
        this->Controls->Add(this->textBox1);
        this->Controls->Add(this->label1);
        this->Name = L"Form1";
        this->Text = L"Form1";
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.




private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    int sum = 0;

    // Utilizar OpenMP para el bucle paralelo
       #pragma omp parallel num_threads(nThreads) reduction(+:sum)
    {
        sum += 1;
    }

    message = String::Concat("Hello World from nthreads ", Convert::ToString(sum));
    textBox1->Text = message;
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    nThreads = int::Parse(comboBox1->Text);
}

}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

