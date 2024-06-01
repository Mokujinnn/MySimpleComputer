#include <signal.h>
#include "mySimpleComputer.h"
#include "console.h"

void IRC(int signum)
{
  int flag;
  if (signum == SIGUSR1)
  {
    sc_memoryInit();
    sc_regInit();
    sc_accumulatorInit();
    sc_icounterSet(0);
    sc_regSet(IGNORE_INTERRUPT, 1);
  }
  if (signum == SIGALRM)
  {
    sc_regGet(IGNORE_INTERRUPT, &flag);
    int tcounter;
    sc_tcounterGet(&tcounter);
    if (tcounter)
    {
      sc_tcounterSet(--tcounter);

      sc_setIgnoreCache(1);
      printFlags();
      printAccumulator();
      printCounters();
      printCommand();
      // printCache();
      sc_setIgnoreCache(0);

      if (!tcounter)
      {
        sc_regSet(IGNORE_INTERRUPT, 0);
        flag = 0;
      }
      else
      {
        sc_regSet(IGNORE_INTERRUPT, 1);
        return;
      }
    }
    if (flag)
      return;
    CU();
    sc_setIgnoreCache(1);
    printFlags();
    printAccumulator();
    printCounters();
    printCommand();
    printCache();
    sc_setIgnoreCache(0);
  }
}