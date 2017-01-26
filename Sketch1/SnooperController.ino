int Forward = 2;
int Backward = 4;
int Left = 7;
int Right = 8;
int pin13 = 13;
int initial = 1;

void setup() {
	pinMode(Forward, OUTPUT);
	pinMode(Backward, OUTPUT);
	pinMode(Left, OUTPUT);
	pinMode(Right, OUTPUT);
	pinMode(pin13, OUTPUT);
	Serial.begin(9600);
}
void loop() {
	if (initial == 1) {
		digitalWrite(Forward, HIGH);
		digitalWrite(Backward, HIGH);
		digitalWrite(Left, HIGH);
		digitalWrite(Right, HIGH);
		initial++;
	}
	if (Serial.available() > 0) {
		int data = Serial.read();
		if (data == 0) {
			digitalWrite(Forward, HIGH);
		}
		if (data == 1) {
			digitalWrite(Forward, LOW);
		}
		else if (data == 2) {
			digitalWrite(Backward, HIGH);
		}
		else if (data == 3)
			digitalWrite(Backward, LOW);
		else if (data == 4)
			digitalWrite(Left, HIGH);
		else if (data == 5)
			digitalWrite(Left, LOW);
		else if (data == 6)
			digitalWrite(Right, HIGH);
		else if (data == 7)
			digitalWrite(Right, LOW);
		else {
			/*digitalWrite(Forward, HIGH);
			digitalWrite(Backward, HIGH);
			digitalWrite(Left, HIGH);
			digitalWrite(Right, HIGH);*/
			digitalWrite(pin13, HIGH);
		}
	}
}