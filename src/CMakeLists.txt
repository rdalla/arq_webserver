# Warning! This code was automatically generated for projects
# without default 'CMakeLists.txt' file.

set(app_sources
	"boardconfig.c"
	"leds.c"
	"main.c"
	"server.c"
)

idf_component_register(SRCS ${app_sources})
