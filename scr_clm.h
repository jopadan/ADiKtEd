/*
 * scr_clm.h header file for scr_clm.c
 */

#ifndef ADIKT_SCRCLM_H
#define ADIKT_SCRCLM_H

struct LEVEL;
struct SCRMODE_DATA;
struct MAPMODE_DATA;
struct WORKMODE_DATA;

//Functions - init and free
short init_mdclm(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata);
void free_mdclm(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata);

//Functions - start and stop
short start_mdclm(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata);
void end_mdclm(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata);

//Functions - actions and screen
void actions_mdclm(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata,int key);
void draw_mdclm(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata);
void draw_mdclm_panel(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata);

// Single actions
void action_update_all_datclm(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata);
void action_delele_custclm_and_update(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata);

//Functions - lower level
int display_dat_subtiles(struct SCRMODE_DATA *scrmode,struct WORKMODE_DATA *workdata,
    int scr_row, int scr_col,short compressed,int ty,int tx);
int display_column(unsigned char *clmentry,int clm_idx, int scr_row, int scr_col);

//Functions - internal

#endif // ADIKT_SCRCLM_H
