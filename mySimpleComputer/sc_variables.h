#ifndef SC_VARIABLES_H
#define SC_VARIABLES_H

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


#endif // SC_VARIABLES_H