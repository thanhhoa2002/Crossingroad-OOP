#include "CGAME.h"

condition_variable cv;
mutex lock1;
void menu();

//Các hằng số và biến toàn cục cần thiết
char MOVING;
CGAME* cg;
bool IS_RUNNING = true;
bool IS_PAUSE = false;
bool MUTED = false;
int LEVEL;

void SubThread()
{
	while (IS_RUNNING)
	{
		GotoXY(WIDTH_CONSOLE + 2, 12);
		cout << " LEVEL: " << LEVEL << " / 3";
		//Nếu người vẫn còn sống
		if (!cg->getPeople().isDead())
		{
			cg->updatePosPeople(MOVING); //Cập nhật vị trí người theo thông tin từ main
		}
		MOVING = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
		cg->updatePosVehicle(); //Cập nhật vị trí xe
		cg->updatePosAnimal(); //Cập nhật vị trí thú
		cg->drawGame();

		if (cg->checkImpact())
		{
			// Xử lý khi đụng xe hay thú
			system("cls");
			if (!MUTED)
				PlaySound(TEXT("Sound\\Sound_Lose.wav"), NULL, SND_ASYNC);
			cg->deathFX();
			loseGame();
			Sleep(1000);
			GotoXY(50, 10);
			cout << "Wanna play more ? Press Y to continue, any other keys to out";
			IS_PAUSE = true;
			LEVEL = 1;
		}

		if (cg->getPeople().isFinish())
		{
			++LEVEL;
			// Xử lý khi về đích
			if (LEVEL == 4) {
				system("cls");
				if (!MUTED)
					PlaySound(TEXT("Sound\\Sound_Win.wav"), NULL, SND_ASYNC);
				winGame();
				Sleep(1000);
				GotoXY(50, 10);
				cout << "Wanna play more ? Press ESC to out, any other keys to out";
				IS_PAUSE = true;
				LEVEL = 0;
			}
			else
				cg->startGame();
		}

		if (IS_PAUSE) {
			unique_lock<mutex> ulock(lock1);
			cv.wait(ulock);
			system("cls");
		}

		cg->setCount1(cg->getCount1() + 1);
		cg->setCount2(cg->getCount2() + 1);

		Sleep(35 - (10 * LEVEL));
	}
}

void playGame(int mode) {
	srand((int)time(NULL));
	SCREEN_COLOR;

	LEVEL = 1;

	cg = new CGAME();
	cg->startGame();

	int key;
	thread t1(SubThread);

	while (true)
	{
		if (mode == 1)
			key = toupper(_getch());
		if (mode == 2)
		{
			key = 'T';
			mode = 1;
		}
		if (!cg->getPeople().isDead())
		{
			if (key == 27)
			{
				cg->exitGame(t1.native_handle()); // Bấm ESC thoát giữa chừng
				break;
			}
			else if (key == 'P')
			{
				cg->pauseGame(t1.native_handle()); // Pause
			}
			else if (key == 'L')
			{
				IS_PAUSE = true;
				Sleep(1000);
				cg->saveGame();
			}
			else if (key == 'T')
			{
				IS_PAUSE = true;
				Sleep(1000);
				cg->loadGame();
			}
			else
			{
				if (IS_PAUSE == true) {
					IS_PAUSE = false;
					cv.notify_all();
				}

				cg->resumeGame((HANDLE)t1.native_handle());
				MOVING = key; //Cập nhật bước di chuyển
			}
		}
		else
		{
			if (key == 'Y')
			{
				cv.notify_all();
				cg->startGame(); // Chơi tiếp
			}
			else
			{
				cg->exitGame(t1.native_handle()); // Thoát trò chơi
				break;
			}
		}
	}
	if (t1.joinable())
		t1.join();
}

void setting() {
	system("cls");
	
	GotoXY(70, 17);
	cout << "S O U N D: ";
	int distance = 1;

	int n = 2;
	string sections[] = { "ON", "OFF" };

	int x = 82, y = 17;
	// Other sections hasn't color
	int tempY = y + distance;
	for (int i = 1; i < n; i++) {
		GotoXY(x, tempY);
		SCREEN_COLOR;
		cout << sections[i];
		tempY += distance;
	}
	// sections[0] has color (Default)
	GotoXY(x, y);
	BUTTON_COLOR;
	cout << sections[0];

	char key;
	int line = 0;
	while (true) {
		key = _getch();
		if (key == KEY_UP) {
			line--;
			if (line < 0) {
				line = n - 1;

				GotoXY(x, y);
				SCREEN_COLOR;
				cout << sections[0];

				GotoXY(x, y + line * distance);
				BUTTON_COLOR;
				cout << sections[n - 1];
			}
			else {
				GotoXY(x, y + (line + 1) * distance);
				SCREEN_COLOR;
				cout << sections[line + 1];

				GotoXY(x, y + line * distance);
				BUTTON_COLOR;
				cout << sections[line];
			}
		}
		else if (key == KEY_DOWN) {
			line++;
			if (line > n - 1) {
				line = 0;

				GotoXY(x, y + (n - 1) * distance);
				SCREEN_COLOR;
				cout << sections[n - 1];

				GotoXY(x, y);
				BUTTON_COLOR;
				cout << sections[0];
			}
			else {
				GotoXY(x, y + (line - 1) * distance);
				SCREEN_COLOR;
				cout << sections[line - 1];

				GotoXY(x, y + line * distance);
				BUTTON_COLOR;
				cout << sections[line];
			}
		}
		else if (key == ENTER && line == 0) {
			MUTED = false;
			if (!MUTED)
				PlaySound(TEXT("Sound\\Sound_Button.wav"), NULL, SND_ASYNC);
			menu();
		}
		else if (key == ENTER && line == 1) {
			MUTED = true;
			menu();
		}
	}
}

void about() {
	system("cls");
	SCREEN_COLOR;

	aboutArt();

	int x = 69;
	GotoXY(x, 9);
	cout << "MEMBER'S INFORMATION" << endl;

	GotoXY(x, 11);
	cout << "Name: Truong Chi Hien" << endl;
	GotoXY(x, 12);
	cout << "ID: 20127494" << endl;

	GotoXY(x, 14);
	cout << "Name: Bui Quoc Hung" << endl;
	GotoXY(x, 15);
	cout << "ID: 20127508" << endl;

	GotoXY(x, 17);
	cout << "Name: Tran Thanh Hoa" << endl;
	GotoXY(x, 18);
	cout << "ID: 20127163" << endl;

	GotoXY(x, 20);
	cout << "Name: Do Minh Tri" << endl;
	GotoXY(x, 21);
	cout << "ID: 20127651" << endl;
}

void menu() {
	system("cls");

	if (!MUTED) {
		PlaySound(TEXT("Sound\\Sound_Menu.wav"), NULL, SND_ASYNC);
	}
	int x = 72, y = 16;
	int distance = 3;

	titleGame();
	SCREEN_COLOR;

	int n = 5;
	string sections[] = { "N E W  G A M E", "L O A D  G A M E", "S E T T I N G S", "A B O U T" ,"Q U I T" };

	// Other sections hasn't color
	int tempY = y + distance;
	for (int i = 1; i < n; i++) {
		GotoXY(x, tempY);
		SCREEN_COLOR;
		cout << sections[i];
		tempY += distance;
	}
	// sections[0] has color (Default)
	GotoXY(x, y);
	BUTTON_COLOR;
	cout << sections[0];

	char key;
	int line = 0;
	while (true) {
		key = _getch();
		if (key == KEY_UP) {
			line--;
			if (line < 0) {
				line = n - 1;

				GotoXY(x, y);
				SCREEN_COLOR;
				cout << sections[0];

				GotoXY(x, y + line * distance);
				BUTTON_COLOR;
				cout << sections[n - 1];
			}
			else {
				GotoXY(x, y + (line + 1) * distance);
				SCREEN_COLOR;
				cout << sections[line + 1];

				GotoXY(x, y + line * distance);
				BUTTON_COLOR;
				cout << sections[line];
			}
		}
		else if (key == KEY_DOWN) {
			line++;
			if (line > n - 1) {
				line = 0;

				GotoXY(x, y + (n - 1) * distance);
				SCREEN_COLOR;
				cout << sections[n - 1];

				GotoXY(x, y);
				BUTTON_COLOR;
				cout << sections[0];
			}
			else {
				GotoXY(x, y + (line - 1) * distance);
				SCREEN_COLOR;
				cout << sections[line - 1];

				GotoXY(x, y + line * distance);
				BUTTON_COLOR;
				cout << sections[line];
			}
		}
		else if (key == ENTER && line == 0) {
			if (!MUTED)
				PlaySound(TEXT("Sound\\Sound_Button.wav"), NULL, SND_ASYNC);
			playGame(1);
		}
		else if (key == ENTER && line == 1) {
			if (!MUTED)
				PlaySound(TEXT("Sound\\Sound_Button.wav"), NULL, SND_ASYNC);
			playGame(2);
		}
		else if (key == ENTER && line == 2) {
			if (!MUTED)
				PlaySound(TEXT("Sound\\Sound_Button.wav"), NULL, SND_ASYNC);
			setting();
		}
		else if (key == ENTER && line == 3) {
			system("cls");
			if (!MUTED)
				PlaySound(TEXT("Sound\\Sound_Button.wav"), NULL, SND_ASYNC);
			cout << "ABOUT" << endl;
			about();
			system("pause");
			menu();
		}
		else if (key == ENTER && line == 4) {
			if (!MUTED)
				PlaySound(TEXT("Sound\\Sound_Button.wav"), NULL, SND_ASYNC);
			system("cls");
			SCREEN_COLOR;
			outGame();
			system("pause");
			exit(0);
		}
	}
}

int main() {
	setConsoleWindow(1300, 660);
	FixConsoleWindow();
	removeScrollBar();
	hideCursor();
	menu();
	return 0;
}