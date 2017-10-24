class Button {
    int id;
    String displayName;
    int parent;
    int child;
    int leds[];
    bool buttonState;
  public:
    Button(int id, String displayName, int parent, int child);
    void light(CRGB color);
};

Button::Button(int id, String displayName, int parent, int child) {
  Button::id = id;
  Button::displayName = displayName;
  Button::parent = parent;
  Button::child = child;
//  for (int i = 0; i < sizeof(leds); i++) {
//    Button::leds[i] = leds[i];
//  }
}

void Button::light(CRGB color) {

}

class Line {
    int id;
    int buttonStart;
    int buttonEnd;
    int leds[];

  public:
    Line(int id, int buttonStart, int buttonEnd, int leds[]);
    void light(CRGB color);
};

Line::Line(int id, int buttonStart, int buttonEnd, int leds[]) {
  Line::id = id;
  Line::buttonStart = buttonStart;
  Line::buttonEnd = buttonEnd;
  for (int i = 0; i < sizeof(leds); i++) {
    Line::leds[i] = leds[i];
  }
};

void Line::light(CRGB color){
  
}

  
