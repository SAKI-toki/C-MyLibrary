#include "Main.h"
void App();
int main()
{
	//メモリリークを検知する
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	_CrtDumpMemoryLeaks();
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	//_CrtSetBreakAlloc(153);
#endif
	App();

	system("pause");
	return 0;

}
///////////////////////////////////////////////

//ここに処理を記入
void App()
{

}