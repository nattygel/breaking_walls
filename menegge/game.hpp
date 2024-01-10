#pragma once

#include "level.hpp"
#include "globals.hpp"


class Game
{
public:
    void play();
    int get_step();
    void step_up();

private:
    Screen* change_state(State state);
    void game_over();
    int m_step = 1;
};