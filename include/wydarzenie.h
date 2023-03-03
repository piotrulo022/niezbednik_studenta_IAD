#ifndef WYDARZENIE_H
#define WYDARZENIE_H
#include <iostream>
using namespace std;

#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/datetime.h>
#include <wx/colour.h>
#include <wx/colourdata.h>



class wydarzenie
{
    public:
        /** Default constructor */
        wydarzenie(wxString n, wxDateTime d, wxColour k): nazwa {n}, data {d}, kolor {k} {}
        wydarzenie();
        /** Default destructor */
        virtual ~wydarzenie();


    protected:


    private:
        wxString nazwa;
        wxDateTime data;
        wxColour kolor;
};

#endif // WYDARZENIE_H
