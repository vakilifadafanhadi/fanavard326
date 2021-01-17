/*
autor: hadi vakili fadafan
subject: fanavard
*/
///region libs
#include <iostream>
using namespace std;
///endregion libs
void main(){
	//number 4 objects = asize
	//number 4 boxes = boxsize
	//array 4 size of objects = a
	//array 4 boxes = box
	const int maxSize = 100;
	size_t boxsize, asize, kSize;
	int a[maxSize], box[maxSize] = { 0 }, bestres[2] = { 0, 0 };
	int ans = 0, j = 0;
	cout << "1:boxes no.(m)" << endl << "Please enter number of boxes: ";
	cin >> boxsize;


	cout << "*************************************" << endl << "2:boxes size(k)" << endl << "Please enter size of boxes: ";//????????skiping words???????
	cin >> kSize;
	//get objects
	cout << "*************************************" << endl << "3:objects no.(n)" << endl << "Please enter number of objects: ";
	cin >> asize;
	cout << "*************************************" << endl << "4:objects size(a(n))" << endl;//????????skiping words???????
	for (int i = 0; i < asize; i++){
		cout << "Please enter size of object no. " << i + 1 << ": ";
		cin >> a[i];
		while (a[i] > kSize){
			cout << "#error: object size can`t be larger than box size." << endl << "box size is: " << kSize << endl;
			cout << "Please enter size of object no. " << i + 1 << ": ";
			cin >> a[i];
		}
	}
	///endregion get params
	///region drawing problem details
	cout << "*************************************" << endl << "* number of boxes = " << boxsize << endl << "* size of boxes = " << kSize << endl << "this is your objects:" << endl;
	for (int i = 0; i < asize; i++){
		cout << "a" << i + 1 << " = " << a[i];
		if (i != asize - 1)
			cout << ", ";
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
	for (int i = j; i < asize; i++){
		int sumObjects = 0;
		for (int c = j; c < asize; c++)
			sumObjects += a[c];
		if (sumObjects > kSize * boxsize)
			j++;
		else
			break;
	}
	int boxIndex = 0;
	int index = j;
	int res[maxSize] = { 0 };
	for (int myindex = j; myindex < asize; myindex++, j++){
		int sumres = 0;
		//int index = j;
		//for (int i = 0; i < boxsize; i++)
			//box[i] = 0;
		for (int i = boxIndex; i < boxsize; i++){
			for (int l = index; l < asize; l++, index++){
				if (a[l] + box[i] <= kSize){
					box[i] += a[index];
					res[i]++;
				}
				else {
					boxIndex = i;
					break;
				}
			}
		}
		for (int i = 0; i < boxsize; i++)
			sumres += res[i];
		if (bestres[0] < sumres && sumres + j == asize){
			bestres[0] = sumres;
			bestres[1] = myindex;
			break;
		}
		else{
			for (int i = 0; i < boxsize; i++){
				box[i] = box[i + 1];
				res[i] = res[i + 1];
			}
			box[boxsize - 1] = 0;
		}
	}
	
	cout << endl << "*************************************" << endl << "best result is : " << bestres[0] << endl << "j index is : " << bestres[1] << endl;
	for (int i = 0; i < boxsize; i++){
		cout << "box" << i + 1 << " = " << a[i];
		if (i != boxsize - 1)
			cout << ", ";
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
	cout << endl << "enter any key to exit";
	int ok;
	cin >> ok;
}