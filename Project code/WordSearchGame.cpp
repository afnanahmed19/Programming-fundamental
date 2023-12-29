#include<iostream>
#include<fstream>
using namespace std;
char* words(int size);
int* dynamic_mem(int size);
char difficuly();
char choices();
void menu();
void board_data(ifstream&fin, char** board, int row, int col);
void check_size(ifstream&fin, int&row, int&col);
char** memory(int row, int col);
void print_board(char** arr, int row, int col);
bool check_word(char* arr);
bool row_wise(char** arr, char* arr2, int row, int col);
bool colom_wise(char** arr, char* arr2, int row, int col);
bool r_row_wise(char** arr, char* arr2, int row, int col);
bool r_col_wise(char** arr, char* arr2, int row, int col);
void check_high_s(int score, int* highscore);
void highscores(int* arr);
bool diognal_wise(char** arr, char* arr2, int row, int col);
bool r_diognal_wise(char** arr, char* arr2, int row, int col);
int main(){
	int* highscore = dynamic_mem(5);
	highscores(highscore);
	cout << "\t\t  -----------------------------" << endl;
	cout << "\t\t  Welcome to word search puzzle" << endl;
	cout << "\t\t  -----------------------------" << endl;
	char* player_name = words(15);
	cout << "Enter a player name:";
	cin.getline(player_name, 15);
	cout << player_name << endl;

	//filing part
	ifstream boarddata("board.txt");
	ifstream dictionary("dictionary.txt");
	int row = 0;
	int col = 0;
	check_size(boarddata, row, col);
	char** board = memory(row, col);
	boarddata.open("board.txt");
	board_data(boarddata, board, row, col);
	boarddata.close();
	int score = 0;
	char level = '\0';
	char choice = '\0';
	//easy
	level = difficuly();
	while (level != 'e' || level != 'e' || level != 'h' || level != 'H' || level != 'm' || level != 'M'){

		if (level == 'e' || level == 'E'){
			int e_chance = 3;
			while (level == 'e' || level == 'E'){

				for (int i = e_chance; i > 0; --i){
					print_board(board, row, col);
					char* word = words(10);
					cout << "Enter word:";
					cin >> word;
					bool present = check_word(word);
					if (present == true){
						bool rowpresent = row_wise(board, word, row, col);
						bool colpresent = colom_wise(board, word, row, col);
						if (rowpresent == true || colpresent == true){
							cout << "\t\tCongratulations you have guess the word" << endl;
							++score;
							cout << "\t\t----------------------------------------" << endl;
							cout << "\t\tTo show menu press m or any key to continue:";
							char mn;
							cin >> mn;
							if (mn == 'm'){
								menu();
								char choice = choices();
								if (choice == 'n' || choice == 'N'){
									score = 0;
									break;
								}
								if (choice == 'r' || choice == 'R'){
									cout << "\t\t  --------------------------" << endl;
									cout << "\t\t  Your game is in pause mode" << endl;
									cout << "\t\t  --------------------------" << endl;
									while (choice == 'r' || choice == 'R'){
										ofstream pause("pausedgame.txt");
										for (int i = 0; i < row; ++i){
											for (int j = 0; j < col; ++j){
												pause << board[i][j];
											}
											pause << endl;
										}
										pause << "your score=" << score << endl;
										menu();
										cout << "For Reload the game press s:" << endl;
										cin >> choice;
										if (choice == 's' || 'S'){
											break;
										}
									}
								}
								if (choice == 'l' || choice == 'L'){
									level = difficuly();
									break;
								}
								if (choice == 'h' || choice == 'H'){
									check_high_s(score, highscore);
									cout << "You score=" << score << endl;
									cout << "High score of the game:";
									for (int i = 0; i < 5; ++i){
										cout << highscore[i] << " ";
									}
									cout << endl;
									ofstream fout("highscore.txt");
									for (int i = 0; i < 5; ++i){
										fout << highscore[i] << " ";
									}


								}
								if (choice == 'e' || choice == 'E'){
									check_high_s(score, highscore);
									cout << "your total score=" << score << endl;
									cout << "Thanks for playing" << endl;
									ofstream fout("highscore.txt");
									for (int i = 0; i < 5; ++i){
										fout << highscore[i] << " ";
									}
									system("pause");
									return 0;
								}
							}
							break;
						}
					}
					cout << "You have " << e_chance - 1 << " chance left" << endl;

					--e_chance;
					if (e_chance == 0){
						cout << "You attempted your maximum tries" << endl;
						cout << "Your Score=" << score << endl;
						delete[]board;
						board = NULL;
						delete[]highscore;
						highscore = NULL;
						delete[]player_name;
						player_name = NULL;
						system("pause");
						return 0;
						break;
					}
				}

			}
		}
		/*Medium part
		strt from her*/

		if (level == 'm' || level == 'M'){
			int m_chance = 2;
			cout << "This is medium" << endl;
			while (level == 'm' || level == 'M'){


				for (int i = m_chance; i >= 0; --i){
					print_board(board, row, col);
					char* word = words(10);
					cout << "Enter word:";
					cin >> word;
					bool present = check_word(word);
					if (present == true){
						bool rev_rowpresent = r_row_wise(board, word, row, col);
						bool rev_colpresent = r_col_wise(board, word, row, col);
						bool rowpresent = row_wise(board, word, row, col);
						bool colpresent = colom_wise(board, word, row, col);

						if (rev_rowpresent == true || rev_colpresent == true){
							cout << "\t\tCongratulations you have guess the word" << endl;
							++score;
							cout << "\t\t----------------------------------------" << endl;
							cout << "\t\tTo show menu press m or any key to continue:";
							char mn;
							cin >> mn;
							if (mn == 'm'){
								menu();
								char choice = choices();
								if (choice == 'n' || choice == 'N'){
									score = 0;
									break;
								}
								if (choice == 'r' || choice == 'R'){
									cout << "\t\t  --------------------------" << endl;
									cout << "\t\t  Your game is in pause mode" << endl;
									cout << "\t\t  --------------------------" << endl;
									while (choice == 'r' || choice == 'R'){
										ofstream pause("pausedgame.txt");
										for (int i = 0; i < row; ++i){
											for (int j = 0; j < col; ++j){
												pause << board[i][j];
											}
											pause << endl;
										}
										pause << "your score=" << score << endl;
										menu();
										cout << "For Reload the game press s:" << endl;
										cin >> choice;
										if (choice == 's' || 'S'){
											break;
										}
									}
								}
								if (choice == 'l' || choice == 'L'){
									level = difficuly();
									break;
								}
								if (choice == 'h' || choice == 'H'){
									check_high_s(score, highscore);

									cout << "You score=" << score << endl;
									cout << "High score of the game:";
									for (int i = 0; i < 5; ++i){
										cout << highscore[i] << " ";
									}
									cout << endl;
									ofstream fout("highscore.txt");
									for (int i = 0; i < 5; ++i){
										fout << highscore[i] << " ";
									}


								}
								if (choice == 'e' || choice == 'E'){
									check_high_s(score, highscore);
									cout << "your total score=" << score << endl;
									cout << "Thanks for playing" << endl;
									ofstream fout("highscore.txt");
									for (int i = 0; i < 5; ++i){
										fout << highscore[i] << " ";
									}
									delete[]board;
									board = NULL;
									delete[]highscore;
									highscore = NULL;
									delete[]player_name;
									player_name = NULL;
									system("pause");
									return 0;
								}
							}
							break;
						}
					}
					cout << "You have " << m_chance - 1 << " chance left" << endl;
					--m_chance;
					if (m_chance == 0){
						cout << "You attempted your maximum tries" << endl;
						cout << "Your Score=" << score << endl;
						delete[]board;
						board = NULL;
						delete[]highscore;
						highscore = NULL;
						delete[]player_name;
						player_name = NULL;
						system("pause");
						return 0;
						break;
					}
				}

			}
		}
		//hard
		if (level == 'h' || level == 'H'){
			int h_chance = 1;
			cout << "This is Hard" << endl;
			cout << "You have only one chance here" << endl;
			while (level == 'h' || level == 'H'){


				for (int i = h_chance; i >= 0; --i){
					print_board(board, row, col);
					char* word = words(10);
					cout << "Enter word:";
					cin >> word;
					bool present = check_word(word);
					if (present == true){

						bool diagonalpresent = diognal_wise(board, word, row, col);
						bool r_diagonalpresent = r_diognal_wise(board, word, row, col);
						if ((diagonalpresent == true) || (r_diagonalpresent == true)){

							cout << "\t\tCongratulations you have guess the word" << endl;
							++score;
							cout << "\t\t----------------------------------------" << endl;
							cout << "\t\tTo show menu press m or any key to continue:";
							char mn;
							cin >> mn;
							if (mn == 'm'){
								menu();
								char choice = choices();
								if (choice == 'n' || choice == 'N'){
									score = 0;
									break;
								}
								if (choice == 'r' || choice == 'R'){
									cout << "\t\t  --------------------------" << endl;
									cout << "\t\t  Your game is in pause mode" << endl;
									cout << "\t\t  --------------------------" << endl;
									while (choice == 'r' || choice == 'R'){
										ofstream pause("pausedgame.txt");
										for (int i = 0; i < row; ++i){
											for (int j = 0; j < col; ++j){
												pause << board[i][j];
											}
											pause << endl;
										}
										pause << "your score=" << score << endl;
										menu();
										cout << "For Reload the game press s:" << endl;
										cin >> choice;
										if (choice == 's' || 'S'){
											break;
										}
									}
								}
								if (choice == 'l' || choice == 'L'){
									level = difficuly();
									break;
								}
								if (choice == 'h' || choice == 'H'){
									check_high_s(score, highscore);

									cout << "You score=" << score << endl;
									cout << "High score of the game:";
									for (int i = 0; i < 5; ++i){
										cout << highscore[i] << " ";
									}
									cout << endl;
									ofstream fout("highscore.txt");
									for (int i = 0; i < 5; ++i){
										fout << highscore[i] << " ";
									}


								}
								if (choice == 'e' || choice == 'E'){
									check_high_s(score, highscore);
									cout << "your total score=" << score << endl;
									cout << "Thanks for playing" << endl;
									ofstream fout("highscore.txt");
									for (int i = 0; i < 5; ++i){
										fout << highscore[i] << " ";
									}
									delete[]board;
									board = NULL;
									delete[]highscore;
									highscore = NULL;
									delete[]player_name;
									player_name = NULL;
									system("pause");
									return 0;
								}
							}

							break;
						}

						//checking


					}
					cout << "You have " << h_chance - 1 << " chance left" << endl;
					--h_chance;
					if (h_chance == 0){
						cout << "You attempted your maximum tries" << endl;
						cout << "Your Score=" << score << endl;
						delete[]board;
						board = NULL;
						delete[]highscore;
						highscore = NULL;
						delete[]player_name;
						player_name = NULL;
						system("pause");
						return 0;
						break;
					}
				}

			}
		}

	}
	delete[]board;
	board = NULL;
	delete[]highscore;
	highscore = NULL;
	delete[]player_name;
	player_name = NULL;
	system("pause");
	return 0;
}
// functions part
bool diognal_wise(char** arr, char* arr2, int row, int col){
	int arr2_count = 0;

	for (int i = 0; arr2[i] != '\0'; ++i){
		++arr2_count;
	}

	int startingcol = 0;
	int endingcol = 0;
	int startingrow = 0;
	int endingrow = 0;
	for (int i = 0; i < row; ++i){


		for (int j = 0; j < col; ++j){
			int k = j;
			int l = i;
			startingcol = k;
			startingrow = l;
			int word_count = 0;
			for (int m = 0; m < arr2_count; ++m){
				if (arr[l][k] == arr2[m]){
					++word_count;
				}
				endingcol = k;
				endingrow = l;
				++l;
				++k;
			}
			if (arr2_count == word_count){

				cout << "\t\t" << arr2 << endl;
				cout << "\t\tStarting at row " << startingrow << " and col " << startingcol << endl;
				cout << "\t\tEnding at row " << endingrow << " and col " << endingcol << endl;

				return true;
			}
		}
	}
	return false;
}
bool r_diognal_wise(char** arr, char* arr2, int row, int col){
	int arr2_count = 0;

	for (int i = 0; arr2[i] != '\0'; ++i){
		++arr2_count;
	}
	// reverse diagonal
	char* new_arr = new char[arr2_count + 1];
	int p = arr2_count - 1;
	for (int i = 0; arr2[i] != '\0'; ++i){
		new_arr[p] = arr2[i];
		--p;
	}
	new_arr[arr2_count] = '\0';

	int startingcol = 0;
	int endingcol = 0;
	int startingrow = 0;
	int endingrow = 0;
	for (int i = row - 1; i >= 0; --i){


		for (int j = col - 1; j >= 0; --j){
			int k = j;
			int l = i;
			startingcol = k;
			startingrow = l;
			int word_count = 0;
			for (int m = 0; m < arr2_count; ++m){
				if (arr[l][k] == new_arr[m]){
					++word_count;
				}
				endingcol = k;
				endingrow = l;
				--l;
				--k;
			}
			if (arr2_count == word_count){
				int s = endingcol;
				for (int i = endingrow; i <startingrow; ++i){
					arr[i][s] == 'X';
					s++;
				}
				cout << "\t\t" << arr2 << endl;
				cout << "\t\tStarting at row " << startingrow << " and col " << startingcol << endl;
				cout << "\t\tEnding at row " << endingrow << " and col " << endingcol << endl;
				delete[]new_arr;
				new_arr = NULL;
				return true;
			}
		}
	}
	delete[]new_arr;
	new_arr = NULL;
	return false;
}
void check_high_s(int score, int* highscore){
	int temp;
	for (int i = 0; i < 4; ++i){
		if (score > highscore[i]){
			temp = highscore[i + 1];
			highscore[i + 1] = highscore[i];
			highscore[i] = score;
			score = temp;
		}
	}
}
void highscores(int* highscore){
	ifstream fin("highscore.txt");
	int i = 0;
	while (!fin.eof()){
		fin >> highscore[i];
		++i;
	}
}

bool r_col_wise(char** arr, char* arr2, int row, int col){
	int arr2_count = 0;
	int count2 = 0;
	for (int i = 0; arr2[i] != '\0'; ++i){
		++arr2_count;
	}
	//to reverse the word
	char* new_arr = new char[arr2_count + 1];
	int p = arr2_count - 1;
	for (int i = 0; arr2[i] != '\0'; ++i){
		new_arr[p] = arr2[i];
		--p;
	}
	new_arr[arr2_count] = '\0';
	int startingcol = 0;
	int endingcol = 0;
	int startingrow = 0;
	int endingrow = 0;
	for (int i = row - 1; i >= 0; --i){
		startingcol = i;
		for (int j = col - 1; j >= arr2_count - 1; --j){
			int count2 = 0;
			int l = j;
			startingrow = l;
			for (int k = 0; new_arr[k] != '\0'; ++k){

				if (new_arr[k] == arr[l][i]){
					++count2;
				}
				--l;

			}
			if (arr2_count == count2){

				cout << "\t\tReverse colom wise word " << new_arr << endl;
				endingcol = startingcol;
				endingrow = (startingrow - count2) + 1;
				/*for (int i = startingrow; i >= endingrow; --i){
				arr[i][startingcol] = 'X';
				}*/
				cout << "\t\tstart at row " << startingrow << " and colom " << startingcol << endl;
				cout << "\t\tEnd at row " << endingrow << " and colom " << endingcol << endl;
				delete[]new_arr;
				new_arr = NULL;
				return true;
			}

		}

	}
	delete[]new_arr;
	new_arr = NULL;

	return false;
}
bool r_row_wise(char** arr, char* arr2, int row, int col){
	int arr2_count = 0;
	int count2 = 0;

	for (int i = 0; arr2[i] != '\0'; ++i){
		++arr2_count;
	}
	//To reverse the word 
	char* new_arr = new char[arr2_count + 1];
	int j = arr2_count - 1;
	for (int i = 0; arr2[i] != '\0'; ++i){
		new_arr[j] = arr2[i];
		--j;
	}
	new_arr[arr2_count] = '\0';
	for (int i = 0; new_arr[i] != '\0'; ++i)
	{
		cout << new_arr[i] << " ";
	}
	cout << endl;
	int endingcol = 0;
	int endingrow = 0;
	for (int i = row - 1; i >= 0; --i){
		int startingrow = i;
		for (int j = col - 1; j >= 0; --j){
			int count2 = 0;
			int l = j;
			int startingcol = j;
			for (int k = 0; new_arr[k] != '\0'; ++k){

				if (new_arr[k] == arr[i][l]){
					++count2;
				}
				--l;
			}

			if (arr2_count == count2){
				cout << "\t\tReverse row wise word " << new_arr << endl;
				endingcol = (startingcol - arr2_count) + 1;
				endingrow = startingrow;
				cout << "\t\tStart at row " << startingrow << " and col " << startingcol << endl;
				cout << "\t\tEnd at row " << endingrow << " and col " << endingcol << endl;
				delete[]new_arr;
				new_arr = NULL;
				return true;
			}
		}
	}
	delete[]new_arr;
	new_arr = NULL;
	return false;
}
bool colom_wise(char** arr, char* arr2, int row, int col){
	int arr2_count = 0;
	int count2 = 0;
	for (int i = 0; arr2[i] != '\0'; ++i){
		++arr2_count;
	}
	int startingcol = 0;
	int endingcol = 0;
	int startingrow = 0;
	int endingrow = 0;
	for (int i = 0; i < row; ++i){
		startingcol = i;
		for (int j = 0; j <= col - arr2_count; ++j){
			int count2 = 0;
			int l = j;
			startingrow = l;
			for (int k = 0; arr2[k] != '\0'; ++k){

				if (arr2[k] == arr[l][i]){
					++count2;
				}
				++l;

			}
			if (arr2_count == count2){
				cout << "\t\tForword colom wise word " << arr2 << endl;
				endingcol = startingcol;
				endingrow = (startingrow + count2) - 1;
				for (int i = startingrow; i <= endingrow; ++i){
					arr[i][startingcol] = 'X';
				}
				cout << "\t\tstart at row " << startingrow << " and colom " << startingcol << endl;
				cout << "\t\tEnd at row " << endingrow << " and colom " << endingcol << endl;
				return true;
			}
		}
	}
	return false;
}
// check the rows and cols of matrix
void check_size(ifstream&fin, int&row, int&col){
	char* arr = words(30);

	fin.getline(arr, 30);
	++row;
	for (int i = 0; arr[i] != '\0'; ++i){
		++col;
	}

	while (1){
		fin.getline(arr, 30);
		++row;
		if (fin.eof()){
			break;
		}

	}
	fin.close();
	delete[]arr;
	arr = NULL;
}
bool row_wise(char** arr, char* arr2, int row, int col){
	int arr2_count = 0;
	int count2 = 0;
	for (int i = 0; arr2[i] != '\0'; ++i){
		++arr2_count;
	}
	int endingcol = 0;
	int endingrow = 0;
	for (int i = 0; i < row; ++i){
		int startingrow = i;
		for (int j = 0; j < col; ++j){
			int startingcol = j;
			int count2 = 0;
			int l = j;

			for (int k = 0; arr2[k] != '\0'; ++k){

				if (arr2[k] == arr[i][l]){
					++count2;
				}
				++l;
			}
			if (arr2_count == count2){
				cout << "\t\tForword row wise word " << arr2 << endl;
				endingcol = (startingcol + arr2_count) - 1;
				endingrow = startingrow;
				for (int i = startingcol; i <= endingcol; ++i){
					arr[startingrow][i] = 'X';
				}
				cout << "\t\tStart at row " << startingrow << " and col " << startingcol << endl;
				cout << "\t\tEnd at row " << endingrow << " and col " << endingcol << endl;
				return true;
			}
		}
	}
	return false;
}
bool check_word(char* arr){
	ifstream fin;
	fin.open("dictionary.txt");
	char* dic = words(13);
	int word_count = 0;

	while (!fin.eof()){
		int dic_count = 0;
		fin >> dic;
		for (int i = 0; dic[i] != '\0'; ++i){
			++dic_count;
		}

		word_count = 0;
		for (int i = 0; i<dic_count; ++i){
			if (dic[i] == arr[i]){
				++word_count;
			}
		}
		if (dic_count == word_count){
			fin.close();
			delete[]dic;
			dic = NULL;
			return true;
		}
	}
	fin.close();
	return false;
}
char** memory(int row, int col){
	char** arr = new char*[row];
	for (int i = 0; i < row; ++i){
		arr[i] = new char[col];
	}
	return arr;
}
void print_board(char** arr, int row, int col){

	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void board_data(ifstream&fin, char** board, int row, int col){

	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			fin >> board[i][j];
		}
	}
}
char difficuly(){
	char choice;
	cout << "E or e for easy" << endl;
	cout << "M or m for medium" << endl;
	cout << "H or h for hard" << endl;
	cout << "Enter Your difficuly level:";
	cin >> choice;
	while (!(choice == 'e' || choice == 'E' || choice == 'M' || choice == 'm' || choice == 'H' || choice == 'h')){
		cout << "Invalid---->" << endl;
		cout << "Enter Your difficuly level:";
		cin >> choice;
	}
	return choice;
}
void menu(){
	cout << "Press n for new game" << endl;
	cout << "Press r for pause game" << endl;
	cout << "Press l for level selection" << endl;
	cout << "ress h for high score" << endl;
	cout << "Press e for exit" << endl;
}
char choices(){
	char choice;
	cout << "Enter your choice:";
	cin >> choice;
	while (!(choice == 'r' || choice == 'R' || choice == 'n' || choice == 'N' || choice == 'L' || choice == 'l' || choice == 'h' || choice == 'H' || choice == 'E' || choice == 'e')){
		cout << "Invalid---->" << endl;
		cout << "Enter your  correct choice:";
		cin >> choice;
	}
	return choice;
}
char* words(int size){
	char* arr = NULL;
	arr = new char[size];
	return arr;
}
int* dynamic_mem(int size){
	int* arr = NULL;
	arr = new int[size];
	return arr;
}