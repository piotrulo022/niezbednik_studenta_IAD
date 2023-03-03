#ifndef WYD_H
#define WYD_H
#include <wx/colour.h>
#include <wx/string.h>
using namespace std;
class wyd
{
    public:
        /** Default constructor */
        wyd(wxString n, wxString d, wxString t, wxColour k);
        wyd(){}
        /** Default destructor */
        virtual ~wyd();
        wxString nazwa;
        wxString typ;
        wxColour kolor;
        wxString data;

    protected:

    private:

};

#endif // WYD_H
