// programmers1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 문제 : 스킬트리

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees);
int divisionSkillTree(string skill, vector<string>& vSkills);
int searchSkillTree(string skill, vector<string> vSkills, string strSkillTree);

int main()
{
	string strSkill;
	vector<string> vSkillsTrees;

	strSkill.clear();
	vSkillsTrees.reserve(5);

	strSkill = "CBD";

	vSkillsTrees.push_back("BACDE");
	vSkillsTrees.push_back("CBADF");
	vSkillsTrees.push_back("AECB");
	vSkillsTrees.push_back("BDA");
	vSkillsTrees.push_back("QWER");

	cout << "Result : " << solution(strSkill, vSkillsTrees) << endl;

	return 0;
}

int solution(string skill, vector<string> skill_trees)
{
	int nAnswer = 0;
	int nCount = 0;
	vector<string> vSkills;

	divisionSkillTree(skill, vSkills);

	for (int i = 0; i < vSkills.size(); i++) {
		cout << vSkills[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < skill_trees.size(); i++) {
		nCount = searchSkillTree(skill, vSkills, skill_trees[i]);
		nAnswer += nCount;
	}
	//nCount = searchSkillTree(skill, vSkills, skill_trees[2]);

	return nAnswer;
}

int divisionSkillTree(string skill, vector<string>& vSkills)
{
	int nLen = 0;
	string strTmp = "";

	nLen = skill.length();

	for (int i = 0; i < nLen; i++) {
		strTmp += skill[i];
		vSkills.push_back(strTmp);
	}

	return 0;
}

int searchSkillTree(string skill, vector<string> vSkills, string strSkillTree)
{
	int nResult = 0;
	string strSkillOrder = "";
	vector<string> vTmpSkill;
	vTmpSkill.reserve(strSkillTree.length());
	vTmpSkill.resize(strSkillTree.length());

	for (int i = 0; i < skill.length(); i++) {
		int nIdx = 0;
		string strTmp = "";
		nIdx = strSkillTree.find(skill[i]);
		strTmp = skill[i];
		if (nIdx != -1) {
			vTmpSkill[nIdx] = strTmp;
		}
	}

	for (int i = 0; i < vTmpSkill.size(); i++) {
		if (vTmpSkill[i] != "") {
			strSkillOrder += vTmpSkill[i];
		}
	}
	//cout << strSkillOrder << endl;

	if (strSkillOrder.length() == 0) {
		return 1;
	}

	for (int i = 0; i < vSkills.size(); i++) {
		if (!vSkills[i].compare(strSkillOrder)) {
			nResult = 1;
			break;
		}
	}


	return nResult;
}