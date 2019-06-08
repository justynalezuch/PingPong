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
void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        //top
        if(ball->Top-5 <= background->Top) y = -y;

        //bottom
        if ((ball->Top + ball->Height +5 ) >= background->Height ){
              y = -y;
        }

        if(ball->Left >= paddle2->Left+paddle2->Width || ball->Left <= paddle1->Left-paddle1->Width)
        {
                timerBall->Enabled = false;
                ball->Visible = false;
        }
        else if (ball->Left <= paddle1->Left + paddle1->Width && ball->Top > paddle1->Top - ball->Width/2 && ball->Top < paddle1->Top + paddle1->Height)
        {
                x = -x;
                if(ball->Top + ball->Height/2 ==  paddle1->Top + paddle1->Height/2)  {

                        x -= 8;
                        y = -y;
                }
        }
        else if (ball->Left + ball->Width >= paddle2->Left && ball->Top > paddle2->Top - ball->Width/2 && ball->Top < paddle2->Top + paddle2->Height)
        {
               x = -x;
               if(ball->Top + ball->Height/2 ==  paddle2->Top + paddle2->Height/2 ) {

                        x -= 8;
                        y = -y;
                }
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ball_accelerationTimer(TObject *Sender)
{
        x -= 2;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::newGameClick(TObject *Sender)
{
        timerBall->Enabled = true;
        welcomeText->Visible = false;
        newGame->Visible = false;
}
//---------------------------------------------------------------------------

