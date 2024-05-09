#pragma once

namespace EasyLogger {

	class EasyLogger {
	public:
		
		EasyLogger() = delete;
		static void SetupEasyLogger();
		static void Log(const char* log);
		
	};
}