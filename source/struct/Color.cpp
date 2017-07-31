#ifndef _COLOR_
#define _COLOR_

enum Color
{
    BLACK,
    WHITE,
    VOID
};

static enum Color getOtherColor(enum Color color)
{
    if (color == BLACK)
        return WHITE;
    if (color == WHITE)
        return BLACK;
    return VOID;
}

#endif
