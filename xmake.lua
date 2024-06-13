add_requires("freeglut", "stb")

target("dengue_defenders")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")
    set_targetdir("$(projectdir)/executavel")
    add_packages("freeglut", "stb")