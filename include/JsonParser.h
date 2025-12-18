#pragma once
#include <string>
#include <filesystem>
#include <optional>


class JsonParser {
public:
    struct Metadata {
        std::string title;
        std::string description;
        std::string creationTime;
        std::string cameraMake;
        std::string cameraModel;
        std::string photoTakenTime;
    };

    static std::optional<Metadata> parse(const std::filesystem::path& jsonPath);
};