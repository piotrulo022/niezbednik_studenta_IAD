#include "dodaj.h"
#include <vector>
#include "kalendarz.h"


//(*InternalHeaders(dodaj)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

//(*IdInit(dodaj)
const long dodaj::ID_BUTTON1 = wxNewId();
const long dodaj::ID_TEXTCTRL1 = wxNewId();
const long dodaj::ID_STATICTEXT2 = wxNewId();
const long dodaj::ID_DATEPICKERCTRL1 = wxNewId();
const long dodaj::ID_STATICTEXT1 = wxNewId();
const long dodaj::ID_COLOURPICKERCTRL1 = wxNewId();
const long dodaj::ID_CHOICE1 = wxNewId();
const long dodaj::ID_BUTTON3 = wxNewId();
const long dodaj::ID_TEXTENTRYDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dodaj,wxDialog)
	//(*EventTable(dodaj)
	//*)
END_EVENT_TABLE()

wyd* p = new wyd();

dodaj::dodaj(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(dodaj)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer4;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(5, 1, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
	Button1 = new wxButton(this, ID_BUTTON1, _("Nazwa"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->Disable();
	FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(1, 2, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Kiedy:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DatePickerCtrl1 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxSize(130,31), wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
	FlexGridSizer3->Add(DatePickerCtrl1, 1, wxALL|wxALIGN_RIGHT, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer4 = new wxFlexGridSizer(1, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Kolor:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
	FlexGridSizer4->Add(ColourPickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("Kolokwium")) );
	Choice1->Append(_("Egzamin"));
	Choice1->Append(_("Wejściówka"));
	Choice1->Append(_("Inne"));
	FlexGridSizer1->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("Zatwierdź"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer1->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	TextEntryDialog1 = new wxTextEntryDialog(this, _("Wprowadz nazwe wydarzenia"), _("Dodawanie nowego wydarzenia"), wxEmptyString, wxOK|wxCANCEL|wxCENTRE|wxWS_EX_VALIDATE_RECURSIVELY, wxDefaultPosition);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dodaj::OnButton1Click);
	Connect(ID_DATEPICKERCTRL1,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&dodaj::OnDatePickerCtrl1Changed);
	Connect(ID_COLOURPICKERCTRL1,wxEVT_COMMAND_COLOURPICKER_CHANGED,(wxObjectEventFunction)&dodaj::OnColourPickerCtrl1ColourChanged);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dodaj::OnButton3Click);
	//*)

}

dodaj::~dodaj()
{
	//(*Destroy(dodaj)
	//*)
}



void dodaj::OnButton1Click(wxCommandEvent& event)
{
    try{
    TextEntryDialog1->ShowModal();
    TextCtrl1->SetValue(TextEntryDialog1->GetValue());
    }catch(exception& e){
    }

}

void dodaj::OnButton3Click(wxCommandEvent& event){

 try{
    wxString naz = TextEntryDialog1->GetValue();
    wxString dat = (DatePickerCtrl1->GetValue()).FormatISODate();
    wxString ty = Choice1->GetStringSelection();
    wxColour kol = ColourPickerCtrl1->GetColour();

    p = new wyd(naz, dat, ty, kol);
    }catch(exception& e){

    }
    Close();

}

void dodaj::OnDatePickerCtrl1Changed(wxDateEvent& event)
{
}

void dodaj::OnColourPickerCtrl1ColourChanged(wxColourPickerEvent& event)
{
}
