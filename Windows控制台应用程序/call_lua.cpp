#include "stdafx.h"
int CallLua()
{
	lua_State *L = luaL_newstate();
	if (L == NULL)
	{
		return -1;
	}

	int bRet = luaL_loadfile(L, "..\\lua_files\\hello.lua");
	if (bRet)
	{
		cout << "load file error" << endl;
		return -1;
	}

	bRet = lua_pcall(L, 0, 0, 0);
	if (bRet)
	{
		cout << "pcall error" << endl;
		return -1;
	}

	lua_getglobal(L, "str");
	string str = lua_tostring(L, -1);
	cout << "str = " << str.c_str() << endl;

	lua_getglobal(L, "tb1");
	lua_getfield(L, -1, "name");
	str = lua_tostring(L, -1);
	cout << "tb1:name = " << str.c_str() << endl;

	lua_getglobal(L, "add");
	lua_pushnumber(L, 10);
	lua_pushnumber(L, 20);
	int iRet = lua_pcall(L, 2, 1, 0);
	if (iRet)
	{
		const char *pErrorMsg = lua_tostring(L, -1);
		cout << pErrorMsg << endl;
		lua_close(L);
		return -1;
	}
	if (lua_isnumber(L, -1))
	{
		double fValue = lua_tonumber(L, -1);
		cout << "Result is " << fValue << endl;
	}

	lua_close(L);
	return 0;
}