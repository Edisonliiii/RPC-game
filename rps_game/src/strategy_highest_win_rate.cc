#include "strategy_highest_win_rate.h"

#include <algorithm>

char const* StrategyHighestWinRate::ComplyStrategy(std::vector<std::vector<int>>& history) const
{
  double win_rate = 0;
  double round = 0;
  double r_win = 0; //r-0, p-1, s-2
  double p_win = 0;
  double s_win = 0;
  for (int i=0; i<3; ++i)
  {
    for (int j=0; j<3; ++j)
    {
      round += history[i][j];
      if (j==1)
      {
        if (i==0) ++r_win;
        else if (i==1) ++p_win;
        else if (i==2) ++s_win;
      }
    }
  }

  win_rate = std::max(std::max(r_win/round, p_win/round), s_win/round);
  if (win_rate == r_win/round) return "Rock";
  else if (win_rate == p_win/round) return "Paper";
  else return "Scissor";
}