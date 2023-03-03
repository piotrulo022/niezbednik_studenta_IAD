#include "kalendarz.h"
#include <iostream>
#include "dodaj.h"
#include <wx/msgdlg.h>
#include <wx/file.h>
#include <fstream>
#include <sstream>
#include "niezbednikMain.h"
using namespace std;
#undef _
#define _(s) wxString::FromUTF8(s)
//(*InternalHeaders(kalendarz)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(kalendarz)
const long kalendarz::ID_STATICBITMAP1 = wxNewId();
const long kalendarz::ID_BUTTON1 = wxNewId();
const long kalendarz::ID_TOGGLEBUTTON2 = wxNewId();
const long kalendarz::ID_TOGGLEBUTTON1 = wxNewId();
const long kalendarz::ID_GRID1 = wxNewId();
const long kalendarz::ID_CALENDARCTRL1 = wxNewId();
const long kalendarz::ID_BUTTON2 = wxNewId();
const long kalendarz::ID_TEXTENTRYDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(kalendarz,wxDialog)
	//(*EventTable(kalendarz)
	//*)
END_EVENT_TABLE()

kalendarz::kalendarz(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(kalendarz)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	FlexGridSizer1 = new wxFlexGridSizer(7, 1, 0, 0);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("wpt.png")).Rescale(wxSize(390,91).GetWidth(),wxSize(390,91).GetHeight())), wxDefaultPosition, wxSize(390,91), 0, _T("ID_STATICBITMAP1"));
	FlexGridSizer1->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(1, 3, 0, 0);
	Button1 = new wxButton(this, ID_BUTTON1, _("Dodaj wydarzenie"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("Zmień"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
	FlexGridSizer2->Add(ToggleButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("Usuwaj wydarzenia"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	FlexGridSizer2->Add(ToggleButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
	Grid1->CreateGrid(0,3);
	Grid1->EnableEditing(false);
	Grid1->EnableGridLines(true);
	Grid1->SetLabelTextColour(wxColour(128,0,64));
	wxFont GridLabelFont_1(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("@Microsoft YaHei"),wxFONTENCODING_DEFAULT);
	Grid1->SetLabelFont(GridLabelFont_1);
	Grid1->SetColLabelValue(0, _("Nazwa"));
	Grid1->SetColLabelValue(1, _("Data"));
	Grid1->SetColLabelValue(2, _("Typ"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	FlexGridSizer1->Add(Grid1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CalendarCtrl1 = new wxCalendarCtrl(this, ID_CALENDARCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, 0, _T("ID_CALENDARCTRL1"));
	FlexGridSizer1->Add(CalendarCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Zapisz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	TextEntryDialog1 = new wxTextEntryDialog(this, wxEmptyString, _("Wprowadzanie nowego wydarzenia"), wxEmptyString, wxOK|wxCANCEL|wxCENTRE|wxWS_EX_VALIDATE_RECURSIVELY, wxDefaultPosition);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalendarz::OnButton1Click);
	Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&kalendarz::OnToggleButton2Toggle);
	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&kalendarz::OnToggleButton1Toggle);
	Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&kalendarz::OnGrid1CellLeftClick);
	Connect(ID_GRID1,wxEVT_GRID_CELL_RIGHT_CLICK,(wxObjectEventFunction)&kalendarz::OnGrid1CellRightClick);
	Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_DCLICK,(wxObjectEventFunction)&kalendarz::OnGrid1CellLeftDClick);
	Grid1->Connect(wxEVT_SET_CURSOR,(wxObjectEventFunction)&kalendarz::OnGrid1SetCursor,0,this);
	Connect(ID_CALENDARCTRL1,wxEVT_CALENDAR_DOUBLECLICKED,(wxObjectEventFunction)&kalendarz::OnCalendarCtrl1DblClicked);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalendarz::OnButton2Click1);
	//*)
    Grid1->SetGridLineColour(*wxWHITE);
    ToggleButton2->SetToolTip(wxT("Kliknij w przycisk, następnie na wydarzenie lub kliknij dwa razy na wydarzenie, aby je zmienić."));
    ToggleButton1->SetToolTip(wxT("Kliknij w przycisk, a następnie prawym przyciskiem myszy na wydarzenie, aby je usunąć."));
    odczyt();
    this->SetSize(this->GetBestSize());

}

kalendarz::~kalendarz()
{
	//(*Destroy(kalendarz)
	//*)
}


dodaj* dlg;

void kalendarz::odczyt(){
    fstream f;
    f.open("wydarzenia.txt");

    while(f.good()){
        string s;
        stringstream ss;
        getline(f, s);
        if(s.length() != 0){
            ss << s;
            string n, d, t, k;
            getline(ss, n, '\t');
            getline(ss, d, '\t');
            getline(ss, t, '\t');
            getline(ss, k, '\t');
            wyd* pom = new wyd(wxString(n.c_str(), wxConvUTF8), wxString(d.c_str(), wxConvUTF8), wxString(t.c_str(), wxConvUTF8), wxString(k.c_str(), wxConvUTF8));
            wydarzenia.push_back(pom);
            Grid1->AppendRows();
            Grid1->SetCellValue(licznik, 0, wxString(n));
            Grid1->SetCellValue(licznik, 1, wxString(d));
            Grid1->SetCellValue(licznik, 2, wxString(t));
            Grid1->SetCellBackgroundColour(licznik, 0, wxString(k));
            Grid1->SetCellBackgroundColour(licznik, 1, wxString(k));
            Grid1->SetCellBackgroundColour(licznik, 2, wxString(k));
            licznik++;
        }
   }
   f.close();
}

void kalendarz::zapis(wyd* x){
    fstream f;
    f.open("wydarzenia.txt", ios::out|ios::app);
    if(f.good()){
            f << x->nazwa << '\t' << x->data << '\t' << x->typ << '\t' <<  x->kolor.GetAsString() << '\n';
        }

    f.close();

}

void kalendarz::OnButton1Click(wxCommandEvent& event){

    try{
    dlg = new dodaj(this);
    dlg->ShowModal();

if(!p->nazwa.IsNull()){
    if(Grid1->GetNumberRows() == 0) licznik = 0;
    wydarzenia.push_back(p);
    zapis(p);
    Grid1->AppendRows();
    Grid1->GetBestVirtualSize();
    Grid1->SetCellValue(licznik, 0, p->nazwa);
    Grid1->SetCellValue(licznik, 1, p->data);
    Grid1->SetCellValue(licznik, 2, p->typ);
    Grid1->SetCellBackgroundColour(licznik, 0, p->kolor);
    Grid1->SetCellBackgroundColour(licznik, 1, p->kolor);
    Grid1->SetCellBackgroundColour(licznik, 2, p->kolor);
        Grid1->AutoSizeColumns();
        this->SetSize(this->GetBestSize());
        licznik++;
        p = new wyd(wxEmptyString, wxEmptyString, wxEmptyString, wxEmptyString);
}
    }catch(exception& e){

    }
}

void kalendarz::zapisz_wektor(vector<wyd*>& m){
    fstream f;
    f.open("wydarzenia.txt", ios::out|ios::binary);

    if(f.good()){
            for (auto& x: m){
                f << x->nazwa << '\t' << x->data << '\t' << x->typ << '\t' <<  x->kolor.GetAsString() << '\n';
            }
    }
    f.close();
}



void kalendarz::OnCalendarCtrl1DblClicked(wxCalendarEvent& event)
{
    dlg = new dodaj(this);
    dlg->DatePickerCtrl1->SetValue(CalendarCtrl1->GetDate());
    dlg->ShowModal();
    if(!p->nazwa.IsNull()){
    Grid1->AppendRows();
    wydarzenia.push_back(p);
    Grid1->GetBestVirtualSize();
    Grid1->SetCellValue(licznik, 0, p->nazwa);
    Grid1->SetCellValue(licznik, 1, p->data);
    Grid1->SetCellValue(licznik, 2, p->typ);
    Grid1->SetCellBackgroundColour(licznik, 0, p->kolor);
    Grid1->SetCellBackgroundColour(licznik, 1, p->kolor);
    Grid1->SetCellBackgroundColour(licznik, 2, p->kolor);

        Grid1->AutoSizeColumns();
        this->SetSize(this->GetBestSize());
        licznik++;
}
}

void kalendarz::OnGrid1CellRightClick(wxGridEvent& event){
    if(ToggleButton1->GetValue()){
    int w = event.GetRow();
    Grid1->DeleteRows(w);
    Grid1->Refresh();
    vector<wyd*>::iterator it = wydarzenia.begin() + w;
    wydarzenia.erase(it);
    licznik--;
    }

}

void kalendarz::OnButton3Click(wxCommandEvent& event){

}

void kalendarz::OnToggleButton1Toggle(wxCommandEvent& event)
{
        if(Grid1->GetNumberRows() == 0) ToggleButton1->SetValue(false);
}

void kalendarz::OnGrid1CellLeftDClick(wxGridEvent& event){
    int w = event.GetRow();
    dlg = new dodaj(this);
    if(!Grid1->GetCellValue(w, 0).IsEmpty()){
        dlg->TextEntryDialog1->SetValue(Grid1->GetRowLabelValue(w));
        wxDateTime d;
        d.ParseDate(Grid1->GetCellValue(w, 0));
        dlg->ShowModal();

        Grid1->SetCellValue(w, 0, p->nazwa);
        Grid1->SetCellValue(w, 1, p->data);
        Grid1->SetCellValue(w, 2, p->typ);
        Grid1->SetCellBackgroundColour(w, 0, p->kolor);
        Grid1->SetCellBackgroundColour(w, 1, p->kolor);
        Grid1->SetCellBackgroundColour(w, 2, p->kolor);
    }
}

void kalendarz::OnButton2Click(wxCommandEvent& event){

}

void kalendarz::OnGrid1CellLeftClick(wxGridEvent& event)
{
    if(ToggleButton2->GetValue()){
        int w = event.GetRow();
        dlg = new dodaj(this);
    if(!Grid1->GetCellValue(w, 0).IsEmpty()){
        dlg->TextEntryDialog1->SetValue(Grid1->GetRowLabelValue(w));
        wxDateTime d;
        d.ParseDate(Grid1->GetCellValue(w, 0));
        dlg->ShowModal();
        Grid1->SetCellValue(w, 0, p->nazwa);
        Grid1->SetCellValue(w, 1, p->data);
        Grid1->SetCellValue(w, 2, p->typ);
        Grid1->SetCellBackgroundColour(w, 0, p->kolor);
        Grid1->SetCellBackgroundColour(w, 1, p->kolor);
        Grid1->SetCellBackgroundColour(w, 2, p->kolor);
        wydarzenia[w] = p;
            this->SetSize(this->GetBestSize());
            ToggleButton2->SetValue(false);
    }
    }
}

void kalendarz::OnToggleButton2Toggle(wxCommandEvent& event)
{
        if(Grid1->GetNumberRows() == 0) ToggleButton2->SetValue(false);
}

void kalendarz::OnButton2Click1(wxCommandEvent& event)
{
    zapisz_wektor(wydarzenia);
    wxMessageBox(_("Zapisano pomyślnie!"), _("Zapisano"), wxICON_INFORMATION);
}

void kalendarz::OnGrid1SetCursor(wxSetCursorEvent& event)
{

}
