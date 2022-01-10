#include"main.h"
#include"function.h"
#include"Console.h"
#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
CauTrucBang CTBang;
CauTrucO** CTO;
COORD CViTriConTro;
bool BDungPhim = false;
int k=6;
int k1;
clock_t start_t, end_t, total_t;
void taoMang2ChieuDong() {
	CTO = new CauTrucO * [CTBang.SDong];
	for (int i = 0; i < CTBang.SCot; i++) {
		CTO[i] = new CauTrucO[CTBang.SCot];
	}
}
void khoiTao(short SDong, short SCot, short SSoBom) {
	CTBang.SDong = SDong;
	CTBang.SCot = SCot;
	CTBang.SSoBom = SSoBom;
	CTBang.SSoODaMo = 0;
	CTBang.SSoCo = 0;
	taoMang2ChieuDong();
	veBang();
	taoBom();
	xuatBom();
}
short toaDoX(short SX) {
	return (SX * 2);
}
short toaDoY(short SY) {
	return(SY);
}

void veO(short SX, short SY, short SKieu) {
	
		switch (SKieu) {
		case 0:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 10, const_cast<char*>("  "));
			break;
		case 1:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 9, 15, const_cast<char*>("1 "));
			break;
		case 2:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 2, 15 ,const_cast<char*>("2 "));
			break;
		case 3:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 15 ,const_cast<char*>("3 "));
			break;
		case 4:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 1, 15 ,const_cast<char*>("4 "));
			break;
		case 5:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 4, 15 ,const_cast<char*>("5 "));
			break;
		case 6:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 2, 15, const_cast<char*>("6 "));
			break;
		case 7:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 15, const_cast<char*>("7 "));
			break;
		case 8:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 13, 15, const_cast<char*>("8 "));
			break;
		case 9:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, const_cast<char*>("8 "));
			break;
		case 10:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 10, const_cast<char*>("  "));
			break;
		case 11:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 7, const_cast<char*>("  "));
			break;
		case 12:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 0, const_cast<char*>(" "));
			break;
		case 13:
			setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, const_cast<char*>("B "));
			break;
		//case 14:
			//setColorBGTextXY(toaDoX(SX), toaDoY(SY), 15, 16, const_cast<char*>("Bx "));
			//break;
		//case 15:
			//setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, const_cast<char*>(" "));
			//break;
		}
	
}
void tuyChon() {
	cout << char(218);
	for (int i = 0; i <= 44; i++)
		cout << char(196);
	cout << char(191) << endl;
	cout << char(179) << "           " << char(4) << " 1 " << char(16) << "    Choi Moi                 " << char(179) << endl;
	cout << char(179);
	for (int i = 0; i <= 44; i++)
	    cout << char(196);
	cout << char(179) << endl;
	cout << char(179) << "           " << char(4) << " 2 " << char(16) << "    Chon Do Kho              " << char(179) << endl;
	cout << char(179);
	for (int i = 0; i <= 44; i++)
		cout << char(196);
	cout << char(179) << endl;
	cout << char(179) << "           " << char(4) << " 3 " << char(16) << "    Bang Xep Hang            " << char(179) << endl;
	cout << char(179);
	for (int i = 0; i <= 44; i++)
		cout << char(196);
	cout << char(179) << endl;
	cout << char(179) << "           " << char(4) << " 4 " << char(16) << "    Luat Choi                " << char(179) << endl;
	cout << char(179);
	for (int i = 0; i <= 44; i++)
		cout << char(196);
	cout << char(179) << endl;
	cout << char(179) << "           " << char(4) << " 5 " << char(16) << "    Thoat                    " << char(179) << endl;
	cout << char(192);
	for (int i = 0; i <= 44; i++)
		cout << char(196);
	cout << char(217) << endl;
	cout << "Moi nhap: ->  ";
	if(k==6){ cin >> k; }
	system("cls");
}
void menu() {
	tuyChon();
	switch (k) {
	case 1:
		if (k1 == 1) {
			
			start_t = clock();

			khoiTao(10, 10, 10);
			xuLySuKien();
			
		}
		if (k1 == 2) {
			start_t = clock();
			khoiTao(15, 15, 60);
			xuLySuKien();
		}
		if (k1 == 3) {
			start_t = clock();
			khoiTao(20, 20, 100);
			xuLySuKien();
		}
		else {
			start_t = clock();
			khoiTao(10, 10, 10);
			xuLySuKien();
		}
		break;
	case 2:
		int dkho;
		cout << char(218);
		for (int i = 0; i <= 44; i++)
			cout << char(196);
		cout << char(191) << endl;
		cout << char(179) << "           " << char(4) << " 1 " << char(16) << "    De                       " << char(179) << endl;
		cout << char(179);
		for (int i = 0; i <= 44; i++)
			cout << char(196);
		cout << char(179) << endl;
		cout << char(179) << "           " << char(4) << " 2 " << char(16) << "    Trung Binh               " << char(179) << endl;
		cout << char(179);
		for (int i = 0; i <= 44; i++)
			cout << char(196);
		cout << char(179) << endl;
		cout << char(179) << "           " << char(4) << " 3 " << char(16) << "    Kho                      " << char(179) << endl;
	
		cout << char(192);
		for (int i = 0; i <= 44; i++)
			cout << char(196);
		cout << char(217) << endl;
		cout << "Moi nhap: ->  ";
		cin >> dkho;
		system("cls");
		if (dkho == 1) { k = 6; k1 = 1;}
		if (dkho == 2) { k = 6; k1 = 2;}
		if (dkho == 3) { k = 6; k1 = 3;}
		menu();
		break;
	case 3:
		in_file();
		xuLySuKien();
		break;
	case 4:
		cout << "luat choi: " << endl << "bam phim z de mo o" << endl << "bam phim x de cam co" <<endl<< "nhung o da cam co thi khong the mo o" << endl << "ban se thua khi mo vao o co min" << endl << "nguoi choi hoan thanh tro choi nhanh nhat la nguoi co diem cao nhat"<<endl;
		cout << "Bam ESC de quay lai";
		xuLySuKien();
		break;
	case 5:
		exit(0);
		break;
	}
}
void in_file() {
	ifstream Filee;
	Filee.open("C:\\Users\\quang\\OneDrive\\Desktop\\input.txt", ios_base::in);
	int a[100], i;
	int n = 5;
	for (i = 0; i < n; i++) {
		Filee >> a[i];
		cout << char(218);

		for (int i = 0; i <= 44; i++)

			cout << char(196);

		cout << char(191) << endl;

		cout << char(179) << "  " << char(4) << "Top  " << i+1 << " :  " << char(16) << " " << a[i] << endl;


		cout << char(192);

		for (int i = 0; i <= 44; i++)

			cout << char(196);

		cout << char(217) << endl;
		
	}
	cout << "Bam ESC de tro ve";
}
void veBang() {
	for (int i = 0; i < CTBang.SDong; ++i) {
		for (int j = 0; j < CTBang.SCot; ++j) {
			if (CTO[i][j].BCamCo == true) {
				veO(j, i, 13);
			}
			else if (CTO[i][j].SBomBenCanh > 0) {
				veO(j, i,CTO[i][j].SBomBenCanh);
			}
			else if (CTO[i][j].BDaMo == true) {
				veO(j, i, 0);
			}
		 else if (((i + j) % 2) > 0) {
				veO(j, i, 11);
			}
			else {
				veO(j, i, 10);
			}
			if (BDungPhim == true) {
				veO(CViTriConTro.X, CViTriConTro.Y, 12);
			}

		}
	}
	cout << endl;
}
void taoBom() {
	short SSoBom = CTBang.SSoBom;
	short SD, SC;
	srand(time(NULL));
	while (SSoBom) {
		SD = rand() % CTBang.SDong;
		SC = rand() % CTBang.SCot;
		if (CTO[SD][SC].BCoBom)
			continue;
		CTO[SD][SC].BCoBom = true;
		--SSoBom;
	}
}
void xuatBom() {
	for (int i = 0; i < CTBang.SDong; i++) {
		for (int j = 0; j < CTBang.SCot; j++) {
			if (CTO[i][j].BCoBom==true) {
				setBackgroundColor(3);
			}
			else setBackgroundColor(4);
			cout << CTO[i][j].BCoBom << " ";
		}
		cout << endl;
	}
	setBackgroundColor(0);
}
void clickPhai(short SX,short SY) {
	if (CTO[SX][SY].BDaMo == false) {
		if (CTO[SX][SY].BCamCo == true) {
			CTO[SX][SY].BCamCo = false;
			CTBang.SSoCo--;
		}
		else {
			CTO[SX][SY].BCamCo = true;
			CTBang.SSoCo++;
		}
	}
	veBang();
}
short demBomBenCanh(short SX, short SY) {
	short SDem = 0;
	for (int i = SX - 1; i <= SX + 1; i++) {
		for (int j = SY - 1; j <= SY + 1; j++) {
			if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY))
				continue;
			if (CTO[i][j].BCoBom == true) {
				SDem++;
			}
		}
	}
	return SDem;
}
void moO(short SX, short SY) {
	if (CTO[SX][SY].BDaMo == false && CTO[SX][SY].BCamCo == false) {
		CTO[SX][SY].BDaMo = true;
		if (CTO[SX][SY].BCoBom == true) {
			system("cls");
			end_t = clock();
			total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
			setColor(15);
			xuatBom();
			cout << endl <<"da thua "<<endl<<"thoi gian choi : "<<total_t << endl;
			
			Sleep(3000);
			k = 6;
			system("cls");
			menu();
		}
		else {
			CTBang.SSoODaMo++;
			if (CTBang.SSoODaMo == CTBang.SDong * CTBang.SCot - CTBang.SSoBom) {
				system("cls");
				end_t = clock();
				total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
				setColor(7);
				cout << "Ban da thang voi thoi gian la :  " << total_t<<endl;
				ifstream Filee;
				Filee.open("C:\\Users\\quang\\OneDrive\\Desktop\\input.txt", ios_base::in);
				int a[100], i, j, min;
				int n = 5;
				for (i = 0; i < n; i++) {
					Filee >> a[i];
				}
				a[n] = total_t;
				ofstream Filee1;
				Filee1.open("C:\\Users\\quang\\OneDrive\\Desktop\\input.txt", ios_base::out);
				for (i = 0; i < n; i++) {
					for (j = i + 1; j < n; j++) {
						if (a[i] > a[j]) {
							min = a[i];
							a[i] = a[j];
							a[j] = min;
						}
					}
					Filee1 << a[i] << endl;
				}
				Filee1.close();
				Filee.close();
				cout << "Bam ESC de tro ve";
				xuLySuKien();
				
			}
			else {


				short SSoBomBenCanh = demBomBenCanh(SX, SY);
				if (SSoBomBenCanh > 0) {
					CTO[SX][SY].SBomBenCanh = SSoBomBenCanh;
				}
				else {
					for (int i = SX - 1; i <= SX + 1; i++) {
						for (int j = SY - 1; j <= SY + 1; j++) {
							if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY))
								continue;
							moO(i, j);
						}
					}
				}

			}
		}
		
	}
}
void clickTrai(short SX, short SY) {
	if (CTO[SX][SY].BCamCo == false && CTO[SX][SY].BDaMo == false) {
		moO(SX, SY);
		veBang();
	}
}
void XuLyPhim(KEY_EVENT_RECORD key) {
	if (key.bKeyDown) {
		switch (key.wVirtualKeyCode) {
		case VK_UP:
			BDungPhim = true;
			CViTriConTro.Y = ((CViTriConTro.Y == 0) ? CTBang.SDong -1 : CViTriConTro.Y - 1);
			veBang();
			break;
		case VK_DOWN:
			BDungPhim = true;
			CViTriConTro.Y = ((CViTriConTro.Y == CTBang.SDong -1) ?0: CViTriConTro.Y + 1);
			veBang();
			break;
		case VK_LEFT:
			BDungPhim = true;
			CViTriConTro.X = ((CViTriConTro.X == 0) ? CTBang.SCot -1 : CViTriConTro.X - 1);
			veBang();
			break;
		case VK_RIGHT:
			BDungPhim = true;
			CViTriConTro.X = ((CViTriConTro.X == CTBang.SCot -1)? 0: CViTriConTro.X + 1);
			veBang();
			break;
		case VK_ESCAPE:
			k = 6;
			system("cls");
			menu();
			break;
		case ClickTrai:
			clickTrai(CViTriConTro.Y, CViTriConTro.X);
			break;
		case ClickPhai:
			clickPhai(CViTriConTro.Y, CViTriConTro.X);
			break;
		}
	}
}
void xuLySuKien() {
	while (1) {
		DWORD number1 = 0;
		DWORD number2 = 0;
		HANDLE input = GetStdHandle(STD_INPUT_HANDLE);
		GetNumberOfConsoleInputEvents(input, &number1);
		if (number1) {
			INPUT_RECORD* IREventBuffer = new INPUT_RECORD[number1];
			ReadConsoleInput(input, IREventBuffer, number1, &number2);
			for (DWORD i = 0; i < number1; i++) {
				if (IREventBuffer[i].EventType == KEY_EVENT) {
					XuLyPhim(IREventBuffer[i].Event.KeyEvent);
				}
			}
		}
	}
}