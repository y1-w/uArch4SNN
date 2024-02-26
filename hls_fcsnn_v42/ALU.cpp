#include "ALU.h"

int ALU(int argument1, int argument2, int flag)
{
    int ret;
    switch (flag)
    {
    case 0:
        ret = argument1 + argument2;
        break;

    case 1:
        ret = argument1 * argument2;
        break;

    case 2:
        ret = argument1 << argument2;
        break;

    case 3:
        ret = argument1 % argument2;
        break;
    }
    return ret;
}
