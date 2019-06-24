function os.winSdkVersion()
    local reg_arch = iif( os.is64bit(), "\\Wow6432Node\\", "\\" )
    local sdk_version = os.getWindowsRegistry( "HKLM:SOFTWARE" .. reg_arch .."Microsoft\\Microsoft SDKs\\Windows\\v10.0\\ProductVersion" )
    if sdk_version ~= nil then return sdk_version end
end
-- To update windows SDK(s)

workspace "Ember"
	configurations {"Debug32", "Release32", "Debug64", "Release64"}
	filter {"system:windows", "action:vs*"}
    systemversion(os.winSdkVersion() .. ".0")

   filter "configurations:*32"
      architecture "x86"

   filter "configurations:*64"
      architecture "x86_64"
	  
	filter "configurations:Debug32"
		defines {"Debug32"}
		
	filter "configurations:Debug64"
		defines {"Debug64"}
		
	filter "configurations:Release32"
		defines {"Release32"}
		
	filter "configurations:Release64"
		defines {"Release64"}
		
project "Ember"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"
	includedirs {"Ember/src/include"}
	files {"Ember/src/**.cpp", "Ember/src/**.h", "Ember/src/**.c", "Ember/src/**.hpp"}
	
project "cd"
	kind "ConsoleApp"
	targetdir "bin/Commands/%{cfg.buildcfg}"
	includedirs {"Ember/Commands/include"}
	files {"Ember/Commands/**.cpp", "Ember/Commands/**.h", "Ember/Commands/**.c", "Ember/Commands/**.hpp"}