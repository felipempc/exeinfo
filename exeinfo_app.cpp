/***************************************************************
 * Name:      EXEInfoMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2015-04-27
 * Copyright:  ()
 * License:
 **************************************************************/


#include "exeinfo_app.hpp"


EXEInfoWindow::EXEInfoWindow()
    : m_VBox(Gtk::Orientation::VERTICAL),
      m_Button_Quit("_Quit", true),
      m_Button_Open("_Open")
{
    set_title("EXE file info");
    set_default_size(600,600);

    m_VBox.set_margin(5);
    set_child(m_VBox);

    m_ScrolledWindow.set_child(m_TextView);
    m_ScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
    m_ScrolledWindow.set_expand();

    m_VBox.append(m_ScrolledWindow);
    m_VBox.append(m_ButtonBox);

    m_Button_Open.set_hexpand(true);
    m_Button_Open.set_halign(Gtk::Align::END);
    m_ButtonBox.append(m_Button_Open);
    m_ButtonBox.append(m_Button_Quit);
    m_ButtonBox.set_margin(5);
    m_ButtonBox.set_spacing(5);

    m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &EXEInfoWindow::OnButtonQuit));
    m_Button_Open.signal_clicked().connect(sigc::mem_fun(*this, &EXEInfoWindow::OnButtonOpen));

/*
    int sbyte = sizeof(unsigned char),
        sword = sizeof(unsigned short),
        sdword = sizeof(unsigned long);
    log_panel->AppendText(wxString::Format("Size of byte = %d\nSize of word = %d\nSize of dword = %d\n", sbyte, sword, sdword));
*/
}


void EXEInfoWindow::OnButtonQuit()
{
    unset_application();
}


void EXEInfoWindow::OnButtonOpen()
{
/*
    mzheader    fileheader;

    unsigned int filesize = 0,
                bytesread = 0;
    wxFile exefile;
    wxString caption = "Choose a file";
    wxString wildcard = "Exe files|*.exe|All files (*.*)|*.*";
    wxFileDialog dialog(this, caption, wxEmptyString, wxEmptyString, wildcard, wxFD_OPEN);

    memset(&fileheader, 0, sizeof(mzheader));

    if (dialog.ShowModal() == wxID_OK)
    {
        log_panel->AppendText("Opening :" + dialog.GetPath() + "\n");
        if (exefile.Open(dialog.GetPath()))
        {
            bytesread = exefile.Read(&fileheader, sizeof(mzheader));
            log_panel->AppendText(wxString::Format("Read = %d\n\n", bytesread));
            ShowExeInfo(fileheader);
            //filesize = static_cast<unsigned int>(exefile.Length());
            //readbuffer = filebuffer.GetWriteBuf(filesize);
        }
        else
            log_panel->AppendText("Couldn't open file.\n");
    }
*/
}



void EXEInfoWindow::ShowExeInfo(mzheader &header)
{
/*
    if (header.ID != MZSIGNATURE)
    {
        log_panel->AppendText("MZ signature not found !\n");
        return;
    }

    log_panel->AppendText(wxString::Format("ID = %.4X\n", header.ID));
    log_panel->AppendText(wxString::Format("Num bytes in last 512-bytes page = %d\n", header.nbytespage));
    log_panel->AppendText(wxString::Format("Total number of 512-byte pages = %d\n", header.totalpages));
    log_panel->AppendText(wxString::Format("Num relocation entries = %d\n", header.nrelocentries));
    log_panel->AppendText(wxString::Format("Header size (paragraphs) = %d\n", header.headersizeparagraphs));
    log_panel->AppendText(wxString::Format("Minimum paragraphs of memory = %d\n", header.minparagmem));
    log_panel->AppendText(wxString::Format("Maximum num of paragraphs = %d\n", header.maxparag));
    log_panel->AppendText(wxString::Format("Initial SS relative start = %d\n", header.initssrelstart));
    log_panel->AppendText(wxString::Format("Initial SP = %.4X\n", header.initsp));
    log_panel->AppendText(wxString::Format("Checksum = %.4X\n", header.checksum));
    log_panel->AppendText(wxString::Format("CS:SP relative to start = %.4X\n", header.csip_start));
    log_panel->AppendText(wxString::Format("Offset of reloc table = %.4X\n", header.offsetreloctable));
    log_panel->AppendText(wxString::Format("Overlay number = %d\n", header.overlaynumber));
*/
}

