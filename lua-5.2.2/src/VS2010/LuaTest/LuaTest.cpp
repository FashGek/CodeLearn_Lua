// LuaTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int _tmain(int argc, _TCHAR* argv[])
{
	lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    int res =  luaL_dostring(L, "print('test'); return 3;");
    int iRes = lua_tointeger(L, -1);
	//luaL_openlibs(L);

 //   const char *buf = "local len = 10000; local tab = {};"
 //       "for i = 1, len do"
 //       "   tab[i] = 'str' .. i;"
 //       "   print(tab[i]);"
 //       "end";
	//luaL_dostring(L,buf);
	//
 //   double const *v = lua_version(L);
 //   printf("%f\n", *v);           ''
    std::cout << "res=" << res << ",iRes=" << iRes << std::endl;
	lua_close(L);
    int i;
    std::cin >> i;

	return 0;
}