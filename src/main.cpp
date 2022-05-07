#include <iostream>
#include "game.hpp"
#include <gtkmm/application.h>

int main(int argc, char* argv[]) {
    std::printf("It works?\n");
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Game central;
    
    return app->run(central);
}
