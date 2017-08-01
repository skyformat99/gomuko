#ifndef _Color_
#define _Color_

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
