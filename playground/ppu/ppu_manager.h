
#ifndef __PPU_MANAGER_H_
#define __PPU_MANAGER_H_

#include <libspe2.h>
#include <pthread.h>
#include <stdio.h>
#include <string>
#include <vector>

struct ppu_pthread_data
{
	spe_context_ptr_t speid;
	pthread_t pthread;
	void * argp;
};

class ppu_manager 
{
private:
	int usable_spes;
	int physical_spes;
	int physical_cpu_nodes;

	std::string spu_program;
public:
	ppu_manager(bool debug = false);
	~ppu_manager();
	
	int spe_count();

	void spe_program(const std::string& filename);
	void spe_run(int count);

	void info();
};

#endif
