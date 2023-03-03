/***************************************************************
 * Name:      niezbednikMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-12-16
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef NIEZBEDNIKMAIN_H
#define NIEZBEDNIKMAIN_H
#include "kalendarz.h"
#include "srednia.h"
#include "quiz.h"
using namespace std;



//(*Headers(niezbednikDialog)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class niezbednikDialog: public wxDialog
{
    public:

        niezbednikDialog(wxWindow* parent,wxWindowID id = -1);
        void fun();
        virtual ~niezbednikDialog();


    private:

        //(*Handlers(niezbednikDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnGrid1CellLeftClick(wxGridEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnglownaPaint(wxPaintEvent& event);
        void OnglownaCellLeftClick(wxGridEvent& event);
        void OnglownaCellLeftClick1(wxGridEvent& event);
        void OnglownaCellLeftClick2(wxGridEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnChoice1Select1(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnButton2Click2(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnChoice2Select(wxCommandEvent& event);
        void OnButton2Click3(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnGrid1CellLeftClick1(wxGridEvent& event);
        //*)

        //(*Identifiers(niezbednikDialog)
        static const long ID_STATICBITMAP1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON4;
        static const long ID_BUTTON3;
        static const long ID_CHOICE2;
        static const long ID_GRID1;
        //*)

        //(*Declarations(niezbednikDialog)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxChoice* Choice1;
        wxChoice* Choice2;
        wxGrid* Grid1;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        //*)

        DECLARE_EVENT_TABLE()
        kalendarz* kal;
        srednia* dlg;
        quiz* qu;
        int siata = 0;



};


#endif // NIEZBEDNIKMAIN_H
