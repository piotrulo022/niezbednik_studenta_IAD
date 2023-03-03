#ifndef KALENDARZ_H
#define KALENDARZ_H
#include "dodaj.h"
#include <wx/file.h>
#include <vector>
#include "wyd.h"
#include <map>


//(*Headers(kalendarz)
#include <wx/button.h>
#include <wx/calctrl.h>
#include <wx/dialog.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/textdlg.h>
#include <wx/tglbtn.h>
//*)

class kalendarz: public wxDialog
{
	public:

		kalendarz(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		void odczyt();
		void zapis(wyd* x);
		void zapisz_wektor(vector<wyd*>& m);
		virtual ~kalendarz();


		//(*Declarations(kalendarz)
		wxButton* Button1;
		wxButton* Button2;
		wxCalendarCtrl* CalendarCtrl1;
		wxGrid* Grid1;
		wxStaticBitmap* StaticBitmap1;
		wxTextEntryDialog* TextEntryDialog1;
		wxToggleButton* ToggleButton1;
		wxToggleButton* ToggleButton2;
		//*)

	protected:

		//(*Identifiers(kalendarz)
		static const long ID_STATICBITMAP1;
		static const long ID_BUTTON1;
		static const long ID_TOGGLEBUTTON2;
		static const long ID_TOGGLEBUTTON1;
		static const long ID_GRID1;
		static const long ID_CALENDARCTRL1;
		static const long ID_BUTTON2;
		static const long ID_TEXTENTRYDIALOG1;
		//*)

	private:

		//(*Handlers(kalendarz)
		void OnButton1Click(wxCommandEvent& event);
		void OnCalendarCtrl1DblClicked(wxCalendarEvent& event);
		void OnGrid1CellRightClick(wxGridEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnToggleButton1Toggle(wxCommandEvent& event);
		void OnGrid1CellLeftDClick(wxGridEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnGrid1CellLeftClick(wxGridEvent& event);
		void OnToggleButton2Toggle(wxCommandEvent& event);
		void OnButton2Click1(wxCommandEvent& event);
		void OnGrid1SetCursor(wxSetCursorEvent& event);
		//*)

		DECLARE_EVENT_TABLE()

		vector<wyd*> wydarzenia;
        int licznik = 0;
};

#endif
