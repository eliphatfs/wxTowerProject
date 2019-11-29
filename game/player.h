#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "world.h"

struct player_t {
    int hp;
    int attack;
    int defence;
    int keynumber;
    int frame;
    int x, y;
    int hp_down(int enemy_hp, int enemy_attack, int enemy_defence);
    bool action_sword();
    bool action_shield();
    bool action_wall();
    bool action_potion();
    bool action_door();
    bool action_fightable(int enemy_hp, int enemy_attack, int enemy_defence);
    bool action_key();
    bool action(world_block_t block_type);
};
player_t& get_player();

#endif // PLAYER_H_INCLUDED
