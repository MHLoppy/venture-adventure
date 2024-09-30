#ifndef _GAME
#define _GAME

#include "splashkit.h"
#include "player.h"
#include "boxes.h"
#include "gems.h"
#include "enemy.h"
#include <vector>

#define SCREEN_WIDTH  512
#define SCREEN_HEIGHT 512
#define TILESIZE 32
#define BOX   300 // boxes are indicated with '300' on the map 
#define GEM   400 // gems are indicated with '400' on the map
#define ENEMY 200 // enemies are indicated with '200' on the map 

struct game_data
{
    vector<vector<int> > map_array;
    player_data player;
    vector<box_data> boxes;
    vector<gem_data> gems;
    vector<enemy_data> enemies;
    bitmap map;
    int gemCount;
    int lives;
    bool gameover;
    bool lifelost = false;
    int index[64];
    point_2d map_loc;
    vector<point_2d> solid;
};

game_data new_game(string map);

vector<vector<int> > new_level(string file);

void get_objects(game_data &game);

bool update_game(game_data &game, int level_id, int lives);

void draw_game(const game_data &game);

void add_box(game_data &game, int x , int y);

void add_gem(game_data &game, int x, int y);

void add_enemy(game_data &game, int x, int y);

void remove_gem(game_data &game, int i);

// Unused - original author was accidentally using std::swap without realizing
// void swap(int &value1, int &value2);

void handle_input(game_data &game);

void moving(game_data &game);

void box_collision(game_data &game);

void box_wall_collision(game_data &game);

void box_box_collision(game_data &game);

void box_gem_collision(game_data &game);

void box_start_collision(game_data &game);

void gem_collision(game_data &game);

void enemy_collision(game_data &game);

void enemy_move(game_data &game);

void update_enemy_position(game_data &game);

void update_box_position(game_data &game);

bool level_clear(game_data &game);

bool check_gameover(game_data &game);

int check_lives(game_data game);

void attack(game_data &game);

void start_screen();

void win_screen();

void credits();

void draw_hud(game_data &game, int level_id);

vector<string> get_verbose_debugging_message(const game_data &game);

#endif
