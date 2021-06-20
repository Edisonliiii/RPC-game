#include "strategy_highest_win_rate.h"

#include <algorithm>
#include <iostream>

char const* StrategyHighestWinRate::ComplyStrategy(std::vector<std::vector<int>>& history) const
{
  double win_rate = 0;
  double round = 1;
  int r_win = 0; //r-0, p-1, s-2
  int p_win = 0;
  int s_win = 0;
  for (int i=0; i<3; ++i)
  {
    for (int j=0; j<3; ++j)
    {
      round += history[i][j];
      if (j==1)
      {
        if (i==0) r_win += history[i][j];
        else if (i==1) p_win += history[i][j];
        else if (i==2) s_win += history[i][j];
      }
    }
  }

  win_rate = std::max(std::max((double)r_win/round, (double)p_win/round), (double)s_win/round);
  if (round == 0) return "Paper";
  if (win_rate == (double)r_win/round) return "Rock";
  else if (win_rate == (double)p_win/round) return "Paper";
  else return "Scissor";
}