#include"System.h"

int main() {
	importData();
	//-----------------------------------
	startPage();
	// Node<SchoolYear>* syCurr = latestSYear;
	// Node<Node<Course>*>* couCurr = syCurr->data.classes->data.students->data.courseScores;
	// while (couCurr) {
	// 	Node<Course>* courseAddress = couCurr->data;
	// 	std::cout << courseAddress->data.Name << std::endl;
	// 	couCurr = couCurr->next;
	// }
	//-----------------------------------
	saveData();
	deleteData();
	return 0;
}