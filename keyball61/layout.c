#include "layout.h"

enum {
    R0 = 4,
    R1 = 5,
    R2 = 6,
    R3 = 7,
    R4 = 8,

    C0 = 29,
    C1 = 28,
    C2 = 27,
    C3 = 26,
};

const uint8_t layout_matrix[][2] = {
    {R0,C0},{R0,C1},{R0,C2},{C0,R0},{C1,R0},{C2,R0},
    {R1,C0},{R1,C1},{R1,C2},{C0,R1},{C1,R1},{C2,R1},
    {R2,C0},{R2,C1},{R2,C2},{C0,R2},{C1,R2},{C2,R2},
    {R3,C0},{R3,C1},{R3,C2},{C0,R3},{C1,R3},{C2,R3},{C3,R3},
    {R4,C0},{R4,C1},                        {C2,R4},{C3,R4},
};

const size_t LAYOUT_MATRIX_MAX = count_of(layout_matrix);
