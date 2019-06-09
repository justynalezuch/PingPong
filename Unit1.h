//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TPingPong : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *paddle1;
        TImage *paddle2;
        TTimer *up1;
        TTimer *down1;
        TTimer *up2;
        TTimer *down2;
        TImage *ball;
        TTimer *timerBall;
        TTimer *ball_acceleration;
        TLabel *welcomeText;
        TButton *newGame;
        TLabel *stotsCounter;
        TLabel *score;
        TLabel *point;
        TButton *nextLevel;
        TButton *newGame2;
        void __fastcall up1Timer(TObject *Sender);
        void __fastcall down1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall up2Timer(TObject *Sender);
        void __fastcall down2Timer(TObject *Sender);
        void __fastcall timerBallTimer(TObject *Sender);
        void __fastcall ball_accelerationTimer(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall nextLevelClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall newGame2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPingPong(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPingPong *PingPong;
//---------------------------------------------------------------------------
#endif
 