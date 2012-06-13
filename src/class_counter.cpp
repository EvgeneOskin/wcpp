#include "def_wc.h"

using namespace std;

counter::counter ()
{
  lines_amount = 0;
  words_amount = 0;
  chars_amount = 0;
}

counter::counter (const string& file_name)
{
  input_file.open (file_name.c_str(), ifstream::in);
  cout << "input file's name: " << file_name << '\n';
  if (!input_file.good())
    {
      cout << "\n\033[0,31mNOT good file name!\n\033[0m\n";
    }
  else
    {
      string secundo_line;
      while (input_file)
	{
	  getline (input_file, secundo_line);
          lines.push_back (secundo_line);
	}
      if (secundo_line.size() != 0)
	lines.pop_back();
      cout << "\033[0.32m";
      for (unsigned int i=0; i < lines.size(); i++)
	cout << lines[i] << '\n';
      cout << "\033[0m";

    }
  lines_amount = 0;
  words_amount = 0;
  chars_amount = 0;
}

counter::~counter()
{
  input_file.close();
}

unsigned int counter::line ()
{
  lines_amount = lines.size ();
  return lines_amount;
}

unsigned int counter::word ()
{
  size_t found_space, found_tab;
  unsigned int current_word_amount;
  words_amount = 0;
  for (unsigned int i = 0; i < lines.size(); i++)
    {
      found_space = -1;
      found_tab = -1;
      current_word_amount = 0;
      do
	{
	  found_space = lines[i].find (' ', found_space + 1);
	  if ((lines[i][found_space] == ' ') && (found_space != 0) && (found_space != lines[i].size() - 1)
	      && (lines[i][found_space - 1] != ' ') && (lines[i][found_space - 1] != '\t'))
	    current_word_amount++;
	}
      while (int (found_space) != -1);
      do
	{
	  found_tab = lines[i].find ('\t', found_tab + 1);
	  if ((lines[i][found_tab] == '\t') && (found_tab != 0) && (found_tab != lines[i].size() - 1)
	      && (lines[i][found_tab - 1] != ' ') && (lines[i][found_tab - 1] != '\t'))
	    current_word_amount++;
	}
      while (int (found_tab) != -1);
      if ((lines[i].size() != 0) && (current_word_amount != lines[i].size()))
	current_word_amount++;
      words_amount += current_word_amount;
      cout << words_amount << '\t' << i<< '\t'<< current_word_amount << '\n';
    }
  return words_amount;
}

unsigned int counter::symbol ()
{
  chars_amount = 0;
  for (unsigned int i = 0; i < lines.size(); i++)
    {
      chars_amount +=lines[i].size ();
    }
  chars_amount += lines.size () - 1;
  return chars_amount;
}
