#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include "draw_image.hpp"

class Game : public Gtk::Window
{
public:
	Game();
	virtual ~Game();

protected:
	void on_click();

	//members
	Gtk::Box m_Vbox;
	Gtk::Button m_button;

	//vars
	DrawImage disp;
};
#endif
