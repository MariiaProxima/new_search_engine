#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "InvertedIndex.h"

struct RelativeIndex {
	size_t doc_id;
	float rank;
	bool operator ==(const RelativeIndex& other) const {
		return (doc_id == other.doc_id && rank == other.rank);
	}
};
class SearchServer {
public:
	/*� ����������� ������ ��������� ������ �� �����
	InvertedIndex, ����� SearchServer ��� ������ ������� ���� �����������
	� �������
	*/
	SearchServer(InvertedIndex& idx) : _index(idx) { };

	//������ � ����� ��������, ��� ������� � ������������ ����������� ������� �� ����
	void Request(const std::string& request, int i, int limits);

	/* ����� ��������� ��������� �������� ���������� ��������������� ������
	����������� ������� ��� �������� ��������
	*/
	std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input, int limit);
private:
	InvertedIndex _index;
	std::vector<std::vector<RelativeIndex>> search_result;
};
