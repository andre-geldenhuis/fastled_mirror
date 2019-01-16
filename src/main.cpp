#include "FastLED.h"

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define NUM_STRIPS 1
#define NUM_LEDS_PER_STRIP 60
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS
CRGBArray<NUM_LEDS> leds;

//#define BRIGHTNESS          30
#define BRIGHTNESS          25
#define FRAMES_PER_SECOND  120



uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void setup() {
  delay(200); // 3 second delay for recovery

  // tell FastLED there's 60 NEOPIXEL leds on pin 3, starting at index 0 in the led array
  FastLED.addLeds<NEOPIXEL, 13>(leds, 0, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // static uint8_t hue=0;
  // leds(0,NUM_LEDS/2 - 1).fill_rainbow(hue++);  // fill the first 20 items with a rainbow
  // leds(NUM_LEDS/2, NUM_LEDS-1) = leds(NUM_LEDS/2-1,0);
  // FastLED.delay(30);

  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds(0,29), NUM_LEDS/2, 20);
  int pos = beatsin16(13,0,NUM_LEDS/2-1);
  leds[pos] += CHSV( gHue, 255, 192);
  leds(NUM_LEDS/2, NUM_LEDS-1) = leds(NUM_LEDS/2-1,0);
  FastLED.show();


}
