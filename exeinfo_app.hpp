/***************************************************************
 * Name:      EXEInfoApp.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2015-04-27 - GTKmm4 30/10/23
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef EXEINFOAPP_H
#define EXEINFOAPP_H

//#include "wx/textctrl.h"

// Gtkmm-4 main header
#include "gtkmm.h"

#include "dosexeinfo.hpp"

class EXEInfoWindow: public Gtk::Window
{
    public:
        EXEInfoWindow();
        //~EXEInfoWindow();
    private:
        Gtk::Box m_VBox;
        Gtk::ScrolledWindow m_ScrolledWindow;
        Gtk::TextView m_TextView;

        Gtk::Box m_ButtonBox;
        Gtk::Button m_Button_Quit, m_Button_Open;

        Glib::RefPtr<Gtk::TextBuffer> m_textbuffer;

        mzheader m_exefileheader;
        

        void OnButtonOpenClicked();
        void OnButtonQuitClicked();
        void OnFileDialogFinished(const Glib::RefPtr<Gio::AsyncResult>& result,
                                    const Glib::RefPtr<Gtk::FileDialog>& dialog);

        void ShowExeInfo(mzheader &header);
        void LoadFile(mzheader &header, std::string const& filepath);
        void Print(Glib::ustring printstring);

};


#endif // EXEINFOMAIN_H
