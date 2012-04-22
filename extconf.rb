# Make makefile
require 'mkmf'

dir_config("Dynamixel_Header_and_Library_Dir")
have_header("dynamixel.h")
have_library("dynamixel", "main")

extension_name = "Dynamixel"
create_makefile(extension_name)

