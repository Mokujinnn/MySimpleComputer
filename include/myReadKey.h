#ifndef MY_READ_KEY_H
#define MY_READ_KEY_H

enum keys
{
  // Functionals keys
  F1,
  F2,
  F3,
  F4,
  F5,
  F6,
  F7,
  F8,
  F9,
  F10,
  F11,
  F12,
  ESC,
  ENTER,

  // Numbers
  NUM0,
  NUM1,
  NUM2,
  NUM3,
  NUM4,
  NUM5,
  NUM6,
  NUM7,
  NUM8,
  NUM9,

  // Regular Keys
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K,
  L,
  M,
  N,
  O,
  P,
  Q,
  R,
  S,
  T,
  U,
  V,
  W,
  X,
  Y,
  Z,

  // Arrows
  LEFT,
  RIGHT,
  UP,
  DOWN,

  PLUS,
  MINUS,

  UNKNOWN
};

int rk_readkey (enum keys *key);
int rk_mytermsave ();
int rk_mytermrestore ();
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readvalue (int *value, int timeout);

#endif // MY_READ_KEY_H