#include <stdbool.h>
#ifndef DISPBUF_SIZE
#define DISPBUF_SIZE 128
#endif
extern struct ui_bridge{
    int dispbuf[DISPBUF_SIZE];
    bool wavemode;
} ui;