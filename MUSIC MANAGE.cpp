#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

struct DormRecord {
    std::string dormName;
    std::vector<int> musicChannels;
    std::vector<int> musicPerChannel;
};

void processDormRecord(const std::string& line, DormRecord& record) {
    std::istringstream iss(line);
    std::string token;
    std::getline(iss, record.dormName, ',');
    
    // Read music channels
    while (std::getline(iss, token, ',')) {
        int channel;
        std::istringstream(token) >> channel;
        record.musicChannels.push_back(channel);
    }

    // Read music per channel
    std::getline(iss, token); // Read the rest of the line
    std::istringstream perCh(token);
    int perChannel;
    while (perCh >> perChannel) {
        if (perChannel >= 1 && perChannel <= 9) { // Validate music per channel IDs
            record.musicPerChannel.push_back(perChannel);
        } else {
            std::cerr << "Error: Music per channel IDs should be between 1 and 9.\n";
            exit(1);
        }
        if (perCh.peek() == ',') {
            perCh.ignore();
        }
    }
}

int main() {
    std::ifstream inputFile("data.txt"); // Change "data.txt" to your actual file name
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    std::string line;
    std::vector<DormRecord> dormRecords;

    std::getline(inputFile, line); // Skip the header line

    while (std::getline(inputFile, line)) {
        DormRecord dorm;
        processDormRecord(line, dorm);
        dormRecords.push_back(dorm);
    }

    inputFile.close();

    // Displaying the processed data (you can modify this part as needed)
    for (const auto& dorm : dormRecords) {
        std::cout << "Dorm Name: " << dorm.dormName << "\n";
        std::cout << "Music Channels: ";
        for (int channel : dorm.musicChannels) {
            std::cout << channel << " ";
        }
        std::cout << "\nMusic per Channel: ";
        for (int perChannel : dorm.musicPerChannel) {
            std::cout << perChannel << " ";
        }
        std::cout << "\n\n";
    }

    return 0;
}
