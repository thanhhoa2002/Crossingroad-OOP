#include "CGAME.h"

CGAME::CGAME()
{
	LEVEL = 1;

	time.setLight1(true);
	time.setLight2(true);
	count1 = 1;
	count2 = 1;

	car.resize(MAX_VEHICLE_LENGTH);
	truck.resize(MAX_VEHICLE_LENGTH);
	dino.resize(MAX_ANIMAL_LENGTH);
	bird.resize(MAX_ANIMAL_LENGTH);
	
	int randomX;
	randomX = (rand() % 69) + 1;
	for (int i = 0; i < MAX_VEHICLE_LENGTH; ++i)
		car[i].setPos(randomX + i * 69, 4);
	randomX = (rand() % 69) + 1;
	for (int i = 0; i < MAX_VEHICLE_LENGTH; ++i)
		truck[i].setPos(randomX + i * 69, 20);
	randomX = (rand() % 20) + 1;
	for (int i = 0; i < MAX_ANIMAL_LENGTH; ++i)
		dino[i].setPos(randomX + i * 40, 12);
	randomX = (rand() % 20) + 1;
	for (int i = 0; i < MAX_ANIMAL_LENGTH; ++i)
		bird[i].setPos(randomX + i * 37, 28);

	plane.setPos(-60, 14);
}

void CGAME::drawGame()
{
	TextColor(153);
	GotoXY(0, 0);

	printf(" ");
	for (int i = 1; i < WIDTH_CONSOLE; i++)	printf("_");
	printf(" ");

	GotoXY(0, HEIGH_CONSOLE);
	printf("|");
	for (int i = 1; i < WIDTH_CONSOLE; i++)	printf("_");
	printf("|");

	for (int i = 1; i < HEIGH_CONSOLE; i++)
	{
		GotoXY(0, i); printf("|");
		GotoXY(WIDTH_CONSOLE, i); printf("|");
	}

	NORMAL;
	GotoXY(WIDTH_CONSOLE + 2, 8);
	printf("C R O S S I N G");
	GotoXY(WIDTH_CONSOLE + 2, 9);
	printf("    R O A D    ");
	GotoXY(WIDTH_CONSOLE + 2, 10);
	printf("    G A M E    ");
	GotoXY(WIDTH_CONSOLE + 2, 11);
	printf("---------------");
	GotoXY(WIDTH_CONSOLE + 2, 16);
	printf("Esc: Exit game");
	GotoXY(WIDTH_CONSOLE + 2, 17);
	printf("P: Pause game");
	GotoXY(WIDTH_CONSOLE + 2, 18);
	printf("L: Save game");
	GotoXY(WIDTH_CONSOLE + 2, 19);
	printf("T: Load game");
	NORMAL;

	GotoXY(0, 0);
}

CGAME::~CGAME() {}

CPEOPLE CGAME::getPeople()
{
	return this->player;
}

void CGAME::resetGame()
{
	player.setX(67); player.setY(33); // Vị trí lúc đầu của người

	time.setLight1(true);
	time.setLight2(true);
	count1 = 1;
	count2 = 1;

	// Tạo mảng xe chạy
	int randomX;
	randomX = (rand() % 69) + 1;
	for (int i = 0; i < MAX_VEHICLE_LENGTH; ++i)
		car[i].setPos(randomX + i * 69, 4);
	randomX = (rand() % 69) + 1;
	for (int i = 0; i < MAX_VEHICLE_LENGTH; ++i)
		truck[i].setPos(randomX + i * 69, 20);
	randomX = (rand() % 20) + 1;
	for (int i = 0; i < MAX_ANIMAL_LENGTH; ++i)
		dino[i].setPos(randomX + i * 40, 12);
	randomX = (rand() % 20) + 1;
	for (int i = 0; i < MAX_ANIMAL_LENGTH; ++i)
		bird[i].setPos(randomX + i * 37, 28);

	plane.setPos(-60, 14);
}

void CGAME::exitGame(HANDLE t)
{
	system("cls");
	outGame();
	exit(0);
}

void CGAME::startGame()
{
	system("cls");
	if (!MUTED)
		PlaySound(TEXT("Sound\\Sound_Play.wav"), NULL, SND_ASYNC);
	this->player.setState(true);
	this->resetGame(); // Khởi tạo dữ liệu gốc
	this->drawGame();
}

void CGAME::loadGame()
{
	system("cls");
	string dir;
	int x, y;


	cout << "Enter the file's name to load game: ";
	cin >> dir;
	ifstream fi("Save_Game//" + dir);
	if (fi) {
		fi >> LEVEL;

		fi >> x >> y;
		player.setX(x);
		player.setY(y);

		for (int i = 0; i < car.size(); i++) {
			fi >> x >> y;
			car[i].setPos(x, y);
		}
		for (int i = 0; i < truck.size(); i++) {
			fi >> x >> y;
			truck[i].setPos(x, y);
		}
		for (int i = 0; i < bird.size(); i++) {
			fi >> x >> y;
			bird[i].setPos(x, y);
		}
		for (int i = 0; i < dino.size(); i++) {
			fi >> x >> y;
			dino[i].setPos(x, y);
		}
		fi >> x >> y;
		time.setLight1(x);
		time.setLight2(y);

		fi >> count1 >> count2;
	}
	else
		cout << "The saving file does not exist, please try again !\n";


	cout << "Press Enter to continue, esc to out!";
	Sleep(1500);
	system("cls");

	fi.close();
}

void CGAME::saveGame()
{
	system("cls");
	string dir;
	cout << "Enter the file's name to save game: ";

	cin >> dir;

	ofstream fo("Save_Game\\" + dir);
	fo << LEVEL << endl;
	fo << player.getX() << ' ' << player.getY() << endl;

	for (int i = 0; i < car.size(); i++) {
		fo << car[i].getX() << ' ' << car[i].getY() << endl;
	}
	for (int i = 0; i < truck.size(); i++) {
		fo << truck[i].getX() << ' ' << truck[i].getY() << endl;
	}
	for (int i = 0; i < bird.size(); i++) {
		fo << bird[i].getX() << ' ' << bird[i].getY() << endl;
	}
	for (int i = 0; i < dino.size(); i++) {
		fo << dino[i].getX() << ' ' << dino[i].getY() << endl;
	}
	fo << time.getLight1() << ' ' << time.getLight2() << endl;
	fo << count1 << ' ' << count2 << endl;
	cout << "Press Enter to continue, esc to out!";
	Sleep(1500);
	fo.close();
}

void CGAME::pauseGame(HANDLE t)
{
	SuspendThread(t);
}

void CGAME::resumeGame(HANDLE t)
{
	ResumeThread(t);
}

void CGAME::updatePosPeople(char key)
{
	int stepX = 1;
	int stepY = 1;

	int j = 0;
	GotoXY(player.getX(), player.getY() + j++);
	cout << player.peopleShape[0];
	GotoXY(player.getX(), player.getY() + j++);
	cout << player.peopleShape[1];
	GotoXY(player.getX(), player.getY() + j++);
	cout << player.peopleShape[2];

	if (key == 'W')
	{
		// Erase
		for (int j = 0; j < 3; j++)
		{
			GotoXY(player.getX(), player.getY() + j);
			cout << "   ";
		}

		// Move
		player.Up(stepY);

		// Draw
		j = 0;
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[0];
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[1];
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[2];
		GotoXY(player.getX(), player.getY() + j++);
	}
	else if (key == 'A')
	{
		// Erase
		for (int j = 0; j < 3; j++)
		{
			GotoXY(player.getX(), player.getY() + j);
			cout << "   ";
		}

		// Move
		player.Left(stepX);

		// Draw
		j = 0;
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[0];
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[1];
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[2];
	}
	else if (key == 'D')
	{
		// Erase
		for (int j = 0; j < 3; j++)
		{
			GotoXY(player.getX(), player.getY() + j);
			cout << "   ";
		}

		// Move
		player.Right(stepX);

		// Draw
		j = 0;
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[0];
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[1];
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[2];
	}
	else if (key == 'S')
	{
		// Erase
		for (int j = 0; j < 5; j++)
		{
			GotoXY(player.getX(), player.getY() + j);
			cout << "   ";
		}

		// Move
		player.Down(stepY);

		// Draw
		j = 0;
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[0];
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[1];
		GotoXY(player.getX(), player.getY() + j++);
		cout << player.peopleShape[2];
	}
}

void CGAME::updatePosVehicle()
{
	if (time.changeLight1(count1))
		count1 = 1;
	if (time.changeLight2(count2))
		count2 = 1;
	time.drawTL();

	// Erase
	for (int i = 0; i < MAX_VEHICLE_LENGTH; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (time.getLight1())
			{
				GotoXY(car[i].getX() + 28, car[i].getY() + j);
				cout << " ";
			}

			if (time.getLight2())
			{
				GotoXY(truck[i].getX() + 26, truck[i].getY() + j);
				cout << " ";
			}
		}
	}

	// Move
	for (int i = 0; i < MAX_VEHICLE_LENGTH; ++i) {
		if (time.getLight1())
		{
			if (car[i].getX() == -28) // Right To Left
			{
				car[i].setX(WIDTH_CONSOLE - 1);
			}
			else
			{
				car[i].Move(-1, 0);
			}
		}

		if (time.getLight2())
		{
			if (truck[i].getX() == -26) // Right To Left
			{
				truck[i].setX(WIDTH_CONSOLE - 1);
			}
			else
			{
				truck[i].Move(-1, 0);
			}
		}
	}

	// Draw
	for (int i = 0; i < MAX_VEHICLE_LENGTH; ++i)
	{
		if (time.getLight1())
		{
			if (car[i].getX() < 0 and car[i].getX() > -29)
			{
				for (int l = 0; l < 5; ++l)
				{
					GotoXY(1, car[i].getY() + l);
					for (int p = abs(car[i].getX()) + 1; p < car[i].shape[l].size(); ++p)
					{
						cout << car[i].shape[l][p];
					}
				}
			}
			else if (car[i].getX() < WIDTH_CONSOLE and car[i].getX() > WIDTH_CONSOLE - 29)
			{
				for (int l = 0; l < 5; ++l)
				{
					GotoXY(car[i].getX(), car[i].getY() + l);
					for (int p = 0; p < WIDTH_CONSOLE - car[i].getX(); ++p)
					{
						cout << car[i].shape[l][p];
					}
				}
			}
			else
			{
				for (int j = 0; j < 5; ++j) {
					GotoXY(car[i].getX(), car[i].getY() + j);
					cout << car[i].shape[j];
				}
			}
		}

		if (time.getLight2())
		{
			if (truck[i].getX() < 0 and truck[i].getX() > -27)
			{
				for (int l = 0; l < 5; ++l)
				{
					GotoXY(1, truck[i].getY() + l);
					for (int p = abs(truck[i].getX()) + 1; p < truck[i].shape[l].size(); ++p)
					{
						cout << truck[i].shape[l][p];
					}
				}
			}
			else if (truck[i].getX() < WIDTH_CONSOLE and truck[i].getX() > WIDTH_CONSOLE - 27)
			{
				for (int l = 0; l < 5; ++l)
				{
					GotoXY(truck[i].getX(), truck[i].getY() + l);
					for (int p = 0; p < WIDTH_CONSOLE - truck[i].getX(); ++p)
					{
						cout << truck[i].shape[l][p];
					}
				}
			}
			else
			{
				for (int j = 0; j < 5; ++j) {
					GotoXY(truck[i].getX(), truck[i].getY() + j);
					cout << truck[i].shape[j];
				}
			}
		}
	}
}

void CGAME::updatePosAnimal()
{
	// Erase
	for (int i = 0; i < MAX_ANIMAL_LENGTH; ++i)
	{
		for (int j = 0; j < 5; j++)
		{
			GotoXY(dino[i].getX(), dino[i].getY() + j);
			cout << " ";
		}

		for (int j = 0; j < 5; j++)
		{
			GotoXY(bird[i].getX(), bird[i].getY() + j);
			cout << " ";
		}
	}

	// Move
	for (int i = 0; i < MAX_ANIMAL_LENGTH; ++i) 
	{
		if (dino[i].getX() == WIDTH_CONSOLE) // Left To Right
		{
			dino[i].setX(-16);
		}
		else
		{
			dino[i].Move(1, 0);
		}

		if (bird[i].getX() == WIDTH_CONSOLE) // Left To Right
		{
			bird[i].setX(-7);
		}
		else
		{
			bird[i].Move(1, 0);
		}
	}

	// Draw
	for (int i = 0; i < MAX_ANIMAL_LENGTH; ++i)
	{
		if (dino[i].getX() > WIDTH_CONSOLE - 17)
		{
			for (int k = 0; k < 5; k++)
			{
				GotoXY(dino[i].getX(), dino[i].getY() + k);
				for (int p = 0; p < WIDTH_CONSOLE - dino[i].getX(); p++)
				{
					cout << dino[i].shape[k][p];
				}
			}
		}
		else if (dino[i].getX() < 0 && dino[i].getX() > -17)
		{
			for (int k = 0; k < 5; k++)
			{
				GotoXY(1, dino[i].getY() + k);
				for (int p = abs(dino[i].getX()); p < dino[i].shape[k].size(); p++)
				{
					cout << dino[i].shape[k][p];
				}
			}
		}
		else
		{
			for (int j = 0; j < 5; ++j) {
				GotoXY(dino[i].getX(), dino[i].getY() + j);
				cout << dino[i].shape[j];
			}
		}

		if (bird[i].getX() > WIDTH_CONSOLE - 8)
		{
			for (int k = 0; k < 5; k++)
			{
				GotoXY(bird[i].getX(), bird[i].getY() + k);
				for (int p = 0; p < WIDTH_CONSOLE - bird[i].getX(); p++)
				{
					cout << bird[i].shape[k][p];
				}
			}
		}
		else if (bird[i].getX() < 0 && bird[i].getX() > -8)
		{
			for (int k = 0; k < 5; k++)
			{
				GotoXY(1, bird[i].getY() + k);
				for (int p = abs(bird[i].getX()); p < bird[i].shape[k].size(); p++)
				{
					cout << bird[i].shape[k][p];
				}
			}
		}
		else
		{
			for (int j = 0; j < 5; ++j) {
				GotoXY(bird[i].getX(), bird[i].getY() + j);
				cout << bird[i].shape[j];
			}
		}
	}
}

bool CGAME::checkImpact()
{
	if (player.getY() >= 26)
		return player.isImpact<CBIRD>(bird, MAX_ANIMAL_LENGTH);
	else if (player.getY() >= 18)
		return player.isImpact<CTRUCK>(truck, MAX_VEHICLE_LENGTH);
	else if (player.getY() >= 10)
		return player.isImpact<CDINO>(dino, MAX_ANIMAL_LENGTH);
	else if (player.getY() >= 2)
		return player.isImpact<CCAR>(car, MAX_VEHICLE_LENGTH);
	else
		return false;
}

void CGAME::deathFX()
{
	system("cls");
	while (plane.getX() < WIDTH_CONSOLE + 17)
	{
		for (int i = 0; i < 8; ++i)
		{
			GotoXY(plane.getX(), plane.getY() + i);
			cout << " ";
		}

		plane.Move(1, 0);

		if (plane.getX() > (WIDTH_CONSOLE + 17 - 61))
		{
			for (int k = 0; k < 8; k++)
			{
				GotoXY(plane.getX(), plane.getY() + k);
				for (int p = 0; p < WIDTH_CONSOLE + 17 - plane.getX(); p++)
				{
					cout << plane.shape[k][p];
				}
			}
		}
		else if (plane.getX() < 0 && plane.getX() > -61)
		{
			for (int k = 0; k < 8; k++)
			{
				GotoXY(1, plane.getY() + k);
				for (int p = abs(plane.getX()); p < plane.shape[k].size(); p++)
				{
					cout << plane.shape[k][p];
				}
			}
		}
		else
		{
			for (int j = 0; j < 8; ++j) {
				GotoXY(plane.getX(), plane.getY() + j);
				cout << plane.shape[j];
			}
		}
		Sleep(5);
	}
}

CTRAFFICLIGHT CGAME::getTime()
{
	return time;
}

int CGAME::getCount1()
{
	return count1;
}

void CGAME::setCount1(int count)
{
	count1 = count;
}

int CGAME::getCount2()
{
	return count2;
}

void CGAME::setCount2(int count)
{
	count2 = count;
}