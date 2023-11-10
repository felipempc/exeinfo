/***************************************************************
 * Name:      EXEInfoApp.cpp
 * Purpose:   Code for Application window
 * Author:     ()
 * Created:   2015-04-27
 * Copyright:  ()
 * License:
 **************************************************************/


#include "exeinfo_app.hpp"
#include <iostream>
#include <fstream>


EXEInfoWindow::EXEInfoWindow()
    : m_VBox(Gtk::Orientation::VERTICAL),
      m_Button_Quit("_Quit", true),
      m_Button_Open("_Open", true)
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

    m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &EXEInfoWindow::OnButtonQuitClicked));
    m_Button_Open.signal_clicked().connect(sigc::mem_fun(*this, &EXEInfoWindow::OnButtonOpenClicked));


    m_textbuffer = m_TextView.get_buffer();
}


void EXEInfoWindow::OnButtonQuitClicked()
{
    close();
}


void EXEInfoWindow::OnButtonOpenClicked()
{
  auto dialog = Gtk::FileDialog::create();
  dialog->set_title("Escolha o arquivo executável");

  auto filters = Gio::ListStore<Gtk::FileFilter>::create();

  auto filter_exe = Gtk::FileFilter::create();
  filter_exe->set_name("EXE files");
  filter_exe->add_pattern("*.exe");
  filters->append(filter_exe);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  filters->append(filter_any);

  dialog->set_filters(filters);
  dialog->set_default_filter(filter_exe);

  // Show the dialog and wait for a user response:
  dialog->open(sigc::bind(sigc::mem_fun(*this, &EXEInfoWindow::OnFileDialogFinished), dialog));

}


void EXEInfoWindow::OnFileDialogFinished(const Glib::RefPtr<Gio::AsyncResult>& result, const Glib::RefPtr<Gtk::FileDialog>& dialog)
{
  try
  {
    auto file = dialog->open_finish(result);

    // Notice that this is a std::string, not a Glib::ustring.
    auto filename = file->get_path();
    std::cout << "File selected: " <<  filename << std::endl;
    LoadFile(m_exefileheader, filename);
    ShowExeInfo(m_exefileheader);
  }
  catch (const Gtk::DialogError& err)
  {
    // Can be thrown by dialog->open_finish(result).
    std::cout << "No file selected. " << err.what() << std::endl;
  }
  catch (const Glib::Error& err)
  {
    std::cout << "Unexpected exception. " << err.what() << std::endl;
  }
}


void EXEInfoWindow::ShowExeInfo(mzheader &header)
{
    if (header.ID != MZSIGNATURE)
    {
        Print("MZ signature not found !\n");
        return;
    }


    Print(Glib::ustring::compose("ID = %1\n", Glib::ustring::format(std::hex, header.ID)));
    Print(Glib::ustring::compose("Num bytes in last 512-bytes page = %1\n", header.nbytespage));
    Print(Glib::ustring::compose("Total number of 512-byte pages = %1\n", header.totalpages));
    Print(Glib::ustring::compose("Num relocation entries = %1\n", header.nrelocentries));
    Print(Glib::ustring::compose("Header size (paragraphs) = %1\n", header.headersizeparagraphs));
    Print(Glib::ustring::compose("Minimum paragraphs of memory = %1\n", header.minparagmem));
    Print(Glib::ustring::compose("Maximum num of paragraphs = %1\n", header.maxparag));
    Print(Glib::ustring::compose("Initial SS relative start = %1\n", header.initssrelstart));
    Print(Glib::ustring::compose("Initial SP = %1\n", header.initsp));
    Print(Glib::ustring::compose("Checksum = %1\n", header.checksum));
    Print(Glib::ustring::compose("CS:SP relative to start = %1\n", header.csip_start));
    Print(Glib::ustring::compose("Offset of reloc table = %1\n", header.offsetreloctable));
    Print(Glib::ustring::compose("Overlay number = %1\n", header.overlaynumber));
}



void EXEInfoWindow::LoadFile(mzheader &header, std::string const &filepath)
{
    std::ifstream ifs(filepath, std::ios::binary|std::ios::ate);

    if(!ifs)
        throw std::runtime_error(filepath + ": "/* + std::strerror(errno)*/);

    auto end = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    auto size = std::size_t(end - ifs.tellg());

    Print(Glib::ustring::compose("Size of file = %1.\n", size));

    if(size == 0)
        return;

    ifs.seekg(0);
    if(!ifs.read((char*) &header, sizeof(mzheader)))
        throw std::runtime_error(filepath + ": "/* + std::strerror(errno)*/);
    Print("File read!\n");
}


/** Print a string on textbuffer */
void EXEInfoWindow::Print(Glib::ustring printstring)
{
  m_textbuffer->insert_interactive_at_cursor(printstring);
}
