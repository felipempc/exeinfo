/***************************************************************
 * Name:      exeinfo_main.cpp
 * Purpose:   Application start
 * Author:     () Felipe mpc
 * Created:   2015-04-27 - Translated to Gtkmm4 30/10/2023
 * Copyright:  (C)
 * License: 
 **************************************************************/


// Gtkmm4 header
#include <gtkmm/application.h>

#include "exeinfo_app.hpp"


int main(int argc, char** argv)
{
        auto app = Gtk::Application::create("exeinfo_application");
        
        return app->make_window_and_run<EXEInfoWindow>(argc, argv);
}
