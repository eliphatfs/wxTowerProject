#ifndef GAME_IO_H
#define GAME_IO_H

extern int game_config[12];

void load_config(const char * path);
void dump_state(const char * path);
void load_state(const char * path);

#endif
