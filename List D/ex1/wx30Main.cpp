/***************************************************************
 * Name:      wx30Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2014-01-05
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wx30Main.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(wx30Frame, wxFrame)
    EVT_CLOSE(wx30Frame::OnClose)
    EVT_MENU(idMenuQuit, wx30Frame::OnQuit)
    EVT_MENU(idMenuAbout, wx30Frame::OnAbout)
END_EVENT_TABLE()

wx30Frame::wx30Frame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title),
      timer_(this,idTimer)
{
//#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    SetMenuBar(mbar);

    wxMenu* fileMenu = new wxMenu( _("") );
    fileMenu->Append( idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application") );
    mbar->Append( fileMenu, _("&File" ));

    wxMenu* helpMenu = new wxMenu( _T("") );
    helpMenu->Append( idMenuAbout, _("&About\tF1"), _("Show info about this application") );
    mbar->Append( helpMenu, _("&Help") );
//#endif // wxUSE_MENUS

//#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar( 2 );
    SetStatusText( _("Hello Code::Blocks user!"), 0 );
    SetStatusText( wxbuildinfo(short_f), 1 );
//#endif // wxUSE_STATUSBAR

   wxPanel* panel = new wxPanel( this );

   timer_.Start( 1000 );

//  Bind(wxEVT_TIMER,[this](wxTimerEvent&)
//    {
//    SetStatusText(wxDateTime::Now().FormatTime(),1);
//    },
//    idTimer);
    Bind( wxEVT_TIMER, &wx30Frame::OnTimer, this, idTimer );

    text_ = new wxTextCtrl( panel, wxID_ANY );
    text_->SetBackgroundColour( wxColour(200,255,255) );
    text_->SetEditable( false );

    c.SetDisplayUpdateHandler( [&](std::string nv) { 
        text_->SetValue( wxString::FromUTF8( nv.c_str() ) ); 
    } );

    std::vector< wxButton* > wejscia;
    for( int i = 0; i < 10; ++i ) {
        wejscia.push_back( new wxButton( panel, wxID_ANY, wxString::Format("%d", i) ) );
        wejscia.back()->Bind( wxEVT_BUTTON, [=](wxCommandEvent&)
            {
                c.Press( static_cast< Calc::Button >( i ) );
            }
        );
    }

    wxButton* plusik = new wxButton( panel, wxID_ANY,wxString::FromUTF8("+") );
    plusik->Bind( wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        c.Press( Calc::Add );
    });

    wxButton* minusik = new wxButton( panel, wxID_ANY, wxString::FromUTF8("-") );
    minusik->Bind( wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        c.Press( Calc::Sub );
    });

    wxButton* mnozonko = new wxButton( panel, wxID_ANY, wxString::FromUTF8("*") );
    mnozonko->Bind( wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        c.Press( Calc::Mul );
    });

    wxButton* dzielonko = new wxButton( panel, wxID_ANY, wxString::FromUTF8("/") );
    dzielonko->Bind( wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        c.Press( Calc::Div );
    });

    wxButton* rowny = new wxButton( panel, wxID_ANY, wxString::FromUTF8("=") );
    rowny->Bind( wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        c.Press( Calc::Eq );
    });

    wxButton* kropka = new wxButton( panel, wxID_ANY, wxString::FromUTF8(".") );
    kropka->Bind( wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        c.Press( Calc::Sep );
    });

    wxButton* clearButton = new wxButton( panel, wxID_ANY, wxString::FromUTF8("C") );
    clearButton->SetForegroundColour( wxColour(255,0,0) );
    clearButton->Bind( wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        c.Press( Calc::CE );
    });


  wxBoxSizer* vsizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* hsizer = new wxBoxSizer(wxHORIZONTAL);

  wxBoxSizer* bar1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* bar2 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* bar0 = new wxBoxSizer(wxHORIZONTAL);

  wxBoxSizer* sizer0 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer1 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer3 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer4 = new wxBoxSizer(wxHORIZONTAL);

  //hsizer -> Add(text_,wxSizerFlags(1));//.Expand());
  hsizer -> Add(text_,wxSizerFlags(1).Expand());

  sizer0 -> Add(clearButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer0 -> Add(dzielonko, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer0 -> Add(mnozonko, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

  sizer1 -> Add( wejscia[ 7 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer1 -> Add( wejscia[ 8 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer1 -> Add( wejscia[ 9 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

  sizer2 -> Add( wejscia[ 4 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer2 -> Add( wejscia[ 5 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer2 -> Add( wejscia[ 6 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

  sizer3 -> Add( wejscia[ 1 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer3 -> Add( wejscia[ 2 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer3 -> Add( wejscia[ 3 ], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

  sizer4 -> Add( wejscia[ 0 ], 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  sizer4 -> Add(kropka, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

  bar2 -> Add(minusik, 1, wxALL|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
  bar2 -> Add(plusik, 2, wxALL|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
  bar2 -> Add(rowny, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);

  vsizer -> Add(hsizer,wxSizerFlags(1).Expand());
  //vsizer -> Add(hsizer,wxSizerFlags(2));//.Expand());
  bar1 -> Add(sizer0, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  bar1 -> Add(sizer1, 1, wxALL, 5);
  bar1 -> Add(sizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  bar1 -> Add(sizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  bar1 -> Add(sizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  bar0 -> Add(bar1, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
  bar0 -> Add(bar2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
  vsizer -> Add(bar0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);

  panel -> SetSizer(vsizer);
  vsizer -> SetSizeHints(this);
}

wx30Frame::~wx30Frame() {}

void wx30Frame::OnClose(wxCloseEvent &event) {
    Destroy();
}

void wx30Frame::OnQuit(wxCommandEvent &event) {
    Destroy();
}

void wx30Frame::OnAbout( wxCommandEvent &event ) {
    wxString msg = wxbuildinfo( long_f );
    wxMessageBox( msg, _("Welcome to...") );
}

void wx30Frame::OnTimer( wxTimerEvent& ) {
    SetStatusText( wxDateTime::Now().FormatTime(), 1 );
}

