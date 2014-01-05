#include <stdio.h>
#include <lua.hpp>

#if defined(_WINDOWS) || defined(WIN32) || defined(_WIN32)
#include <windows.h>
#else
#include <linux/kernel.h>
#endif

#define MIN(x, y) min(x, y)
#define MAX(x, y) max(x, y)

#define PAI(L, n) (long)(lua_isnumber(L, n) ? luaL_checknumber((L), (n)) : 0)       //ȡ�����Ĳ���
#define PAD(L, n) (double)(lua_isnumber(L, n) ? luaL_checknumber((L), (n)) : 0.0)   //ȡ�����Ͳ���
#define PAC(L, n) (char)(lua_isnumber(L, n) ? luaL_checknumber((L), (n)) : 0)       //ȡ���ַ��Ĳ���

#define PAS(L, n) (lua_isstring(L, n) ? luaL_checkstring((L), (n)) : "")            //ȡ�ַ�������
#define PASL(L, n) (lua_isstring(L, n) ? lua_strlen(L, n) : 0)                      //ȡ�ַ����ĳ���
#define CS(f, L, n) memcpy(f, PAS(L, n), \
    MIN(sizeof(f), PASL(L, n))); f[sizeof(f) - 1] = 0      //�����ַ�������

#define PN(L, f) lua_pushnumber(L, f)
#define PINT(L, f) lua_pushinteger(L, f)
#define PS(L, f) lua_pushlstring(L, f, MIN(sizeof(f), strlen(f)))


//����û�
//@param username, age
//@return id
extern "C" int AddUser(lua_State *L)
{
    static int id = 0;
    char name[20] = {0};
    int age = 0;
    CS(name, L, 1);
    age = PAI(L, 2);
    printf("name=%s, age=%d\n", name, age);

    PINT(L, ++id);
    return 1;
}

static const luaL_reg LuaCallCFunctions [] =
{
    {"AddUser", AddUser},
    {NULL, NULL}
};

extern "C" __declspec(dllexport) int luaopen_LuaCallC(lua_State* L) 
{
    const char* libName = "LuaCallC";
    luaL_register(L, libName, LuaCallCFunctions);
    return 1;
}