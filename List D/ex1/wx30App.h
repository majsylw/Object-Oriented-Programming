/***************************************************************
 * Name:      wx30App.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2014-01-05
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef wx30APP_H
#define wx30APP_H

#include <wx/app.h>

class wx30App : public wxApp
{
  wxLocale* locale_;
    public:
        virtual bool OnInit();
};

#endif // wx30APP_H
