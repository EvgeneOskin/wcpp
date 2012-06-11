#include "def_wc.h"

using namespace std;


int main (int argc, char* argv[])
{
  if (argc == 2)
    {
      string file_name(argv[1]);
      counter WC_counter (file_name);
      cout << "line:" << WC_counter.line() << "\n";
      cout << "word:" << WC_counter.word() << "\n";
      cout << "symbol:" << WC_counter.symbol() << "\n";
    }
  else
    cout << "Type the one file name after wcpp\n";
  return 0;
}
