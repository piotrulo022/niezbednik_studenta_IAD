#ifndef DODAJ_H
#define DODAJ_H
#include "wyd.h"
#include "kalendarz.h"


using namespace std;
//(*Headers(dodaj)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/clrpicker.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/textdlg.h>
//*)



class dodaj: public wxDialog
{
	public:

		dodaj(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dodaj();


		//(*Declarations(dodaj)
		wxButton* Button1;
		wxButton* Button3;
		wxChoice* Choice1;
		wxColourPickerCtrl* ColourPickerCtrl1;
		wxDatePickerCtrl* DatePickerCtrl1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		wxTextEntryDialog* TextEntryDialog1;
		//*)

	protected:

		//(*Identifiers(dodaj)
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_COLOURPICKERCTRL1;
		static const long ID_CHOICE1;
		static const long ID_BUTTON3;
		static const long ID_TEXTENTRYDIALOG1;
		//*)

	private:

		//(*Handlers(dodaj)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnDatePickerCtrl1Changed(wxDateEvent& event);
		void OnColourPickerCtrl1ColourChanged(wxColourPickerEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnClose1(wxCloseEvent& event);
		void OnClose2(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()

};
extern wyd* p;

#endif
