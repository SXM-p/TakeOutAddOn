#include "JsonParser.h"
#include "json.hpp"
#include <fstream>

std::optional<JsonParser::Metadata> JsonParser::parse(const std::filesystem::path& jsonPath) {
    try {
        // Read the JSON file
        std::ifstream file(jsonPath);
        if (!file.is_open()) {
            return std::nullopt;
        }

        nlohmann::json jsonData;
        file >> jsonData;

        Metadata metadata;
        metadata.title = jsonData.value("title", "");
        metadata.description = jsonData.value("description", "");
        metadata.creationTime = jsonData.value("creationTime", "");
        metadata.cameraMake = jsonData.value("cameraMake", "");
        metadata.cameraModel = jsonData.value("cameraModel", "");
        metadata.photoTakenTime = jsonData.value("photoTakenTime", "");

        return metadata;
    } catch (const std::exception& e) {
        // Handle parsing errors or file read errors
        return std::nullopt;
    }
}