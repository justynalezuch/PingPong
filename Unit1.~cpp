//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::up1Timer(TObject *Sender)
{
        if(paddle1->Top > 10 )paddle1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::down1Timer(TObject *Sender)
{
        if( (paddle1->Top + paddle1->Height) < (background->Height - 10)) paddle1->Top += 10;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::up2Timer(TObject *Sender)
{
        if(paddle2->Top > 10 )paddle2->Top -= 10;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::down2Timer(TObject *Sender)
{
        if( (paddle2->Top + paddle2->Height) < (background->Height - 10)) paddle2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 65) up1->Enabled = true;
        if(Key == 90) down1->Enabled = true;

        if(Key == VK_UP) up2->Enabled = true;
         if(Key == VK_DOWN) down2->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 65) up1->Enabled = false;
        if(Key == 90) down1->Enabled = false;

          if(Key == VK_UP) up2->Enabled = false;
         if(Key == VK_DOWN) down2->Enabled = false;

}

//---------------------------------------------------------------------------
