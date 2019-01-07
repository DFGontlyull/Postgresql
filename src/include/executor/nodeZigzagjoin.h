#ifndef NODEZIGZAGJOIN_H
#define NODEZIGZAGJOIN_H

#include "nodes/execnodes.h"

extern ZigZagJoinState *ExecInitZigzagJoin(ZigzagJoin *node, EState *estate, int eflags);
extern void ExecEndZigzagJoin(ZigzagJoinState *node);
extern void ExecReScanZigzagJoin(ZigzagJoinState *node);

#endif	