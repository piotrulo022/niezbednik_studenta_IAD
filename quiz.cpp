#include "quiz.h"
#include <sstream>
#include <fstream>
#include "niezbednikMain.h"
#include <algorithm>
#include <wx/msgdlg.h>

#undef _
#define _(s) wxString::FromUTF8(s)

//(*InternalHeaders(quiz)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

vector <Przedmiot1> przedmioty1;
//(*IdInit(quiz)
const long quiz::ID_STATICTEXT1 = wxNewId();
const long quiz::ID_CHOICE1 = wxNewId();
const long quiz::ID_STATICTEXT2 = wxNewId();
const long quiz::ID_CHOICE2 = wxNewId();
const long quiz::ID_STATICTEXT3 = wxNewId();
const long quiz::ID_CHOICE3 = wxNewId();
const long quiz::ID_BITMAPBUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(quiz,wxDialog)
	//(*EventTable(quiz)
	//*)
END_EVENT_TABLE()



void sczytaj1(string plik){
    fstream f1;
    f1.open(plik);
    while(f1.good()){
        stringstream ss1;
        string s1;
        getline(f1, s1, '\n');
    if(s1.length() != 0){
        ss1 << s1;
        string pom1, waga1;
        getline(ss1, pom1, '\t');
        getline(ss1, waga1);
        Przedmiot1 p1;
        p1.nazwa = pom1;
        p1.waga = stoi(waga1);
        przedmioty1.push_back(p1);
    }

    }
    f1.close();
}


quiz::quiz(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(quiz)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(4, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Wybierz semestr"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->Append(_("I"));
	Choice1->Append(_("II"));
	Choice1->Append(_("III"));
	Choice1->Append(_("IV"));
	Choice1->Append(_("V"));
	Choice1->Append(_("VI"));
	FlexGridSizer2->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Wybierz przedmiot"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	FlexGridSizer2->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Wybierz zaliczenie"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice3 = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	FlexGridSizer2->Add(Choice3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("quiz.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	FlexGridSizer2->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&quiz::OnChoice1Select);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&quiz::OnChoice2Select);
	Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&quiz::OnChoice3Select1);
	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quiz::OnBitmapButton1Click);
	//*)

	BM=BitmapButton1;

	restart();
	analiza1kol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium1\\zad1.png")));
	analiza1kol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium1\\zad2.png")));
	analiza1kol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium1\\zad3.png")));
	analiza1kol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium1\\zad4.png")));
	analiza1kol1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium1\\zad5.png")));

	analiza1kol2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium2\\zad1.png")));
	analiza1kol2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium2\\zad2.png")));
	analiza1kol2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium2\\zad3.png")));
	analiza1kol2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium2\\zad4.png")));
	analiza1kol2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Kolokwium2\\zad5.png")));

	analiza1egz1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin1\\zad1.png")));
	analiza1egz1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin1\\zad2.png")));
	analiza1egz1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin1\\zad3.png")));
	analiza1egz1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin1\\zad4.png")));
	analiza1egz1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin1\\zad5.png")));
	analiza1egz1[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin1\\zad6.png")));

	analiza1egz2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin2\\zad1.png")));
	analiza1egz2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin2\\zad2.png")));
	analiza1egz2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin2\\zad3.png")));
	analiza1egz2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin2\\zad4.png")));
	analiza1egz2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin2\\zad5.png")));
	analiza1egz2[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin2\\zad6.png")));

	analiza1egz3[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin3\\zad1.png")));
	analiza1egz3[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin3\\zad2.png")));
	analiza1egz3[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin3\\zad3.png")));
	analiza1egz3[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin3\\zad4.png")));
	analiza1egz3[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Analiza_Matematyczna\\Egzamin3\\zad5.png")));

	algebralinkol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium1\\zad1.png")));
	algebralinkol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium1\\zad2.png")));
	algebralinkol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium1\\zad3.png")));
	algebralinkol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium1\\zad4.png")));
	algebralinkol1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium1\\zad5.png")));

	algebralinkol2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium2\\zad1.png")));
	algebralinkol2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium2\\zad2.png")));
	algebralinkol2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium2\\zad3.png")));
	algebralinkol2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium2\\zad4.png")));
	algebralinkol2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Kolokwium2\\zad5.png")));

	algebralinegz1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin1\\zad1.png")));
	algebralinegz1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin1\\zad2.png")));
	algebralinegz1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin1\\zad3.png")));
	algebralinegz1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin1\\zad4.png")));
	algebralinegz1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin1\\zad5.png")));

	algebralinegz2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin2\\zad1.png")));
	algebralinegz2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin2\\zad2.png")));
	algebralinegz2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin2\\zad3.png")));
	algebralinegz2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin2\\zad4.png")));
	algebralinegz2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin2\\zad5.png")));

	algebralinegz3[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin3\\zad1.png")));
	algebralinegz3[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin3\\zad2.png")));
	algebralinegz3[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin3\\zad3.png")));
	algebralinegz3[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin3\\zad4.png")));
	algebralinegz3[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin3\\zad5.png")));
	algebralinegz3[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Algebra_Liniowa\\Egzamin3\\zad6.png")));

	logikakol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium1\\zad1.png")));
	logikakol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium1\\zad2.png")));
	logikakol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium1\\zad3.png")));
	logikakol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium1\\zad4.png")));
	logikakol1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium1\\zad5.png")));
	logikakol1[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium1\\zad6.png")));
	logikakol1[6]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium1\\zad7.png")));

	logikakol2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium2\\zad1.png")));
	logikakol2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium2\\zad2.png")));
	logikakol2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium2\\zad3.png")));
	logikakol2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium2\\zad4.png")));
	logikakol2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium2\\zad5.png")));
	logikakol2[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Kolokwium2\\zad6.png")));

    logikaegz1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin1\\zad1.png")));
    logikaegz1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin1\\zad2.png")));
    logikaegz1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin1\\zad3.png")));
    logikaegz1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin1\\zad4.png")));
    logikaegz1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin1\\zad5.png")));
    logikaegz1[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin1\\zad6.png")));
    logikaegz1[6]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin1\\zad7.png")));
    logikaegz1[7]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin1\\zad8.png")));

    logikaegz2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin2\\zad1.png")));
    logikaegz2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin2\\zad2.png")));
    logikaegz2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin2\\zad3.png")));
    logikaegz2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin2\\zad4.png")));
    logikaegz2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin2\\zad5.png")));
    logikaegz2[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin2\\zad6.png")));
    logikaegz2[6]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin2\\zad7.png")));
    logikaegz2[7]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin2\\zad8.png")));

    logikaegz3[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin3\\zad1.png")));
    logikaegz3[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin3\\zad2.png")));
    logikaegz3[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin3\\zad3.png")));
    logikaegz3[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin3\\zad4.png")));
    logikaegz3[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin3\\zad5.png")));
    logikaegz3[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin3\\zad6.png")));
    logikaegz3[6]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin3\\zad7.png")));
    logikaegz3[7]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Logika\\Egzamin3\\zad8.png")));

    funkcjeelzal[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Funkcje_Elementarne\\Zaliczenie\\zad1.png")));
    funkcjeelzal[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Funkcje_Elementarne\\Zaliczenie\\zad2.png")));
    funkcjeelzal[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Funkcje_Elementarne\\Zaliczenie\\zad3.png")));
    funkcjeelzal[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Funkcje_Elementarne\\Zaliczenie\\zad4.png")));
    funkcjeelzal[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Funkcje_Elementarne\\Zaliczenie\\zad5.png")));
    funkcjeelzal[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Funkcje_Elementarne\\Zaliczenie\\zad6.png")));

    programowaniekol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Programowanie\\Kolokwium1\\zad1.png")));
    programowaniekol2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Programowanie\\Kolokwium2\\zad1.png")));

    narzedziainfzal[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad1.png")));
    narzedziainfzal[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad2.png")));
    narzedziainfzal[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad3.png")));
    narzedziainfzal[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad4.png")));
    narzedziainfzal[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad5.png")));
    narzedziainfzal[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad6.png")));
    narzedziainfzal[6]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad7.png")));
    narzedziainfzal[7]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad8.png")));
    narzedziainfzal[8]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad9.png")));
    narzedziainfzal[9]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad10.png")));
    narzedziainfzal[10]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Narzedzia_Informatyczne\\Zaliczenie\\zad11.png")));

    systemyopkol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Systemy_Operacyjne\\Kolokwium1\\zad1.png")));
    systemyopkol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Systemy_Operacyjne\\Kolokwium1\\zad2.png")));
    systemyopkol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Systemy_Operacyjne\\Kolokwium1\\zad3.png")));
    systemyopkol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Systemy_Operacyjne\\Kolokwium1\\zad4.png")));
    systemyopkol1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Systemy_Operacyjne\\Kolokwium1\\zad5.png")));
    systemyopkol1[5]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\Systemy_Operacyjne\\Kolokwium1\\zad6.png")));

    bhpzal1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\BHP\\Kolokwium1\\zad1.png")));
    bhpzal1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\BHP\\Kolokwium1\\zad2.png")));
    bhpzal1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\BHP\\Kolokwium1\\zad3.png")));
    bhpzal1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\BHP\\Kolokwium1\\zad4.png")));
    bhpzal1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr1\\BHP\\Kolokwium1\\zad5.png")));

    analiza2kol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium1\\zad1.png")));
    analiza2kol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium1\\zad2.png")));
    analiza2kol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium1\\zad3.png")));
    analiza2kol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium1\\zad4.png")));
    analiza2kol1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium1\\zad5.png")));
    analiza2kol1[5]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium1\\zad6.png")));
    analiza2kol1[6]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium1\\zad7.png")));

    analiza2kol2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad1.png")));
    analiza2kol2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad2.png")));
    analiza2kol2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad3.png")));
    analiza2kol2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad4.png")));
    analiza2kol2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad5.png")));
    analiza2kol2[5]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad6.png")));
    analiza2kol2[6]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad7.png")));
    analiza2kol2[7]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad8.png")));
    analiza2kol2[8]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad9.png")));
    analiza2kol2[9]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Kolokwium2\\zad10.png")));

    analiza2egz1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad1.png")));
    analiza2egz1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad2.png")));
    analiza2egz1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad3.png")));
    analiza2egz1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad4.png")));
    analiza2egz1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad5.png")));
    analiza2egz1[5]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad6.png")));
    analiza2egz1[6]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad7.png")));
    analiza2egz1[7]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad8.png")));
    analiza2egz1[8]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad9.png")));
    analiza2egz1[9]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad10.png")));
    analiza2egz1[10]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad11.png")));
    analiza2egz1[11]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin1\\zad12.png")));

    analiza2egz2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad1.png")));
    analiza2egz2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad2.png")));
    analiza2egz2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad3.png")));
    analiza2egz2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad4.png")));
    analiza2egz2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad5.png")));
    analiza2egz2[5]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad6.png")));
    analiza2egz2[6]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad7.png")));
    analiza2egz2[7]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad8.png")));
    analiza2egz2[8]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad9.png")));
    analiza2egz2[9]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad10.png")));
    analiza2egz2[10]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad11.png")));
    analiza2egz2[11]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin2\\zad12.png")));

    analiza2egz3[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad1.png")));
    analiza2egz3[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad2.png")));
    analiza2egz3[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad3.png")));
    analiza2egz3[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad4.png")));
    analiza2egz3[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad5.png")));
    analiza2egz3[5]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad6.png")));
    analiza2egz3[6]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad7.png")));
    analiza2egz3[7]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad8.png")));
    analiza2egz3[8]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad9.png")));
    analiza2egz3[9]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad10.png")));
    analiza2egz3[10]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad11.png")));
    analiza2egz3[11]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Analiza_Matematyczna\\Egzamin3\\zad12.png")));

    algebraabskol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium1\\zad1.png")));
    algebraabskol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium1\\zad2.png")));
    algebraabskol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium1\\zad3.png")));
    algebraabskol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium1\\zad4.png")));
    algebraabskol1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium1\\zad5.png")));

    algebraabskol2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium2\\zad1.png")));
    algebraabskol2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium2\\zad2.png")));
    algebraabskol2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium2\\zad3.png")));
    algebraabskol2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium2\\zad4.png")));
    algebraabskol2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Kolokwium2\\zad5.png")));

    algebraabsegz1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin1\\zad1.png")));
    algebraabsegz1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin1\\zad2.png")));
    algebraabsegz1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin1\\zad3.png")));
    algebraabsegz1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin1\\zad4.png")));
    algebraabsegz1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin1\\zad5.png")));

    algebraabsegz2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin2\\zad1.png")));
    algebraabsegz2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin2\\zad2.png")));
    algebraabsegz2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin2\\zad3.png")));
    algebraabsegz2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin2\\zad4.png")));
    algebraabsegz2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Algebra_Wspolczesna\\Egzamin2\\zad5.png")));

    matdyskol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium1\\zad1.png")));
    matdyskol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium1\\zad2.png")));
    matdyskol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium1\\zad3.png")));
    matdyskol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium1\\zad4.png")));
    matdyskol1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium1\\zad5.png")));

    matdyskol2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium2\\zad1.png")));
    matdyskol2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium2\\zad2.png")));
    matdyskol2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium2\\zad3.png")));
    matdyskol2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium2\\zad4.png")));
    matdyskol2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Kolokwium2\\zad5.png")));

    matdysegz1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin1\\zad1.png")));
    matdysegz1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin1\\zad2.png")));
    matdysegz1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin1\\zad3.png")));
    matdysegz1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin1\\zad4.png")));
    matdysegz1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin1\\zad5.png")));
    matdysegz1[5]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin1\\zad6.png")));

    matdysegz2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin2\\zad1.png")));
    matdysegz2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin2\\zad2.png")));
    matdysegz2[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin2\\zad3.png")));
    matdysegz2[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin2\\zad4.png")));
    matdysegz2[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin2\\zad5.png")));
    matdysegz2[5]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Matematyka_Dyskretna\\Egzamin2\\zad6.png")));

    grafikakompkol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Grafika_Komputerowa\\Kolokwium1\\zad1.png")));
    grafikakompkol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Grafika_Komputerowa\\Kolokwium1\\zad2.png")));
    grafikakompkol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Grafika_Komputerowa\\Kolokwium1\\zad3.png")));

    programowanieobkol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_Obiektowe\\Kolokwium1\\zad1.png")));
    programowanieobkol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_Obiektowe\\Kolokwium1\\zad2.png")));

    programowaniewrkol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad1.png")));
    programowaniewrkol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad2.png")));
    programowaniewrkol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad3.png")));
    programowaniewrkol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad4.png")));
    programowaniewrkol1[4]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad5.png")));
    programowaniewrkol1[5]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad6.png")));
    programowaniewrkol1[6]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad7.png")));
    programowaniewrkol1[7]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad8.png")));
    programowaniewrkol1[8]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad9.png")));
    programowaniewrkol1[9]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad10.png")));
    programowaniewrkol1[10]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad11.png")));
    programowaniewrkol1[11]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad12.png")));
    programowaniewrkol1[12]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Programowanie_w_R\\Kolokwium1\\zad13.png")));

    psychologiakol1[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Psychologia\\Kolokwium1\\zad1.png")));
    psychologiakol1[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Psychologia\\Kolokwium1\\zad2.png")));
    psychologiakol1[2]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Psychologia\\Kolokwium1\\zad3.png")));
    psychologiakol1[3]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Psychologia\\Kolokwium1\\zad4.png")));

    psychologiakol2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Psychologia\\Kolokwium2\\zad1.png")));
    psychologiakol2[1]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Psychologia\\Kolokwium2\\zad2.png")));

    narzedziainfzal2[0]=wxBitmap(wxImage(_T("Zadania\\Semestr2\\Narzedzia_Informatyczne\\Kolokwium1\\zad1.png")));

	//analiza1kol1[0]=wxBitmap(wxImage(_T()))
	//\Zadania\Semestr1\Analiza_Matematyczna\Kolokwium1
}

quiz::~quiz()
{
	//(*Destroy(quiz)
	//*)
}

int i;

void quiz::restart(){
    BitmapButton1->SetBitmap(wxBitmap(wxImage(_T("quiz.png"))));
    i=0;
}

void quiz::OnChoice1Select(wxCommandEvent& event)
{
    //robienie list przedmiotów dla danych semestrów
    sczytaj1("przedmioty.txt");
    //sem1
    if(Choice1->GetSelection() == 0){
        Choice2->Clear();
        Choice3->Clear();
          for(int i = 0; i < 10; i++){
            string n = przedmioty1[i].nazwa;
            Choice2->Append(_(n.c_str()));
        }}
    //sem2
    if(Choice1->GetSelection() == 1){
        Choice2->Clear();
        Choice3->Clear();
        for(int i = 0; i < 9; i++){
            string n = przedmioty1[i + 10].nazwa;
            Choice2->Append(_(n.c_str()));
        }}
    //sem3
    if(Choice1->GetSelection() == 2){
        Choice2->Clear();
        Choice3->Clear();
            for(int i = 0; i < 9; i++){
            string n = przedmioty1[i + 19].nazwa;
            Choice2->Append(_(n.c_str()));}}
    //sem4
    if(Choice1->GetSelection() == 3){
        Choice2->Clear();
        Choice3->Clear();
            for(int i = 0; i < 9; i++){
            string n = przedmioty1[i + 28].nazwa;
            Choice2->Append(_(n.c_str()));}}
    //sem5
    if(Choice1->GetSelection() == 4){
        Choice2->Clear();
        Choice3->Clear();
            for(int i = 0; i < 9; i++){
            string n = przedmioty1[i + 37].nazwa;
            Choice2->Append(_(n.c_str()));}}
    //sem6
     if(Choice1->GetSelection() == 5){
        Choice2->Clear();
        Choice3->Clear();
            for(int i = 0; i < 9; i++){
            string n = przedmioty1[i + 46].nazwa;
            Choice2->Append(_(n.c_str()));}}


}

void quiz::OnChoice2Select(wxCommandEvent& event)
{
    //2 kolokwia+egzamin
    if((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 0)
        || (Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 1)
       || (Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 2)
       || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 0)
        || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 1)
       || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 2)){
            Choice3->Clear();
            Choice3->Append(_("Kolokwium 1"));
            Choice3->Append(_("Kolokwium 2"));
            Choice3->Append(_("Egzamin 1. termin"));
            Choice3->Append(_("Egzamin 2. termin"));
            Choice3->Append(_("Egzamin 3. termin"));
            //restart();
            }
    //2 kolokwia, brak egzaminu
    if((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 3)
        || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 8))
       {
            Choice3->Clear();
            Choice3->Append(_("Kolokwium 1"));
            Choice3->Append(_("Kolokwium 2"));
            //restart();
       }
    //tylko 1 kolokwium
    if((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 4)
       || (Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 5)
       || (Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 6)
       || (Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 7)
       || (Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 8)
       || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 3)
       || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 5)
       || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 6)
       || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 7)
       || (Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 9)
       )
    {
        Choice3->Clear();
        Choice3->Append(_("Kolokwium"));
        //restart();
    }
    //tylko projekt
    if((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 4))
       {
            Choice3->Clear();
            Choice3->Append(_("Projekty"));
            //restart();
       }

restart();

}

void quiz::OnChoice3Select(wxCommandEvent& event)
{
    restart();
}



void quiz::OnBitmapButton1Click(wxCommandEvent& event)
{
    //analiza1
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 0))){
        if(i<5){
        BitmapButton1->SetBitmap(analiza1kol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 1))){
        if(i<5){
        BitmapButton1->SetBitmap(analiza1kol2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 2))){
        if(i<6){
        BitmapButton1->SetBitmap(analiza1egz1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 3))){
        if(i<6){
        BitmapButton1->SetBitmap(analiza1egz2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 4))){
        if(i<5){
        BitmapButton1->SetBitmap(analiza1egz3[i]);
        i++;}}
    //algebraliniowa
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 0))){
        if(i<5){
        BitmapButton1->SetBitmap(algebralinkol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 1))){
        if(i<5){
        BitmapButton1->SetBitmap(algebralinkol2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 2))){
        if(i<5){
        BitmapButton1->SetBitmap(algebralinegz1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 3))){
        if(i<5){
        BitmapButton1->SetBitmap(algebralinegz2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 4))){
        if(i<6){
        BitmapButton1->SetBitmap(algebralinegz3[i]);
        i++;}}
    //logika
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 0))){
        if(i<7){
        BitmapButton1->SetBitmap(logikakol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 1))){
        if(i<6){
        BitmapButton1->SetBitmap(logikakol2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 2))){
        if(i<8){
        BitmapButton1->SetBitmap(logikaegz1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 3))){
        if(i<8){
        BitmapButton1->SetBitmap(logikaegz2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 4))){
        if(i<8){
        BitmapButton1->SetBitmap(logikaegz3[i]);
        i++;}}
    //funkcje elementarne
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 4) && (Choice3->GetSelection() == 0))){
        if(i<6){
        BitmapButton1->SetBitmap(funkcjeelzal[i]);
        i++;}}
    //programowanie
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 3) && (Choice3->GetSelection() == 0))){
        if(i<1){
        BitmapButton1->SetBitmap(programowaniekol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 3) && (Choice3->GetSelection() == 1))){
        if(i<1){
        BitmapButton1->SetBitmap(programowaniekol2[i]);
        i++;}}
    //narzedzia inf
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 5) && (Choice3->GetSelection() == 0))){
        if(i<11){
        BitmapButton1->SetBitmap(narzedziainfzal[i]);
        i++;}}
    //system operacyjne
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 7) && (Choice3->GetSelection() == 0))){
        if(i<6){
        BitmapButton1->SetBitmap(systemyopkol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 0) && (Choice2->GetSelection() == 8) && (Choice3->GetSelection() == 0))){
        if(i<5){
        BitmapButton1->SetBitmap(bhpzal1[i]);
        i++;}}
    //analiza2
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 0))){
        if(i<7){
        BitmapButton1->SetBitmap(analiza2kol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 1))){
        if(i<10){
        BitmapButton1->SetBitmap(analiza2kol2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 2))){
        if(i<12){
        BitmapButton1->SetBitmap(analiza2egz1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 3))){
        if(i<12){
        BitmapButton1->SetBitmap(analiza2egz2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 0) && (Choice3->GetSelection() == 4))){
        if(i<12){
        BitmapButton1->SetBitmap(analiza2egz3[i]);
        i++;}}
    //algebra wspoleczesna
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 0))){
        if(i<5){
        BitmapButton1->SetBitmap(algebraabskol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 1))){
        if(i<5){
        BitmapButton1->SetBitmap(algebraabskol2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 2))){
        if(i<5){
        BitmapButton1->SetBitmap(algebraabsegz1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 1) && (Choice3->GetSelection() == 3))){
        if(i<5){
        BitmapButton1->SetBitmap(algebraabsegz2[i]);
        i++;}}
    //matematyka dyskretna
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 0))){
        if(i<5){
        BitmapButton1->SetBitmap(matdyskol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 1))){
        if(i<5){
        BitmapButton1->SetBitmap(matdyskol2[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 2))){
        if(i<6){
        BitmapButton1->SetBitmap(matdysegz1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 2) && (Choice3->GetSelection() == 3))){
        if(i<6){
        BitmapButton1->SetBitmap(matdysegz2[i]);
        i++;}}
    //grafika komputerowa
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 3) && (Choice3->GetSelection() == 0))){
        if(i<3){
        BitmapButton1->SetBitmap(grafikakompkol1[i]);
        i++;}}
    //programowanie obiektowe
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 5) && (Choice3->GetSelection() == 0))){
        if(i<2){
        BitmapButton1->SetBitmap(programowanieobkol1[i]);
        i++;}}
    //programowanie w R
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 6) && (Choice3->GetSelection() == 0))){
        if(i<13){
        BitmapButton1->SetBitmap(programowaniewrkol1[i]);
        i++;}}
    //psychologia
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 8) && (Choice3->GetSelection() == 0))){
        if(i<4){
        BitmapButton1->SetBitmap(psychologiakol1[i]);
        i++;}}
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 8) && (Choice3->GetSelection() == 1))){
        if(i<4){
        BitmapButton1->SetBitmap(psychologiakol2[i]);
        i++;}}
    //narzedzia informatyczne 2
    if(((Choice1->GetSelection() == 1) && (Choice2->GetSelection() == 4) && (Choice3->GetSelection() == 0))){
        if(i<1){
        BitmapButton1->SetBitmap(narzedziainfzal2[i]);
        i++;}}

}

void quiz::OnChoice3Select1(wxCommandEvent& event)
{
    restart();
}
