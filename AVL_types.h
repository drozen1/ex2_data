//
// Created by Dor on 01/05/2020.
//

#ifndef EX1_DATASTRUCK_AVL_TYPES_H
#define EX1_DATASTRUCK_AVL_TYPES_H

namespace AVLUtils{


    typedef enum {
        SUCCESS = 0,
        FAILURE = -1,
        ALLOCATION_ERROR = -2,
        INVALID_INPUT = -3
    } StatusType;

    typedef enum {
        RR = 0,
        RL = 1,
        LL = 2,
        LR = 3,
        No_Roll_Needed = 4
    } Roll2_Perform;

    typedef enum {
        LEFT = 0,
        RIGHT = 1,
    } TypeOfSon;

}
#endif //EX1_DATASTRUCK_AVL_TYPES_H
