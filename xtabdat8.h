/*
 * xtabdat8.h   define exported routines from xtabdat8.c
 */

#ifndef BULL_XTABDAT8_H
#define BULL_XTABDAT8_H

// Data types

struct TABFILE_ITEM {
    unsigned long offset;
    unsigned int width;
    unsigned int height;
       };

struct TABFILE {
    long count;
    unsigned long filelength;
    struct TABFILE_ITEM *items;
       };

struct DATFILE {
    long count;
    unsigned long filelength;
    unsigned char *data;
       };

struct IMAGEITEM {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
    unsigned char *alpha;
       };

struct IMAGELIST {
    unsigned long count;
    struct IMAGEITEM *items;
       };

// Routines

int read_tabfile_data(struct TABFILE *tabf,char *srcfname);
int free_tabfile_data(struct TABFILE *tabf);
int read_datfile_data(struct DATFILE *datf,char *srcfname);
int free_datfile_data(struct DATFILE *datf);
int read_dattab_images(struct IMAGELIST *images,unsigned long *readcount,struct TABFILE *tabf,struct DATFILE *datf,int verbose);
int free_dattab_images(struct IMAGELIST *images);
int read_dat_image_idx(struct IMAGEITEM *image,unsigned long *readedsize,struct DATFILE *datf,unsigned long off,unsigned int width,unsigned int height);

int create_images_dattab_idx(struct IMAGELIST *images,char *datfname,char *tabfname,int verbose);

// Error returns

#define XTABDAT8_COLOUR_LEAK 2
#define XTABDAT8_ENDOFBUFFER 4
#define XTABDAT8_NOMEMORY 8


#endif
