
#include <iostream>
#include <vector>
#include <string>

#include "ppu_manager.h"
#include "benchmark.h"

enum App { Success = 1, Error = 0 };

const std::string Name = "Coursework";
const std::string SpuProgram = "./spu/spu";

typedef std::pair<std::string, int> spu_pair;
typedef std::vector<spu_pair> spu_programs;

int main(int argc, char * argv[])
{
	ppu_manager ppu_manager(true);
	benchmark track(Name);

	const int spe_count = ppu_manager.spe_count();

	spu_programs programs;
	programs.push_back(spu_pair(SpuProgram, spe_count));
	programs.push_back(spu_pair(SpuProgram, spe_count));

	const int processes = programs.size();
	
	for(int i = 0; i < processes; ++i)
	{
		ppu_manager.spe_program(programs[i].first);
		ppu_manager.spe_run(programs[i].second);
	}
	
	return Success;
}
