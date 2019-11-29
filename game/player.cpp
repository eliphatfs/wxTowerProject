#include "player.h"

static player_t player;
player_t& get_player() {
    return player;
}
int player_t::hp_down(int enemy_hp, int enemy_attack, int enemy_defence) {
    int health;
    if(attack <= enemy_defence) return 0;
    else {
        if(enemy_attack <= defence) return hp;
        else health = hp - enemy_hp / (attack - enemy_defence) * (enemy_attack - defence);
    }
    if(health <= 0) return 0;
    else return health;
}
bool player_t::action_sword() {
    attack += 5;
    return true;
}
bool player_t::action_shield() {
    defence += 5;
    return true;
}
bool player_t::action_wall() {
    return false;
}
bool player_t::action_potion() {
    hp += 100;
    return true;
}
bool player_t::action_door() {
    if(keynumber == 0) return false;
    else {
        keynumber -= 1;
        return true;
    }
}
bool player_t::action_key() {
    keynumber += 1;
    return true;
}
bool player_t::action_fightable(int enemy_hp, int enemy_attack, int enemy_defence) {
    if(hp_down(enemy_hp, enemy_attack, enemy_defence) == 0) return false;
    else{
        hp = player_t::hp_down(enemy_hp, enemy_attack, enemy_defence);
        return true;
    }
}
