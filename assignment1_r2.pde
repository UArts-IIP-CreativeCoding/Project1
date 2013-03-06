// credits
// http://processing.org/reference/
// movement design for "stress"
// brenden moore - uarts 2013

int value = 0;

void setup() {
  size(1024, 768);
  smooth();
  background(0);
}

void draw() {
  // smaller o - green relaxed
  stroke(255);
  fill(169, 239, 185);
  ellipse(width/2, height/2, 50, 50);
  // larger o - red alaert
  if (mousePressed) {
    fill(176, 15, 15);
    ellipse(width/2, height/2, 250, 250);
    
  //noFill();
  fill(169, 239, 185);
  stroke(50);
  beginShape();
  curveVertex(random, 800); // the first control point
  curveVertex(700, 500); // is also the start point of curve

  curveVertex(50, 150); // the last point of curve
  curveVertex(300, 200); // is also the last control point
  endShape();
    
  }   
  else {
    background(0);
    ellipse(width/2, height/2, 50, 50);
  }
}

//void mouseClicked() {
//  if (value == 0) {
//    background(0);    
//    fill(176, 15, 15);
//    ellipse(width/2, height/2, 250, 250); // larger o
//  }
//  else {
//    value = 0;
//  }
//}

