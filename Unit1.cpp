//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPingPong *PingPong;

int x = -8;
int y = 8;

int player1Points = 0;
int player2Points = 0;

int numberOfStots = 0;


//---------------------------------------------------------------------------
__fastcall TPingPong::TPingPong(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TPingPong::up1Timer(TObject *Sender)
{
        if(paddle1->Top > 10 )paddle1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::down1Timer(TObject *Sender)
{
        if( (paddle1->Top + paddle1->Height) < (background->Height - 10)) paddle1->Top += 10;
}

//---------------------------------------------------------------------------
void __fastcall TPingPong::up2Timer(TObject *Sender)
{
        if(paddle2->Top > 10 )paddle2->Top -= 10;
}

//---------------------------------------------------------------------------
void __fastcall TPingPong::down2Timer(TObject *Sender)
{
        if( (paddle2->Top + paddle2->Height) < (background->Height - 10)) paddle2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 65) up1->Enabled = true;
        if(Key == 90) down1->Enabled = true;

        if(Key == VK_UP) up2->Enabled = true;
         if(Key == VK_DOWN) down2->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TPingPong::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 65) up1->Enabled = false;
        if(Key == 90) down1->Enabled = false;

        if(Key == VK_UP) up2->Enabled = false;
        if(Key == VK_DOWN) down2->Enabled = false;

}

//---------------------------------------------------------------------------
void __fastcall TPingPong::timerBallTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        if(ball->Top-5 <= background->Top) y = -y;


        if ((ball->Top + ball->Height + 5 ) >= background->Height ) y = -y;


        if(ball->Left <= paddle1->Left || ball->Left >= paddle2->Left  )
        {

                if(ball->Left <= paddle1->Left) player2Points++;
                else if (ball->Left >= paddle2->Left) player1Points++;
                
                timerBall->Enabled = false;
                ball->Visible = false;

                stotsCounter->Visible = true;
                stotsCounter->Caption = "Iloœæ odbiæ: " + IntToStr(numberOfStots);

                score->Visible = true;
                score->Caption = IntToStr(player1Points) + ":" + IntToStr(player2Points);

                point->Visible = true;

                nextLevel->Visible = true;
                newGame2->Visible = true;


        }
        else if (ball->Left <= paddle1->Left + paddle1->Width && ball->Top > paddle1->Top - ball->Width/2 && ball->Top < paddle1->Top + paddle1->Height)
        {
                x = -x;
                point->Caption = "< Punkt dla gracza lewego";


                numberOfStots++;
                if(ball->Top + ball->Height/2 ==  paddle1->Top + paddle1->Height/2)  {

                        x -= 8;
                        y = -y;
                }
        }
        else if (ball->Left + ball->Width >= paddle2->Left && ball->Top > paddle2->Top - ball->Width/2 && ball->Top < paddle2->Top + paddle2->Height)
        {
               x = -x;
               point->Caption = "Punkt dla gracza prawego >";

               numberOfStots++;
               if(ball->Top + ball->Height/2 ==  paddle2->Top + paddle2->Height/2 ) {

                        x -= 8;
                        y = -y;
                }
        }

}
//---------------------------------------------------------------------------

void __fastcall TPingPong::ball_accelerationTimer(TObject *Sender)
{
        x -= 2;
}
//---------------------------------------------------------------------------


void __fastcall TPingPong::newGameClick(TObject *Sender)
{
        timerBall->Enabled = true;
        welcomeText->Visible = false;
        newGame->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TPingPong::nextLevelClick(TObject *Sender)
{
        nextLevel->Visible = false;


        x = -8;
        y = 8;

        ball->Left = 500;
        ball->Top = 260;
        ball->Visible = true;
        timerBall->Enabled = true;

        point->Visible = false;


        welcomeText->Visible = false;
        newGame2->Visible = false;

        score->Visible = false;
        stotsCounter->Visible = false;

        numberOfStots = 0;

}
//---------------------------------------------------------------------------


void __fastcall TPingPong::FormCreate(TObject *Sender)
{
      ShowMessage(
      "Witaj w grze PingPong.\n\n"
      "Lewy gracz steruje wciskaj¹c klawisze A oraz Z.\n"
      "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³.\n\n"
      "Dla urozmaicenia zabawy:\n"
      "Kiedy odbijesz pi³kê na œrodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyspieszy.\n"
      "Im d³u¿ej odbijasz, tym pi³ka szybciej przemieszcza siê.\n"
      "Mo¿esz dowolnie zmieniaæ pole gry.\n\n"
      "Mi³ej zabawy!\n"


      );
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::newGame2Click(TObject *Sender)
{
    int result = Application->MessageBox( "Czy na pewno chcesz zacz¹æ od nowa?", "PotwierdŸ", MB_YESNO);

    if(result == IDYES) {

        nextLevel->Visible = false;

        player1Points = 0;
        player2Points = 0;

        x = -8;
        y = 8;

        ball->Left = 500;
        ball->Top = 260;
        ball->Visible = true;
        timerBall->Enabled = true;

        point->Visible = false;


        welcomeText->Visible = false;
        newGame2->Visible = false;

        score->Visible = false;
        stotsCounter->Visible = false;

        numberOfStots = 0;


    }



}
//---------------------------------------------------------------------------

