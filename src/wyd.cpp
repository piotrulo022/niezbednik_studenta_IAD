#include "wyd.h"

wyd::wyd(wxString n, wxString d, wxString t, wxColour k)
{
    nazwa = n;
    data = d;
    typ = t;
    kolor = k;

}

wyd::~wyd()
{
    //dtor
}
