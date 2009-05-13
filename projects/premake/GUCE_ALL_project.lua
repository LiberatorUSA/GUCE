
--[[---------------------------------------------------------------------------]]
--[[                                                                           ]]
--[[    Setup globals                                                          ]]
--[[                                                                           ]]
--[[---------------------------------------------------------------------------]]

gucefHome = options[ "GUCEF_HOME" ]

--[[---------------------------------------------------------------------------]]
--[[                                                                           ]]
--[[    GUCE project file generation script for premake                        ]]
--[[                                                                           ]]
--[[---------------------------------------------------------------------------]]

dofile( "functions.lua" )
project_setup( "GUCE" )

--[[---------------------------------------------------------------------------]]
--[[                                                                           ]]
--[[    Add the project files for all GUCE modules                             ]]
--[[                                                                           ]]
--[[---------------------------------------------------------------------------]]

dofile( "packages.lua" )

--[[---------------------------------------------------------------------------]]
--[[                                                                           ]]
--[[    Add the project files for all GUCEF modules                            ]]
--[[                                                                           ]]
--[[---------------------------------------------------------------------------]]

projectPath = ""

create_project_path( projectPath, "gucefMT", gucefHome )
add_package_at_location( "gucefMT", projectPath )
add_windows_library_dependency( "winmm" )

create_project_path( projectPath, "gucefCORE", gucefHome )
add_package_at_location( "gucefCORE", projectPath )
add_package_dependency( "gucefMT" )

create_project_path( projectPath, "gucefCORE_TestApp", gucefHome )
add_application_at_location( "gucefCORE_TestApp", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )

create_project_path( projectPath, "gucefCOMCORE", gucefHome )
add_package_at_location( "gucefCOMCORE", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_windows_library_dependency( "ws2_32" )

create_project_path( projectPath, "gucefCOMCORE_TestApp", gucefHome )
add_application_at_location( "gucefCOMCORE_TestApp", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_package_dependency( "gucefCOMCORE" )

create_project_path( projectPath, "gucefCOM", gucefHome )
add_package_at_location( "gucefCOM", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_package_dependency( "gucefCOMCORE" )

create_project_path( projectPath, "gucefCOM_TestApp", gucefHome )
add_application_at_location( "gucefCOM_TestApp", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_package_dependency( "gucefCOMCORE" )
add_package_dependency( "gucefCOM" )

create_project_path( projectPath, "gucefVFS", gucefHome )
add_package_at_location( "gucefVFS", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )

create_project_path( projectPath, "gucefVFS_TestApp", gucefHome )
add_application_at_location( "gucefVFS_TestApp", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_package_dependency( "gucefVFS" )

create_project_path( projectPath, "gucefCORE", gucefHome )
add_package_at_location( "gucefIMAGE", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )

create_project_path( projectPath, "gucefIMAGE_TestApp", gucefHome )
add_application_at_location( "gucefIMAGE_TestApp", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_package_dependency( "gucefIMAGE" )

create_project_path( projectPath, "gucefINPUT", gucefHome )
add_package_at_location( "gucefINPUT", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )

create_project_path( projectPath, "gucefPATCHER", gucefHome )
add_package_at_location( "gucefPATCHER", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_package_dependency( "gucefVFS" )
add_package_dependency( "gucefCOMCORE" )
add_package_dependency( "gucefCOM" )

create_project_path( projectPath, "gucefDRN", gucefHome )
add_package_at_location( "gucefDRN", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_package_dependency( "gucefCOMCORE" )

create_project_path( projectPath, "gucefDRN_TestApp", gucefHome )
add_application_at_location( "gucefDRN_TestApp", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )
add_package_dependency( "gucefCOMCORE" )
add_package_dependency( "gucefDRN" )

create_project_path( projectPath, "gucefGUI", gucefHome )
add_package_at_location( "gucefGUI", projectPath )
add_package_dependency( "gucefMT" )
add_package_dependency( "gucefCORE" )

