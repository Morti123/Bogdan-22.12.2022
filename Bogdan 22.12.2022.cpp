
#include "aide.h"
#include "functions.h"
using namespace sf;
int main()
{
	srand(time(nullptr));
	// Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//ñîçäàíèå îáúåêòîâ èãðû

	//ðàêåòêè
	RectangleShape leftBat, rightBat;
	initBat(leftBat, leftBatColor, leftBatStartPos);
	initBat(rightBat, rightBatColor, rightBatStartPos);
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;
	//øàðèê
	CircleShape ball;
	initBall(ball, BALL_COLOR, ballStartPos);

	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	//Ñ×ÅÒ
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;

	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	initText(leftPlayerScoreText, leftPlayerScore, font, charSize, leftTextStartPos);
	Text rightPlayerScoreText;
	initText(rightPlayerScoreText, rightPlayerScore, font, charSize, rightTextStartPos);
	// Ãëàâíûé öèêë ïðèëîæåíèÿ. Âûïîëíÿåòñÿ, ïîêà îòêðûòî îêíî
	while (window.isOpen())
	{
		//1 Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
		Event event;
		while (window.pollEvent(event))
		{
			// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
			if (event.type == Event::Closed)
				// òîãäà çàêðûâàåì åãî
				window.close();
		}

		//2 Îáíîâëåíèå îáúåêòîâ
		//øàðèê
		//äâèæåíèå øàðèêà
		ball.move(ball_speedx, ball_speedy);
		//ïîïàë-âûøåë çà ëåâóþ 
		if (ball.getPosition().x <= 0)
		{
			//ñêîðîñòü ïî îñè õ ñìåíèëàñü íà ïðîòèâîïîëîæíóþ
			ball_speedx = -ball_speedx;
			//ïðàâûé èãðîê çàáèë ãîë
			rightPlayerScore++;
			rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
		}
		//èëè ïðàâóþ ãðàíèöó
		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * BALL_RADIUS))
		{
			//ñêîðîñòü ïî îñè õ ñìåíèëàñü íà ïðîòèâîïîëîæíóþ
			ball_speedx = -ball_speedx;
			//ëåâûé èãðîê çàáèë ãîë
			leftPlayerScore++;
			leftPlayerScoreText.setString(std::to_string(leftPlayerScore));
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_HEIGHT - 2 * BALL_RADIUS))
		{
			//ñêîðîñòü ïî îñè y ñìåíèëàñü íà ïðîòèâîïîëîæíóþ
			ball_speedy = -ball_speedy;
		}

		//Ïðîâåðêà íàæàòèé êëàâèø
		//åñëè êëàâèøà W íàæàòà - ëåâà ðàêåòêà âíèç
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedY = batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rightBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightBatSpeedY = batSpeed;
		}
		if (leftBat.getPosition().y <= 0) {
			leftBat.setPosition(batOffset, 0.f);
		}
		if (leftBat.getPosition().y + batHeight >= WINDOW_HEIGHT) {
			leftBat.setPosition(batOffset, WINDOW_HEIGHT - batHeight);
		}
		if (rightBat.getPosition().y <= 0) {
			rightBat.setPosition(WINDOW_WIDTH - batOffset, 0.f);
		}
		if (rightBat.getPosition().y + batHeight >= WINDOW_HEIGHT) {
			rightBat.setPosition(WINDOW_WIDTH - batOffset, WINDOW_HEIGHT - batHeight);
		}
		//äâèãàåì ðàêåòêó  
		leftBat.move(0, leftBatSpeedY);
		rightBat.move(0, rightBatSpeedY);
		//è ñðàçó îáíóëÿåì ñêîðîñòü
		leftBatSpeedY = 0;
		rightBatSpeedY = 0;
		float ballX = ball.getPosition().x;
		float ballY = ball.getPosition().y;
		Vector2f midTop{ ballX + BALL_RADIUS,  ballY };
		Vector2f  midLeft{ ballX, ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS,  ballY + 2 *  BALL_RADIUS };
		Vector2f midRight{ ballX + 2* BALL_RADIUS, ballY+BALL_RADIUS };
		if (pointInRect(leftBat, midLeft)) ball_speedx = -ball_speedx;
		if (pointInRect(leftBat,midBottom)|| pointInRect(leftBat, midTop)) ball_speedy = -ball_speedy;
		if (pointInRect(rightBat, midRight)) ball_speedx = -ball_speedx;
		if (pointInRect(rightBat, midBottom) || pointInRect(rightBat, midTop)) ball_speedy = -ball_speedy;

		//3 Îòðèñîâêà îêíà
		//3.1 Î÷èñòêà îêíà
		window.clear(sf::Color(0,613,0,613));
		//3.2 Îòðèñîâêà îáúåêòîâ (Â ÏÀÌßÒÈ!)
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);
		//3.3 âûâîä íà ýêðàí
		window.display();
	}

	return 0;
}