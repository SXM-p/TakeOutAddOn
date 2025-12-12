#include "FileScanner.h"

FileScanner::FileScanner(const std::string& sourceDir) : source(sourceDir) {}

void FileScanner::scan() {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(source)) {
        if (entry.is_regular_file()) {
            const auto& path = entry.path();
            const auto& ext = path.extension().string();

            if (ext == ".jpg" || ext == ".png" || ext == ".jpeg" || ext == ".bmp") {
                images.push_back(path);
            } else if (ext == ".mp4" || ext == ".avi" || ext == ".mov" || ext == ".mkv") {
                videos.push_back(path);
            } else if (ext == ".json") {
                jsonFiles.push_back(path);
            }
        }
    }
}

std::vector<std::filesystem::path> FileScanner::getImages () const {
    return images;
}

std::vector<std::filesystem::path> FileScanner::getVideos () const {
    return videos;
}

std::vector<std::filesystem::path> FileScanner::getJsonFiles () const {
    return jsonFiles;
}

