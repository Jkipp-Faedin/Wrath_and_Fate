#include <ncurses.h>

void erase (int y, int x)
{
  mvaddch(y, x, '#');
}

void game_loop(char main_char, int row, int col, int ch)
{
  mvaddch(row,col,main_char);
  refresh();
  while(1)
  {
    ch = getch();
    if(ch == 'a')
    {
      erase(row, col);
      col--;
      mvaddch(row,col,main_char);
      refresh();
    }
    else if(ch == 'd')
    {
      erase(row, col);
      col++;
      mvaddch(row, col, main_char);
      refresh();
    }
    else if(ch == 'w')
    {
      erase(row, col);
      row--;
      mvaddch(row, col, main_char);
      refresh();
    }else if(ch == 's')
    {
      erase(row, col);
      row++;
      mvaddch(row, col, main_char);
      refresh();
    }
    else if(ch == 'e' || ch == 'E')
    {
      clear();
      printw("This is a basic \"game\"\nMove with WASD, quit with q, shake with e");
      mvaddch(row, col, main_char);
    }
    else if(ch == 'q' || ch == 'Q')
    {
      break;
    }
  }
}

int main()
{
  int row = 10, col = 10;
  char main_char = '@';
//Ini ncurses
  initscr();
  noecho();
//print the thing!
  printw("This is a basic \"game\"\nMove with WASD, quit with q, shake with e");
  int ch = getch();
  game_loop(main_char, row, col, ch);
  endwin();
  return 0;
}
