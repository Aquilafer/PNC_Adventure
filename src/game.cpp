#include "game.hpp"
#include <iostream>

Game::Game() : m_button("CLICK ME")
{
	set_border_width(10);
	set_default_size(1000, 1000);

	m_button.signal_clicked().connect(sigc::mem_fun(*this, &Game::on_click));
	add(m_button);
	m_button.show();
}

Game::~Game()
{
}

void Game::on_click()
{
	std::cout << "Hello there!\n";
}
