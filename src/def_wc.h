#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class counter
{
 public:
  std::ifstream input_file;
  unsigned int lines_amount;
  unsigned int words_amount;
  unsigned int chars_amount;
  unsigned int line ();
  unsigned int word ();
  unsigned int symbol ();
  counter ();
  counter (const std::string& file_name);
  ~counter ();
 private:
  std::vector<std::string> lines;
};
