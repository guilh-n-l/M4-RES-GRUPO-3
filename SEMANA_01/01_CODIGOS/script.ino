bool boolSwitch = false;

String createTruth(bool argBool, String argString, int argInt, float argFloat) {
  String boolVal;
  if(argBool == true) {
    boolVal = " is True";
    if(argFloat < 50) {
      boolVal = " should be True";
    }
  }
  else {
    boolVal = " is False";
    if(argFloat < 50) {
      boolVal = " should be False";
    }
  }
  String message = argString + boolVal + " with " + String(argFloat, 2) + "% of confidence, calculated by a wopping speed of " + String(argInt) + "Km/h";
  boolSwitch = true;
  return message;
} 

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a statement, it's truth value, and the level of confidence (Ex.: 'Dogs > Cats, true, 95')");
}

void loop() {
  while (boolSwitch == false) {
    if (Serial.available() > 0) {
      String wholeString = Serial.readStringUntil('\n');
      int firstComma = wholeString.indexOf(", ");
      String statement = wholeString.substring(0, firstComma);
      int secondComma = wholeString.indexOf(", ", firstComma + 1);
      bool truthValue = wholeString.substring(firstComma + 2, secondComma).equalsIgnoreCase("true");
      float confidence = wholeString.substring(secondComma + 2).toFloat();
      Serial.println(createTruth(truthValue, statement, 100, confidence));
    }
  }
}
