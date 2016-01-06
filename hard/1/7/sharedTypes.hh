#ifndef __SHARED_TYPES_HH__
#define __SHARED_TYPES_HH__

enum marker{ None, Ecks, Oh };
typedef std::pair<unsigned int, unsigned int> Action;
//typedefs world as a 2D array of markers
typedef marker world[3][3];

#endif

