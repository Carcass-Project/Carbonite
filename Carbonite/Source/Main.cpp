#include "PCH.h"

#include "Carbonite.h"
#include "Log.h"
#include "Utils/Core.h"

#include <cstdlib>

#include <stdexcept>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
#if CARBONITE_IS_CONFIG_DIST
	try
	{
#endif
		auto& carbonite = Carbonite::Get(); // Get carbonite instance
		carbonite.init();                   // Initialize carbonite
		carbonite.run();                    // Run carbonite
		carbonite.deinit();                 // Deinitialize carbonite
		Carbonite::Destroy();               // Destroy carbonite instance
#if CARBONITE_IS_CONFIG_DIST
	}
	catch (const std::exception& e)
	{
		Log::critical(e.what());
		return EXIT_FAILURE;
	}
#endif
	return EXIT_SUCCESS;
}

#if _WIN32
#undef APIENTRY
#include <Windows.h>

int WinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance, [[maybe_unused]] _In_ LPSTR lpCmdLine, [[maybe_unused]] _In_ int nShowCmd)
{
	return main(__argc, __argv);
}
#endif
