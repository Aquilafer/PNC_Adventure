#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class Game : public Gtk::Window
{
public:
	Game();
	virtual ~Game();

protected:
	void on_click();

	//members
	Gtk::Button m_button;
};
#endif
