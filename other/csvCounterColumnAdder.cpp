#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    // 讀取CSV檔案
    std::ifstream inputFile("users.csv");
    if (!inputFile.is_open()) {
        std::cerr << "無法打開檔案" << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string>> data;  // 存儲CSV數據的二維向量

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> row;

        while (std::getline(ss, token, ',')) {
            row.push_back(token);
        }

        data.push_back(row);
    }

    // 關閉檔案
    inputFile.close();

    // 新增一列（column）並設置標題為 "counter"
    data[0].push_back("counter");

    // 進行計數
    for (size_t i = 1; i < data.size(); ++i) {
        data[i].push_back(std::to_string(i));
    }

    // 打印處理後的CSV數據
    for (const auto& row : data) {
        for (size_t j = 0; j < row.size(); ++j) {
            std::cout << row[j];
            if (j < row.size() - 1) {
                std::cout << "\t";
            }
        }
        std::cout << std::endl;
    }

    // 寫入CSV檔案
    std::ofstream outputFile("output.csv");
    if (!outputFile.is_open()) {
        std::cerr << "無法創建檔案" << std::endl;
        return 1;
    }

    for (const auto& row : data) {
        for (size_t j = 0; j < row.size(); ++j) {
            outputFile << row[j];
            if (j < row.size() - 1) {
                outputFile << ",";
            }
        }
        outputFile << std::endl;
    }

    // 關閉檔案
    outputFile.close();

    return 0;
}
