#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <mutex>
#include <thread>
#include <sstream>

struct Entry {
	size_t doc_id, count;

	//�������� ��� ���������� �������� ���������
	bool operator ==(const Entry& other) const {
		return (doc_id == other.doc_id &&
			count == other.count);
	}
};
class InvertedIndex {
public:
	InvertedIndex() = default;

	//�������� ��� ��������� ���� ����������, �� ������� ����� ���������
	void UpdateDocumentBase(std::vector<std::string> input_docs);

	//������ � ������� �� ��������� � ��� ���������� �����
	void PutFreqDictionary(std::string input_words, int i);

	//��������� �������
	std::map<std::string, std::vector<Entry>> GetFreqDictionary();

	//����� ���������� ���������� ��������� ����� word � ����������� ���� ����������
	std::vector<Entry> GetWordCount(const std::string& word);
private:
	std::vector<std::string> docs; // ������ ����������� ����������
	std::map<std::string, std::vector<Entry>> freq_dictionary; // ��������� �������
};
