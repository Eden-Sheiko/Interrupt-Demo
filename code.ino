const int SW1_PIN = 3;
const int SW2_PIN = 2;
const int GREEN_LED_PIN = 5;
const int RED_LED_PIN = 4;

void setup() {
  // Disable global interrupts
  cli();
  
  // Configure Inputs/Outputs
  // Inputs:
  DDRD &= ~(1 << SW1_PIN);
  DDRD &= ~(1 << SW2_PIN);
  // Outputs:
  DDRB |= (1 << GREEN_LED_PIN);
  DDRB |= (1 << RED_LED_PIN);

  // Configure interrupt triggers
  // SW1: Logical Change Trigger
  EICRA |= (1 << ISC00);
  // SW2: Rising Edge Trigger
  EICRA |= (1 << ISC11) | (1 << ISC10);

  // Enable Interrupt Vectors
  EIMSK |= (1 << INT0) | (1 << INT1);

  // Enable global interrupts
  sei();
}

// ISR for SW1 interrupt
ISR(INT0_vect) {
  // Toggle green LED
  PORTB ^= (1 << GREEN_LED_PIN);
}

// ISR for SW2 interrupt
ISR(INT1_vect) {
  // Toggle red LED
  PORTB ^= (1 << RED_LED_PIN);
}

void loop() {
  // The main loop will remain empty, as the ISR will handle the LED state change
}
