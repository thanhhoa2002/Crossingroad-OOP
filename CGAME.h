#pragma once

#include "CPEOPLE.h"
#include "CTRAFFICLIGHT.h"
#include "ART.h"


class CGAME 
{
private:
	CTRAFFICLIGHT time;
	int count1;
	int count2;

	vector<CTRUCK> truck;
	vector<CCAR> car;
	vector<CDINO> dino;
	vector<CBIRD> bird;
	CPLANE plane;
	CPEOPLE player;

public:

	CGAME(); // Chuẩn bị dữ liệu cho tất cả các đối tượng
	void drawGame(); // Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	~CGAME(); // Hủy tài nguyên đã cấp phát

	CPEOPLE getPeople(); // Lấy thông tin người

	void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE); // Thực hiện thoát Thread
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	
	void loadGame(); // Thực hiện tải lại trò chơi đã lưu
	void saveGame(); // Thực hiện lưu lại dữ liệu trò chơi
	
	void pauseGame(HANDLE); // Tạm dừng Thread
	void resumeGame(HANDLE); // Quay lai Thread

	void updatePosPeople(char); // Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(); // Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosAnimal();// Thực hiện cho CDINAUSOR & CBIRD di chuyển

	bool checkImpact(); // Thực hiện kiểm tra va chạm

	void deathFX(); // Thực hiện hiệu ứng khi chết

	CTRAFFICLIGHT getTime(); // Thực hiện đổi đèn giao thông
	int getCount1();
	int getCount2();
	void setCount1(int);
	void setCount2(int);
};