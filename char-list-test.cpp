// vi: set noet ai sts=4 sw=4 ts=8: 
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class CharList {
	private:
		class Node {
			public:
				Node() : val_(0), next_(NULL) {}
				Node(char val, Node* next) : val_(val), next_(next) {}
				void set_val(char val) { val_ = val; }
				void set_next(Node* next) { next_ = next; }
				char get_val() const { return val_; }
				Node* get_next() const { return next_; }
				bool has_next() const { return (get_next() != NULL); }
			private:
				char val_;
				Node* next_;
		};
	public:
		CharList() : head_(NULL) {}
		~CharList() { 
			Node* curNode = head_;
			while (curNode != NULL) {
				Node* tmp = curNode;
				curNode = curNode->get_next();
				delete tmp;
			}
		}

		//API that accepts the char string as an input and appends it to the 
		//CharList. Assumes str is null terminated '\0'
		bool scan(const char* str);
		char* format() const;

		//API that accepts char string pattern. It iterates through the list, check
		//if the pattern exists in the list. If yes then deletes it.
		//Return value should be 
		//true => At least one pattern is found
		//false => pattern is not found.
		//Note: Expect @pattern to be a null-terminated string.
		bool match_and_delete(const char* pattern);

	private:
		//API to push given val into the linked list; a node carrying the given
		//value is appended to the list.
		Node* push_back(char val);

		//API to get the last node in the linked list. Can be NULL for empty list.
		Node* get_last_node() const;

	private:
		Node* head_;	
};

bool
CharList::scan(const char* str) {
	if (str == NULL)
		return false;

	while (*str != 0) {
		push_back(*str);
		str++;
	}
	return true;
}

char*
CharList::format() const {
	static const uint32_t BUF_CNT=6;
	static const uint32_t MAX_STREAM_LEN=1024;
	static char buffers[BUF_CNT][MAX_STREAM_LEN];
	static uint32_t  turn = 0;

	turn = (turn + 1) % BUF_CNT;
	char* buffer = buffers[turn];

	Node* curNode = head_;
	uint32_t len = 0;
	while (curNode != NULL && (len < MAX_STREAM_LEN-1)) {
		*buffer = curNode->get_val();
		buffer++;
		len++;
		curNode = curNode->get_next();
	}
	*buffer = 0;
	return buffers[turn];
}

//API to push given val into the linked list; a node carrying the given value 
//is appended to the list.
CharList::Node*
CharList::push_back(char val) {
	if (head_ == NULL) {
		head_ = new Node(val, NULL);
		return head_;
	} else {
		Node* lastNode = get_last_node();
		Node* newNode = new Node(val, NULL);
		lastNode->set_next(newNode);
		return newNode;
	}
}

//API to get the last node in the linked list. Can be NULL for empty list.
CharList::Node*
CharList::get_last_node() const {
	if (head_ == NULL)
		return head_; 
	else {
		Node* curNode = head_;
		while (curNode->has_next()) {
			curNode = curNode->get_next();
		}
		return curNode;
	}
}

//API that accepts char string pattern. It iterates through the list, check if 
//the pattern exists in the list. If yes then deletes it.
//Return value should be 
//true => At least one pattern is found
//false => pattern is not found.
bool
CharList::match_and_delete(const char* pattern) {
	//To be implemented.
	bool bPatternExists = false;
	Node *PrevNode = head_;
	Node *firstNodeOfMatch = head_;
	Node *noMatchNode = head_;
	Node* curNode = head_;
	Node* lastNode = get_last_node();
	const char *patternHead = pattern;

	if (head_ == NULL || pattern == NULL)
		return bPatternExists;
	while (curNode != NULL) {
		if(*pattern == '\0')
		{
			if( head_ == firstNodeOfMatch)
			{
			    head_ = curNode;
			}
			noMatchNode = PrevNode;
			while(firstNodeOfMatch != curNode)
			{
			    Node *tmp = firstNodeOfMatch;
			    firstNodeOfMatch = firstNodeOfMatch->get_next();
			    delete tmp;
			}
		        if(head_ != curNode)
			    noMatchNode->set_next(curNode);
			else
			    PrevNode = curNode;
			pattern = patternHead;
			bPatternExists = true;
		}
		else if(*pattern == curNode->get_val())
		{
			pattern++;			
			if(*pattern == '\0' && curNode == lastNode)
			{
			    if(head_ == firstNodeOfMatch)
			    {
				head_ = NULL;
			    }
			    noMatchNode = PrevNode;
			    while(firstNodeOfMatch != curNode)
			    {
				Node *tmp = firstNodeOfMatch;
				firstNodeOfMatch = firstNodeOfMatch->get_next();
				delete tmp;
			    }
			    noMatchNode->set_next(NULL);
			    delete curNode;
			    pattern = patternHead;
			    bPatternExists = true;
			}
			curNode = curNode->get_next();		
		}
		else
		{
			PrevNode = firstNodeOfMatch;
			if(pattern == patternHead)
			    curNode = curNode->get_next();		
			firstNodeOfMatch = curNode;
			pattern = patternHead;
		}
	}
	return bPatternExists;
}

void test_case_1() {
	static const char* TEST_STR = "11011";
	CharList l;
	l.scan(TEST_STR);
	char* buf = l.format();
	if (strcmp(TEST_STR, buf) == 0) {
		printf ("%s == %s Test Case 1 successful \n", TEST_STR, buf);
	} else {
		printf ("%s != %s Test Case 1 failed \n", TEST_STR, buf);
	}
}

void test_case_2() {
	static const char* TEST_STR = "11011";
	static const char* PATTERN  = "110";
	static const char* RESULT   = "11";
	CharList l;
	l.scan(TEST_STR);
	bool ret = l.match_and_delete(PATTERN);
	char* buf = l.format();
	if ((strcmp(RESULT, buf) == 0) && ret) {
		printf ("%s == %s Test Case 2 successful \n", RESULT, buf);
	} else {
		printf ("%s != %s Test Case 2 failed \n", RESULT, buf);
	}
}

void test_case_3() {
	static const char* TEST_STR = "111101111";
	static const char* PATTERN  = "1011";
	static const char* RESULT   = "11111";
	CharList l;
	l.scan(TEST_STR);
	bool ret = l.match_and_delete(PATTERN);
	char* buf = l.format();
	if ((strcmp(RESULT, buf) == 0) && ret) {
		printf ("%s == %s Test Case 3 successful \n", RESULT, buf);
	} else {
		printf ("%s != %s Test Case 3 failed \n", RESULT, buf);
	}
}

void test_case_4() {
	static const char* TEST_STR = "000010000";
	static const char* PATTERN  = "0000";
	static const char* RESULT   = "1";
	CharList l;
	l.scan(TEST_STR);
	bool ret = l.match_and_delete(PATTERN);
	char* buf = l.format();
	if ((strcmp(RESULT, buf) == 0) && ret) {
		printf ("%s == %s Test Case 4 successful \n", RESULT, buf);
	} else {
		printf ("%s != %s Test Case 4 failed \n", RESULT, buf);
	}
}

void test_case_5() {
	static const char* TEST_STR = "111111111";
	static const char* PATTERN  = "111111111";
	static const char* RESULT   = "";
	CharList l;
	l.scan(TEST_STR);
	bool ret = l.match_and_delete(PATTERN);
	char* buf = l.format();
	if ((strcmp(RESULT, buf) == 0) && ret) {
		printf ("%s == %s Test Case 5 successful \n", RESULT, buf);
	} else {
		printf ("%s != %s Test Case 5 failed \n", RESULT, buf);
	}
}

void test_case_6() {
	static const char* TEST_STR = "111111111";
	static const char* PATTERN  = "0";
	static const char* RESULT   = "111111111";
	CharList l;
	l.scan(TEST_STR);
	bool ret = l.match_and_delete(PATTERN);
	char* buf = l.format();
	if ((strcmp(RESULT, buf) == 0) && !ret) {
		printf ("%s == %s Test Case 6 successful \n", RESULT, buf);
	} else {
		printf ("%s != %s Test Case 6 failed \n", RESULT, buf);
	}
}

int main() {
	test_case_1();
	test_case_2();
	test_case_3();
	test_case_4();
	test_case_5();
	test_case_6();
	return 0;
}

