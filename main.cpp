

#include <iostream>

extern "C"
{
	#include "./libs/lua5.1/lua.h"
	#include "./libs/lua5.1/lualib.h"
	#include "./libs/lua5.1/lauxlib.h"
}

class Sim {
public:
	static int Print(lua_State *L)
	{
		std::cout << "Hello World" << std::endl;
	}
};

static const struct luaL_Reg Simlib[] = {
	{"Print", Sim::Print},
	{NULL, NULL}
};


int main() {

	lua_State *L = luaL_newstate();

	luaL_openlibs(L);

	luaL_openlib(L, "TheSim", Simlib, 0);
	lua_pushvalue(L, -1);
	lua_setmetatable(L, -2);

	luaL_dofile(L, "main.lua");

	while(true){}

	lua_close(L);

}