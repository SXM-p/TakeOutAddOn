#pragma once
#include <string>
#include <vector>
#include <filesystem>

class FileScanner {
    public:
        FileScanner(const std::string& sourceDir);

        void scan();

        std::vector<std::filesystem::path> getImages () const;
        std::vector<std::filesystem::path> getVideos () const;
        std::vector<std::filesystem::path> getJsonFiles () const;

    private:
        std::string source;
        std::vector<std::filesystem::path> images;
        std::vector<std::filesystem::path> videos;
        std::vector<std::filesystem::path> jsonFiles;
};
