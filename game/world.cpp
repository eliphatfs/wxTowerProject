#include "world.h"
#include <iostream>
using namespace std;

static world_block_t world_map[1000][1000];
world_block_t get_world_block(int x, int y) {
    if (x < 0 || x >= 1000 || y < 0 || y >= 1000) cout << "out of space in get_world_block" << endl;
    return world_map[x][y];
}
void set_world_block(int x, int y, world_block_t block) {
    if (x < 0 || x >= 1000 || y < 0 || y >= 1000) cout << "out of space in set_world_block" << endl;
    world_map[x][y] = block;
}
