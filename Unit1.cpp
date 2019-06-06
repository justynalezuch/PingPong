//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = 8;

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
void __fastcall TForm1::timer_ballTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        //top
        if(ball->Top-5 <= background->Top) y = -y;

        //bottom
        if ((ball->Top + ball->Height +5 ) >= background->Height ){
              y = -y;
        }

        //loss
        if(ball->Left >= paddle2->Left+paddle2->Width+15 || ball->Left <= paddle1->Left-paddle1->Width-15)
        {
                timer_ball->Enabled = true;
                ball->Visible = false;

        }
}
//---------------------------------------------------------------------------

