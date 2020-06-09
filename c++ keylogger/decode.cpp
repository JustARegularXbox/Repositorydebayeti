 /*
  This is Iancu's work
  It cost, ... everything
                         */
#include <fstream>
#include <windows.h>
#include <ctype.h>
#include <map>

using namespace std;

void createMap(map<unsigned short, pair<unsigned short, unsigned short>> &shift) {
  ifstream in("shift_keys.txt");

  unsigned short val;
  char ch_1, ch_2;
  while (in >> val >> ch_1 >> ch_2)
    shift[val] = make_pair(ch_1, ch_2);

  in.close();
}

int main() {
  map<unsigned short, pair <unsigned short, unsigned short>> shift;
  createMap(shift);

  ifstream in("ascii");
  ofstream out("text");

  unsigned short ch;
  bool shiftState, capsState = false;
  while (in >> ch >> shiftState) {
    switch (ch) {
    case VK_TAB:
      out << "        ";
      break;
    case VK_CONTROL:
      out << "\nCONTROL KEY\n";
      break;
    case VK_SPACE:
      out << " ";
      break;
    case VK_RETURN:
      out << "\n";
      break;
    case VK_LBUTTON:
      out << "\nLEFT MOUSE CLICK\n";
      break;
    case VK_RBUTTON:
      out << "\nRIGHT MOUSE CLICK\n";
      break;
    case VK_ESCAPE:
      out << "\nESCAPE\n";
      break;
    case VK_UP:
      out << "\nUP ARROW KEY\n";
      break;
    case VK_DOWN:
      out << "\nDOWN ARROW KEY\n";
      break;
    case VK_BACK:
      int pos;
      pos = out.tellp();
      out.seekp(pos - 1);
      out << ' ';
      out.seekp(pos - 1);
      break;
    case VK_CAPITAL:
      capsState = !capsState;
      break;
    default:
      if (isalpha(ch))
        if (shiftState + capsState == 1)
          out << char(ch);
        else
          out << char(ch + 32);
      else
        try {
          if (shiftState)
            out << char(shift[ch].second);
          else
            out << char(shift[ch].first);
        }
        catch(...) {
          out << char(ch);
        }
      break;
    }
  }

  in.close();
  out.close();
  return 0;
}
