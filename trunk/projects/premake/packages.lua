add_package("guceCORE")
add_library_dependency("gucefMT")
add_library_dependency("gucefCORE")

add_package("guceGUI")
add_package_dependency("guceCORE")
add_library_dependency("gucefMT")
add_library_dependency("gucefCORE")

add_package("guidriverCEGUIOgre")
add_package_dependency("guceGUI")
add_package_dependency("guceCORE")