#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    // Ū��CSV�ɮ�
    std::ifstream inputFile("users.csv");
    if (!inputFile.is_open()) {
        std::cerr << "�L�k���}�ɮ�" << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string>> data;  // �s�xCSV�ƾڪ��G���V�q

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

    // �����ɮ�
    inputFile.close();

    // �s�W�@�C�]column�^�ó]�m���D�� "counter"
    data[0].push_back("counter");

    // �i��p��
    for (size_t i = 1; i < data.size(); ++i) {
        data[i].push_back(std::to_string(i));
    }

    // ���L�B�z�᪺CSV�ƾ�
    for (const auto& row : data) {
        for (size_t j = 0; j < row.size(); ++j) {
            std::cout << row[j];
            if (j < row.size() - 1) {
                std::cout << "\t";
            }
        }
        std::cout << std::endl;
    }

    // �g�JCSV�ɮ�
    std::ofstream outputFile("output.csv");
    if (!outputFile.is_open()) {
        std::cerr << "�L�k�Ы��ɮ�" << std::endl;
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

    // �����ɮ�
    outputFile.close();

    return 0;
}
