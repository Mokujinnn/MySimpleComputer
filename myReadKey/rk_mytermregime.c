#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int
rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
{
  struct termios term;

  if (tcgetattr (STDIN_FILENO, &term) != 0)
    {
      return -1;
    }

  if (regime == 0)
    {
      term.c_lflag &= ~ICANON;
      term.c_cc[VTIME] = vtime;
      term.c_cc[VMIN] = vmin;
    }
  else
    {
      term.c_lflag |= ICANON;
    }

  term.c_lflag = (echo == 0) ? term.c_lflag & ~ECHO : term.c_lflag | ECHO;

  term.c_lflag = (sigint == 0) ? term.c_lflag & ~ISIG : term.c_lflag | ISIG;

  tcsetattr (STDIN_FILENO, TCSANOW, &term);
  return 0;
}