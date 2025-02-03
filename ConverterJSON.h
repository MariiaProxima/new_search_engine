#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "json-develop/single_include/nlohmann/json.hpp"

class ConverterJSON {
public:
	ConverterJSON() = default;

	//��������� ������� ����� config.json
	void ConfigJsonExist();

	//����� ��������� ����������� ������
	std::vector<std::string> GetTextDocuments();

	//����� ��������� ���� max_responses ��� ����������� �����������
	int GetResponsesLimit() const;

	//����� ��������� �������� �� ����� requests.json
	std::vector<std::string> GetRequests();

	//�������� � ���� answers.json ���������� ��������� ��������
	void putAnswers(std::vector<std::vector<std::pair<int, float>>>
		answers);
private:
	nlohmann::json objJson;
	std::fstream fileInput;
	int responsesLimit = 5;
};
