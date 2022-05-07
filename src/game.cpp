#include "game.hpp"
#include <iostream>

namespace PIC
{
	const char* p1 = "./media/room_1.png";
	const char* p2 = "./media/room_2.png";
	const char* p2m = "./media/room_2m.png";
	const char* p3 = "./media/room_3.png";
}

Game::Game() :
	m_button("CLICK ME"),
	disp(PIC::p1)
{
	set_border_width(10);
	set_default_size(820, 1000);

	add(m_Vbox);
	m_button.signal_clicked().connect(sigc::mem_fun(*this, &Game::on_click));
	//add(m_button);

	m_Vbox.pack_start(disp, Gtk::PACK_SHRINK);
	show_all_children();
	//m_button.show();
}

Game::~Game()
{
}

void Game::on_click()
{
	std::cout << "Hello there!\n";
}
