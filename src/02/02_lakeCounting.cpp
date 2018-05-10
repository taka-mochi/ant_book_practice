#include <iostream>
#include <vector>
#include <stack>
#include <string>

int lake_counting(std::vector<std::string> &lake_map)
{
  int ROWS = lake_map.size();
  int COLS = lake_map[0].size();
  std::vector<std::vector<int> > visited_flags(lake_map.size());
  for (size_t i=0; i<lake_map.size(); i++) {
	visited_flags[i] = std::vector<int>(lake_map[i].size());
	std::fill(visited_flags[i].begin(), visited_flags[i].end(), 0);
  }

  int lake_count = 0;
  std::vector<std::pair<int,int> > check_coords;

  for (int row = 0; row<ROWS; row++) {
	for (int col = 0; col<COLS; col++) {
	  if (visited_flags[row][col]) continue;

	  if (lake_map[row][col] == '.') {
		// not water
		visited_flags[row][col] = 1;
		continue;
	  }

	  auto make_coord = [](int r, int c){return std::pair<int,int>(r,c);};

	  // water found!
	  lake_count++;
	  check_coords.push_back(make_coord(row, col));

	  while (!check_coords.empty()) {
		auto pos = check_coords[check_coords.size()-1];
		check_coords.resize(check_coords.size()-1);
		int check_row = pos.first;
		int check_col = pos.second;

		// check invalid coord
		if (check_row < 0 || check_row >= ROWS || check_col < 0 || check_col >= COLS) continue;

		if (visited_flags[check_row][check_col]) {
		  // already visited
		  continue;
		}

		if (lake_map[check_row][check_col] == 'W') {
		  // water found! check 8 around
		  check_coords.push_back(make_coord(check_row-1, check_col-1));
		  check_coords.push_back(make_coord(check_row-1, check_col+0));
		  check_coords.push_back(make_coord(check_row-1, check_col+1));
		  check_coords.push_back(make_coord(check_row+0, check_col-1));
		  check_coords.push_back(make_coord(check_row+0, check_col+1));
		  check_coords.push_back(make_coord(check_row+1, check_col-1));
		  check_coords.push_back(make_coord(check_row+1, check_col+0));
		  check_coords.push_back(make_coord(check_row+1, check_col+1));
		}

		visited_flags[check_row][check_col] = 1;
		
	  }
	  
	}
  }

  return lake_count;
}

int main()
{
  std::vector<std::string> lake1;
  lake1.push_back("W........WW.");
  lake1.push_back(".WWW.....WWW");
  lake1.push_back("W...WW...WW.");
  lake1.push_back(".........WW.");
  lake1.push_back(".........W..");
  lake1.push_back("..W......W..");
  lake1.push_back(".W.W.....WW.");
  lake1.push_back("W.W.W.....W.");
  lake1.push_back(".W.W......W.");
  lake1.push_back("..W.......W.");


  std::cout << lake_counting(lake1) << std::endl;

  return 0;
}
