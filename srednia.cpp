#include "srednia.h"
#include <sstream>
#include <fstream>
#include "niezbednikMain.h"
#include <algorithm>
#include <wx/msgdlg.h>


#undef _
#define _(s) wxString::FromUTF8(s)


//(*InternalHeaders(srednia)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

vector <Przedmiot> przedmioty;
//(*IdInit(srednia)
const long srednia::ID_STATICBITMAP2 = wxNewId();
const long srednia::ID_STATICTEXT2 = wxNewId();
const long srednia::ID_CHECKBOX1 = wxNewId();
const long srednia::ID_CHECKBOX2 = wxNewId();
const long srednia::ID_STATICTEXT1 = wxNewId();
const long srednia::ID_CHOICE1 = wxNewId();
const long srednia::ID_GRID1 = wxNewId();
const long srednia::ID_BUTTON2 = wxNewId();
const long srednia::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(srednia,wxDialog)
	//(*EventTable(srednia)
	//*)
END_EVENT_TABLE()

string w2s(wxString w){
    return string(w.mb_str(wxConvUTF8));
}

wxString s2w(string s){
    return wxString(s.c_str(), wxConvUTF8);
}

void srednia::sczytaj(string plik){
    fstream f;
    f.open(plik);
    while(f.good()){
        stringstream ss;
        string s;
        getline(f, s, '\n');
    if(s.length() != 0){
        ss << s;
        string pom, waga;
        getline(ss, pom, '\t');
        getline(ss, waga);
        Przedmiot p;
        p.nazwa = pom;
        p.waga = stoi(waga);
        przedmioty.push_back(p);
    }

    }
    f.close();
}

void srednia::zapisz_oceny(){
    fstream f;
    int i = 0;
    f.open("oceny.txt", ios::out|ios::binary);
    f << CheckBox1->GetValue() << '\n' << CheckBox2->GetValue() << '\n';
    f << Choice1->GetSelection()  << '\n';
    if(f.good()){
        while(i < Grid1->GetNumberRows()){
            f << Grid1->GetCellValue(i, 0) << '\n';
            i++;
        }
    }
    f.close();
}

void srednia::wczyt(){
    fstream f;
    f.open("oceny.txt", ios::in);
    if(f.good()){
        bool cb1, cb2;
        string s;
        getline(f, s);
        cb1 = stoi(s);
        getline(f, s);
        cb2 = stoi(s);
        CheckBox1->SetValue(cb1);
        CheckBox2->SetValue(cb2);
        getline(f, s);
        Choice1->SetSelection(stoi(s));
    }

}

srednia::srednia(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(srednia)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer5;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(6, 1, 0, 0);
	StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxBitmap(wxImage(_T("wpt.png")).Rescale(wxSize(315,109).GetWidth(),wxSize(315,109).GetHeight())), wxDefaultPosition, wxSize(315,109), 0, _T("ID_STATICBITMAP2"));
	FlexGridSizer2->Add(StaticBitmap2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5 = new wxFlexGridSizer(6, 1, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Roczna/semestralna"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer5->Add(StaticText2, 1, wxALL, 5);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Semestralna"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	FlexGridSizer5->Add(CheckBox1, 1, wxALL|wxSHAPED, 5);
	CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("Roczna"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBox2->SetValue(false);
	FlexGridSizer5->Add(CheckBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Wybierz"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer5->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	FlexGridSizer5->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
	FlexGridSizer5->Add(Grid1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(1, 3, 0, 0);
	Button2 = new wxButton(this, ID_BUTTON2, _("Oblicz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(94,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->Disable();
	FlexGridSizer4->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&srednia::OnCheckBox1Click);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&srednia::OnCheckBox2Click);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srednia::OnChoice1Select);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srednia::OnButton2Click);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&srednia::OnTextCtrl1Text);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&srednia::OnInit);
	//*)
//	wczyt();
	 if(CheckBox1->IsChecked()){
    Choice1->Clear();
    Choice1->Append(_("I."));
	Choice1->Append(_("II."));
	Choice1->Append(_("III."));
	Choice1->Append(_("IV."));
	Choice1->Append(_("V."));
	Choice1->Append(_("VI."));
	Choice1->Append(_("VII."));
    CheckBox2->Disable();
    }
    else CheckBox2->Enable();

        if(CheckBox2->IsChecked()){
    Choice1->Clear();
    Choice1->Append(_("I."));
	Choice1->Append(_("II."));
	Choice1->Append(_("III."));
    CheckBox1->Disable();
    }
    else CheckBox1->Enable();

    this->SetSize(this->GetBestSize());

}

srednia::~srednia()
{
	//(*Destroy(srednia)
	//*)
}

void srednia::OnCheckBox1Click(wxCommandEvent& event){
    if(CheckBox1->IsChecked()){
    Choice1->Clear();
    Choice1->Append(_("I."));
	Choice1->Append(_("II."));
	Choice1->Append(_("III."));
	Choice1->Append(_("IV."));
	Choice1->Append(_("V."));
	Choice1->Append(_("VI."));
	Choice1->Append(_("VII."));
    CheckBox2->Disable();
    }
    else CheckBox2->Enable();
}

void srednia::OnCheckBox2Click(wxCommandEvent& event){

    if(CheckBox2->IsChecked()){
    Choice1->Clear();
    Choice1->Append(_("I."));
	Choice1->Append(_("II."));
	Choice1->Append(_("III."));
    CheckBox1->Disable();
    }
    else CheckBox1->Enable();
}

void srednia::OnButton1Click(wxCommandEvent& event)
{

}

void srednia::OnChoice1Select(wxCommandEvent& event){
        sczytaj("przedmioty.txt");
        Grid1->ClearGrid();

        if(Grid1->GetNumberRows() == 0){
        Grid1->CreateGrid(10, 1);
        Grid1->SetColLabelValue(0, _("Ocena"));
        Grid1->SetRowLabelSize(350);
        }
    //semy
    //I.
    if(CheckBox1->IsChecked()){
    if(Choice1->GetSelection() == 0){
        if(Grid1->GetNumberRows() < 10) Grid1->AppendRows(10 - Grid1->GetNumberRows());
        else if(Grid1->GetNumberRows() > 10) Grid1->DeleteRows(10, Grid1->GetNumberRows() - 9);
        for(int i = 0; i < 10; i++){
            string n = przedmioty[i].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
        }

    }
    //II.
    if(Choice1->GetSelection() == 1){
        if(Grid1->GetNumberRows() < 9) Grid1->AppendRows(9 - Grid1->GetNumberRows());
        else if(Grid1->GetNumberRows() > 9) Grid1->DeleteRows(9, Grid1->GetNumberRows() - 9);
        for(int i = 0; i < 9; i++){
            string n = przedmioty[i + 10].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
        }
    }
    //III.
        if(Choice1->GetSelection() == 2){
        if(Grid1->GetNumberRows() < 9) Grid1->AppendRows(9 - Grid1->GetNumberRows());
        else if(Grid1->GetNumberRows() > 9) Grid1->DeleteRows(9, Grid1->GetNumberRows() - 9);
        for(int i = 0; i < 9; i++){
            string n = przedmioty[i + 19].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
        }

    }
    //IV.
        if(Choice1->GetSelection() == 3){
        if(Grid1->GetNumberRows() < 9) Grid1->AppendRows(9 - Grid1->GetNumberRows());
        else if(Grid1->GetNumberRows() > 9) Grid1->DeleteRows(9, Grid1->GetNumberRows() - 9);
        for(int i = 0; i < 9; i++){
            string n = przedmioty[i + 28].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
        }

    }
    //V.
        if(Choice1->GetSelection() == 4){
        if(Grid1->GetNumberRows() < 9) Grid1->AppendRows(9 - Grid1->GetNumberRows());
        else if(Grid1->GetNumberRows() > 9) Grid1->DeleteRows(9, Grid1->GetNumberRows() - 9);
        for(int i = 0; i < 9; i++){
            string n = przedmioty[i + 37].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
        }

    }
    //VI.
        if(Choice1->GetSelection() == 5){
        if(Grid1->GetNumberRows() < 10) Grid1->AppendRows(10 - Grid1->GetNumberRows());
        else if(Grid1->GetNumberRows() > 10) Grid1->DeleteRows(10, Grid1->GetNumberRows() - 9);
        for(int i = 0; i < 10; i++){
            string n = przedmioty[i + 46].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
        }

    }
    //VII.
    if(Choice1->GetSelection() == 6){
        if(Grid1->GetNumberRows() < 2) Grid1->AppendRows(2 - Grid1->GetNumberRows());
        else if(Grid1->GetNumberRows() > 2) Grid1->DeleteRows(2, Grid1->GetNumberRows() - 1);
        for(int i = 0; i < 3; i++){
            string n = przedmioty[i + 56].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
        }
    }
}
//roki
    if(CheckBox2->IsChecked()){

        if(Choice1->GetSelection() == 0){
            if(Grid1->GetNumberRows() < 19) Grid1->AppendRows(19 - Grid1->GetNumberRows());


            for(int i = 0; i < 20; i++){
            string n = przedmioty[i].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
            }
        }
         if(Choice1->GetSelection() == 1){
            if(Grid1->GetNumberRows() < 18) Grid1->AppendRows(18 - Grid1->GetNumberRows());
            if(Grid1->GetNumberRows() == 19) Grid1->DeleteRows(18);

                    for(int i = 0; i < 18; i++){
            string n = przedmioty[i + 19].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));

        }
    }

         if(Choice1->GetSelection() == 2){
            if(Grid1->GetNumberRows() < 19) Grid1->AppendRows(19 - Grid1->GetNumberRows());

            for(int i = 0; i < 20; i++){
            string n = przedmioty[i + 37].nazwa;
            Grid1->SetRowLabelValue(i, _(n.c_str()));
            }
        }
    }
    this->SetSize(this->GetBestSize());
}

void srednia::OnGrid1CellLeftClick(wxGridEvent& event)
{
}
double policz_srednia(int sem, wxGrid* w){

    double wyn;

    if(sem == 1){
        for(int i = 0; i < w->GetNumberRows(); i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            wyn += (przedmioty[i].waga) * l;
        }

    return wyn/30;
    }

    else if(sem == 2){
       for(int i = 0; i < w->GetNumberRows(); i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            wyn += (przedmioty[i+10].waga) * l;
        }
        return wyn/30.0;

    }
        else if(sem == 3){
       for(int i = 0; i < w->GetNumberRows(); i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            wyn += (przedmioty[i+19].waga) * l;
        }
        return wyn/30.0;
    }
        else if(sem == 4){
       for(int i = 0; i < w->GetNumberRows(); i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            wyn += (przedmioty[i+28].waga) * l;
        }
        return wyn/30.0;
    }
            else if(sem == 5){
       for(int i = 0; i < w->GetNumberRows(); i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            wyn += (przedmioty[i+37].waga) * l;
        }
        return wyn/30.0;
    }
                else if(sem == 6){
       for(int i = 0; i < w->GetNumberRows(); i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            wyn += (przedmioty[i+46].waga) * l;
        }
        return wyn/30.0;
    }
            else if(sem == 7){
       for(int i = 0; i < w->GetNumberRows(); i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            wyn += (przedmioty[i+56].waga) * l;
        }
        return wyn/40.0;
    }
}

double sr_rok(int rok, wxGrid* w){
    double a;
    if(rok == 1){
         for(int i = 0; i < 19; i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            a += (przedmioty[i].waga) * l;
        }
        return a/60;
    }
    if(rok == 2){
        for(int i = 0; i < 18; i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            a += (przedmioty[i + 19].waga) * l;
        }
        return a/60;
    }
    if(rok == 3){
         for(int i = 0; i < 19; i++){
            wxString s = w->GetCellValue(i, 0);
            double l = stod(w2s(s));
            a += (przedmioty[i + 37].waga) * l;
        }
        return a/60;
    }
}



void srednia::OnChoice1Select1(wxCommandEvent& event){
}



void srednia::OnListCtrl1BeginDrag(wxListEvent& event)
{
}

void srednia::OnListCtrl1BeginDrag1(wxListEvent& event)
{
}

void srednia::OnGrid1CellLeftClick1(wxGridEvent& event)
{
}

void srednia::OnGrid1CellLeftClick2(wxGridEvent& event)
{
}

void srednia::OnGrid1CellLeftClick3(wxGridEvent& event)
{
}

void srednia::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void srednia::OnButton2Click(wxCommandEvent& event){
try{
    if(CheckBox1->IsChecked()){
    TextCtrl1->SetValue(s2w(to_string(policz_srednia(Choice1->GetSelection()+1, Grid1))));
    }

    if(CheckBox2->IsChecked()){
      TextCtrl1->SetValue(s2w(to_string(sr_rok(Choice1->GetSelection()+1, Grid1))));
    }
    zapisz_oceny();
}catch(exception& e){
    wxMessageBox(s2w("Nieprawidłowe lub brak danych"), _("Błąd"), wxICON_ERROR);
}
}


void srednia::OnButton1Click3(wxCommandEvent& event)
{
    wczyt();
}

void srednia::OnInit(wxInitDialogEvent& event)
{
}
