local imgui = {
	name = "",
	location = ""
}

function imgui:setup()
	self.name = common:projectName()
	self.location = common:projectLocation()

	kind("StaticLib")
	common:staticLibOutDirs()

	includedirs({ "%{prj.location}/" })

	files({
		self.location .. "/imgui.h",
		self.location .. "/imgui.cpp",
		self.location .. "/imgui_draw.cpp",
		self.location .. "/imgui_internal.h",
		self.location .. "/imgui_tables.cpp",
		self.location .. "/imgui_widgets.cpp",
		self.location .. "/imstb_rectpack.h",
		self.location .. "/imstb_textedit.h",
		self.location .. "/imstb_truetype.h"
	})
end

function imgui:setupDep()
	links({ self.name })
	sysincludedirs({ self.location })
end

return imgui
