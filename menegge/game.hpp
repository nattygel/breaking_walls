#pragma once

#include "level.hpp"
#include "globals.hpp"


class Game
{
public:
    void paly();

private:
    Screen* change_state(State state);
    void step_up();
    void game_over();
};