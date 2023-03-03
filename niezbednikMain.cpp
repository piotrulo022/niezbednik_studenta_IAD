/***************************************************************
 * Name:      niezbednikMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2021-12-16
 * Copyright:  ()
 * License:
 **************************************************************/

#include "niezbednikMain.h"
#include <wx/msgdlg.h>
#include "srednia.h"
#include "quiz.h"
#include "kalendarz.h"
#include <iostream>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <cstdlib>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <wx/arrstr.h>
using namespace std;

//(*InternalHeaders(niezbednikDialog)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)


#undef _
#define _(s) wxString::FromUTF8(s)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(niezbednikDialog)
const long niezbednikDialog::ID_STATICBITMAP1 = wxNewId();
const long niezbednikDialog::ID_STATICTEXT1 = wxNewId();
const long niezbednikDialog::ID_STATICTEXT2 = wxNewId();
const long niezbednikDialog::ID_CHOICE1 = wxNewId();
const long niezbednikDialog::ID_BUTTON1 = wxNewId();
const long niezbednikDialog::ID_BUTTON2 = wxNewId();
const long niezbednikDialog::ID_BUTTON4 = wxNewId();
const long niezbednikDialog::ID_BUTTON3 = wxNewId();
const long niezbednikDialog::ID_CHOICE2 = wxNewId();
const long niezbednikDialog::ID_GRID1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(niezbednikDialog,wxDialog)
    //(*EventTable(niezbednikDialog)
    //*)

END_EVENT_TABLE()



niezbednikDialog::niezbednikDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(niezbednikDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;

    Create(parent, wxID_ANY, _("Niezbędnik studenta IAD"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetBackgroundColour(wxColour(255,255,255));
    FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(4, 1, 0, 0);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("wpt.png")).Rescale(wxSize(383,97).GetWidth(),wxSize(383,97).GetHeight())), wxDefaultPosition, wxSize(383,97), 0, _T("ID_STATICBITMAP1"));
    FlexGridSizer2->Add(StaticBitmap1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Niezbędnik studenta IAD"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(128,64,0));
    wxFont StaticText1Font(18,wxFONTFAMILY_MODERN,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Courier New"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxSHAPED, 5);
    FlexGridSizer3 = new wxFlexGridSizer(3, 3, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Dostępne funkcje:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("Średnia"));
    Choice1->Append(_("Sprawdź wiedzę"));
    Choice1->Append(_("Kalendarz"));
    FlexGridSizer3->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Wybierz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    FlexGridSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(2, 2, 0, 0);
    Button2 = new wxButton(this, ID_BUTTON2, _("Organizacja roku"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    FlexGridSizer4->Add(Button2, 1, wxALL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Pokaż wydarzenia"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer4->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Plan zajęć"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    FlexGridSizer4->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->Append(_("I. rok"));
    Choice2->Append(_("II. rok"));
    Choice2->SetForegroundColour(wxColour(128,0,0));
    FlexGridSizer4->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer5 = new wxFlexGridSizer(1, 1, 0, 0);
    Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    Grid1->CreateGrid(0,3);
    Grid1->SetBackgroundColour(wxColour(6,164,249));
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetLabelTextColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    Grid1->SetColLabelValue(0, _("Nazwa"));
    Grid1->SetColLabelValue(1, _("Data"));
    Grid1->SetColLabelValue(2, _("Typ"));
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    FlexGridSizer5->Add(Grid1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&niezbednikDialog::OnChoice1Select1);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&niezbednikDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&niezbednikDialog::OnButton2Click1);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&niezbednikDialog::OnButton4Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&niezbednikDialog::OnButton3Click);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&niezbednikDialog::OnChoice2Select);
    Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&niezbednikDialog::OnGrid1CellLeftClick1);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&niezbednikDialog::OnInit);
    Connect(wxEVT_PAINT,(wxObjectEventFunction)&niezbednikDialog::OnPaint);
    //*)
    this->SetIcon(wxIcon(wxT("ikonka")));
    Choice2->Hide();
    Button4->Hide();
    Grid1->Hide();

}

niezbednikDialog::~niezbednikDialog()
{
    //(*Destroy(niezbednikDialog)
    //*)
}

void niezbednikDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void niezbednikDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
 int pom1, pom2, pom3 = 0;
void niezbednikDialog::OnButton1Click(wxCommandEvent& event){
    int a = Choice1->GetSelection();
    switch(a){
        case 0:{
            if(pom1 == 0){
            dlg = new srednia(this);
            dlg->ShowModal();
            pom1++;
            }else dlg->ShowModal();
            break;
        }
        case 1:{
            if(pom2 == 0){
            qu = new quiz(this);
            qu->ShowModal();
            pom2++;
            }else qu->ShowModal();
            break;
        }
        case 2:{
            if(pom3 == 0){
            kal = new kalendarz(this);
            kal->ShowModal();
            Button4->Show();
            pom3++;
            }else kal->ShowModal();
            break;
        }
    }
    if(siata >0)siata--;
      Grid1->Hide();
}

void niezbednikDialog::OnChoice1Select(wxCommandEvent& event)
{
}

void niezbednikDialog::OnGrid1CellLeftClick(wxGridEvent& event)
{
}

void niezbednikDialog::OnButton2Click(wxCommandEvent& event){


}

void niezbednikDialog::OnglownaCellLeftClick1(wxGridEvent& event)
{
}

void niezbednikDialog::OnglownaCellLeftClick2(wxGridEvent& event)
{

}

void niezbednikDialog::OnInit(wxInitDialogEvent& event)
{
}

void niezbednikDialog::OnPaint(wxPaintEvent& event)
{

}

void niezbednikDialog::OnChoice1Select1(wxCommandEvent& event)
{
}

void niezbednikDialog::OnButton2Click1(wxCommandEvent& event)
{
    system("organizacja.pdf");
}

void niezbednikDialog::OnButton2Click2(wxCommandEvent& event)
{
}

void niezbednikDialog::OnButton3Click(wxCommandEvent& event)
{
    Choice2->Show();
}

void niezbednikDialog::OnChoice2Select(wxCommandEvent& event)
{
    if(Choice2->GetSelection() == 0) system("iad1.pdf");
    else system("iad2.pdf");
    Choice2->Hide();
}

void niezbednikDialog::OnButton2Click3(wxCommandEvent& event)
{
}
void niezbednikDialog::fun(){

int licznik = 0;
if(Grid1->GetNumberRows() != 0) Grid1->DeleteRows(0, Grid1->GetNumberRows());
while(licznik < kal->Grid1->GetNumberRows()){
    Grid1->AppendRows();
    wxString jeden = kal->Grid1->GetCellValue(licznik, 0);
    wxString dwa = kal->Grid1->GetCellValue(licznik, 1);
    wxString trzy = kal->Grid1->GetCellValue(licznik, 2);
    wxColor cztery = kal->Grid1->GetCellBackgroundColour(licznik, 0);
    Grid1->SetCellValue(licznik, 0, jeden);
    Grid1->SetCellValue(licznik, 1, dwa);
    Grid1->SetCellValue(licznik, 2, trzy);
    Grid1->SetCellBackgroundColour(licznik, 0, cztery);
    Grid1->SetCellBackgroundColour(licznik, 1, cztery);
    Grid1->SetCellBackgroundColour(licznik, 2, cztery);
    licznik++;
    }
}



void niezbednikDialog::OnButton4Click(wxCommandEvent& event)
{
  siata++;
  if(siata % 2 != 0){

    fun();
    Grid1->Show();
    this->SetSize(this->GetBestSize());
  }else Grid1->Hide();
  this->SetSize(this->GetBestSize());
}

void niezbednikDialog::OnGrid1CellLeftClick1(wxGridEvent& event)
{
}
