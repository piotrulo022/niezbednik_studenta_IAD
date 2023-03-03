#ifndef SREDNIA_H
#define SREDNIA_H
#include <iostream>
#include <wx/listctrl.h>

#include <vector>
using namespace std;
//(*Headers(srednia)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class srednia: public wxDialog
{
	public:

		srednia(wxWindow* parent,wxWindowID id=wxID_ANY);
		void zapisz_oceny();
		void sczytaj(string plik);
		void wczyt();
		virtual ~srednia();

		//(*Declarations(srednia)
		wxButton* Button2;
		wxCheckBox* CheckBox1;
		wxCheckBox* CheckBox2;
		wxChoice* Choice1;
		wxGrid* Grid1;
		wxStaticBitmap* StaticBitmap2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(srednia)
		static const long ID_STATICBITMAP2;
		static const long ID_STATICTEXT2;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_GRID1;
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(srednia)
		void OnButton1Click(wxCommandEvent& event);
		void OnChoice1Select(wxCommandEvent& event);
		void OnGrid1CellLeftClick(wxGridEvent& event);
		void OnButton1Click1(wxCommandEvent& event);
		void OnChoice1Select1(wxCommandEvent& event);
		void OnListCtrl1BeginDrag(wxListEvent& event);
		void OnListCtrl1BeginDrag1(wxListEvent& event);
		void OnGrid1CellLeftClick1(wxGridEvent& event);
		void OnGrid1CellLeftClick2(wxGridEvent& event);
		void OnGrid1CellLeftClick3(wxGridEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnCheckBox2Click(wxCommandEvent& event);
		void OnButton1Click2(wxCommandEvent& event);
		void OnButton1Click3(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

		DECLARE_EVENT_TABLE()



};
		struct Przedmiot{
        string nazwa;
        int waga;
    };


#endif
