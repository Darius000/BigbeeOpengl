workspace "BigbeeOpengl"
	architecture "x86"
	configurations {"Debug", "Release", "Dist"}
	

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "BHive"
	location "BHive"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
	
	pchheader "pch.h"
	pchsource "BHive/Src/pch.cpp"
	
	includedirs 
	{
		 "%{prj.name}/vendor/Include", 
		 "%{prj.name}/Src", 
		 "%{prj.name}/Src/DataTypes"
	 }
	
	libdirs {"%{prj.name}/vendor/Lib"}	
	
	links
	{
		"OpenGL32" ,
		"assimp-vc140-mt", 
		"glfw3"
	}

	files 
	{
		"%{prj.name}/Src/**.h", 
		"%{prj.name}/Src/**.cpp", 
		"%{prj.name}/Src/**.c", 
		"%{prj.name}/Shaders/**",
		"%{prj.name}/vendor/Include/IMGUI/**.h", 
		"%{prj.name}/vendor/Include/IMGUI/**.cpp"
	}

	--[[vpaths 
	{ 
		["Headers/*"] = {"**.h"},
		["Sources/*"] = {"**.c","**.cpp"}
	}]]---
	
	filter {"files:BHive/vendor/Include/IMGUI/**.cpp"}
		flags{'NoPCH'}

	filter {"files:**.c"}
		flags{'NoPCH'}
		
	filter "system:windows"
		cppdialect "C++17"
		--[[staticruntime  "On"--]]
		systemversion "10.0.17763.0"
		
		defines
		{
			"BHIVE_WINDOWS",
			"BH_BUILD_DLL"
		}
		
		--[[postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Test")
		}--]]
			
		filter "configurations:Debug"
			defines {"BH_DEBUG"}
			symbols "On"
			
		filter "configurations:Release"
			defines {"BH_RELEASE"}
			symbols "On"
			optimize "On"
			
		filter "configurations:Dist"
			defines {"BH_Dist"}
			optimize "On"
		
--[[project "Test"
	location "Test"
	kind "ConsoleApp"
	language "C++"
		
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/Src/**.h", 
		"%{prj.name}/Src/**.cpp"
	}
	
	includedirs
	{
		"ThirdParty/Include",
		"BHive/Src",
		"BHive/Src/DataTypes"
	}
	
	links
	{
		"BHive"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime  "On"
		systemversion "10.0.17134.0"
		
		defines
		{
			"BHIVE_WINDOWS"
		}
		
		filter "configurations:Debug"
			defines {"BH_DEBUG"}
			symbols "On"
			
		filter "configurations:Release"
			defines {"BH_RELEASE"}
			symbols "On"
			optimize "On"
			
		filter "configurations:Dist"
			defines {"BH_Dist"}
			optimize "On"--]]
	
	
	