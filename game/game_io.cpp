#include "world.h"
#include "player.h"
#include <fstream>
#include <iostream>
using namespace std;

int game_config[12];

void dump_state(const char * path) {
    ofstream file(path, ios::binary);
    player_t plr = get_player();
    file.write((char *)&plr, sizeof(plr));
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            world_block_t block = get_world_block(i, j);
            file.write((char *)&block, sizeof(world_block_t));
        }
    }
}

void load_config(const char * path) {
    ifstream file(path);
    for (int i = 0; i < 12; i++)
        file >> game_config[i];
}

void load_state(const char * path) {
    ifstream file(path, ios::binary);
    if (file.fail())
        return;
    player_t& plr = get_player();
    file.read((char *)&plr, sizeof(plr));
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            world_block_t block;
            file.read((char *)&block, sizeof(world_block_t));
            set_world_block(i, j, block);
        }
    }
}
