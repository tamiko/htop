/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_DarwinProcess
#define HEADER_DarwinProcess
/*
htop - DarwinProcess.h
(C) 2015 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Settings.h"
#include "DarwinProcessList.h"

#include <sys/sysctl.h>

typedef struct DarwinProcess_ {
   Process super;

   uint64_t utime;
   uint64_t stime;
} DarwinProcess;


extern ProcessClass DarwinProcess_class;

DarwinProcess* DarwinProcess_new(Settings* settings);

void Process_delete(Object* cast);

bool Process_isThread(Process* this);

void DarwinProcess_setStartTime(Process *proc, struct extern_proc *ep, time_t now);

char *DarwinProcess_getCmdLine(struct kinfo_proc* k, int show_args );

void DarwinProcess_setFromKInfoProc(Process *proc, struct kinfo_proc *ps, time_t now, bool exists);

void DarwinProcess_setFromLibprocPidinfo(DarwinProcess *proc, DarwinProcessList *dpl);

#endif