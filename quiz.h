#ifndef QUIZ_H
#define QUIZ_H
#include <iostream>
#include <wx/listctrl.h>
#include <vector>
using namespace std;
//(*Headers(quiz)
#include <wx/bmpbuttn.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class quiz: public wxDialog
{
	public:

		quiz(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~quiz();

		//(*Declarations(quiz)
		wxBitmapButton* BitmapButton1;
		wxChoice* Choice1;
		wxChoice* Choice2;
		wxChoice* Choice3;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		//*)

	protected:

		//(*Identifiers(quiz)
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT3;
		static const long ID_CHOICE3;
		static const long ID_BITMAPBUTTON1;
		//*)

	private:

		//(*Handlers(quiz)
		void OnChoice1Select(wxCommandEvent& event);
		void OnChoice2Select(wxCommandEvent& event);
		void OnBitmapButton1Click(wxCommandEvent& event);
		void OnChoice3Select(wxCommandEvent& event);
		void OnChoice3Select1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
		wxBitmapButton* BM;
		wxBitmap analiza1kol1[5];
		wxBitmap analiza1kol2[5];
		wxBitmap analiza1egz1[6];
		wxBitmap analiza1egz2[6];
		wxBitmap analiza1egz3[5];

		wxBitmap algebralinkol1[5];
		wxBitmap algebralinkol2[5];
		wxBitmap algebralinegz1[5];
		wxBitmap algebralinegz2[5];
		wxBitmap algebralinegz3[6];

		wxBitmap logikakol1[7];
		wxBitmap logikakol2[6];
		wxBitmap logikaegz1[8];
		wxBitmap logikaegz2[8];
		wxBitmap logikaegz3[8];

		wxBitmap funkcjeelzal[6];

		wxBitmap programowaniekol1[1];
		wxBitmap programowaniekol2[1];

		wxBitmap narzedziainfzal[11];

		wxBitmap systemyopkol1[6];

		wxBitmap bhpzal1[5];

		wxBitmap analiza2kol1[7];
		wxBitmap analiza2kol2[10];
		wxBitmap analiza2egz1[12];
		wxBitmap analiza2egz2[12];
		wxBitmap analiza2egz3[12];

		wxBitmap algebraabskol1[5];
		wxBitmap algebraabskol2[5];
		wxBitmap algebraabsegz1[5];
		wxBitmap algebraabsegz2[5];

		wxBitmap matdyskol1[5];
		wxBitmap matdyskol2[5];
		wxBitmap matdysegz1[6];
		wxBitmap matdysegz2[6];

		wxBitmap grafikakompkol1[3];

		wxBitmap programowanieobkol1[2];

		wxBitmap programowaniewrkol1[13];

		wxBitmap psychologiakol1[4];
		wxBitmap psychologiakol2[4];

		wxBitmap narzedziainfzal2[1];



		void restart();

};

struct Przedmiot1{
    string nazwa;
    int waga;
    };

#endif
