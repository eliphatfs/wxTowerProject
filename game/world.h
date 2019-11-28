#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

enum world_block_t {
    wall=1, space, door, key, skeleton, witch, boss, sword, shield, potion
};

world_block_t get_world_block(int x, int y);
void set_world_block(int x, int y, world_block_t block);

#endif // WORLD_H_INCLUDED
