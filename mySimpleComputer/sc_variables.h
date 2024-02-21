#ifndef SC_VAR
#define SC_VAR

enum SIZE
{
	SIZEMEM = 128
};

extern int MEM[SIZEMEM];

// Flag registers

enum FLAGS
{
    ON,
    OFF
};

// Flag registrers end

extern int ACC;
extern size_t INST_COUNTER;
extern int REG_FLAG;


#endif 