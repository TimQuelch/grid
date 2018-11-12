from conans import ConanFile, CMake

class gridConan(ConanFile):
    name = "grid"
    version = "0.1.0"
    author = "Tim Quelch"
    requires = ("fmt/5.2.1@bincrafters/stable",
                "catch2/2.4.1@bincrafters/stable")
    generators = ("cmake_paths")
    exports_sources = ("*", "!build/*")

    def _cmake_configure(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def build(self):
        cmake = self._cmake_configure()
        cmake.build()

    def package(self):
        cmake = self._cmake_configure()
        cmake.install()
