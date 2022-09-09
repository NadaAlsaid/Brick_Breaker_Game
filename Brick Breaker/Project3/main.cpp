#include <SFML\Graphics.hpp>	
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include <SFML\Audio.hpp>
using namespace std;
using namespace sf;
#define MAX_NUMBER_OF_ITEMS 4
class Menu
{
public:
	Menu(float width, float height);
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("PHOTO/score.TTF"))
	{
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Play level 1");
	menu[0].setCharacterSize(36);
	menu[0].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Play level 2");
	menu[1].setCharacterSize(36);
	menu[1].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));


	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("score");
	menu[2].setCharacterSize(50);
	menu[2].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(Color::White);
	menu[3].setString("Exit");
	menu[3].setCharacterSize(50);
	menu[3].setPosition(sf::Vector2f(width / 2.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	selectedItemIndex = 0;
}
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}


// postion of litter A****
int AA[12][2] = {
	0 , 97 ,
	130 , 97,
	190 , 97 ,
	190 , 37 ,
	64 , 37 ,
	525 , 37 ,
	651 , 37 ,
	323 , 200 ,
	455 , 200 ,
	490 , 260 ,
	590 , 97 ,
	380 , 320 };

// postioin of litter L*****
int LL[2][2] = {
	590 , 37 ,
	64 , 97
};

// position of litter N*****
int nn[3][2] = {
	0 , 37 ,
	258 , 200 ,
	237, 260
};

// postion of litter D*****
int d[4][2]{
	130 , 37 ,
	652 , 97 ,
	389 , 200 ,
	570 , 320 ,
};

// position of litter S*****
int s[3][2] = {
	460 , 37 ,
	363 , 260 ,
	460, 97
};

// position of litter H*****
int h[3][2] = {
	719 , 37 ,
	523 , 97 ,
	318, 320
};

// position of litter M*****
int m[3][2] = {
	446 , 320 ,
	190 , 320 ,
	427, 260
};

// position of litter E*****
int ee[2][2] = {
	300 , 260 ,
	510, 320
};

// position of Bodys
int Body[3][2] = {
	616, 250 ,
	80 , 250 ,
	310 , 70 ,
};

//
struct point {
	int x, y;
} a[12];

bool iscollide(Sprite s1, Sprite s2)
{

	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

	bool hide = true;
int main()
{
	bool  loss = true;
	srand(time(0));
	int score1 = 0;
	//Music Menu 
	
	Music song2;
	if (song2.openFromFile("PHOTO/song2.ogg") == 0)
		return 1;
	// Font 

	Font font;

	font.loadFromFile("PHOTO/score.TTF");

	Texture t1, t2, t3, t4, t5, t6;
	t1.loadFromFile("PHOTO/block2.gif");
	t2.loadFromFile("PHOTO/bach1.png");
	t3.loadFromFile("PHOTO/ball2.gif");
	t4.loadFromFile("PHOTO/paddle2.gif");
	t6.loadFromFile("PHOTO/block3.gif");

	bool loss1 = true;

	//texet
	Text titel1;
	titel1.setFont(font);
	titel1.setString("Score : " + std::to_string(score1));
	titel1.setFillColor(sf::Color(200, 500, 0));


	Sprite backgraud(t2), ball1(t3), ruler1(t4),  block3(t6);
	ruler1.setPosition(328, 578);
	ball1.setPosition(355, 544);
	block3.setPosition(370, 294);
	Sprite block[1000];
	int n = 0;
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= 5; j++) {
			block[n].setPosition(i * 42, j * 30);
			block[n].setTexture(t1);
			n++;
		}

	for (int i = 1; i <= 6; i++)
		for (int j = 8; j <=14 ; j++) {
			block[n].setPosition(i * 42, j * 30);
			block[n].setTexture(t1);
			n++;
		}

	for (int i = 14; i <= 20; i++)
		for (int j = 8; j <= 14; j++) {
			block[n].setPosition(i * 37, j * 30);
			block[n].setTexture(t1);
			n++;
		}
	//Music Level 2 
	Music song;
	if (song.openFromFile("PHOTO/song3.ogg") == 0)
		return 1;
	float dx = 6, dy = -5;
	float x;
	// level 1******
	float movex = 0.5;
	float movey = -2;
	bool game = 0;
	int ruler_scale = 1;
	srand(time(0));
	RenderWindow window(sf::VideoMode(800, 600), "Brick Breaker");
	//Background menu
	Texture textureback;
	textureback.loadFromFile("PHOTO/photo.png");
	Sprite background1(textureback);

	int score = 0;
	//Background 
	Texture textures;
	textures.loadFromFile("PHOTO/Picture.png");
	Sprite background(textures);

	//music
	Music song1;
	if (song1.openFromFile("PHOTO/song.ogg") == 0)
		return 1;

	// Font 
	font.loadFromFile("PHOTO/score.TTF");

	// TEXT
	Text titel;
	titel.setFont(font);
	titel.setString("Score : " + std::to_string(score));
	titel.setFillColor(sf::Color(255, 215, 0));

	//Ruler
	Texture texture;
	texture.loadFromFile("PHOTO/do.gif");
	Sprite ruler(texture);
	ruler.setPosition(328, 585);

	//Ball
	Texture texture1;
	texture1.loadFromFile("PHOTO/ball.gif");
	Sprite ball(texture1);
	ball.setPosition(355, 549);

	// Shaps 
	Texture texture3;
	Sprite N[3];
	for (int i = 0; i < 3; i++) {
		texture3.loadFromFile("PHOTO/N.gif");
		N[i].setTexture(texture3);
	}

	Texture texture9;
	Sprite A[12];
	for (int i = 0; i < 12; i++)
	{
		texture9.loadFromFile("PHOTO/A.gif");
		A[i].setTexture(texture9);
	}

	Texture texture10;
	Sprite L[2];
	for (int i = 0; i < 2; i++) {
		texture10.loadFromFile("PHOTO/L.gif");
		L[i].setTexture(texture10);
	}

	Texture texture5;
	Sprite S[3];
	for (int i = 0; i < 3; i++) {
		texture5.loadFromFile("PHOTO/S.gif");
		S[i].setTexture(texture5);
	}

	Texture texture8;
	Sprite D[4];
	for (int i = 0; i < 4; i++) {
		texture8.loadFromFile("PHOTO/D.gif");
		D[i].setTexture(texture8);
	}

	Texture texture11;
	Sprite body[3];
	for (int i = 0; i < 3; i++) {
		texture11.loadFromFile("PHOTO/body2.gif");
		body[i].setTexture(texture11);
	}



	Texture texture12;
	Sprite H[3];
	for (int i = 0; i < 3; i++) {
		texture12.loadFromFile("PHOTO/H.gif");
		H[i].setTexture(texture12);
	}

	Texture texture18;
	texture18.loadFromFile("PHOTO/Y.gif");
	Sprite Y(texture18);
	Y.setPosition(720, 97);

	Texture texture21;
	Sprite E[2];
	for (int i = 0; i < 2; i++) {
		texture21.loadFromFile("PHOTO/E.gif");
		E[i].setTexture(texture21);
	}

	Texture texture23;
	Sprite M[3];
	for (int i = 0; i < 3; i++) {
		texture23.loadFromFile("PHOTO/M.gif");
		M[i].setTexture(texture23);
	}

	Texture texture26;
	texture26.loadFromFile("PHOTO/O.gif");
	Sprite O(texture26);
	O.setPosition(251, 320);

	bool hideE[2];
	for (int i = 0; i < 2; i++)
	{
		hideE[i] = true;
	}
	bool hideN[3];
	for (int i = 0; i < 3; i++)
	{
		hideN[i] = true;
	}
	bool hideA[12];
	for (int i = 0; i < 12; i++)
	{
		hideA[i] = true;
	}
	bool hideD[4];
	for (int i = 0; i < 4; i++)
	{
		hideD[i] = true;
	}
	bool hide4[3];
	for (int i = 0; i < 3; i++)
	{
		hide4[i] = true;
	}

	bool hideS[3];
	for (int i = 0; i < 3; i++)
	{
		hideS[i] = true;
	}

	bool hideL[2];
	for (int i = 0; i < 2; i++)
	{
		hideL[i] = true;
	}
	bool hideM[4];
	for (int i = 0; i < 4; i++)
	{
		hideM[i] = true;
	}
	bool  hideH[3];
	for (int i = 0; i < 3; i++)
	{
		hideH[i] = true;
	}
	bool hideO = true;
	bool hideY = true;
	// 0 -> level 1
	// 1 -> level 2
	// 2 -> menu
	int phase = 2;
	if (phase == 2) {
		song2.setLoop(true);
		song2.play();
	}
	else {
		song2.stop();
	}
	bool bl = 0;
	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		//events
		Event event;
		Event e;
		Event event1;
		if (phase == 2) {

			while (window.pollEvent(event1))
			{
				switch (event1.type)
				{
				case Event::KeyReleased:
					switch (event1.key.code)
					{
					case Keyboard::Up:
						menu.MoveUp();
						break;

					case Keyboard::Down:
						menu.MoveDown();
						break;

					case Keyboard::Return:
						switch (menu.GetPressedItem())
						{
						case 0:
							phase = 0;
							song2.stop();
							song1.setLoop(true);
							song1.play();
							break;
						case 1:
							phase = 1;
							song2.stop();
							song.setLoop(true);
							song.play();
							break;
						case 2:
							phase = 3;
							break;
						case 3:
							window.close();
							break;
						}

						break;
					}

					break;
				case Event::Closed:
					window.close();

					break;

				}
			}
		}
		if (phase == 0) {
			
			while (window.pollEvent(event))
			{

				if (event.type == Event::Closed)
				{
					window.close();
				}
				if (Keyboard::isKeyPressed(Keyboard::Right) && ruler.getPosition().x < 717) {
					ruler.move(60, 0);
					ruler.setOrigin(0, 0);
					ruler.setScale(ruler_scale, ruler_scale);
				}
			/*	if (event.type== Event::MouseMoved && ruler1.getPosition().x > 10 && ruler1.getPosition().x < 717) {
					x  = event.mouseMove.x;
					if (x < ruler1.getPosition().x|| ruler1.getPosition().x >= 717) {
						x = event.mouseMove.x % 20;
						ruler1.move(-x, 0);
					}
					else {
						x = event.mouseMove.x%20;
						ruler1.move(x, 0);
					}*/
				if (Keyboard::isKeyPressed(Keyboard::Left) && ruler.getPosition().x > 10) {
					ruler.move(-60, 0);
				ruler.setOrigin(ruler.getLocalBounds().width, 0);
				ruler.setScale(-ruler_scale, ruler_scale);
				}
			
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
				{
					game = 1;
				}

			}

			if (game)
			{
				ball.move(movex, movey);
			}
			if (ball.getPosition().x > 750)
			{
				movex = -movex;
			}

			if (ball.getPosition().y < 10)
			{
				movey = -movey;
			}
			if (ball.getPosition().x < 10)
			{
				movex = -movex;
			}

			// hide rectangels
			for (int i = 0; i < 2; i++)
			{
				if (ball.getGlobalBounds().intersects(L[i].getGlobalBounds()) && hideL[i]) {

					hideL[i] = false;
					score++;
				}
			}
			for (int i = 0; i < 2; i++)
			{
				if (ball.getGlobalBounds().intersects(E[i].getGlobalBounds()) && hideE[i]) {

					hideE[i] = false;
					score++;
				}
			}
			for (int i = 0; i < 3; i++)
			{
				if (ball.getGlobalBounds().intersects(N[i].getGlobalBounds()) && hideN[i]) {

					hideN[i] = false;
					score++;
				}
			}
			for (int i = 0; i < 4; i++)
			{
				if (ball.getGlobalBounds().intersects(D[i].getGlobalBounds()) && hideD[i]) {

					hideD[i] = false;
					score++;
				}
			}
			for (int i = 0; i < 12; i++)
			{
				if (ball.getGlobalBounds().intersects(A[i].getGlobalBounds()) && hideA[i]) {

					hideA[i] = false;
					score++;
				}
			}

			if (ball.getGlobalBounds().intersects(O.getGlobalBounds()) && hideO) {

				hideO = false;
				score++;
			}
			if (ball.getGlobalBounds().intersects(Y.getGlobalBounds()) && hideY) {

				hideY = false;
				score++;
			}
			for (int i = 0; i < 3; i++)
			{
				if (ball.getGlobalBounds().intersects(S[i].getGlobalBounds()) && hideS[i]) {

					hideS[i] = false;
					score++;
				}
			}
			for (int i = 0; i < 3; i++)
			{
				if (ball.getGlobalBounds().intersects(M[i].getGlobalBounds()) && hideM[i]) {

					hideM[i] = false;
					score++;
				}
			}
			for (int i = 0; i < 3; i++)
			{
				if (ball.getGlobalBounds().intersects(H[i].getGlobalBounds()) && hideH[i]) {

					hideH[i] = false;
					score++;
				}
			}
			if (ball.getGlobalBounds().intersects(ruler.getGlobalBounds())) {

				movey = -(rand() % 5 + 2);
			}
			for (int i = 0; i < 3; i++)
			{
				if (ball.getGlobalBounds().intersects(body[i].getGlobalBounds())) {
					movex = -movex;
					movey = -movey;
				}
			}

			if (ball.getPosition().y > 598)
			{
				titel.setString("YOU    LOST \n Score : " + std::to_string(score));

				titel.setFillColor(Color(255, 215, 0));

				titel.setPosition(320, 220);
				loss1 = false;
			}
			else {

				titel.setString("Score : " + std::to_string(score));

			}
			if (score == 34)
			{
				titel.setString("YOU    WIN \n Score : " + std::to_string(score));

				titel.setFillColor(sf::Color(255, 215, 0));

				titel.setPosition(320, 220);
				
			}
		}
		if (phase == 1) {
			
			while (window.pollEvent(e))
			{
				if (e.type == Event::Closed)
					window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				ball1.move(dx, dy);
			}
	
				ball1.move(dx / 10, 0);
			for (int i = 0; i < n; i++)
				if (iscollide(ball1, block[i])) { block[i].setPosition(-100, 0); score1++; dx = -dx; }
		
				ball1.move(0, dy / 10);
			for (int i = 0; i < n; i++)
				if (iscollide(ball1, block[i])) { block[i].setPosition(-100, 0); score1++; dy = -dy; }

			if (Keyboard::isKeyPressed(Keyboard::Right)&& ruler1.getPosition().x < 714)ruler1.move(6, 0);
			if (Keyboard::isKeyPressed(Keyboard::Left) && ruler1.getPosition().x > 10) ruler1.move(-6, 0);
			if (iscollide(ruler1, ball1)) { dy = -(rand() % 5 + 2); }
			if (iscollide(block3, ball1)) {
				dy = -(rand() % 5 + 2);
				dx = -(rand() % 10 + 2);
			}
			Vector2f b = ball1.getPosition();
			if (b.x < 10 || b.x >790) {
				
				dx = -dx;
			}
			if (b.y < 0) {
				dy = -dy;
				
			}

			if (ball1.getPosition().y > 587)
			{
				titel1.setString("YOU    LOST \n Score : " + std::to_string(score1));
				titel1.setFillColor(Color(200, 500, 0));
				titel1.setPosition(390, 330);
				loss = false;
			}
			else if (score == 185) {
				titel1.setString("you win 000000000 \n Score : " + std::to_string(score1));
				titel1.setFillColor(Color(200, 500, 0));
				titel1.setPosition(390, 330);
			}
			else {
				titel1.setString("Score : " + std::to_string(score1));
			}

		

		}
		// Clear this design 

		window.clear();


		if (phase == 0) {

			if (loss1 == true) {
				if (score1 == 34) {
					window.draw(titel);
					phase = 1;
				}
				else {
					window.draw(background);

					window.draw(ruler);
					// position bodys******
					for (int i = 0; i < 3; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = Body[i][J];
							if (J == 1)
								a[i].y = Body[i][J];
						}
					}
					for (int i = 0; i < 3; i++)
					{
						body[i].setPosition(a[i].x, a[i].y);
						window.draw(body[i]);
					/*	if (ball.getGlobalBounds().intersects(body[i].getGlobalBounds())) {
							movex = -(rand() % 5 + 2);
							movey = -(rand() % 5 + 2);
						}*/
					}

					// position N******
					for (int i = 0; i < 3; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = nn[i][J];
							if (J == 1)
								a[i].y = nn[i][J];
						}
					}
					for (int i = 0; i < 3; i++)
					{
						N[i].setPosition(a[i].x, a[i].y);
						if (hideN[i])
						{
							window.draw(N[i]);
						}
					}

					// position A*****
					for (int i = 0; i < 12; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = AA[i][J];
							if (J == 1)
								a[i].y = AA[i][J];
						}
					}
					for (int i = 0; i < 12; i++)
					{
						A[i].setPosition(a[i].x, a[i].y);
						if (hideA[i])
							window.draw(A[i]);
					}

					// position L*****
					for (int i = 0; i < 2; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = LL[i][J];
							if (J == 1)
								a[i].y = LL[i][J];
						}
					}

					for (int i = 0; i < 2; i++)
					{
						L[i].setPosition(a[i].x, a[i].y);
						if (hideL[i])
							window.draw(L[i]);

					}

					// position D******
					for (int i = 0; i < 4; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = d[i][J];
							if (J == 1)
								a[i].y = d[i][J];
						}
					}
					for (int i = 0; i < 4; i++)
					{
						D[i].setPosition(a[i].x, a[i].y);
						if (hideD[i])
							window.draw(D[i]);

					}

					// postion S*****
					for (int i = 0; i < 3; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = s[i][J];
							if (J == 1)
								a[i].y = s[i][J];
						}
					}
					for (int i = 0; i < 3; i++)
					{
						S[i].setPosition(a[i].x, a[i].y);
						if (hideS[i])
							window.draw(S[i]);

					}

					// position H*****
					for (int i = 0; i < 3; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = h[i][J];
							if (J == 1)
								a[i].y = h[i][J];
						}
					}
					for (int i = 0; i < 3; i++)
					{
						H[i].setPosition(a[i].x, a[i].y);
						if (hideH[i])
							window.draw(H[i]);

					}

					// position M*****
					for (int i = 0; i < 3; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = m[i][J];
							if (J == 1)
								a[i].y = m[i][J];
						}
					}
					for (int i = 0; i < 3; i++)
					{
						M[i].setPosition(a[i].x, a[i].y);
						if (hideM[i])
							window.draw(M[i]);

					}

					// position E*****
					for (int i = 0; i < 2; i++)
					{
						for (int J = 0; J < 2; J++)
						{
							if (J == 0)
								a[i].x = ee[i][J];
							if (J == 1)
								a[i].y = ee[i][J];
						}
					}
					for (int i = 0; i < 2; i++)
					{
						E[i].setPosition(a[i].x, a[i].y);
						if (hideE[i])
							window.draw(E[i]);


					}


					if (hideY)
						window.draw(Y);
					if (hideO)
						window.draw(O);
					window.draw(titel);

					window.draw(ball);
				}
		}else {
			window.draw(titel);
			}
		}
		if (phase == 1) {

			if (loss == true) {
				if (score1 == 185) {
					window.draw(titel1);
					
				}
				else {
					window.draw(backgraud);
					window.draw(ball1);
					window.draw(ruler1);
					window.draw(block3);
					for (int i = 0; i < n; i++) {
						window.draw(block[i]);
					}
					window.draw(titel1);
				}
			}
			else {
				window.draw(titel1);
				
			}

		}
		if (phase == 2) {

			window.draw(background1);
			menu.draw(window);
		}
		window.display();
	}

	return 0;
}
